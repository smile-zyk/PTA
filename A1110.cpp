#include<iostream>
#include<cstring>
#include <string>
using namespace std;
const int N = 30;
int l[N], r[N];
int tree[N];
bool has_father[N];
int n, root, cnt;

void dfs(int u, int cnt)
{
	if (u==-1)return;
	tree[cnt] = u;
	dfs(l[u], cnt * 2);
	dfs(r[u], cnt * 2 + 1);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	memset(l, -1, sizeof(l));
	memset(r, -1, sizeof(r));
	memset(tree, -1, sizeof(tree));
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string a, b;
		cin >> a >> b;
		if (a != "-")l[i] = stoi(a), has_father[l[i]] = true;
		if (b != "-")r[i] = stoi(b), has_father[r[i]] = true;
	}
	while (has_father[root])root++;
	dfs(root, 1);
	for (int i = 1; i <= n; i++)
	{
		if (tree[i]==-1)
		{
			printf("No %d", root);
			return 0;
		}
	}
	printf("Yes %d", tree[n]);
}