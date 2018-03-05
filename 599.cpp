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
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, pair<int,int>>Map;
        for (int i = 0; i < list1.size(); ++i)
        {
        	Map[list1[i]] = make_pair(0, i);
        }
        for (int i = 0; i < list2.size(); ++i)
        {
        	if (Map.find(list2[i]) != Map.end())
        	{
        		Map[list2[i]].first = 1;
        		Map[list2[i]].second += i;
        	}
        	else
        	{
        		Map[list2[i]] = make_pair(0, i);
        	}
        	
        }
        int Min = INT_MAX;
        for(std::map<string, pair<int, int>>:: iterator s = Map.begin(); s != Map.end(); s++)
        {
        	if ((s->second).first == 1 && (s->second).second < Min)
        	{
        		Min = (s->second).second;
        	}
        }
        vector<string> v;
        for(std::map<string, pair<int, int>>:: iterator s = Map.begin(); s != Map.end(); s++)
        {
        	if((s->second).first == 1 && (s->second).second == Min)
        	{
        		v.push_back(s->first);
        	}
        }
        return v;
    }
};