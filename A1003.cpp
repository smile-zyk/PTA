#include<iostream>
#include<cstring>
using namespace std;
const int N = 510;
int dist[N], ct[N], cnt[N], w[N], sum[N];
int map[N][N];
int n, m, s, t;

void dijkstra()
{
	memset(dist, 0x3f, sizeof(dist));
	dist[s] = 0, cnt[s] = 1; sum[s] = w[s];
	for (int i = 0; i < n; i++)
	{
		int t = -1;
		for (int j = 0; j < n; j++)
			if (!ct[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		ct[t] = true;
		for (int j = 0; j < n; j++)
		{
			if (dist[t] + map[t][j] < dist[j])
			{
				dist[j] = dist[t] + map[t][j];
				cnt[j] = cnt[t];
				sum[j] = sum[t] + w[j];
			}
			else if (dist[t] + map[t][j] == dist[j])
			{
				cnt[j] += cnt[t];
				sum[j] = max(sum[j], sum[t] + w[j]);
			}
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	memset(map, 0x3f, sizeof(map));
	cin >> n >> m >> s >> t;
	for (int i = 0; i < n; i++)cin >> w[i];
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = map[b][a] = min(map[a][b], c);
	}
	dijkstra();
	cout << cnt[t] << " " << sum[t] << endl;
}