#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
using namespace std;

string check(string a, string b)
{
	string res;
	char first = 0;
	int flag = 1;
	for (int i = 0; i < min(a.size(), b.size()); i++)
	{
		if (a[i] == b[i])
		{
			res += a[i];
			if (flag&&isalpha(a[i])) { first = i+'0'; flag = 0; }
		}
	}
	res = first + res;
	return res;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	const char* table[8] = { " ","MON","TUE","WED","THU","FRI","SAT","SUN" };
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	string res1, res2;
	res1 = check(a, b);
	res2 = check(c, d);
	int flag = 0;
	int day, hour, minute;
	for (auto i : res1)
	{
		if (!flag)
		{
			if (i >= 'A' && i <= 'G')
			{
				day = i - 'A' + 1;
				flag = 1;
			}
		}
		else
		{
			if (i >= 'A' && i <= 'N')
			{
				hour = i - 'A' + 10;
				break;
			}
			else if (isdigit(i))
			{
				hour = i - '0';
				break;
			}
		}
	}
	minute = res2[0] - '0';
	printf("%s %02d:%02d", table[day], hour, minute);
}