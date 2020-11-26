//#include<iostream>
//#include<unordered_map>
//#include<string>
//#include<cstring>
//using namespace std;
//const int N = 210;
//unordered_map<string, unordered_map<string, int>> d;
//unordered_map<string, int> cnt, cost, happy,p_happy;
//unordered_map<string, string> path;
//unordered_map<string, bool> ct;
//int n, m ;
//string s;
//
//void dijkstra()
//{
//	cost[s] = 0; cnt[s] = 1;
//	for (int i = 0; i < n; i++)
//	{
//		string t;
//		cost[t] = 0x3f3f3f3f;
//		for (auto ver : cost)
//		{
//			if (!ct[ver.first] && cost[ver.first] < cost[t])
//				t = ver.first;
//		}
//		ct[t] = true;
//		for (auto& edge : d[t])
//		{
//			string ver = edge.first;
//			int c = edge.second;
//			if (cost[ver] > cost[t] + d[t][ver])
//			{
//				cnt[ver] = cnt[t];
//				p_happy[ver] = p_happy[t]+happy[ver];
//				cost[ver] = cost[t] + d[t][ver];
//				path[ver] = t;
//			}
//			else if (cost[ver] == cost[t] + d[t][ver])
//			{
//				cnt[ver] += cnt[t];
//				if (p_happy[ver] < p_happy[t] + happy[ver])
//				{
//					path[ver] = t;
//					p_happy[ver] = p_happy[t] + happy[ver];
//				}
//			}
//		}
//	}
//}
//
//int main()
//{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
//	cin >> n >> m >> s;
//	happy[s] = p_happy[s] = 0;
//	for (int i = 1; i < n; i++)
//	{
//		string name;
//		int  a;
//		cin >> name >> a;
//		happy[name] = a;
//		p_happy[name] = a;
//	}
//	while (m--)
//	{
//		string b, e;
//		int c;
//		cin >> b >> e >> c;
//		d[b][e] = d[e][b] = c;
//		cost[b] = cost[e] = 0x3f3f3f3f;
//		ct[b] = ct[e] = false;
//	}
//	dijkstra();
//	cout << cnt["ROM"] << " " << cost["ROM"] << " " << p_happy["ROM"] << " ";
//	vector<string> res;
//	string p = "ROM";
//	int sum = -1;
//	while (!p.empty())
//	{
//		res.push_back(p);
//		p = path[p];
//		sum++;
//	}
//	cout << p_happy["ROM"] / sum << endl;
//	for (int i = res.size() - 1; i >= 0; i--)
//	{
//		if (i != res.size() - 1)cout << "->";
//		cout << res[i];
//	}
//}
#include<iostream>
#include<cstring>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;
const int N = 210;
int d[N][N], dist[N], cost[N], cnt[N], c[N], path[N], num[N];
bool ct[N];
string city[N];
unordered_map<string, int> mp;
int n, m, s;

void dijkstra()
{
	memset(path, -1, sizeof(path));
	memset(dist, 0x3f, sizeof(dist));
	dist[s] = 0; cnt[s] = 1; cost[s] = 0;
	for (int i = 0; i < n; i++)
	{
		int t = -1;
		for (int j = 0; j < n; j++)
		{
			if (!ct[j]&&(t == -1 || dist[j] < dist[t]))
				t = j;
		}
		ct[t] = true;
		for (int j = 0; j < n; j++)
		{
			if (dist[j] > dist[t] + d[t][j])
			{
				dist[j] = dist[t] + d[t][j];
				cnt[j] = cnt[t];
				cost[j] = cost[t] + c[j];
				path[j] = t;
				num[j] = num[t] + 1;
			}
			else if (dist[j] == dist[t] + d[t][j])
			{
				cnt[j] += cnt[t];
				if (cost[j] < cost[t] + c[j])
				{
					path[j] = t;
					num[j] = num[t] + 1;
					cost[j] = cost[t] + c[j];
				}
				else if (cost[j] ==  cost[t] + c[j])
				{
					if (num[j] > num[t] + 1)
					{
						num[j] = num[t] + 1;
						path[j] = t;
					}
				}
			}
		}
	}
}

int main()
{
	memset(d, 0x3f, sizeof(d));
	string ts;
	cin >> n >> m >> ts;
	mp[ts] = 0;
	city[0] = ts;
	for (int i = 1; i < n; i++)
	{
		string id;
		int a;
		cin >> id >> a;
		city[i] = id;
		mp[city[i]] = i;
		c[i] = a;
	}
	while (m--)
	{
		string a, b;
		int c;
		cin >> a >> b >> c;
		int x, y;
		x = mp[a], y = mp[b];
		d[x][y] = d[y][x] = min(d[x][y], c);
	}
	dijkstra();
	int t = mp["ROM"];
	cout << cnt[t] << ' ' << dist[t] << ' ' << cost[t] << ' ' << cost[t] / num[t] << endl;
	int p = t;
	vector<int> res;
	while (~p)
	{
		res.push_back(p);
		p = path[p];
	}
	for (int i = res.size() - 1; i >= 0; i--)
	{
		if (i != res.size() - 1)cout << "->";
		cout << city[res[i]];
	}
}