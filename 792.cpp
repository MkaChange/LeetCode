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
//思路：先写一个是否为子序列函数，然后进行判断，这里由于测试数据words含有很多相同的字符串，所以用map，否则会超时；
class Solution {
public:
    bool isSubstr(string str, string subStr){
        int len1 = str.length(), len2 = subStr.length();
        int i = 0, j = 0;
        while(i < len2 && j < len1){
            if (str[j] == subStr[i]){
                i++;
            }
            j++;
        }
        return i == len2;
    }
    int numMatchingSubseq(string S, vector<string>& words) {
        int count = 0;
        std::map<string, int> Map;
        for(int i = 0; i < words.size(); i++){
            map<string, int>::iterator key = Map.find(words[i]);
            if ( key != Map.end()){
                (key->second) += 1;
            }else{
                Map[words[i]] = 1;
            }
        }
        for(map<string, int>::iterator i = Map.begin(); i != Map.end(); i++){
            if (isSubstr(S, i->first)){
                count += i->second;
            }
        }
        return count;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> words;
    words.resize(1);
    for(int i = 0; i < 1; i++){
            cin>>words[i];
    }
    cout<<s.numMatchingSubseq("abcde", words)<<endl;
    return 0;
}