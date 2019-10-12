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
//19/10/5凌晨
class Solution {
public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) 
	{
		int siz1 = nums1.size(), siz2 = nums2.size();
		vector<int> rec1, rec2;	//两个数组分别记录两数组利用数字的序号
		map<int, vector<int>> dp1, dp2;
		cal_dp(dp1, nums1);
		for (auto c : dp1)
		{
			cout <<"长度:"<< c << endl;
			for (auto x : dp1[c])
			{
				cout << x << " ";
			}
			cout << endl;
		}
		cal_dp(dp2, nums2);
		return vector<int>();
	}
	void cal_dp(map<int,vector<int>>& dp, vector<int>& nums)
	{
		if (nums.size() == 0)
		{
			return;
		}
		dp.clear();
		int limit = max_element(nums.begin(), nums.end()) - nums.begin() + 1;
		dp[0] = vector<int>();	//dp初始条件
		dp[0].push_back(limit - 1);
		for (int i = 1; i < nums.size(); ++i)
		{
			dp[i] = dp[i - 1];	//先复制之前的dp vector
			if (limit == nums.size())	//到头了就回溯
			{
				int j = i - 1;
				while (j>0 and dp[i][j] == dp[i][j - 1] + 1)
				{
					--j;
				}
				//从(dp[i][j-1],dp[i][j])找最大的数插进去
				int le = 0, ri = dp[i][j];
				if (j > 0)
				{
					le = dp[i][j - 1] + 1;
				}
				dp[i].insert(dp[i].begin() + j, max_element(nums.begin() + le, nums.begin() + ri) - nums.beign());
			}
			else    //后面还有富余数字，直接添加一个最大的数字的索引到后面
			{
				dp[i].push_back(max_element(nums.begin() + dp[i].back() + 1, nums.end()) - nums.begin());
			}
		}
	}
};
int main()
{
	Solution x;
	vector<int> nums1, nums2;
	nums1 = { 3,4,6,5 };
	nums2 = { 9,1,2,5,8,3 };
	x.maxNumber(nums1, nums2);
	getchar();
}