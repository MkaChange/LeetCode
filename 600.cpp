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
//版本1:超时
class Solution {
public:
    int findIntegers(int num) {
    	int t = num;
    	int cnt = 0;
  		while(t > 0)
  		{
  			cnt++;
  			t = t >> 1;
  		}
  		//0-（2^n-1)有连续1的个数f(n) = f(n-1) + f(n - 2) + 2^(n-2)；
  		//统计比num大且二进制有连续1的数的个数
        vector<int>s(cnt + 2,0);
        s[0] = 0, s[1] = 0;
        for(int i = 2; i <= cnt; i++)
            s[i] = s[i -1] + s[i - 2] + pow(2, i-2);
  		int p = 0;

  		for (int i = num + 1; i <= pow(2, cnt) - 1; ++i)
  		{
  			int n = i;
  			int a = n & 1;
  			while(n > 0)
  			{
  				n = n >> 1;
  				if((n & 1) == 1 && a == 1)
  				{
  					p++;
                    //cout<<i<<endl;
  					break;
  				}
  				a = n & 1;
  			}
  		}
  		return (num + 1 - (s[cnt] - p));
    }
};
//版本二：从num的二进制的每一位下手；
//0-（2^n-1)有连续1的个数f(n) = f(n-1) + f(n - 2) + 2^(n-2)；
//所以没有连续1的个数为（2^(n) - f(n)) = (2^(n-1) - f(n-1)) + (2^(n-2) - f(n - 2));
class Solution2 {
public:
int findIntegers(int num) {
        vector<int>f(32);
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < f.size(); i++)
            f[i] = f[i - 1] + f[i - 2];
        int i = 30, sum = 0, prev_bit = 0;
// num = 0b11111,二进制数的范围是00000-11111，我们可以将其分为两个部分，00000-01111和10000-10111，
//因为任何大于11000的数字都是不成立的，因为有开头已经有了两个连续1。
//而我们发现其实00000-01111就是f(4)，而10000-10111就是f(3)，所以f(5) = f(4) + f(3)，
        while (i >= 0) {
            if ((num & (1 << i)) != 0) {
                sum += f[i];
                if (prev_bit == 1) {
                    return sum;
                }
                prev_bit = 1;
            } else
                prev_bit = 0;
            i--;
        }
        return sum + 1;//说明这个数本身也不连续，所以加1；
    }
}