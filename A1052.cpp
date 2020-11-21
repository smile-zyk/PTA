#include<iostream>
#include<algorithm>
using namespace std;
struct Node
{
	int adress = -1;
	int val;
	bool operator<(const Node& n)const
	{
		return val < n.val;
	}
};

Node nodes[100010];
int mem[100010][2];
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n, head;
	cin >> n >> head;
	for (int i = 0; i < n; i++)
	{
		int adress, val, next;
		scanf("%d %d %d", &adress, &val, &next);
		mem[adress][0] = val;
		mem[adress][1] = next;
	}
	int p = head;
	int len = 0;
	while (p != -1)
	{
		nodes[len].adress = p;
		nodes[len].val = mem[p][0];
		p = mem[p][1];
		len++;
	}
	sort(nodes, nodes+ len);
	if (nodes[0].adress == -1)
		printf("%d -1\n", len);
	else
		printf("%d %05d\n", len, nodes[0].adress);
	for (int i = 0; i < len; i++)
	{
		printf("%05d %d ", nodes[i].adress, nodes[i].val);
		if (nodes[i + 1].adress == -1)
			printf("-1\n");
		else
			printf("%05d\n", nodes[i + 1].adress);
	}
}