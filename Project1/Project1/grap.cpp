#include<iostream>
#include<queue>
#define MAX 20;
enum { WHITE, GRAY, BLACK };
using namespace std;
class graphnode
{
public:
	graphnode()
	{
		next = NULL;
		color = WHITE;
		d = 0;
	}
	int id;
	int color;
	int d;
	graphnode*next;
	void setup();//�����������ڽ�����
	void show();
};
void graphnode::setup()
{
	int x;
	cin >> x;
	cin >> x;
	graphnode*point = this;
	while (x)//����0��ʾ����
	{
		graphnode*p = new graphnode();
		p->id = x;
		point->next = p;
		point = point->next;
		cin >> x;
	}
}
void graphnode::show()
{
	graphnode*p = this;
	while (p)
	{
		cout << p->id << " ";
		p = p->next;
	}
}
class graph
{
public:
	graph() { vexnum = 0; }
	void initial();
	void BFS(graphnode s);
	void DFS();
	void dfsvisited(graphnode u);
	int vexnum;//the nunber of the vextrix;
	graphnode adj[20];//�ڽ�����
};
void graph::initial()
{
	cout << "����ͼ���ٽ�����洢���������㣺" << endl;
	cin >> vexnum;
	cout << "����������" << endl;
	for (int i = 0; i < vexnum; i++)
	{
		adj[i].id = i + 1;
		adj[i].setup();
	}
	cout << "��һλΪ�ڽ������־��" << endl;
	for (int i = 0; i < vexnum; i++)
	{
		adj[i].show();
		cout << endl;
	}
}
void graph::BFS(graphnode s)
{
	queue<graphnode>que;
	for (int i = 0; i < vexnum; i++)
	{
		adj[i].color = WHITE;
	}

	adj[s.id - 1].color = GRAY;
	que.push(s);
	while (!que.empty())
	{
		graphnode *u = &que.front();
		que.pop();
		cout << (*u).id << " ";
		graphnode*p = (*u).next;
		while (p)
		{

			if (adj[(*p).id - 1].color == WHITE)
			{

				adj[(*p).id - 1].color = GRAY;
				que.push(adj[(*p).id - 1]);

			}
			p = p->next;

		}
		adj[(*u).id - 1].color = BLACK;
	}
}
void graph::DFS()
{
	for (int i = 0; i < vexnum; i++)
	{
		adj[i].color = WHITE;
	}
	for (int i = 0; i < vexnum; i++)
	{
		if (adj[i].color == WHITE)
		{
			dfsvisited(adj[i]);
		}
	}
}
void graph::dfsvisited(graphnode u)
{
	cout << adj[u.id - 1].id << " ";
	adj[u.id - 1].color = GRAY;
	graphnode*p = (adj[u.id - 1].next);
	while (p)
	{
		if (adj[(*p).id - 1].color == WHITE)
		{
			dfsvisited(*p);
		
		}
		p = p->next;
	}
	adj[u.id - 1].color = BLACK;
}
int main()
{
	graph g1;
	g1.initial();
	cout << "������ȱ���" << endl;
	g1.BFS(g1.adj[0]);
	cout << endl;
	cout << "������ȱ���" << endl;
	g1.DFS();
	return 0;
}
