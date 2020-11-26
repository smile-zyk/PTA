#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
int n, k;
unordered_map < string, vector<pair<string, int>>> g;
unordered_map<string, int> total;
unordered_map<string, bool> ct;

int dfs(string u, vector<string>& nodes)
{
	ct[u] = true;
	nodes.push_back(u);
	int sum = 0;
	for (auto& edge : g[u])
	{
		sum += edge.second;
		if (!ct[edge.first])
			sum += dfs(edge.first, nodes);
	}
	return sum;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> n >> k;
	while (n--)
	{
		string a, b;
		int t;
		g[a].push_back({ b,t });
		g[b].push_back({ a,t });
		total[a] += t;
		total[b] += t;
	}
	vector<pair<string, int>> res;
	for (auto ver : g)
	{
		string id = ver.first;
		vector<string> nodes;
		int sum = 0;
		sum = dfs(id, nodes) / 2;
		if (nodes.size() > 2 && sum > k)
		{
			string boss=nodes[0];
			for (auto node : nodes)
			{
				if (total[node] > total[boss])
					boss = node;
			}
			res.push_back({ boss,nodes.size() });
		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << endl;
	for (auto i : res)
	{
		cout << i.first << " " << i.second << endl;
	}
}