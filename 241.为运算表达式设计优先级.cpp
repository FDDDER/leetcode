#include<string>
#include<vector>
#include<set>
#include<map>
#include<regex>
#include<sstream>
#include<iostream>
#include<stdio.h>
#include<list>
#include<cstdlib>
using namespace std;
//19/10/4
class Solution {
public:
	map<string, vector<int>> dict;
	vector<int> diffWaysToCompute(string input) 
	{
		if (dict.count(input))
		{
			return dict[input];
		}
		vector<int> res;
		for (int i = 0; i < input.size(); ++i)
		{
			char c = input[i];
			if (c == '+' or c == '-' or c == '*')
			{
				auto res1 = diffWaysToCompute(input.substr(0, i));
				auto res2 = diffWaysToCompute(input.substr(i + 1, input.size()));
				for (auto x : res1)
				{
					for (auto y : res2)
					{
						if (c == '+')
						{
							res.push_back(x + y);
						}
						else if (c == '-')
						{
							res.push_back(x - y);
						}
						else
						{
							res.push_back(x * y);
						}
					}
				}
			}
		}
		//��cur�Ǵ����ִ���resӦ��Ϊ��
		if (res.empty())
		{
			res.push_back(stoi(input));
		}
		
		dict[input] = res;	//��¼��ǰ�ַ������ֵ���
		return res;
	}
};
int main()
{
	Solution x;
	vector<int> res = x.diffWaysToCompute("2*3-4*5");
	for (auto c : res)
	{
		cout << c << " ";
	}
	getchar();
}