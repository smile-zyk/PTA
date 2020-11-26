#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#define PII pair<int,int>
#define x first
#define y second
using namespace std;
const int N = 10010, M = 1000010;
int h[N], e[M], ne[M], line[M], w[M],idx;
int dist[N], sum[N], pre[N];
bool ct[N];
int stops[N];
string info[N];

string get_number(int n)
{
	char res[6];
	sprintf(res, "%04d", n);
	return res;
}

void add(int a, int b, int l, int c)
{
	e[idx] = b, line[idx] = l, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(int start, int end)
{
	memset(ct, 0, sizeof ct);
	memset(dist, 0x3f, sizeof dist);
	memset(pre, -1, sizeof pre);
	memset(sum, 0, sizeof sum);
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	dist[start] = sum[start] = 0;
	heap.push({ 0,start });
	while (heap.size())
	{
		PII t=heap.top();
		heap.pop();
		int ver = t.y;
		if (ct[ver])continue;
		ct[ver] = true;
		for (int i = h[ver]; ~i; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[ver] + w[i])
			{
				dist[j] = dist[ver] + w[i];
				sum[j] = sum[ver] + 1;
				info[j]= "Take Line#"+to_string(line[i])+ " from "+get_number(ver)+" to "+get_number(j) +".";
				pre[j] = ver;
				heap.push({ dist[j],j });
			}
			else if (dist[j] == dist[ver] + w[i])
			{
				if (sum[j] > sum[ver] + 1)
				{
					sum[j] = sum[ver] + 1;
					info[j] = "Take Line#" + to_string(line[i]) + " from " + get_number(ver) + " to " + get_number(j) + ".";
					pre[j] = ver;
				}
			}
		}
	}
	cout << dist[end] << endl;
	vector<string> res;
	int p = end;
	while (p != start)
	{
		res.push_back(info[p]);
		p = pre[p];
	}
	for (int i = res.size() - 1; i >= 0; i--)
	{
		cout << res[i] << endl;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	memset(h, -1, sizeof(h));
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int m;
		cin >> m;
		for (int i = 0; i < m; i++)cin >> stops[i];
		for (int j = 0; j < m; j++)
			for (int k = 0; k < j; k++)
			{
				int len;
				if (stops[0] != stops[m - 1])len = j - k;
				else len = min(m - 1 - j + k, j - k);
				add(stops[j], stops[k], i, len);
				add(stops[k], stops[j], i, len);
			}
	}
	int m;
	cin >> m;
	while (m--)
	{
		int start, end;
		cin >> start >> end;
		dijkstra(start, end);
	}
}