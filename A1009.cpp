#include<iostream>
using namespace std;
#define MAXSIZE 1010
float a[MAXSIZE];
float b[MAXSIZE];
float res[MAXSIZE * 2];
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n;
	cin >> n;
	while (n--)
	{
		int e;
		float c;
		cin >> e >> c;
		a[e] = c;
	}
	cin >> n;
	while (n--)
	{
		int e;
		float c;
		cin >> e >> c;
		b[e] = c;
	}
	for(int i=0;i<MAXSIZE;i++)
	{
		if (a[i] != 0)
		{
			for (int j = 0; j < MAXSIZE; j++)
			{
				if (b[j] != 0)
					res[i + j] += a[i] * b[j];
			}
		}
	}
	int k = 0;
	for (int i = 0; i < MAXSIZE * 2 - 1; i++)
		if (res[i] != 0)k++;
	cout << k;
	for (int i = MAXSIZE * 2 - 1; i >= 0; i--)
	{
		if (res[i] != 0)
			printf(" %d %.1f", i, res[i]);
	}
}