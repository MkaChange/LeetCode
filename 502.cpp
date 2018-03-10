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
#include<queue>
using namespace std;
//贪心 + 优先队列（维护比W小的profits)，不用优先队列会超时
class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int n = Profits.size();
        vector<pair<int, int>> a;
        for (int i = 0; i < n; ++i) {
            a.push_back(make_pair(Capital[i], Profits[i]));
        }
        sort(begin(a), end(a));
        
        priority_queue<int> heap;
        int j=0;
        for (j = 0; j < n; ++j) {
            if (a[j].first <= W) heap.push(a[j].second);
            else break;
        }
        
        int maxCap = W;
        while (heap.size() > 0 && k > 0) {
            auto x = heap.top(); 
            heap.pop();
            maxCap += x;
            --k;
            
            for (; j < n; ++j) {
                if (a[j].first <= maxCap) heap.push(a[j].second);
                else break;
            }
        }
        return maxCap;
    }
};