#pragma once
#include <vector>
#include <string>
#include "Block.h"
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
	Block _rowBlock[9];
	Block _columnBlock[9];
	Block _cellBlock[3][3];
	
};

