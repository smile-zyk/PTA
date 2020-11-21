#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

struct stu
{
	string id;
	int grade;
	int loca_num;
	int loca_rank;
	int final_rank;
	bool operator<(const stu& s)const
	{
		if (grade != s.grade) return grade > s.grade;
		else return id < s.id;
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	cin >> n;
	vector<stu> final_list;
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		string id;
		int grade;
		vector<stu> location_list;
		while (k--)
		{
			cin >> id >> grade;
			location_list.push_back({ id,grade ,i });
		}
		sort(location_list.begin(), location_list.end());
		int last = 0;
		int r = 1;
		int s = 1;
		for (auto& i : location_list)
		{
			if (last != i.grade)
			{
				i.loca_rank = s;
				r = s;
			}
			else
				i.loca_rank = r;
			last = i.grade;
			s++;
		}
		final_list.insert(final_list.end(), location_list.begin(), location_list.end());
	}
	sort(final_list.begin(), final_list.end());
	int last = 0;
	int r = 1;
	int s = 1;
	for (auto& i : final_list)
	{
		if (last != i.grade)
		{
			i.final_rank = s;
			r = s;
		}
		else
			i.final_rank = r;
		last = i.grade;
		s++;
	}
	cout << final_list.size()<<endl;
	for (auto& i : final_list)
	{
		cout << i.id << " " << i.final_rank << " " << i.loca_num << " " << i.loca_rank << endl;
	}
}