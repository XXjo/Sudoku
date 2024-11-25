#include "Block.h"
#include <assert.h>


Block::Block()
{
}

Block::~Block()
{
}

void Block::SetValue(int* value) {
	_nums[_index++] = value;
}

bool Block::IsValid() const {
	assert(_index == MAX_COUNT);
	for (int i = 0; i < _index; i++) {
		for (int j = i + 1; j < _index; j++) {
			if (*_nums[i] == *_nums[j]) {
				return false;
			}
		}
	}
	return true;
}