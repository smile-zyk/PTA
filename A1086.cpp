#include<iostream>
#include<stack>
using namespace std;
const int N = 40;
int n;
int pre[N], in[N];
int i = 0;

void dfs(int pl,int pr,int il,int ir)
{
	if (pl > pr)return;
	int root = pre[pl];
	int k = 0;
	for (k = il; k <= ir; k++)if (in[k] == root)break;
	dfs(pl + 1, pl + 1 + (k - 1 - il), il, k - 1);
	dfs(pr - (ir - k - 1), pr, k + 1, ir);
	if (i != 0)cout << " ";
	cout << root;
	i = 1;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	stack<int> st;
	cin >> n;
	int pi = 0, ii = 0;
	int m = 2 * n;
	while (m--)
	{
		string op;
		int n;
		cin >> op;
		if (op[1] == 'u')
		{
			cin >> n;
			st.push(n);
			pre[pi++] = n;
		}
		else
		{
			n = st.top();
			st.pop();
			in[ii++] = n;
		}
	}
	dfs(0, n - 1, 0, n - 1);
}