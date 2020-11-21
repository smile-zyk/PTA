#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<set>
using namespace std;
int main()
{
	unordered_map<string, set<int>> stu;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	while (m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		char name[6];
		while (b--)
		{
			scanf("%s", name);
			stu[name].insert(a);
		}
	}
	char name[6];
	while (n--)
	{
		scanf("%s", name);
		printf("%s %d", name, stu[name].size());
		for (auto& i : stu[name])
		{
			printf(" %d", i);
		}
		printf("\n");
	}
}