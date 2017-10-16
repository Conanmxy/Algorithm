#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<functional>
const int maxn = 10;
using namespace std;
struct Edge
{
	int from, to, dist;//from �����㣬to:����㣬 dist :���룬��Ȩֵ
	Edge(int u, int v, int d) :from(u), to(v), dist(d) {}
};
struct HeapNode//��1��ʼ���
{
	int d, u;//d�ǵ�ԭ�����̾��룬u�ǽڵ���
	bool operator < (const HeapNode& rhs)const//����С�ں������
	{
		return d > rhs.d;
	}
};
struct grap //������ͨͼ����1��ʼ��Žڵ�,
{
	int n, m, from, to, dist;//n���㣬m����
	vector<Edge>edges;//�߼���
	vector<int>G[maxn];//ÿ��������һ���������䵱�ٽ�����Ĺ���
	vector<int>E[maxn];//��¼��
	bool done[maxn];//���ʱ�־,0��ʾû�з���
	int p[maxn];//��¼ÿ���ڵ����һ���ڵ�
	int d[maxn];//dijkstra ��¼ÿ���㵽ԭ����С����
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
	void DFS(int s)//s �ǳ�����
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
		queue<int>q;//ջ
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
	//������dijkstra�㷨
	void dijkstra(int s)
	{
		priority_queue<HeapNode>Q;
		for (int i = 1; i <= n; i++)
			d[i] = INT_MAX;//��ʼ��Ϊ�����
		d[s] = 0;//�����ڵ���Ϊ0
		memset(done, 0, sizeof(done));
		Q.push(HeapNode{ 0,s });//��һ���ڵ���ջ
		while (!Q.empty())
		{
			HeapNode x = Q.top(); Q.pop();
			int u = x.u;
			if (done[u])continue;//���ʹ����Թ�
			done[u] = true;//û���ʵ����true
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