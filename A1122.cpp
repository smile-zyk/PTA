#include<iostream>
#include<vector>
using namespace std;
const int N = 210;
bool d[N][N];
vector<int> v;
bool ct[N];
int n, m, k;

bool check()
{
	if (v[0] != v[v.size() - 1])return false;
	if (v.size() != n + 1)return false;
	for (int j = 0; j < v.size() - 1; j++)
	{
		if (!d[v[j]][v[j + 1]])return false;
		ct[v[j]] = true;
	}
	for (int j = 1; j <= n; j++)if (!ct[j])return false;
	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> n >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		d[a][b] = true;
		d[b][a] = true;
	}
	cin >> k;
	while (k--)
	{
		memset(ct, 0, sizeof(ct));
		v.clear();
		int c;
		cin >> c;
		while (c--)
		{
			int a;
			cin >> a;
			v.push_back(a);
		}
		if (check())puts("YES") ;
		else puts("NO");
	}
}