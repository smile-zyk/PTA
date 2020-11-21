//#include<iostream>
//#include<vector>
//using namespace std;
//const int N = 110;
//vector<int> h[110];
//int max_depth;
//int cnt[N];
//void dfs(int depth, int n)
//{
//	if (h[n].empty())
//	{
//		cnt[depth]++;
//		max_depth = max(depth, max_depth);
//	}
//	else
//	{
//		for (auto& i : h[n])
//			dfs(depth + 1, i);
//	}
//}
//
//int main()
//{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
//	int n, m;
//	cin >> n >> m;
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> b;
//		while (b--)
//		{
//			int c;
//			cin >> c;
//			h[a].push_back(c);
//		}
//	}
//	dfs(0, 1);
//	for (int i = 0; i <= max_depth; i++)
//	{
//		if (i != 0)cout << " ";
//		cout << cnt[i];
//	}
//}
#include<iostream>
#include<cstring>
using namespace std;
const int N = 110;
int h[N],e[N], ne[N], idx;
int cnt[N], max_depth;
void insert_head(int a,int c)
{
	e[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int i, int depth)
{
	if (h[i] == -1)
	{
		cnt[depth]++;
		max_depth = max(depth, max_depth);
	}
	else
	{
		for (int n = h[i]; ~n; n = ne[n])
			dfs(e[n], depth + 1);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	memset(h, -1, sizeof(h));
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		while (b--)
		{
			int c;
			cin >> c;
			insert_head(a, c);
		}
	}
	dfs(1, 0);
	for (int i = 0; i <= max_depth; i++)
	{
		if (i != 0)cout << " ";
		cout << cnt[i];
	}
}