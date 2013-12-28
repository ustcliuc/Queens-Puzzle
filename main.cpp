#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <time.h>
#include <string>

#include "BasicOperations.h"

using  namespace std;

int *backtrackingSearch(const int N);
int *randomSearch(const int N);
int *hillClimbingSearch(const int N);
int *minConflictsSearch(const int N);

int main()
{
	int *queens = NULL;
	clock_t start;
	clock_t finish;
	float duration;
	int N = 0;
	char command = '-1';
	cout << "Please choose a method:" << endl;
	wcout << "1: Back Tracking Search\t2: Random Search\n3: Hill Climbing Search\t4: Min Conflicts Search(best)\n" << endl;
	while (command != '0')
	{
		cin >> command;
		cout << "Please input N" << endl;
		cin >> N;
		if (N <= 0)
			continue;

		switch (command)
		{
			case '1':
				start = clock();
				queens = backtrackingSearch(N);
				finish = clock();
				duration = (float)(finish-start)*1000/CLOCKS_PER_SEC;		//计算时间
				cout << "Time used: " << duration << "ms" << endl;
				break;
			case '2':
				start = clock();
				queens = randomSearch(N);
				finish = clock();
				duration = (float)(finish-start)*1000/CLOCKS_PER_SEC;
				cout << "Time used: " << duration << "ms" << endl;
				break;
			case '3':
				start = clock();
				queens = hillClimbingSearch(N);
				finish = clock();
				duration = (float)(finish-start)*1000/CLOCKS_PER_SEC;
				cout << "Time used: " << duration << "ms" << endl;
				break;
			case '4':
				start = clock();
				queens = minConflictsSearch(N);
				finish = clock();
				duration = (float)(finish-start)*1000/CLOCKS_PER_SEC;
				cout << "Time used: " << duration << "ms" << endl;
				break;
			case '0':
				break;
			default:
				cout << "Please input correct command" << endl;
		}
		cout << "\n";
		if (checkCurrentState(queens, N) == true)
		{
			cout << "Find a solution" << endl;
			printSolution(queens, N);
			cout << endl;
		}
		else
			cout << "Cannot find a solution" << endl;
		if (queens != NULL)
		{
			delete queens;
			queens = NULL;
		}
	}
	return 0;
}
