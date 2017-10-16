#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<functional>
const int maxn=10;
using namespace std;
struct Edge
{
	int from, to, dist;//from �����㣬to:����㣬 dist :���룬��Ȩֵ
	Edge(int u, int v, int d) :from(u), to(v), dist(d) {}
};
struct grap //������ͨͼ����1��ʼ��Žڵ�,
{
	int n, m,from,to,dist;//n���㣬m����
	vector<Edge>edges;//�߼���
	vector<int>G[maxn];//ÿ��������һ���������䵱�ٽ�����Ĺ���
	bool done[maxn];//���ʱ�־,0��ʾû�з���
	int p[maxn];//��¼ÿ���ڵ����һ���ڵ�
	void init()
	{
		cin >> n >> m;
		this->n = n;
		this->m = m;
		for (int i = 0; i <= n; i++)
		{
			G[i].clear();
			done[i] = 0;
		}
		edges.clear();
		for (int i = 1; i <= m; i++)
		{
			cin >> from >> to >> dist;
			AddEdge(from, to, dist);
		}
	}
	void AddEdge(int from, int to, int dist)
	{
		edges.push_back(Edge(from, to, dist));
		G[from].push_back(to);
	}
	void DFS(int s)//s �ǳ�����
	{
		if(done[s]==0)
		cout << s << " ";
		else return;
		while (!G[s].empty())
		{
			DFS(G[s][0]);
			G[s].erase(G[s].begin());
		}
		done[s] = 1;
	}
	void BFS(int s)
	{
		queue<int>q;//ջ
		memset(done, 0, sizeof(done));
		if (done[s] == 0)
			q.push(s);
		while(!q.empty())
		{
			int temp_node = q.front();
			cout << temp_node;
			done[temp_node] = 1;
			q.pop();
			for (int i = 0; i < G[temp_node].size(); i++)
			{
				if (done[G[temp_node][i]] == 0)
				{
					q.push(G[temp_node][i]);
				}
			}
		}
	}
};
int main()
{
	grap g1;
	g1.init();
	//g1.DFS(1);
	g1.BFS(1);
	return 0;
}