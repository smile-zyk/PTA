#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_map>
#include<string>
using namespace std;
const int N = 310;
int g[N][N], e[N], idx;
unordered_map<int, int> mp;
set<int> boys;
set<int> girls;
int n, m;

string get_number(int a)
{
	char res[5];
	sprintf(res, "%04d", a);
	return res;
}

void add(int a)
{
	if (mp[a] == 0)
	{
		mp[a] = ++idx;
		e[idx] = a;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> n >> m;
	while (m--)
	{
		string i, j;
		cin >> i >> j;
		int a = abs(stoi(i));
		int b = abs(stoi(j));
		add(a), add(b);
		int x = mp[a], y = mp[b];
		g[x][y]=g[y][x] = true;
		if (i[0] !='-')boys.insert(x);
		else girls.insert(x);
		if (j[0]!='-') boys.insert(y);
		else girls.insert(y);
	}
	int k;
	cin >> k;
	vector<string> res;
	while (k--)
	{
		res.clear();
		string i, j;
		cin >> i >> j;
		int a = abs(stoi(i)), b = abs(stoi(j));
		int x = mp[a], y = mp[b];
		vector<int> ga, gb;
		if (i[0]!='-')
		{
			for (auto& i : boys)
				if (g[x][i]&&i!=y)ga.push_back(i);
		}
		else 
			for (auto& i : girls) 
				if (g[x][i]&&i!=y)ga.push_back(i);
		if (j[0]!='-')
		{
			for (auto& i : boys)
				if (g[y][i]&&i!=x)gb.push_back(i);
		}
		else 
			for (auto& i : girls) 
				if (g[y][i]&&i!=x)gb.push_back(i);
		for(auto &c:ga)
			for (auto& d : gb)
			{
				if (g[c][d])
				{
					string s = get_number(e[c]) + " " + get_number(e[d]);
					res.push_back(s);
				}
			}
		sort(res.begin(), res.end());
		cout << res.size()<<endl;
		for (auto& i : res)
		{
			cout << i << endl;
		}
	}
}