#include <iostream>

#include "BasicOperations.h"

using namespace std;

//找到一种交换方式使全局使冲突数最少，返回最小冲突数
//Find a switch plan to minimize the number of conflictions globally and retrun the new number of conflictions
int minimizeConflictionsGlobally(int *queens, const int N)
{
	int num_conflictions = countConflictions(queens, N);
	if (num_conflictions == 0)
		return 0;
	int new_row = -1;
	int new_col = -1;
	for (int i = 0; i < N; i++)
	{
		int temp = queens[i];
		for (int j = 0; j < N; j++)
		{
			if (j == temp)
				continue;
			queens[i] = j;
			int new_num_conflictions = countConflictions(queens, N);
			if (new_num_conflictions < num_conflictions)
			{
				num_conflictions = new_num_conflictions;
				new_row = i;
				new_col = j;
			}
		}
		queens[i] = temp;
	}
	if(new_row == -1 && new_col == -1){
		return -1;
	}
	queens[new_row] = new_col;
	return num_conflictions;
}

//爬山法搜索（带重新初始化）
//Use Hill Climbing method to search for a solution, 
//using re-initialization to avoid local minima
int *hillClimbingSearch(const int N){
	int *queens, *negative_diagonal_num, *positive_diagonal_num;
	int total_search_times = 0;
	while (true)
	{
		if (initQueens3(queens, negative_diagonal_num, positive_diagonal_num, N) == 0)
			return queens;
		int adjust_times = 0;
		while (true)
		{
			int num_conflictions = minimizeConflictionsGlobally(queens, N);
			adjust_times++;
			if(num_conflictions == 0)
			{
				//cout << "initialize times:" << total_search_times << endl;
				//cout<<"minimize times:"<< adjust_times <<endl;
				return queens;
			}
			else if (num_conflictions == -1)
				break;	//跳出并重新初始化/Re-initialization
		}
		delete queens;
		delete negative_diagonal_num;
		delete positive_diagonal_num;
		total_search_times++;
	}
}
