#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N = 510;
int d[N][N], t[N][N], dist[N], time[N], dp[N], tp[N];
bool dst[N], tst[N];
int n, m, s, e;

void dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	memset(time, 0x3f, sizeof time);
	memset(tp, -1, sizeof tp);
	memset(dp, -1, sizeof dp);
	int cost[N] = { 0 };
	int num[N] = { 0 };
	dist[s] = 0, time[s] = 0;
	for (int i = 0; i < n; i++)
	{
		int m = -1, l = -1;
		for (int j = 0; j < n; j++)
		{
			if (!dst[j] && (m == -1 || dist[j] < dist[m]))
				m = j;
			if (!tst[j] && (l == -1 || time[j] < time[l]))
				l = j;
		}
		dst[m] = true;
		tst[l] = true;
		for (int j = 0; j < n; j++)
		{
			if (dist[j] > dist[m] + d[m][j])
			{
				dist[j] = dist[m] + d[m][j];
				cost[j] = cost[m] + t[m][j];
				dp[j] = m;
			}
			else if (dist[j] == dist[m] + d[m][j])
			{
				if (cost[j] > cost[m] + t[m][j])
				{
					cost[j] = cost[m] + t[m][j];
					dp[j] = m;
				}
			}
			if (time[j] > time[l] + t[l][j])
			{
				time[j] = time[l] + t[l][j];
				num[j] = num[l] + 1;
				tp[j] = l;
			}
			else if (time[j] == time[l] + t[l][j])
			{
				if (num[j] > num[l] + 1)
				{
					num[j] = num[l] + 1;
					tp[j] = l;
				}
			}
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	memset(d, 0x3f, sizeof d);
	memset(t, 0x3f, sizeof t);
	cin >> n >> m;
	while (m--)
	{
		int a, b, flag, len, time;
		cin >> a >> b >> flag >> len >> time;
		d[a][b] = len, t[a][b] = time;
		if (!flag)d[b][a] = len, t[b][a] = time;
	}
	cin >> s >> e;
	dijkstra();
	vector<int> lres, tres;
	int p = e;
	while (~p)
	{
		lres.push_back(p);
		p = dp[p];
	}
	p = e;
	while (~p)
	{
		tres.push_back(p);
		p = tp[p];
	}
	if (lres == tres)
	{
		printf("Distance = %d; Time = %d: ", dist[e], time[e]);
		for (int i = lres.size() - 1; i >= 0; i--)
		{
			if (i != lres.size() - 1)cout << " -> ";
			cout << lres[i];
		}
	}
	else
	{
		printf("Distance = %d: ", dist[e]);
		for (int i = lres.size() - 1; i >= 0; i--)
		{
			if (i != lres.size() - 1)cout << " -> ";
			cout << lres[i];
		}
		cout << endl;
		printf("Time = %d: ", time[e]);
		for (int i = tres.size() - 1; i >= 0; i--)
		{
			if (i != tres.size() - 1)cout << " -> ";
			cout << tres[i];
		}
	}
}