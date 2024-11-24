#pragma once

constexpr int MAX_COUNT = 9;	//声明全局变量

class Block
{
public:
	Block();
	~Block();
	bool IsValid() const;
	void SetValue(int* value);

private:
	int* _nums[MAX_COUNT];
	int index = 0;
};


