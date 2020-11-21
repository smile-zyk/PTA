#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<map>
using namespace std;
map<string, int> Mar_low;
map<string, int> Mar_high;
const char* Earth_low[] = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
const char* Earth_high[] = { "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	for (int i = 0; i < 13; i++)
	{
		Mar_low[Earth_low[i]] = i;
		Mar_high[Earth_high[i]] = i;
	}
	int n;
	cin >> n;
	getchar();
	string a;
	while (n--) 
	{
		getline(cin, a);
		if (a[0] <= '9')
		{
			int n = atoi(a.c_str());
			if (n < 13)cout << Earth_low[n] << endl;
			else if (n % 13 == 0)cout << Earth_high[n / 13] << endl;
			else
				cout << Earth_high[n / 13] << " " << Earth_low[n % 13]<<endl;
		}
		else
		{
			stringstream is(a);
			vector<string> word;
			int res;
			string tmp;
			while (is >> tmp)word.push_back(tmp);
			if (word.size() == 1)
			{
				if (Mar_low.count(word[0]))
					cout << Mar_low[word[0]] << endl;
				else
					cout << Mar_high[word[0]] * 13 << endl;
			}
			else
				cout << Mar_high[word[0]] * 13 + Mar_low[word[1]] << endl;
		}
	}
}