#include<iostream>
#include<cstring>
using namespace std;
int n, m;
const int N = 510;
int g[N][N];
int dist[N];
bool ct[N];

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!ct[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        ct[t] = true;
        for (int j = 1; j <= n; j++)
        {
            if (dist[j] > dist[t] + g[t][j])
            {
                dist[j] = dist[t] + g[t][j];
            }
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    memset(g, 0x3f, sizeof g);
    cin >> n >> m;
    while (m--)
    {
        int a, b, l;
        cin >> a >> b >> l;
        g[a][b] = min(g[a][b], l);
    }
    dijkstra();
    if (dist[n] == 0x3f3f3f3f)
        cout << "-1";
    else cout << dist[n];
}