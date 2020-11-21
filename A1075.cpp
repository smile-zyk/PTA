#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct Stu
{
	int id;
	int scores[8];
	int final_score = 0;
	int full_num = 0;
	int flag = 0;
	Stu() {
		memset(scores, -1, sizeof(scores));
	}
	bool operator<(const Stu& d)const
	{
		if (final_score != d.final_score)return final_score > d.final_score;
		else if (full_num != d.full_num)
			return full_num > d.full_num;
		else return id < d.id;
	}
};

Stu stus[100010];
int full_score[8];
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n, k, m;
	cin >> n >> k >> m;
	for (int i = 1; i <= k; i++)
	{
		cin >> full_score[i];
	}

	while (m--)
	{
		int id, que_id, score;
		scanf("%d %d %d", &id, &que_id, &score);
		if (score == -1)score = 0;
		else stus[id].flag = 1;
		stus[id].scores[que_id] = max(stus[id].scores[que_id], score);
	}
	for (int i = 1; i <= n; i++)
	{
		stus[i].id = i;
		for (int j = 1; j <= k; j++)
		{
			if (stus[i].scores[j] != -1)
				stus[i].final_score += stus[i].scores[j];
			if (stus[i].scores[j] == full_score[j])stus[i].full_num++;
		}
	}
	sort(stus + 1, stus + 1 + n);
	int rank = 1;
	int record = 1;
	int last_score = 0;
	for (int i = 1; i <= n; i++)
	{
		if (stus[i].flag == 1)
		{
			if (stus[i].final_score != last_score)
			{
				printf("%d", record);
				rank = record;
			}
			else
				printf("%d", rank);
			record++;
			last_score = stus[i].final_score;
			printf(" %05d %d", stus[i].id, stus[i].final_score);
			for (int j = 1; j <= k; j++)
			{
				if (stus[i].scores[j] == -1)
					printf(" -");
				else
					printf(" %d", stus[i].scores[j]);
			}
			printf("\n");
		}
	}
}