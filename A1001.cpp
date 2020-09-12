#include<string>
#include<iostream>
using namespace std;
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