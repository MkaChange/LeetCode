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
    /*
     * @param : An integer
     * @param : An integer
     * @return: An integer denote the count of digit k in 1..n
     * 思路：对0 - n 每个数每个位进行统计，不过效率很差
     */
    // int digitCounts(int k, int n) {
    //     // write your code here
    //     int count = 0;
    //     if (k == 0)
    //     {
    //     	count++;
    //     }
    //     for (int i = 1; i <= n; ++i)
    //     {
    //     	/* code */
    //     	int t = i;
    //     	while(t != 0)
    //     	{
    //     		if ((t % 10) == k)
    //     		{
    //     			/* code */
    //     			count++;
    //     		}
    //     		t = t / 10;
    //     	}
    //     }
    //     return count;
    // }
    /*
     * 分两种情况：k = 0;特殊考虑
     * k != 0;有以下结论：
     * 当某一位的数字小于k时，那么该位出现k的次数为：更高位数字x当前位数
	 * 当某一位的数字等于k时，那么该位出现k的次数为：更高位数字x当前位数+低位数字+1
     * 当某一位的数字大于k时，那么该位出现k的次数为：(更高位数字+1)x当前位数
     */
    int digitCounts(int k, int n){
	    int count = 0;
	    int factor = 1;
	    int low = 0, cur = 0, high = 0;
	    while(n / factor != 0){
	        low = n - (n/factor) * factor;//低位数字
	        cur = (n/factor) % 10;//当前位数字
	        high = n / (factor*10);//高位数字
	        if(cur < k)
	            count += high * factor;
	        else if(cur == k)
	            count += high * factor + low + 1;
	        else
	            count += (high + 1) * factor;

	        factor *= 10;
	    }
	    if (k != 0){
	    	return count;
	    }else{
	    	int len = to_string(n).length();
	    	if (len == 1){
	    		return 1;
	    	}
	    	int t;
	    	for (int i = 1; i < len; ++i)
	    	{
	    		/* code */
	    		t = (i == 1)?(10):(t * 10 - t);
	    		count -= (len - i) * t;
	    	}
	    	return count;
	    }

    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout<<s.digitCounts(0, 100)<<endl;
	return 0;
}