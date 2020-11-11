#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct Person
{
	int arrive_time, play_time;
	int start_time, wait_time;
	bool operator<(const Person& p)const
	{
		if (start_time != p.start_time)return start_time < p.start_time;
		else return arrive_time < p.arrive_time;
	}
	bool operator>(const Person& p)const
	{
		return arrive_time > p.arrive_time;
	}
};
struct Table
{
	int id;
	int endtime;
	bool operator>(const Table& t) const
	{
		if (endtime != t.endtime)
			return endtime > t.endtime;
		else
			return id > t.id;
	}
};
const int N = 105, INF = 22 * 3600;
bool is_vip_table[N];
int table_cnt[N];
vector<Person> res;

string get_time(int time)
{
	char res[20];
	sprintf(res, "%02d:%02d:%02d", (time / 3600), (time % 3600) / 60, time % 60);
	return res;
}

void assign(priority_queue<Person, vector<Person>, greater<Person> >& person, priority_queue<Table, vector<Table>, greater<Table> >& table)
{
	auto p = person.top(); person.pop();
	auto t = table.top(); table.pop();
	p.start_time = t.endtime;
	p.wait_time = (int)((p.start_time - p.arrive_time) / 60.0 + 0.5);
	res.push_back(p);
	t.endtime += p.play_time;
	table.push(t);
	table_cnt[t.id]++;

}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	priority_queue<Person, vector<Person>, greater<Person> > normal_person;
	priority_queue<Person, vector<Person>, greater<Person> > vip_person;
	normal_person.push({ INF });
	vip_person.push({ INF });
	int n;
	cin >> n;
	while (n--)
	{
		int hour, minute, second, play_time, is_vip;
		scanf("%d:%d:%d %d %d", &hour, &minute, &second, &play_time, &is_vip);
		int arrive_time = hour * 3600 + minute * 60 + second;
		play_time *= 60;
		if (is_vip)
			vip_person.push({ arrive_time,min(play_time,7200) });
		else
			normal_person.push({ arrive_time,min(play_time,7200) });
	}
	priority_queue<Table, vector<Table>, greater<Table> > normal_table;
	priority_queue<Table, vector<Table>, greater<Table> > vip_table;
	normal_table.push({ -1,INF });
	vip_table.push({ -1,INF });
	int k, m;
	cin >> k >> m;
	while (m--)
	{
		int id;
		cin >> id;
		is_vip_table[id] = true;
	}
	for (int i = 1; i <= k; i++)
	{
		if (is_vip_table[i] == true)
			vip_table.push({ i,8 * 3600 });
		else
			normal_table.push({ i,8 * 3600 });
	}
	while (vip_person.size() > 1 || normal_person.size() > 1)
	{
		auto np = normal_person.top();
		auto vp = vip_person.top();
		int arrive_time = min(np.arrive_time, vp.arrive_time);
		while (normal_table.top().endtime < arrive_time)  
		{
			auto t = normal_table.top();
			normal_table.pop();
			t.endtime = arrive_time;
			normal_table.push(t);
		}
		while (vip_table.top().endtime < arrive_time)
		{
			auto t = vip_table.top();
			vip_table.pop();
			t.endtime = arrive_time;
			vip_table.push(t);
		}

		auto nt = normal_table.top();
		auto vt = vip_table.top();
		int end_time = min(nt.endtime, vt.endtime);

		if (end_time >= 21 * 3600) break;

		if (vp.arrive_time <= end_time && vt.endtime == end_time) assign(vip_person, vip_table);

		else if (np< vp)
		{
			if (nt > vt) assign(normal_person, vip_table);
			else assign(normal_person, normal_table);
		}
		else
		{
			if (nt > vt) assign(vip_person, vip_table);
			else assign(vip_person, normal_table);
		}
	}
	sort(res.begin(), res.end());
	for (auto& r : res)
	{
		cout << get_time(r.arrive_time) << " " << get_time(r.start_time) << " " << r.wait_time << endl;
	}
	for (int i = 1; i <= k; i++)
	{
		if (i != 1)cout << " ";
		cout << table_cnt[i];
	}
}