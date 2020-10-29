#include<string>
#include<iostream>
using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int a, b, c;
	cin >> a >> b;
	c = a + b;
	string num = to_string(c);
	string res;
	for (int i = num.size() - 1, j = 0; i >= 0; i--)
	{
		res = num[i] + res;
		j++;
		if (j % 3 == 0 && i && num[i - 1] != '-')res = ',' + res;
	}
	cout << res;
}

/*
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string result;
	int a, b, c;
	scanf("%d %d", &a, &b);
	c = a + b;
	result = to_string(abs(c));
	for (int i = 1; i * 3 < result.size() - i + 1; i++)
	{
		result.insert(result.size() - 4 * i + 1, 1, ',');
	}
	if (c < 0)
		printf("-");
	printf("%s", result.c_str());
}
*/