#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> add(vector<int>& a, vector<int>& b)
{
	vector<int> res;
	int t = 0;
	for (int i = 0; i < a.size() || i < b.size() || t; i++)
	{
		int s = 0;
		if (i < a.size())s += a[i];
		if (i < b.size())s += b[i];
		s += t;
		res.push_back(s % 10);
		t = s / 10;
	}
	return res;
}

void print_vector(vector<int> a)
{
	reverse(a.begin(), a.end());
	for (auto i : a)
		cout << i;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string A;
	vector<int> a;
	cin >> A;
	for (int i = A.size() - 1; i >= 0; i--)a.push_back(A[i] - '0');
	int n = 10;
	while (n--)
	{
		vector<int> b = a;
		reverse(b.begin(), b.end());
		if (a == b)break;
		print_vector(a);
		printf(" + ");
		print_vector(b);
		printf(" = ");
		a = add(a, b);
		print_vector(a);
		cout << endl;
	}
	if (n == -1)
		printf("Not found in 10 iterations.");
	else
	{
		print_vector(a);
		printf(" is a palindromic number.");
	}
}