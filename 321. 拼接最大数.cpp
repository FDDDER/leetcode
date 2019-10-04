#include<set>
#include<map>
#include<regex>
#include<sstream>
#include<iostream>
#include<stdio.h>
#include<list>
#include<cstdlib>
#include<stack>
using namespace std;
//19/10/4
class Solution {
public:
	string removeDuplicateLetters(string s)
	{
		stack<char> sta;
		int last_exist[26] = { 0 };
		for (int i = 0; i < s.size(); ++i)
		{
			last_exist[s[i] - 'a'] = i;
		}
		int visited[26] = { 0 };
		for (int i=0;i<s.size();++i)
		{
			char c = s[i];
			if (visited[c - 'a'])
			{
				continue;
			}
			if (sta.empty() or c>sta.top())
			{
				sta.push(c);
			}
			else
			{
				string cur_s = s.substr(i + 1, s.size());
				while (!sta.empty() and sta.top() > c and last_exist[sta.top()-'a']>i)
				{
					visited[sta.top() - 'a'] = 0;
					sta.pop();
				}
				sta.push(c);
			}
			visited[c - 'a'] = 1;
		}
		string res = "";
		while (!sta.empty())
		{
			res += sta.top();
			sta.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
int main()
{
	Solution x;
	string s = "cbacdcbc";
	cout<<x.removeDuplicateLetters(s);
	getchar();
}