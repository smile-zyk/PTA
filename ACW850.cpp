#include<queue>
#include<iostream>
#include<cstring>
#define PII pair<int,int> 
using namespace std;
const int N = 150010;
int h[N], ne[N], e[N], w[N], idx;
int dist[N];
bool ct[N];
int n, m;

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({ 0,1 });
    while (heap.size())
    {
        auto ver = heap.top();
        heap.pop();
        int t = ver.second;
        if (ct[n])continue;
        ct[t] = true;
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                heap.push({ dist[j],j });
            }
        }
    }
}

void add(int a, int b, int l)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = l, h[a] = idx++;
}

int main()
{
    memset(h, -1, sizeof h);
    scanf("%d %d", &n, &m);
    while (m--)
    {
        int a, b, l;
        scanf("%d %d %d", &a, &b, &l);
        add(a, b, l);
    }
    dijkstra();
    if (dist[n] == 0x3f3f3f3f)
        cout << "-1";
    else cout << dist[n];
}