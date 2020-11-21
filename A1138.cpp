#include<iostream>
#include<unordered_map>
using namespace std;
const int N = 50010;//�������ϴ�ʱ����ʹ��hash�������ұ����е�Ԫ�أ�����ᳬʱ��
int pre[N], in[N], post[N], cnt, n;
unordered_map<int, int> inpos;
void dfs(int pl, int pr, int il, int ir)
{
	if (pl > pr)return;
	int root = pre[pl];
	//int k = 0;
	//while (in[k] != root)k++;
	int k = inpos[root];//�����������ʱ��
	dfs(pl + 1, pl + k - il, il, k - 1);
	dfs(pl + k - il + 1, pr, k + 1, ir);
	post[cnt++] = root;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)cin >> pre[i];
	for (int i = 0; i < n; i++)
	{
		cin >> in[i];
		inpos[in[i]] = i;
	}
	dfs(0, n - 1, 0, n - 1);
	cout << post[0]<<endl;
}