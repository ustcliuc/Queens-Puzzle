#include "BasicOperations.h"

//随机法搜索
//use random method to search for a solution
int *randomSearch(const int N)
{
	int *queens = new int[N];
	while (true)
	{
		queens = initQueens2(N);
		if (checkCurrentState(queens, N) == true)
			break;
		else
			delete queens;
	}
	return queens;
}
