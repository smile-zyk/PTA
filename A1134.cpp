#include<iostream>
using namespace std;
const int N = 10010;
struct edge
{
	int a, b;
}e[N];
int n, m;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> e[i].a >> e[i].b;
	}
	int k;
	cin >> k;
	while (k--)
	{
		bool st[N] = { false };
		int cnt;
		cin >> cnt;
		while (cnt--)
		{
			int a;
			cin >> a;
			st[a] = true;
		}
		int i;
		for (i = 0; i < m; i++)if (!st[e[i].a] && !st[e[i].b])break;
		if (i == m)puts("Yes");
		else puts("No");
	}
}