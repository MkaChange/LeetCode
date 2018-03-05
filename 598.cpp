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
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int maxs = INT_MAX;
        int maxt = INT_MAX;
        if(ops.size() == 0) return m * n;
    	for(auto v: ops){
            int s = v[0];
            int t = v[1];
            //cout<<s <<" "<<t<<endl;
            if(s < maxs)  maxs = s;
            if(t < maxt)  maxt = t;
        }
        return maxs * maxt;
    }
};