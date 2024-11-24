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
    //for(int i = 0; i < _MAX_COUNT)

}

Scene::~Scene()
{

}

void Scene::Create() {
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
}