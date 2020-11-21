#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
int preorder[N], inorder[N];
int postorder[N];
int n, cnt;

bool rebuild(int il, int ir, int pl, int pr, int type)
{
	if (il > ir)return true;
	int root = preorder[pl];
	int k;
	if (type)
	{
		for (k = il; k <= ir; k++)
			if (inorder[k] == root)break;
		if (k > ir)return false;
	}
	else
	{
		for (k = ir; k >= il; k--)
			if (inorder[k] == root)break;
		if (k < il)return false;
	}
	bool res = true;
	if (!rebuild(il, k - 1, pl + 1, pl + 1 + (k - 1 - il), type))res = false;
	if (!rebuild(k + 1, ir, pr - (ir - k - 1), pr, type))res = false;
	postorder[cnt++] = root;
	return res;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> preorder[i];
		inorder[i] = preorder[i];
	}
	sort(inorder, inorder + n);
	if (rebuild(0, n - 1, 0, n - 1, 1))
	{
		printf("YES\n");
		for (int i = 0; i < n; i++)
		{
			if (i != 0)printf(" ");
			printf("%d", postorder[i]);
		}
	}
	else
	{
		reverse(inorder, inorder + n);
		cnt = 0;
		if (rebuild(0, n - 1, 0, n - 1, 0))
		{
			printf("YES\n");
			for (int i = 0; i < n; i++)
			{
				if (i != 0)printf(" ");
				printf("%d", postorder[i]);
			}
		}
		else
			printf("NO\n");
	}
}