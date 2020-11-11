#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct person
{
	int arrive_time;
	int service_time;
	bool operator<(const person&p) const
	{
		return arrive_time < p.arrive_time;
	}
};
priority_queue<int, vector<int>, greater<int>> windows;
person p[10010];
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int hour, minute, second,service_time;
		scanf("%d:%d:%d %d", &hour, &minute, &second, &service_time);
		p[i] = { hour * 3600 + minute * 60 + second,min(service_time * 60,3600) };
	}
	for (int i = 0; i < k; i++)
	{
		windows.push(8 * 3600);
	}
	sort(p, p + n);
	int sum = 0, cnt = 0;
	for(int i=0;i<n;i++)
	{
		auto people = p[i];
		if (people.arrive_time > 17 * 3600)break;
		int already_time = windows.top(); 
		windows.pop();
		int start_time = max(already_time, people.arrive_time);
		sum += start_time - people.arrive_time;
		cnt++;
		windows.push(start_time + people.service_time);
	}
	printf("%.1f", sum / 60.0 / cnt);
}