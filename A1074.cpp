#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
struct node
{
    int adress = -1;
    int val;
}nodes[N];
int mem[N][2];
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int head, n, k;
    cin >> head >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int adress, val, next;
        cin >> adress >> val >> next;
        mem[adress][0] = val;
        mem[adress][1] = next;
    }
    int p = head;
    int len = 0;
    while (p != -1)
    {
        nodes[len].val = mem[p][0];
        nodes[len].adress = p;  
        p = mem[p][1];
        len++;
    }
    for (int i = 0; (i+1) * k <= len; i++)
        reverse(nodes + i * k, nodes + (i + 1) * k);
    for (int i = 0; i < len; i++)
    {
        printf("%05d %d ", nodes[i].adress, nodes[i].val);
        if (nodes[i + 1].adress == -1)
            printf("-1\n");
        else
            printf("%05d\n", nodes[i + 1].adress);
    }
}