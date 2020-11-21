#include<iostream>
using namespace std;
int n;
int a[110];
int b[110];
void down(int u,int n)
{
	int t = u;
	if (u * 2 <= n && b[t] < b[u * 2])t = u * 2;
	if (u * 2 + 1 <= n && b[t] < b[u * 2 + 1])t = u * 2 + 1;
	if (u != t)
	{
		swap(b[t], b[u]);
		down(t, n);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> n;

	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++)cin >> b[i];
	int p = 2;
	while (p <= n && b[p] >= b[p - 1])p++;
	int k = p;
	while (p <= n && a[p] == b[p])p++;
	if (p == n + 1)
	{
		printf("Insertion Sort\n");
		while (k && b[k] < b[k - 1])swap(b[k], b[k - 1]), k--;
	}
	else
	{
		printf("Heap Sort\n");
		int p = n;
		while (b[1] <= b[p])p--;
		swap(b[1], b[p]);
		down(1, p - 1);
	}
	for (int i = 1; i <= n; i++)
	{
		if (i != 1)cout << " ";
		cout << b[i];
	}
}