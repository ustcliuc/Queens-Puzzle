//随机序列生成，不同行的值可重复
//Generate an array randomly
int *initQueens1(int N);

//随机序列生成，不同行的值不重复
//Generate an array randomly, ensuring that different rows have different value
int *initQueens2(int N);

//初始化序列，使冲突数尽可能最小
//Initialize an array which minimize the number of conflictions
int initQueens3(int *&queens, int *&negative_diagonal_num, int *&positive_diagonal_num, const int N);

//判断该位置是否可以放置
//Check whether this position is available
bool checkPosition(const int *queens, const int row, const int col);

//判断问题是否已被解决
//Check whether current state is a solution
bool checkCurrentState(const int *queens, const int N);

//输出结果
//Print result
void printSolution(const int *queens, const int N);

//将结果写入文件
//Write solution to specific file
void writeSolutionToFile(const char *file_name, const int *queens, const int N);

//计算冲突数
//count confliction times
int countConflictions(const int *queens, const int N);
