#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
int tree[N];
int in[N];
int n, cnt = 1;
void rebuild(int i)
{
	if (i * 2 <= n)rebuild(i * 2);
	tree[i] = in[cnt++];
	if (i * 2 + 1 <= n)rebuild(i * 2 + 1);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> in[i];
	sort(in + 1, in + 1 + n);
	rebuild(1);
	for (int i = 1; i <= n; i++)
	{
		if (i != 1)cout << " ";
		cout << tree[i];
	}
}