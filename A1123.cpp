#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N = 30;
int e[N], l[N], r[N], idx, h[N],max_k,max_depth;
vector<int> d[N];

void dfs(int u, int cnt, int depth)
{
	d[depth].push_back(e[u]);
	max_depth = max(depth, max_depth);
	max_k = max(cnt, max_k);
	if (l[u] != -1)dfs(l[u], cnt * 2, depth + 1);
	if (r[u] != -1)dfs(r[u], cnt * 2 + 1, depth + 1);
}

void update(int u)
{
	h[u] = max(h[l[u]], h[r[u]]) + 1;
}

int get_balance(int u)
{
	return h[l[u]] - h[r[u]];
}

void R(int& u)
{
	int p = l[u];
	l[u] = r[p], r[p] = u;
	update(u), update(p);
	u = p;
}

void L(int& u)
{
	int p = r[u];
	r[u] = l[p], l[p] = u;
	update(u), update(p);
	u = p;
}

void insert(int &u,int val)
{
	if (u == -1)e[idx] = val, u = idx++;
	else if (val < e[u])
	{
		insert(l[u], val);
		if (get_balance(u) == 2)
		{
			if (get_balance(l[u]) == 1)R(u);
			else L(l[u]), R(u);
		}
	}
	else
	{
		insert(r[u], val);
		if (get_balance(u) == -2)
		{
			if (get_balance(r[u]) == -1)L(u);
			else R(r[u]), L(u);
		}
	}
	update(u);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	memset(l, -1, sizeof(l));
	memset(r, -1, sizeof(r));
	int n;
	cin >> n;
	int root = -1;
	int a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		insert(root, a);
	}
	dfs(root, 1, 0);
	int flag = 0;
	for (int i = 0; i <= max_depth; i++)
	{
		for (int j=0;j<d[i].size();j++)
		{
			if (flag != 0)cout << " ";
			cout << d[i][j];
			flag = 1;
		}
	}
	cout << endl;
	if (max_k == n)cout << "YES";
	else cout << "NO";
}