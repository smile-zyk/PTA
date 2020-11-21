#include<iostream>
using namespace std;
const int N = 100010;
int n, m;
int p[N];

int find(int x)
{
    if (p[x] != x)p[x] = find(p[x]);
    else return p[x];
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    char c;
    while (m--)
    {
        int a, b;
        char c[2];
        scanf("%s %d %d", &c, &a, &b);
        if (c[0] == 'M')
            p[find(a)] = find(b);
        else
            if (find(a) == find(b))
                printf("Yes\n");
            else
                printf("No\n");
    }
    return 0;
}