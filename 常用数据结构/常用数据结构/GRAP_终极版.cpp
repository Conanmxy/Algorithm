#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<functional>
const int maxn = 10;
using namespace std;
struct Edge
{
	int from, to, dist;//from 出发点，to:进入点， dist :距离，即权值
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
struct grap //有向连通图，以1开始标号节点,
{
	int n, m, from, to, dist;//n个点，m条边
	vector<Edge>edges;//边集合
	vector<int>G[maxn];//每个点设置一个向量，充当临结链表的功能
	vector<int>E[maxn];//记录边
	bool done[maxn];//访问标志,0表示没有访问
	int p[maxn];//记录每个节点的上一个节点
	int d[maxn];//dijkstra 记录每个点到原点最小距离
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
		int m = edges.size();
		G[from].push_back(to);
		E[from].push_back(m - 1);
	}
	void DFS(int s)//s 是出发点
	{
		if (done[s] == 0)
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
		while (!q.empty())
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
	//以下是dijkstra算法
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
	grap g1;
	g1.init();
	//g1.DFS(1);
	//g1.BFS(1);
	g1.dijkstra(1);
	for (int i = 1; i <= g1.n; i++)
		g1.show(i, 1);
	return 0;
}