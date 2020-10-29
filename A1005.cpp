#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string num;
	cin >> num;
	int sum = 0;
	for (auto i : num)
	{
		sum += i - '0';
	}
	string res = to_string(sum);
	const char* table[] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	int flag = 0;
	for (auto i : res)
	{
		if (flag) cout << " ";
		cout << table[i - '0'];
		flag = 1;
	}
}