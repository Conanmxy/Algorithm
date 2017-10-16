#include<iostream>
#include<stack>
#include<vector>
#define M 100
#define N 100
using namespace std;

class MGraph
{
public:
	int matrix[N][M];//�ڽӾ���
	int n;//������
	int e;//����
};
void DijkstraPath(MGraph g, vector<int>&dist, vector<int>&path, int v0)//v0��ʾԴ����
{
	int i, j, k;
	vector<bool>visited(g.n);
	for (int i = 0; i < g.n; i++)
	{
		if (g.matrix[v0][i]>0 && i != v0)
		{
			dist[i] = g.matrix[v0][i];
			path[i] = v0;//path��¼���·���ϴ�v0��i��ǰһ������
		}
		else
		{
			dist[i] = INT_MAX;//�������ڣ���ȨֵΪ�����
			path[i] = -1;
		}
		visited[i] = false;
		path[v0] = v0;
		dist[v0] = 0;
	}
	visited[v0] = true;
	for (int i = 1; i < g.n; i++)//ѭ����չn-1��
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
void showPath(vector<int>&path, int v, int v0)//��ӡ���·���ϵ�ÿ����
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
	int n, e;//��ʾ����ı���������
	cin >> n >> e;
	//while (cin >> n >> e&&e != 0)
	{
		int i, j;
		int s, t, w;//��ʾ��s->w��һ����
		MGraph g;
		int v0;//���
		vector<int>dist(n);
		//int *dist = (int*)malloc(sizeof(int)*n);
		//����dist��Ŵ�Դ�����㵽����ÿһ������Ķ�̬��С����
		vector<int>path(n);
		//int *path = (int*)malloc(sizeof(int)*n);
		//path������·����ÿ���ڵ��ǰ��
		for (int i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				g.matrix[i][j] = 0;//��ʼ������ȫ��Ϊ0��
		g.n = n;
		g.e = e;
		for (int i = 0; i < e; i++)
		{
			cin >> s >> t >> w;
			g.matrix[s][t] = w;//����ÿ���ߵ�ֵ
		}
		cin >> v0;//����ԭ��
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