#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<functional>
#define maxn 10
using namespace std;
struct Edge
{
	int from, to, dist;
	Edge(int u, int v, int d) :from(u), to(v), dist(d) {}
};
struct HeapNode//以1开始标号
{
	int d, u;//d是到原点的最短距离，u是节点标号
	bool operator < (const HeapNode& rhs)const//重载小于号运算符
	{
		return d > rhs.d;
	}
};
struct Dijkstra
{
	int n, m,from,to,dist;
	vector<Edge>edges;
	vector<int>G[maxn];
	vector<int>E[maxn];
	bool done[maxn];
	int d[maxn];
	int p[maxn];
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
		m = edges.size();
		G[from].push_back(to);
		E[from].push_back(m - 1);//E[i]存放每个节点的出发的边的编号，Edges[E[u][i]]即为相应的一条边
	}
	void dijkstra(int s)
	{
		priority_queue<HeapNode>Q;
		for (int i = 1; i <= n; i++)
			d[i] = INT_MAX;//初始化为无穷大
		d[s] = 0;//出发节点设为0
		memset(done, 0, sizeof(done));
		Q.push(HeapNode{ 0,s });//第一个节点入栈
		while (!Q.empty())
		{
			HeapNode x = Q.top(); Q.pop();
			int u = x.u;
			if (done[u])continue;//访问过的略过
			done[u] = true;//没访问的设成true
			for (int i = 0; i < G[u].size(); i++)
			{
				Edge& e = edges[E[u][i]];
				if (d[e.to] > d[u] + e.dist)
				{
					d[e.to] = d[u] + e.dist;
					p[e.to] = u;
					Q.push(HeapNode{ d[e.to],e.to });
				}
			}
		}
	}
	void show(int  v, int v0)
	{
		stack<int>s;
		while (v != v0)
		{
			s.push(v);
			v = p[v];
		}
		s.push(v);
		while (!s.empty())
		{
			cout << s.top();
			s.pop();
		}
		cout << endl;
	}
};
int main()
{
	Dijkstra dij;
	dij.init();
	dij.dijkstra(1);
	for (int i = 1; i <= dij.n; i++)
		dij.show(i, 1);
	
	return 0;
}