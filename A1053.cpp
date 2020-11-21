#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 110;
int w[N],v[N], h[N], ne[N];
int n, m, s;
int path[N];
vector<vector<int>> res;

void dfs(int u)
{
	if (h[u] == -1)
	{
		if (w[u] == s)
		{
			vector<int> t;
			int p = u;
			while (p != -1)
			{
				t.push_back(v[p]);
				p = path[p];
			}
			reverse(t.begin(), t.end());
			res.push_back(t);
		}
		return;
	}
	for (int i = h[u]; ~i; i = ne[i])
	{
		path[i] = u;
		w[i] += w[u];
		dfs(i);
	}
}

void add(int a, int b)
{
	ne[b] = h[a], h[a] = b;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	memset(h, -1, sizeof(h));
	memset(path, -1, sizeof(path));
	cin >> n >> m >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> w[i]; v[i] = w[i];
	}
	int id, k, b;
	while(m--)
	{
		cin >> id >> k;
		while (k--)
		{
			cin >> b;
			add(id, b);
		}
	}
	dfs(0);
	sort(res.begin(), res.end());
	for (int i= res.size()-1;i>=0;i--)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			if (j != 0)cout << " ";
			cout << res[i][j];
		}
		cout << endl;
	}
}