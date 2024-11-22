#include "Scene.h"


vector<vector<char>> Scene::_PATTERN;   //静态变量声明，必须得有，否则导致链接报错
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
}

Scene::~Scene()
{

}

void Scene::Create() {

}