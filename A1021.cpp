#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

const int N = 10010, M = N * 2;
int h[N], e[M], ne[M], p[N], idx;

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}

int dfs(int u, int father)
{
	int depth = 0;
	for (int i = h[u]; ~i; i = ne[i])
	{
		if (e[i] != father)
		{
			depth = max(depth, dfs(e[i], u) + 1);
		}
	}
	return depth;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	memset(h, -1, sizeof(h));
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		p[i] = i;
	int k = n;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (find(a) != find(b))
		{
			p[find(a)] = find(b);
			k--;
		}
		add(a, b), add(b, a);
	}
	vector<int> res;
	if (k == 1)
	{
		int max_depth = 0;
		for (int i = 1; i <= n; i++)
		{
			int depth = dfs(i, -1);
			if (depth > max_depth)
			{
				max_depth = depth;
				res.clear();
				res.push_back(i);
			}
			else if (depth == max_depth)
				res.push_back(i);
		}
		for (int i = 0; i < res.size(); i++)
		{
			if (i != 0)cout << endl;
			cout << res[i];
		}
	}
	else
	{
		printf("Error: %d components", k);
	}
}