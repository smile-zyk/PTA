#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string male_last_id, male_last_name, female_first_id, female_first_name;
	int male_last_grade = -1, female_first_grade = -1;
	int n;
	cin >> n;
	while (n--)
	{
		string name, id, sex;
		int grade;
		cin >> name >> sex >> id >> grade;
		if (sex == "M" && (male_last_grade == -1 || grade < male_last_grade))
		{
			male_last_grade = grade;
			male_last_id = id;
			male_last_name = name;
		}
		if (sex == "F" && (female_first_grade == -1 || grade > female_first_grade))
		{
			female_first_grade = grade;
			female_first_id = id;
			female_first_name = name;
		}
	}

	if (female_first_grade == -1)
		cout << "Absent" << endl;
	else
		cout << female_first_name << " " << female_first_id << endl;
	if (male_last_grade == -1)
		cout << "Absent" << endl;
	else
		cout << male_last_name << " " << male_last_id << endl;
	if (female_first_grade == -1 || male_last_grade == -1)
		cout << "NA" << endl;
	else
		cout << female_first_grade - male_last_grade<<endl;

}