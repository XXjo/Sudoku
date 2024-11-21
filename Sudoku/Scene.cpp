#include "Scene.h"

Scene::Scene()
{
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
        vector<char> temp(strs[i].begin(), strs[0].end());
        _PATTERN.push_back(temp);
    }

}

Scene::~Scene()
{
}