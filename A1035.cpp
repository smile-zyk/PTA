#include<iostream>
#include<string>
using namespace std;

string change(string s) 
{
	string res;
	for (auto i : s)
	{
		if (i == '1')res += '@';
		else if (i == '0') res += '%';
		else if (i == 'l') res += 'L';
		else if (i == 'O') res += 'o';
		else res += i;
	}
	return res;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	const int N = 1010;
	int n, m = 0;
	string id[N], pwd[N];
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		string cur_id, cur_pwd;
		cin >> cur_id >> cur_pwd;
		string changed_pwd=change(cur_pwd);
		if (changed_pwd != cur_pwd)
		{
			id[m] = cur_id;
			pwd[m] = changed_pwd;
			m++;
		}
	}
	if (!m)
	{
		if (n == 1)
			printf("There is 1 account and no account is modified");
		else
			printf("There are %d accounts and no account is modified", n);
	}
	else
	{
		printf("%d\n", m);
		for (size_t i = 0; i < m; i++)
		{
			cout << id[i] <<" "<< pwd[i] << endl;
		}
	}
}