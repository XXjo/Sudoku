#pragma once

#include <stdlib.h>
#include <time.h>

/// <summary>
/// 生成指定范围内的随机整数
/// </summary>
/// <param name="begin"></param>
/// <param name="end"></param>
/// <returns></returns>
inline int Random(int begin, int end) {
	srand(time(NULL));
	return rand() % (end - begin + 1) + begin;
}
