#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
const int N = 40;
int pre[N], in[N];
unordered_map<int, int> in_pos;
int root;
bool ans;

int build(int il, int ir, int pl, int pr, int& sum)
{
	if (il > ir)
	{
		sum++;
		return 0;
	}
	int root = pre[pl];
	int k = in_pos[abs(root)];
	if (k<il || k>ir)
	{
		ans = false;
		return 0;
	}
	int left, right, ls = 0, rs = 0;
	left = build(il, k - 1, pl + 1, pl + 1 + k - 1 - il, ls);
	right = build(k + 1, ir, pl + 1 + k - 1 - il + 1, pr, rs);
	if (ls != rs)ans = false;
	sum = ls;
	if (root < 0)
	{
		if (left < 0 || right < 0)
			ans = false;
	}
	else sum++;
	return root;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	cin >> n;
	while (n--)
	{
		int k;
		cin >> k;
		for(int i=0;i<k;i++)
		{
			cin >> pre[i];
			in[i] = abs(pre[i]);
		}
		sort(in, in + k);
		in_pos.clear();
		for (int i = 0; i < k; i++)in_pos[in[i]] = i;
		int sum;
		ans = true;
		root = build(0, k - 1, 0, k - 1, sum);
		if (root < 0)ans = false;
		if (ans)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}