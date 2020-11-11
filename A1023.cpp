//y总的方法
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string A;
	vector<int> a;
	cin >> A;
	for (int i = A.size() - 1; i >= 0; i--)a.push_back(A[i] - '0');
	vector<int> b;
	int t = 0;
	for (int i = 0; i < a.size(); i++)
	{
		int s = a[i] * 2 + t;
		b.push_back(s % 10);
		t = s / 10;
	}
	if (t)b.push_back(1);
	vector<int> c = b;
	sort(c.begin(), c.end());
	sort(a.begin(), a.end());
	if (a == c)
		printf("Yes\n");
	else
		printf("No\n");
	for (int i = b.size() - 1; i >= 0; i--)
		cout << b[i];
}
// 自己的方法
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//vector<int> flag(10);
//vector<int> res_flag(10);
//int main()
//{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
//	string input, res;
//	cin >> input;
//	int t = 0;
//	for (int i = input.size() - 1; i >= 0; i--)
//	{
//		flag[input[i] - '0']++;
//		res += ((input[i] - '0') * 2 + t) % 10 + '0';
//		res_flag[((input[i] - '0') * 2 + t) % 10]++;
//		if ((input[i] - '0') * 2 + t >= 10)t = 1;
//		else t = 0;
//	}
//	if (t == 1)
//	{
//		res += '1';
//		res_flag[1]++;
//	}
//		reverse(res.begin(),res.end());
//	if (res_flag == flag)
//		printf("Yes\n");
//	else
//		printf("No\n");
//	printf("%s", res.c_str());
//}