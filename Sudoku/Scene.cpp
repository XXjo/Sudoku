#include "Scene.h"

vector<vector<char>> Scene::_PATTERN;   //静态变量定义，必须得有，否则导致链接报错
void Scene::InitPattern() {
    vector<string> strs{
       "ighcabfde",
       "cabfdeigh",
       "fdeighcab",
       "ghiabcdef",
       "abcdefghi",
       "defghiabc",
       "higbcaefd",
       "bcaefdhig",
       "efdhigbca"
    };
    for (int i = 0; i < strs.size(); i++) {
        vector<char> temp(strs[i].begin(), strs[i].end());
        _PATTERN.push_back(temp);
    }
}


Scene::Scene(){
    //将_nums地址存入对应block
    for (int row = 0; row < MAX_COUNT; row++) {
        Block block;
        for (int col = 0; col < MAX_COUNT; col++) {
            block.SetValue(_nums + row * MAX_COUNT + col);
        }
        _rowBlocks[row] = block;
    }

    for (int col = 0; col < MAX_COUNT; col++) {
        Block block;
        for (int row = 0; row < MAX_COUNT; row++) {
            block.SetValue(_nums + row * MAX_COUNT + col);
        }
        _columnBlocks[col] = block;
    }

    for (int row = 0; row < MAX_COUNT; row++) {
        for (int col = 0; col < MAX_COUNT; col++) {
            _cellBlocks[row / 3][col / 3].SetValue(_nums + row * MAX_COUNT + col);
        }
    }
}

Scene::~Scene()
{

}

void Scene::Create(Type type) {
    unordered_map<char, int> dict;
    vector<char> keys = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' };
    for (int i = 1; i < 10; i++) {
        int index = Random(0, keys.size() - 1);
        dict[keys[index]] = i;
        keys.erase(keys.begin() + index);
    }

    for (int row = 0; row < MAX_COUNT; row++) {
        for (int col = 0; col < MAX_COUNT; col++) {
            int value = dict[_PATTERN[row][col]];
            _nums[row * MAX_COUNT + col] = value;
        }
    }

    int earseNumber = -1;
    switch (type) {
    case Type::simple:
        earseNumber = 20;
        break;
    case Type::medium:
        earseNumber = 35;
        break;
    case Type::hard:
        earseNumber = 50;
        break;
    default:
        earseNumber = 0;
        break;
    }

    this->EarseNumberRamdon(earseNumber);
}

int* Scene::GetNums() {
    return _nums;
}

void Scene::EarseNumberRamdon(int num) {
    vector<int> v;
    for (int i = 0; i < MAX_COUNT * MAX_COUNT; i++) {
        v.push_back(i);
    }
    for (int i = 0; i < num; i++) {
        int index = Random(0, v.size() - 1);
        _nums[v[index]] = -1;
        v.erase(v.begin() + index);
    }
}