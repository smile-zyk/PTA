#include<iostream>
#include<vector>
#include <unordered_map>
#include<algorithm>
using namespace std;
vector<vector<int> > v(4);
char table[] = { 'A','C','M','E' };

bool cmp(int a, int b)
{
	return a > b;
}

int get_rank(int n, vector<int> a)
{
	for (int i = 0; i < a.size(); i++)
		if (n == a[i])return i + 1;
}
int main()
{
	unordered_map<string, vector<int> > data;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	while (n--)
	{
		string name;
		int c, m, e;
		cin >> name >> c >> m >> e;
		int a = (c + m + e) / 3;
		data[name] = { a,c,m,e };
		v[0].push_back(a);
		v[1].push_back(c);
		v[2].push_back(m);
		v[3].push_back(e);
	}
	for (int i = 0; i < 4; i++)
		sort(v[i].begin(), v[i].end(), cmp);
	while (k--)
	{
		string name;
		cin >> name;
		if (data[name].size() == 0)
			printf("N/A\n");
		else
		{
			int min_rank = 10;
			int min_i = 0;
			for (int i = 0; i < data[name].size(); i++)
			{
				int rank = get_rank(data[name][i], v[i]);
				if (rank < min_rank)min_rank = rank, min_i = i;
			}
			cout << min_rank << " " << table[min_i]<<endl;
		}
	}
}