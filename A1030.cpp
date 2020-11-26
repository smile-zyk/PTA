#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int N = 510, M = N * 2;
int ct[N],dist[N],cost[N];
int h[N], ne[M], e[M], l[M],c[M],path[N], idx;
int n, m, s, t;

void add(int a, int b, int len, int cost)
{
	e[idx] = b, l[idx] = len, c[idx] = cost, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	memset(path, -1, sizeof path);
	dist[s] = 0, cost[s] = 0, path[s] = -1;
	for (int i = 0; i < n; i++)
	{
		int t = -1;
		for (int j = 0; j < n; j++)
		{
			if (!ct[j] && (t == -1 || dist[j] < dist[t]))
				t = j;
		}
		ct[t] = 1;
		for (int i = h[t]; ~i; i = ne[i])
		{
			if (dist[e[i]] > dist[t] + l[i])
			{
				dist[e[i]] = dist[t] + l[i];
				cost[e[i]] = cost[t] + c[i];
				path[e[i]] = t;
			}
			else if (dist[e[i]] == dist[t] + l[i])
			{
				if (cost[e[i]] > cost[t] + c[i])
				{
					cost[e[i]] = cost[t] + c[i];
					path[e[i]] = t;
				}
			}
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	memset(h, -1, sizeof h);
	cin >> n>>m>> s>> t;
	int a, b, c, d;
	while (m--)
	{
		cin >> a >> b >> c >> d;
		add(a, b, c, d);
		add(b, a, c, d);
	}
	dijkstra();
	vector<int> res;
	int p = t;
	while (p != -1)
	{
		res.push_back(p);
		p = path[p];
	}
	for (int i = res.size() - 1; i >= 0; i--)cout << res[i] << " ";
	cout << dist[t] << " " << cost[t];
}