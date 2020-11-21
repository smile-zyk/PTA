#include<iostream>
#include<string>
using namespace std;
const int N = 30;
int pre[N], post[N];
int n;
int rebuild(int prel, int prer, int postl, int postr,string &in)
{
	if (prel > prer)return 1;
	if (pre[prel] != post[postr] )return 0;
	int resort = 0;
	int root = pre[prel];
	string rin, lin;
	for (int i = prel; i <= prer; i++)
	{
		int l_resort = rebuild(prel + 1, i, postl, postl + (i - prel - 1),lin);
		int r_resort = rebuild(i + 1, prer, postl + i - prel, postr - 1, rin);
		if (l_resort && r_resort)
		{
			in = lin + to_string(pre[prel]) + " " + rin;
			resort += l_resort * r_resort;
			if (resort > 1)break;
		}
	}
	return resort;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)cin >> pre[i];
	for (int i = 0; i < n; i++)cin >> post[i];
	string in;
	int res = rebuild(0, n - 1, 0, n - 1, in);
	if (res == 1)printf("Yes\n");
	else printf("No\n");
	in.pop_back();
	cout << in;
}