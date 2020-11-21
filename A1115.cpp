#include<iostream>
#include<cstring>
using namespace std;
const int N = 1010;
int e[N], l[N], r[N], idx;
int root, max_depth, n;
int d[N];
void insert(int val, int& index, int depth)
{
	if (index == -1)
	{
		e[idx] = val, index = idx++;
		d[depth]++;
		max_depth = max(depth, max_depth);
		return;
	}
	if (val > e[index])insert(val, r[index], depth + 1);
	else insert(val, l[index], depth + 1);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	memset(l, -1, sizeof(l));
	memset(r, -1, sizeof(r));
	root = -1;
	cin >> n;
	int a;
	while (n--)
	{
		cin >> a;
		insert(a, root, 0);
	}
	printf("%d + %d = %d", d[max_depth], d[max_depth - 1], d[max_depth] + d[max_depth - 1]);
}