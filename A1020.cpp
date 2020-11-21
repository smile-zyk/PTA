#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define it vector<int>::iterator
using namespace std;
typedef struct Btree
{
	int val;
	Btree *lchild,*rchild;
}*btree;

void RebuildTree(it InL, it InR, it PostL, it PostR, btree& t)
{
	t = new Btree();
	int root = *(PostR - 1);
	t->val = root;
	int leftlen = find(InL, InR, root) - InL;
	int rightlen = InR - find(InL, InR, root) - 1;
	if (leftlen>0)
		RebuildTree(InL, InL + leftlen, PostL, PostL + leftlen, t->lchild);
	if (rightlen>0)
		RebuildTree(InR - rightlen, InR, PostR - 1 - rightlen, PostR - 1, t->rchild);
}

void LevelOrder(btree t)
{
	if (!t)return;
	queue<btree> nodes;
	nodes.push(t);
	int i = 0;
	while (!nodes.empty())
	{
		btree tmp = nodes.front();
		nodes.pop();
		if (i != 0)cout << " ";
		cout << tmp->val;
		if(tmp->lchild)
		nodes.push(tmp->lchild);
		if(tmp->rchild)
		nodes.push(tmp->rchild);
		i = 1;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> In, Post;
	for (int i = 0; i < n; i++)
	{
		int n;
		cin >> n;
		Post.push_back(n);
	}
	for (int i = 0; i < n; i++)
	{
		int n;
		cin >> n;
		In.push_back(n);
	}
	btree t = NULL;
	RebuildTree(In.begin(), In.end(), Post.begin(), Post.end(), t);
	LevelOrder(t);
}