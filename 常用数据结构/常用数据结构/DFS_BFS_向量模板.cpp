#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<functional>
const int maxn=10;
using namespace std;
struct Edge
{
	int from, to, dist;//from 出发点，to:进入点， dist :距离，即权值
	Edge(int u, int v, int d) :from(u), to(v), dist(d) {}
};
struct grap //有向连通图，以1开始标号节点,
{
	int n, m,from,to,dist;//n个点，m条边
	vector<Edge>edges;//边集合
	vector<int>G[maxn];//每个点设置一个向量，充当临结链表的功能
	bool done[maxn];//访问标志,0表示没有访问
	int p[maxn];//记录每个节点的上一个节点
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
	void DFS(int s)//s 是出发点
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
		queue<int>q;//栈
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