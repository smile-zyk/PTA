#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
const int N = 10010;
vector<pair<int, int>> edges;
int color[N];
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		edges.push_back({ a,b });
	}
	int k;
	cin >> k;
	while (k--)
	{
		set<int> num;
		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			cin >> color[i];
			num.insert(color[i]);
		}
		for (auto &edge : edges)
		{
			int x = edge.first, y = edge.second;
			if (color[x] == color[y])
			{
				flag = false; break;
			}
		}
		if (flag)cout << num.size() << "-coloring" << endl;
		else cout << "No" << endl;
	}
}