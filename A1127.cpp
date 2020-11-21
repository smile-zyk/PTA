#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 40;
int in[N], post[N];
int  cnt, n, max_depth;
vector<int> d[N];

void dfs(int il, int ir, int pl, int pr, int depth)
{
	if (il > ir)return;
	int root = post[pr];
	d[depth].push_back(root), max_depth = max(depth, max_depth);
	int k = 0;
	while (in[k] != root)k++;
	dfs(il, k - 1, pl, pl + (k - 1 - il), depth + 1);
	dfs(k + 1, ir, pl + k - il, pr - 1, depth + 1);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)cin >> in[i];
	for (int i = 0; i < n; i++)cin >> post[i];
	dfs(0, n - 1, 0, n - 1, 0);
	int flag = 0;
	for (int i = 0; i <= max_depth; i++)
	{
		if (i % 2 == 0)for (int j = d[i].size() - 1; j >= 0; j--)
		{
			if (flag != 0)cout << " ";
			cout << d[i][j];
			flag = 1;
		}
		else for (int j = 0; j < d[i].size(); j++)
		{
			if (flag != 0)cout << " ";
			cout << d[i][j];
			flag = 1;
		}
	}
}