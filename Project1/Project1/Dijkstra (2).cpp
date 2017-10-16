#include<iostream>
#include<stack>
#include<vector>
#define M 100
#define N 100
using namespace std;

class MGraph
{
public:
	int matrix[N][M];//邻接矩阵
	int n;//顶点数
	int e;//边数
};
void DijkstraPath(MGraph g, vector<int>&dist, vector<int>&path, int v0)//v0表示源顶点
{
	int i, j, k;
	vector<bool>visited(g.n);
	for (int i = 0; i < g.n; i++)
	{
		if (g.matrix[v0][i]>0 && i != v0)
		{
			dist[i] = g.matrix[v0][i];
			path[i] = v0;//path记录最短路径上从v0到i的前一个顶点
		}
		else
		{
			dist[i] = INT_MAX;//若不相邻，则权值为无穷大
			path[i] = -1;
		}
		visited[i] = false;
		path[v0] = v0;
		dist[v0] = 0;
	}
	visited[v0] = true;
	for (int i = 1; i < g.n; i++)//循环扩展n-1次
	{
		int min = INT_MAX;
		int u;
		for (j = 0; j < g.n; j++)
		{
			if (visited[j] == false && dist[j] < min)
			{
				min = dist[j];
				u = j;
			}
		}
		visited[u] = true;
		for (k = 0; k < g.n; k++)
		{
			if (visited[k] == false && g.matrix[u][k]>0 && min + g.matrix[u][k] < dist[k])
			{
				dist[k] = min + g.matrix[u][k];
				path[k] = u;
			}
		}
	}
}
void showPath(vector<int>&path, int v, int v0)//打印最短路径上的每个点
{
	stack<int>s;
	while (v != v0)
	{
		s.push(v);
		v = path[v];
	}
	s.push(v);
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
}
int main()
{
	int n, e;//表示输入的边数和条数
	cin >> n >> e;
	//while (cin >> n >> e&&e != 0)
	{
		int i, j;
		int s, t, w;//表示从s->w的一条边
		MGraph g;
		int v0;//起点
		vector<int>dist(n);
		//int *dist = (int*)malloc(sizeof(int)*n);
		//数组dist存放从源出发点到其他每一个顶点的动态最小距离
		vector<int>path(n);
		//int *path = (int*)malloc(sizeof(int)*n);
		//path存放最短路径上每个节点的前驱
		for (int i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				g.matrix[i][j] = 0;//初始化距离全部为0；
		g.n = n;
		g.e = e;
		for (int i = 0; i < e; i++)
		{
			cin >> s >> t >> w;
			g.matrix[s][t] = w;//输入每条边的值
		}
		cin >> v0;//输入原点
		DijkstraPath(g, dist, path, v0);
		for (int i = 0; i < n; i++)
		{
			if (i != v0)
			{
				showPath(path, i, v0);
				cout <<" "<< dist[i] << endl;
			}
		}
	}
	return 0;
}