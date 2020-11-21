#include<iostream>
#include<string>
using namespace std;

char get_char(int a)
{
	if (a <= 9)return a + '0';
	else return a - 10 + 'A';
}

string to_thirteen(int a)
{
	string res;
	while (a)
	{
		res = get_char(a % 13) + res;
		a /= 13;
	}
	while(res.size() < 2)res = '0' + res;
	return res;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int a, b, c;
	cin >> a >> b >> c;
	cout << "#" << to_thirteen(a) << to_thirteen(b) << to_thirteen(c);
}