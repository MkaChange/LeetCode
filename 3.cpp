class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(300, -1);
        int ans = 0, start = 0;
        for(int i = 0; i < s.length(); i++){
            if(v[s[i] - '0' + 48] == -1){
                v[s[i] - '0' + 48] = i;
                ans = max(i - start + 1, ans);
            }else{
                //abcdb
                
                start = max(start, v[s[i] - '0' + 48] + 1);
                v[s[i] - '0' + 48] = i;
                ans = max(i - start + 1, ans);
                
            }
            // cout<<start;
        }
        return ans;
    }
};
