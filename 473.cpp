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

class Solution {
public:
    vector<bool> included;
    int length;
    vector<int> nums;

    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false;
        int sum = 0;
        for (auto n : nums) {
            sum += n;
        }
        if (sum == 0 || sum % 4 != 0) return false;
        sort(nums.begin(), nums.end());
        length = sum / 4;
        this->nums = nums;
        included = vector<bool>(15, false);
        if (nums[0] == length) {
            return dfs(1, 0, 1);
        }
        else {
            return dfs(1, nums[0], 0);
        }
    }
    
    bool dfs(int i, int sum, int count) {
        //cout << i << " " << sum << " " << count << endl;
        while (i < nums.size() && included[i]) ++i;
        if (i == nums.size()) return false;
        sum += nums[i];
        included[i] = true;
        if (sum < length) {
            if (dfs(i+1, sum, count))
                return true;
        }
        else if (sum == length) {
            if (count == 2) return true;
            else {
                if (dfs(1, 0, count+1))
                    return true;
            }
        }
        sum -= nums[i];
        included[i] = false;
        return dfs(i+1, sum, count);
    }
};
