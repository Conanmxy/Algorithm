#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
const int maxnum = 100;
const int maxint = 99999;
typedef struct Edge {
	int u, v;//����յ�
	int weight;//�ߵ�Ȩֵ
}Edge;
//��1Ϊ��׼
Edge edge[maxnum];//����ߵ�ֵ
int dist[maxnum];//����ڵ㵽Զ�����Сֵ
int nodepre[maxnum];//ǰ��
int nodenum, edgenum, source;//�ڵ�����������ԭ��
							 //��ʼ��ͼ
void init()
{
	//����ڵ�����������ԭ��
	cin >> nodenum >> edgenum >> source;
	for (int i = 1; i <= nodenum; ++i)
	{
		dist[i] = maxint;
		nodepre[i] = 1;
	}
	nodepre[1] = 0;//��һ���ڵ��ǰ�����ó�0��
	dist[source] = 0;
	for (int i = 1; i <= edgenum; i++)
	{
		cin >> edge[i].u >> edge[i].v >> edge[i].weight;
	}
}
//�ɳڼ���
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
	for (int i = 1; i <= nodenum - 1; ++i)//��1Ϊ��׼
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