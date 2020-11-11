#include<iostream>
#include<vector>
using namespace std;

long long to_ten(string a,int n)
{
	long long res = 0;
	for(int i=0;i<a.size();i++)
	{
		res *= n;
		if (isdigit(a[i]))
			res += a[i] - '0';
		else
			res += 10 + a[i] - 'a';
	}
	return res;
}

int find_min(string v)
{
	int max = 0;
	for (auto i : v)
	{
		int n;
		if (isdigit(i))
			n = i - '0';
		else
			n = 10 + i - 'a';
		if (n > max)max = n;
	}
	return max ? max + 1 : 2;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string a, b;
	int tag, radix;
	long long res;
	cin >> a >> b >> tag >> radix;
	int flag = 0;
	long long index;
	if (tag == 1)
	{
		res = to_ten(a, radix);
		long long begin = find_min(b);
		long long end = res + 1;
		while (begin <= end)
		{
			index = (begin + end) / 2;
			long long n = to_ten(b, index);
			if (n > res || n < 0)
				end = index - 1;
			else if (n == res)
			{
				flag = 1;
				break;
			}
			else
				begin = index + 1;
		}
	}
	else
	{
		res = to_ten(b, radix);
		long long begin = find_min(a);
		long long end = res + 1;
		while (begin <= end)
		{
			index = (begin + end) / 2;
			long long n = to_ten(a, index);
			if (n > res || n < 0)
				end = index - 1;
			else if (n == res)
			{
				flag = 1;
				break;
			}
			else
				begin = index + 1;
		}
	}
	if (flag)cout << index;
	else cout << "Impossible";
}