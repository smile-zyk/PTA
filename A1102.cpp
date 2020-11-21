#include<iostream>
#include<string>
#include<queue>
using namespace std;
const int N = 20;
int n;
int l[N], r[N];
int i, j, g;
int root[N] = { 0 };
void reverse(int u)
{
	if (u == -1)return;
	reverse(l[u]);
	reverse(r[u]);
	swap(l[u], r[u]);
}

void dfs(int u)
{
	if (u == -1)return;
	dfs(l[u]);
	if (i != 0)cout << " ";
	cout << u;
	i = 1;
	dfs(r[u]);
}

void bfs()
{
	queue<int> qu;
	qu.push(g);
	while (!qu.empty())
	{
		int tmp = qu.front();
		qu.pop();
		if (j != 0)cout << " ";
		cout << tmp;
		j = 1;
		if (~l[tmp])qu.push(l[tmp]);
		if (~r[tmp])qu.push(r[tmp]);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string a, b;
		cin >> a >> b;
		if (a != "-")l[i] = stoi(a), root[l[i]] = 1;
		else l[i] = -1;
		if (b != "-") r[i] = stoi(b), root[r[i]] = 1;
		else r[i] = -1;
	}
	for (int i = 0; i < n; i++)
	{
		if (!root[i])
		{
			g = i;
			break;
		}
	}
	reverse(g);
	bfs();
	cout << endl;
	dfs(g);
}