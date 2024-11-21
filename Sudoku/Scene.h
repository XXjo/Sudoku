#pragma once
#include <vector>
#include <string>
using namespace std;


class Scene
{
public:
	
	Scene();
	~Scene();
	void Create();

private:
	static vector<vector<char>> _PATTERN;
};

