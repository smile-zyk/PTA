#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int N = 1440 * 31 + 10;
struct Record
{
	int minutes;
	string state;
	string format_time;
	bool operator<(const Record& r)const
	{
		return minutes < r.minutes;
	}
};
map<string, vector<Record>> persons;
double rate[24];
double cost[1440 * 31 + 10];
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	for (int i = 0; i < 24; i++)
		cin >> rate[i];
	for (int i = 1; i < N; i++)
		cost[i] = cost[i - 1] + rate[((i - 1) % 1440) / 60] / 100;
	int n;
	cin >> n;
	char name[25], state[10],format_time[20];
	int month, day, hour, minute, minutes;
	while (n--)
	{
		scanf("%s %d:%d:%d:%d %s", name, &month, &day, &hour, &minute, state);
		minutes = (day - 1) * 1440 + hour * 60 + minute;
		sprintf(format_time, "%02d:%02d:%02d", day, hour, minute);
		persons[name].push_back({ minutes,state,format_time });
	}
	for (auto& person : persons)
	{
		auto records = person.second;
		sort(records.begin(), records.end());
		double total = 0;
		for (int i = 0; i + 1 < records.size(); i++)
		{
			auto name = person.first;
			auto a = records[i], b = records[i + 1];
			if (a.state=="on-line"&&b.state=="off-line")
			{
				if (!total)printf("%s %02d\n", name.c_str(), month);
				float c = cost[b.minutes] - cost[a.minutes];
				printf("%s %s %d $%0.2f\n", a.format_time.c_str(), b.format_time.c_str(),b.minutes-a.minutes, c);
				total += c;
			}
		}
		if(total) printf("Total amount: $%.2f\n", total);
	}
}