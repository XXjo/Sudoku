#pragma once

#include <stdlib.h>
#include <time.h>

/// <summary>
/// ����ָ����Χ�ڵ��������
/// </summary>
/// <param name="begin"></param>
/// <param name="end"></param>
/// <returns></returns>
inline int Random(int begin, int end) {
	srand(time(NULL));
	return rand() % (end - begin + 1) + begin;
}
