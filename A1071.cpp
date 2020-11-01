#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	char c;
	map<string,int> res;
	string s;
	while ((c = getchar()) != '\n')
	{
		if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		{
			if (c >= 'A' && c <= 'Z')
			{
				c = tolower(c);
			}
			s.push_back(c);
		}
		else
		{
			if (s.size() != 0)
			{
				res[s]++;//在map中下标访问，如果map中不存在该键值，则自动新建并插入！
				s.clear();
			}
		}
	}
	if (s.size() != 0)//注意这里最后一个如果不处理的话会被丢掉
		res[s]++;
	int cnt = -1;
	string res_s;
	for (auto i : res)
	{
		if (i.second > cnt)
		{
			cnt = i.second;
			res_s = i.first;
		}
	}
	cout << res_s << " " << cnt;
}