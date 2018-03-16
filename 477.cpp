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

using namespace std;
//整体来看，对32位的每一位统计1的个数。
class Solution {
public:
    
    int totalHammingDistance(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> bitMap(32, 0);
        int k;
        for (int i = 0; i < nums.size(); ++i)
        {
            k = 0;
            while(k < 32)
            {
                if((1<<k) & nums[i]) bitMap[k]++;
                k = k + 1;
            }
        }
        int  total = 0;
        for (int i = 0; i < 32; ++i)
        {
            total += bitMap[i] * (nums.size() - bitMap[i]);
        }
        return total;
    }
};

