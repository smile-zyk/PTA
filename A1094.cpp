#include<iostream>
#include<vector>
using namespace std;
const int N = 110;
vector<int> h[N];
int d[N], max_depth, max_n;
void dfs(int u, int depth)
{
	d[depth]++;
	if (d[depth] > max_n)
	{
		max_n = d[depth];
		max_depth = depth;
	}
	if (!h[u].size())return;
	else
	{
		for (auto& i : h[u])
			dfs(i, depth + 1);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int id, a, k;
		cin >>id >> k;
		while (k--)
		{
			cin >> a;
			h[id].push_back(a);
		}
	}
	dfs(1, 1);
	cout<<max_n << " " << max_depth;
}