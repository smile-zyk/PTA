#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void add(vector<int> &a, vector<int> &b)
{
	int t = 0;
	for (int i = 0; i < a.size() ; i++)
	{
		int s = a[i] + b[i] + t;
		a[i] = s % 10;
		t = s / 10;
	}
	if (t)a.push_back(1);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string A;
	vector<int> a;
	int n;
	cin >> A >> n;
	for (int i = A.size() - 1; i >= 0; i--)a.push_back(A[i] - '0');
	int i;
	vector<int> b;
	for (i = 0; i < n; i++)
	{
		b = a;
		reverse(b.begin(), b.end());
		if (a == b)break;
		else add(a, b);
	}
	for (int i = a.size() - 1; i >= 0; i--)
	{
		printf("%d", a[i]);
	}
	printf("\n%d", i);
}