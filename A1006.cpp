#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string first_id;
	string first_time;
	string last_id;
	string last_time;
	int n;
	cin >> n;
	int flag = 1;
	while (n--)
	{
		string id, in_time, out_time;
		cin >> id >> in_time >> out_time;
		if (first_time > in_time || flag)
		{
			first_time = in_time;
			first_id = id;
		}
		if (last_time < out_time || flag)
		{
			last_time = out_time;
			last_id = id;
		}
		flag = 0;
	}
	cout << first_id <<" "<< last_id;
}