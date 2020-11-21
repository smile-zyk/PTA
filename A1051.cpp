#include<iostream>
#include<stack>
using namespace std;
const int N = 1010;
int m, n, k;
int a[N];

bool check(int* a)
{
	stack<int> st;
	for (int i = 1, j = 0; i <= n; i++)
	{
		st.push(i);
		if (st.size() > m)return false;
		while (st.size() && st.top() == a[j])
		{
			st.pop();
			j++;
		}
	}
	return st.empty();
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> m >> n >> k;
	while (k--)
	{
		for (int i = 0; i < n; i++)cin >> a[i];
		if (check(a))cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}