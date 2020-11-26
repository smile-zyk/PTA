#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N = 1010;

bool ct[N];
vector<int> mp[N];
int n, m;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> n >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		mp[b].push_back(a);
	}
	int k;
	cin >> k;
	vector<int> res;
	for(int i=0;i<k;i++)
	{
		memset(ct, 0, sizeof ct);
		bool flag = true;
		for (int t = 1; t <= n; t++)
		{
			int i;
			cin >> i;
			for (auto& j : mp[i])
			{
				if (!ct[j])
				{
					flag = false;
					break;
				}
			}
			if (flag)
				ct[i] = true;
		}
		if (!flag)res.push_back(i);
	}
	for (int i = 0; i < res.size(); i++)
	{
		if (i != 0)cout << " ";
		cout << res[i];
	}
}