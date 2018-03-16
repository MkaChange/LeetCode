#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<long long>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(i+1==nums[i]) continue;
            long long x = nums[i];
            long long temp;
            while(x>=1 && x<=nums.size() && x!=nums[x-1]){
                temp = nums[x - 1];
                nums[x - 1] = x;
                x = temp;
                //swap(x, nums[x-1]);
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(i+1!=nums[i])    return i+1;
        }
        return nums.size()+1;
    }
};


int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    std::vector<long long> v;
    for (int i = 0; i < n; ++i)
    {
        long long x;
        cin>>x;
        v.push_back(x);
    }
    Solution s;
    cout<<s.firstMissingPositive(v)<<endl;

    return 0;
}