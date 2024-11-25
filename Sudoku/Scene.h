#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include "Block.h"
#include "Utils.inl"
#include "Enums.h"

using namespace std;


class Scene
{
public:
	static vector<vector<char>> _PATTERN;
	static void InitPattern();
	Scene();
	~Scene();
	void Create(Type type);
	int* GetNums();

private:
	int _nums[81];
	Block _rowBlocks[MAX_COUNT];
	Block _columnBlocks[MAX_COUNT];
	Block _cellBlocks[3][3];

	void EarseNumberRamdon(int num);
	
};

