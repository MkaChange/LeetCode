#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<algorithm>
#include<stack>
using namespace std;
//从player1角度思考，player2是为了让player1分数最小化，然后动归；
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        std::vector<vector<int>> dp(nums.size());
        for (int i = 0; i < nums.size(); ++i)
        {
        	dp[i].resize(nums.size());
        }
        if (nums.size() % 2 == 0)
        {
        	for (int i = 0; i < nums.size(); ++i)
        	{
        		dp[i][i] = -nums[i];
        	}

        }
        else
        {
        	for (int i = 0; i < nums.size(); ++i)
        	{
        		dp[i][i] = nums[i];
        	}
       	}
       	int i, j, k;
        for (int k = 1; k < nums.size(); ++k)
       	{
       		for (int i = 0; i < nums.size() - 1; ++i)
       		{
       			j = i + k;
       			if (j >= nums.size())
       			{
       				break;
       			}
       			if (nums.size() % 2 == 0)//player2 取最后一个数
       			{
	       			if(k % 2 == 0)//player2
	       			{
	       				dp[i][j] = min(dp[i][j - 1] - nums[j], dp[i + 1][j] - nums[i]);
	       			}
	       			else//player1
	       			{
	       				dp[i][j] = max(dp[i][j - 1] + nums[j], dp[i + 1][j] + nums[i]);
	       				
	       			}
       			}
       			else//player1 取最后一个数
       			{
       				if(k % 2 == 0)//player1
	       			{
	       				dp[i][j] = max(dp[i][j - 1] + nums[j], dp[i + 1][j] + nums[i]);
                        //cout<<dp[i][j]<<endl;
	       			}
	       			else//player2
	       			{
	       				dp[i][j] = min(dp[i][j - 1] - nums[j], dp[i + 1][j] - nums[i]);
                        //cout<<dp[i][j]<<endl;
	       			}
       			}
       		}
       	}
        //for(int i = 0; i< nums.size() -1; i++)
         //   for(int j = i; j < nums.size(); j++)
          //      cout<<dp[i][j]<<endl;
       	return (dp[0][nums.size() - 1] >= 0);
    }
};
