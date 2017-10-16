#include<iostream>
using namespace std;
int success = 0;//定义全局标志，表示老鼠走迷宫是否成功
int findPath(int i, int j, int endRow, int endCol, int **maze, int n, int m);//n表示行数,m表示列数
void mouseMaze(int startRow, int startCol, int endRow, int endCol, int **maze, int n, int m)
{
	cout << "迷宫示意图如下：" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (maze[i][j] == 2)
			{
				cout << "#";
			}
			else cout << " ";
		}
		cout << endl;
	}
	if (findPath(startRow, startCol, endRow, endCol, maze, n, m) == 0)
	{
		cout << "没有出口" << endl;
	}
	else {
		cout << "老鼠走过的路径为" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (maze[i][j] == 2)
				{
					cout << "#";
				}
				else if (maze[i][j] == 1)
				{
					cout << "*";
				}
				else { cout << " "; }
			}
			cout << endl;
		}
		
	}
}
int findPath(int i, int j, int endRow, int endCol, int **maze, int n, int m)
{
	maze[i][j] = 1;//将当前所在的各自赋值为1；表示已经走过
	if (i == endRow&&j == endCol)
	{
		success = 1;
		return success;
	}
	else
	{
		if (i < n - 1 && j < m - 2 && maze[i][j+1] == 0 && success != 1)
			findPath(i, j + 1, endRow, endCol, maze, n, m);
		if (i < n - 2 && j < m - 1 && maze[i+1][j] == 0 && success != 1)
			findPath(i+1,j, endRow, endCol, maze, n, m);
		if (i < n - 1 && j-1>0 && maze[i][j-1] == 0 && success != 1)
			findPath(i, j - 1, endRow, endCol, maze, n, m);
		if (i-1>0 && j < m -1&& maze[i-1][j] == 0 && success != 1)
			findPath(i-1, j, endRow, endCol, maze, n, m);
		if (success != 1)
			maze[i][j] == 0;
		return success;
	}
}
int main()
{
	cout << "请输入迷宫的行数和列数：" << endl;
	int n, m;
	cin >> n >> m;
	int**maze = new int*[n];
	for (int i = 0; i < n; i++)
	{
		maze[i] = new int[m];
	}
	cout << "请输入迷宫，2表示墙壁，0表示可以通行的通道：" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> maze[i][j];
		}
	}
	int startRow, startCol, endRow, endCol;
	cout << "请输入迷宫入口坐标：" << endl;
	cin >> startRow >> startCol;
	cout << "请输入迷宫出口位置坐标" << endl;
	cin >> endRow >> endCol;
	mouseMaze(startRow, startCol, endRow, endCol, maze, n, m);
	return 0;
}

















