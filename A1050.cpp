#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	string res;
	unordered_set<char> hash;
	for (auto i : s2)
	{
		hash.insert(i);
	}
	for (auto i : s1)
	{
		if (!hash.count(i))
			res += i;
	}
	cout << res;
}

//int main()
//{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
//	string s1, s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	bool map[255] = { false };
//	string res;
//	for (auto i : s2)
//	{
//		map[i] = true;
//	}
//	for (auto i : s1)
//	{
//		if (!map[i])
//			res += i;
//	}
//	cout << res;
//}