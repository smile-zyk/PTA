#include<iostream>
#include<cmath>
#include<string>
using namespace std;

bool is_primer(int a)
{
	if (a == 1)
		return false;
	for (int i = 2; i <= sqrt(a); i++)
	{
		if (a % i == 0)
			return false;
	}
	return true;
}

int get_reverse(string a,int r)
{
	int res = 0;
	int n = atoi(a.c_str());
	while (n)
	{
		int t = n % r;
		res = res * r + t;
		n /= r;
	}
	return res;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string a;
	int b;
	while (cin >> a, a[0]!='-')
	{
		cin >> b;
		if (is_primer(get_reverse(a,b)) && is_primer(atoi(a.c_str())))
			printf("Yes\n");
		else
			printf("No\n");
	}
}