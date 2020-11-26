#include<iostream>
#include<cstring>
using namespace std;
const int N = 210;
bool g[N][N],st[N];
int n, m;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> n >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		g[a][b] = g[b][a] = true;
	}
	int k;
	cin >> k;
	int a[N] = { 0 };
	while (k--)
	{
		int count;
		cin >> count;
		bool ct[N] = { false };
		for (int i = 0; i < count; i++)cin >> a[i],ct[a[i]]=true;
		bool flag = true;
		for (int i = 0; i < count; i++) 
			for (int j = i + 1; j < count; j++)
			{
				if (!g[a[i]][a[j]])
				{
					flag = false;
					break;
				}
			}
		if (flag)
		{
			memset(st, 0, sizeof st);
			bool l_flag = false;
			for(int i=1;i<=n;i++)
			{
				if (!ct[i])
				{
					int j;
					for (j = 0; j < count; j++)
						if (!g[i][a[j]])
							break;
					if (j == count)
					{
						l_flag = true;
						break;
					}
				}
			}
			if (!l_flag)puts("Yes");
			else puts("Not Maximal");
		}
		else puts("Not a Clique");
	}
}