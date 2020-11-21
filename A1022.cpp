//Ñ¹Ïß¹ý
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
struct bookdata
{
	string id;
	set<string> keywords;
	vector<string> otherdata;
	int publish_time;
};

vector<bookdata> books;

vector<string> get_id(string word, int key)
{
	vector<string> res;
	if (key == 1 || key == 2 || key == 4)
	{
		if (key == 4)key = 2;
		else key = key - 1;
		for (auto &i : books)
		{
			auto data = i.otherdata;
			if (data[key] == word)
				res.push_back(i.id);
		}
		return res;
	}
	else if (key == 3)
	{ 
		for (auto &i : books)
		{
			auto data = i.keywords;
			if (data.count(word))
				res.push_back(i.id);
		}
		return res;
	}
	else
	{
		for (auto& i : books)
		{
			auto data = i.publish_time;
			int w = atoi(word.c_str());
			if (w == data)
				res.push_back(i.id);
		}
		return res;
	}
}
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	cin >> n;
	while (n--)
	{
		string id, name, autor, publish,keyword;
		int publish_time;
		set<string> keywords;
		cin >> id;
		getchar();
		getline(cin, name);
		getline(cin, autor);
		getline(cin, keyword);
		stringstream is(keyword);
		string word;
		while (is >> word)keywords.insert(word);
		getline(cin, publish);
		cin >> publish_time;
		getchar();
		vector<string> otherdata = { name, autor, publish };
		books.push_back ({ id,keywords,otherdata,publish_time });
	}
	int m;
	cin >> m;
	while (m--)
	{
		string judge;
		cin >> judge;
		getchar();
		string word;
		getline(cin,word);
		vector<string> res = get_id(word, judge[0] - '0');
		cout << judge << " " << word<<endl;
		sort(res.begin(), res.end());
		if (res.size())
			for (auto& i : res)
				cout << i << endl;
		else
			cout << "Not Found" << endl;
	}
}