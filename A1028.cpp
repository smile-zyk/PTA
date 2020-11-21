//数据量较大的时候，用scanf和printf可以有效缩短时间
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct stu
{
	string id;
	string name;
	int grade;
};

bool cmp1(stu s1, stu s2)
{
	return s1.id < s2.id;
}

bool cmp2(stu s1, stu s2)
{
	if (s1.name != s2.name)return s1.name < s2.name;
	else return s1.id < s2.id;
}

bool cmp3(stu s1, stu s2)
{
	if (s1.grade != s2.grade)return s1.grade < s2.grade;
	else return s1.id < s2.id;
}

bool(*p[3])(stu, stu) = { cmp1,cmp2,cmp3 };

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	stu stus[10010];
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		char id[10], name[10];
		int grade;
		scanf("%s %s %d", id, name, &grade);
		stus[i]={ id,name,grade };
	}
	sort(stus, stus+n, p[m - 1]);
	for(int j=0;j<n;j++)
	{
		auto& i = stus[j];
		printf("%s %s %d\n", i.id.c_str(), i.name.c_str(), i.grade);
	}
}