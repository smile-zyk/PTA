#include<iostream>
using namespace std;
#define MAXSIZE 1005
float res[MAXSIZE];
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int i = 2;
	while (i--)
	{
		int n;
		cin >> n;
		while (n--)
		{
			int e;
			float c;
			cin >> e >> c;
			res[e] += c;
		}
	}
	int k = 0;
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (res[i] != 0)k++;
	}
	cout << k;
	for (int i = MAXSIZE-1; i >= 0; i--)
	{
		if (res[i] != 0)
			printf(" %d %.1f", i, res[i]);
	}
}