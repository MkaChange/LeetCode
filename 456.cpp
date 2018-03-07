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
//i < j < k, ai < ak < aj;
//思路：首先存储前k个数的最小值.
//然后从后往前扫描，对应为aj，同时维护一个栈，使得栈顶的数比min[j]大；
//如果aj > min[j]，说明存在i < j ,使得 ai < aj;然后看栈里的数，对应着ak，而且保证了ak > ai;
//所以，如果栈顶元素比aj小，说明就找到了；否则，就把aj push 到栈里；
//这个栈是一个单调栈，栈底到栈顶元素单调递减。
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
    	if(nums.size() < 3) return false;
        std::vector<int> Min(nums.size());
        Min[0] = nums[0];
        stack<int> s;
        for (int i = 1; i < nums.size(); ++i)
        {
        	Min[i] = min(Min[i - 1], nums[i]);
        }
        for (int j = nums.size() - 1; j >= 0 ; j--)
        {
        	/* code */
        	if (nums[j] > Min[j])
        	{
        		while(!s.empty() && s.top() <= Min[j])
        			s.pop();
        		if (!s.empty() && s.top() < nums[j])
        		{
        			return true;
        		}
        		s.push(nums[j]);
        	}
        }
        	return false;
        

    }
};