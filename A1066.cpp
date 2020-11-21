#include<iostream>
#include<cstring>
using namespace std;
const int N = 30;
int l[N], r[N], e[N], idx;//记录二叉树信息
int h[N];//记录节点高度
int n;
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
	l[u] = r[p];
	r[p] = u;
	update(u), update(p);
	u = p;
}

void L(int& u)
{
	int p = r[u];
	r[u] = l[p];
	l[p] = u;
	update(u), update(p);
	u = p;
}

void insert(int& u,int val)
{
	if (u == -1)e[idx] = val, u = idx++;
	else if (val < e[u])
	{
		insert(l[u], val);
		if (get_balance(u) == 2)
		{
			if (get_balance(l[u]) == 1)R(u);
			else L(l[u]),R(u);
		}
	}
	else
	{
		insert(r[u], val);
		if (get_balance(u) == -2)
		{
			if (get_balance(r[u]) == -1)L(u);
			else R(r[u]),L(u);
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
	int root = -1;
	cin >> n;
	int a;
	while (n--)
	{
		cin >> a;
		insert(root, a);
	}
	cout << e[root];
}