#include<iostream>
using namespace std;
struct  mess
{
	int a;
	int b;
	int c;
	mess operator+(const mess& m)const
	{
		mess res;
		int t = 0;
		res.c = (c + m.c) % 29;
		t = (c + m.c) / 29;
		res.b = (b + m.b + t) % 17;
		t = (b + m.b + t) / 17;
		res.a = a + m.a + t;
		return res;
	}
};
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	mess a, b;
	scanf("%d.%d.%d", &a.a, &a.b, &a.c);
	scanf("%d.%d.%d", &b.a, &b.b, &b.c);
	mess c = a + b;
	printf("%d.%d.%d", c.a, c.b, c.c);
}