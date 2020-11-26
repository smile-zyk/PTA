#include<iostream>
#include<cstring>
using namespace std;
const int N = 210;

int g[N][N];
int sum[N];
int n, m, k;
int flag, min_dist=0x3fffffff, min_id;

int get_dist(int * in,int size)
{
	int dist = 0;
	for (int i = 0; i < size - 1; i++)
	{
		if (g[in[i]][in[i + 1]] != -1)
			dist += g[in[i]][in[i + 1]];
		else
		{
			flag = 0;
			return -1;
		}
	}
	if (in[0] != in[size - 1])flag = 0;
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (!sum[i])
			{
				flag = 0;
				return dist;
			}
		}
		if (size == n + 1)flag = 1;
		else flag = 2;
	}
	return dist;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	memset(g, -1, sizeof g);
	cin >> n >> m;
	while (m--)
	{
		int a, b, d;
		cin >> a >> b >> d;
		g[a][b] = g[b][a] = d;
	}
	cin >> k;
	int in[N];
	for (int i = 1; i <= k; i++)
	{
		memset(sum, 0, sizeof sum);
		flag = 0;
		int cnt;
		cin >> cnt;
		for (int i = 0; i < cnt; i++)cin >> in[i], sum[in[i]]++;
		int dist = get_dist(in, cnt);
		if (dist != -1)
			cout << "Path " << i << ": " << dist << " ";
		else
			cout << "Path " << i << ": N/A ";
		if (!flag)cout << "(Not a TS cycle)\n";
		else if (flag == 1)cout << "(TS simple cycle)\n";
		else cout << "(TS cycle)\n";
		if (flag&&dist < min_dist)
		{
			min_dist = dist;
			min_id = i;
		}
	}
	printf("Shortest Dist(%d) = %d", min_id, min_dist);
}