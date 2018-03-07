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
/*1 + x + x^2 + ...... + x^d = n；而n < 10^18<(2^62)，所以d最大为62；最小为 1，然后再二分找x
The input can be stored in a long long int, here I use unsigned long long int for a larger range. We need to find k, for 1+k^1+k^2+k^3+…+k^d=n. The smallest possible base is k=2, with has the longest possible representation, i.e., largest d. So, to find the smallest base means to find the longest possible representation “11111…1” based on k. As n<=10^18, so n<(1<<62). We iterate the length of the representation from 62 to 2 (2 can always be valid, with base=n-1), and check whether a given length can be valid.
For a given length d, we use binary search to check whether there is a base k which satisfies 1+k^1+k^2+…k^d=n. The left limit is 1, and the right limit is pow(n,1/d)+1, i.e., the d th square root of n. The code is shown below
*/
//注意right的初始值，否则会导致溢出而出现sum变成负数；
class Solution {
public:
    string smallestGoodBase(string n) {
        unsigned long long num = stol(n);
        for (int i = log2(num) + 1; i >= 2; --i) {
            //cout<<i<<endl;
            unsigned long long left = 2, right = pow(num, 1.0 / (i-1));
            while (left <= right) {
                unsigned long long mid = left + (right - left) / 2, sum = 0;
                for (int j = 0; j < i; ++j) {
                    sum = sum * mid + 1;
                }
                //cout<<sum<<endl;
                if (sum == num) return to_string(mid);
                else if (sum < num) left = mid + 1;
                else right = mid - 1;
            }
            //break;
        }
        return to_string(num - 1);
    }
};
int main()
{
 Solution s;
 cout<<s.smallestGoodBase("2251799813685247")<<endl;
}
