#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 110;
int e[N], l[N], r[N],in[N];
int n, cnt;

void dfs(int u)
{
	if (u == -1)return;
	dfs(l[u]);
	e[u] = in[cnt++];
	dfs(r[u]);
}

void levelorder()
{
	queue<int> qu;
	qu.push(0);
	int i = 0;
	while (!qu.empty())
	{
		int tmp = qu.front();
		qu.pop();
		if (i != 0)cout << " ";
		cout << e[tmp];
		i = 1;
		if (l[tmp] != -1)qu.push(l[tmp]);
		if (r[tmp] != -1)qu.push(r[tmp]);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		l[i] = a;
		r[i] = b;
	}
	for (int i = 0; i < n; i++)
		cin >> in[i];
	sort(in, in + n);
	dfs(0);
	levelorder();
}