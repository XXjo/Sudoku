#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include "Block.h"
#include "Utils.inl"

using namespace std;


class Scene
{
public:
	static vector<vector<char>> _PATTERN;
	static void InitPattern();
	Scene();
	~Scene();
	void Create();

private:
	int _nums[81];
	Block _rowBlock[MAX_COUNT];
	Block _columnBlock[MAX_COUNT];
	Block _cellBlock[3][3];
	
};

