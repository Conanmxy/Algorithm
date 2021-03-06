#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
const int maxnum = 100;
const int maxint = 99999;
typedef struct Edge {
	int u, v;//起点终点
	int weight;//边的权值
}Edge;
//以1为基准
Edge edge[maxnum];//保存边的值
int dist[maxnum];//保存节点到远点的最小值
int nodepre[maxnum];//前驱
int nodenum, edgenum, source;//节点数，边数，原点
							 //初始化图
void init()
{
	//输入节点数，边数，原点
	cin >> nodenum >> edgenum >> source;
	for (int i = 1; i <= nodenum; ++i)
	{
		dist[i] = maxint;
		nodepre[i] = 1;
	}
	nodepre[1] = 0;//第一个节点的前驱设置成0；
	dist[source] = 0;
	for (int i = 1; i <= edgenum; i++)
	{
		cin >> edge[i].u >> edge[i].v >> edge[i].weight;
	}
}
//松弛计算
void relax(int u, int v, int weight)
{
	if (dist[v] > dist[u] + weight)
	{
		dist[v] = dist[u] + weight;
		nodepre[v] = u;
	}
}
void show(int i)
{
	stack<int>s;
	while (i)
	{
		s.push(i);
		i = nodepre[i];
	}
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
}
bool Bellman_Ford()
{
	for (int i = 1; i <= nodenum - 1; ++i)//以1为基准
		for (int j = 1; j <= edgenum; j++)
			relax(edge[j].u, edge[j].v, edge[j].weight);
	bool flag = 1;
	for (int i = 1; i <= edgenum; i++)
		if (dist[edge[i].v] > dist[edge[i].u] + edge[i].weight)
		{
			flag = 0;
			break;
		}
	return flag;
}
int main()
{
	init();
	if (Bellman_Ford())
		for (int i = 1; i <= nodenum; i++)
		{
			show(i);
			cout << dist[i] << endl;
		}
	return 0;
}