#include<iostream>
using namespace std;
int success = 0;//����ȫ�ֱ�־����ʾ�������Թ��Ƿ�ɹ�
int findPath(int i, int j, int endRow, int endCol, int **maze, int n, int m);//n��ʾ����,m��ʾ����
void mouseMaze(int startRow, int startCol, int endRow, int endCol, int **maze, int n, int m)
{
	cout << "�Թ�ʾ��ͼ���£�" << endl;
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
		cout << "û�г���" << endl;
	}
	else {
		cout << "�����߹���·��Ϊ" << endl;
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
	maze[i][j] = 1;//����ǰ���ڵĸ��Ը�ֵΪ1����ʾ�Ѿ��߹�
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
	cout << "�������Թ���������������" << endl;
	int n, m;
	cin >> n >> m;
	int**maze = new int*[n];
	for (int i = 0; i < n; i++)
	{
		maze[i] = new int[m];
	}
	cout << "�������Թ���2��ʾǽ�ڣ�0��ʾ����ͨ�е�ͨ����" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> maze[i][j];
		}
	}
	int startRow, startCol, endRow, endCol;
	cout << "�������Թ�������꣺" << endl;
	cin >> startRow >> startCol;
	cout << "�������Թ�����λ������" << endl;
	cin >> endRow >> endCol;
	mouseMaze(startRow, startCol, endRow, endCol, maze, n, m);
	return 0;
}

















