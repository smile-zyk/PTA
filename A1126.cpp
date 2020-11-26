#include<iostream>
#include<vector>
using namespace std;
const int N = 510;
int n, m, k;
vector<int> v[N];
int mp[N];
bool st[N];
void dfs(int u)
{
	k++;
	st[u] = true;
	for (auto i : v[u])
	{
		if (!st[i])
			dfs(i);
	}
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
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		mp[i] = v[i].size();
	vector<int> ji;
	int flag = 1;
	for (int i = 1; i <= n; i++)
	{
		if (i != 1)cout << " ";
		cout << mp[i];
		if (mp[i] % 2 != 0)flag = 0, ji.push_back(i);
	}
	cout << endl;
	dfs(1);
	if (k == n)
	{
		if (flag)cout << "Eulerian" << endl;
		else
		{
			if (ji.size() == 2)cout << "Semi-Eulerian" << endl;
			else cout << "Non-Eulerian" << endl;
		}
	}
	else
		cout << "Non-Eulerian" << endl;
}