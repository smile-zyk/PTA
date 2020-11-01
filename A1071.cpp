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
				res[s]++;//��map���±���ʣ����map�в����ڸü�ֵ�����Զ��½������룡
				s.clear();
			}
		}
	}
	if (s.size() != 0)//ע���������һ�����������Ļ��ᱻ����
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