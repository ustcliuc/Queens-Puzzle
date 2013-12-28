#include <math.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//ɣͬеֵظ
//Generate an array randomly
int *initQueens1(int N)
{
	int *queens = new int[N];
	for (int i = 0; i < N; i++){
		queens[i] = rand()%N;
	}
	return queens;
}

//ɣͬеֵظ
//Generate an array randomly, ensuring that different rows have different value
int *initQueens2(int N)
{
	int *queens = new int[N];
	for (int i = 0; i < N; i++)
	{
		queens[i] = -1;
	}
	for (int i = 0; i < N; )
	{
		int row = rand()%N;
		if (queens[row] == -1){
			queens[row] = i;
			i++;
		}
	}
	return queens;
}

//ʼУʹͻС
//Initialize an array which minimize the number of conflictions
int initQueens3(int *&queens, int *&negative_diagonal_num, int *&positive_diagonal_num, const int N)
{
	queens = new int[N];
	negative_diagonal_num = new int[2*N-1];
	positive_diagonal_num = new int[2*N-1];

	for (int i = 0; i < 2*N-1; i++)
	{
		negative_diagonal_num[i] = 0;
		positive_diagonal_num[i] = 0;
	}

	for (int i = 0; i < N; i++)
		queens[i] = i;
	int j = 0;
	for (int i = 0; i < N*3.08; i++)
	{
		int m = rand()%(N-j)+j;
		int temp = queens[j];
		queens[j] = queens[m];
		queens[m] = temp;
		if (negative_diagonal_num[j+queens[j]]+positive_diagonal_num[j-queens[j]+N-1] == 0)
		{
			negative_diagonal_num[j+queens[j]]++;
			positive_diagonal_num[j-queens[j]+N-1]++;
			j++;
			if (j == N)
				break;
		}
		else
		{
			temp = queens[j];
			queens[j] = queens[m];
			queens[m] = temp;
		}
	}
	for (int i = j; i < N; i++)
	{
		int m = rand()%(N-i)+i;
		int temp = queens[i];
		queens[i] = queens[m];
		queens[m] = temp;
		negative_diagonal_num[i+queens[i]]++;
		positive_diagonal_num[i-queens[i]+N-1]++;
	}
	return N-j;
}

//жϸλǷԷ
//Check whether this position is available
bool checkPosition(const int *queens, const int row, const int col)
{
	for (int i = 0; i < row; i++)
	{
		if(queens[i] == col || (queens[i]-col) == (i-row) || (queens[i]-col) == (row-i))
			return false;
	}
	return true;
}

//жǷѱ
//Check whether current state is a solution
bool checkCurrentState(const int *queens, const int N)
{
	for (int i = 0; i < N; i++)
	{
		if (checkPosition(queens, i,queens[i]) == false)
			return false;
	}
	return true;
}

//
//Print result
void printSolution(const int *queens, const int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << queens[i] << " ";
	}
}

//дļ
//Write solution to specific file
void writeSolutionToFile(const char *file_name, const int *queens, const int N)
{
	if (!(freopen(file_name, "w", stdout)))
		return;

	for (int i = 0; i < N; i++)
	{
		cout << queens[i] << " ";
	}
}

//ͻ
//count confliction times
int countConflictions(const int *queens, const int N)
{
	int times=0;
	for (int i = 0; i < N; i++)
		for (int j = i+1; j < N; j++)
			if (queens[i] == queens[j] || abs(queens[i]-queens[j]) == abs(i-j))
				times++;
	return times;
}
