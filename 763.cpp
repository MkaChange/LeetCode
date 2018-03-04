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
//区间合并， 贪心；
class p{
public:
    int start;
    int end;
    bool operator< ( const p &b) const{
		if (start < b.start){
			return true;
		}else if (start == b.start){
			return end <= b.end;
		}else{
			return false;
		}
	}
};
class Solution {
public:
    vector<int> partitionLabels(string S) {
    	vector<p> v1(26);
    	for (int i = 0; i < v1.size(); ++i)
    	{
    		v1[i].start = 501;
    		v1[i].end = -1;
    	}
        for (int i = 0; i < S.length(); ++i)
        {
        	if(v1[S[i] - 'a'].start > i) v1[S[i] - 'a'].start = i;
        	if (v1[S[i] - 'a'].end < i) v1[S[i] - 'a'].end = i;
        }
        sort(v1.begin(), v1.end());
        int endi = 0, starti = 0, k = 0;
        vector<int> len;
        for (int i = 0; i < v1.size(); ++i)
        {
            if(v1[i].start == 501) break;
            endi = max(v1[i].end, endi);
            if (endi == S.length() -1)
            {
            	len.push_back(endi - starti + 1);
            	break;
            }
        	if (endi < v1[i + 1].start){
        		//cout<<endi<<"S";
        		len.push_back(endi - starti + 1);
        		starti = v1[i + 1].start;
        	}
        }
        return len;
    }
};
int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> v= s.partitionLabels("tcrbcxuxiiiixprupcubpuptrcxpbxpxbxuuutibcppicgguxiputixcrrcxttrxrpbixixrpptbpbtibcgbpbgtribrpprxcbbbguigxgxpbpibrtupgrpiriuuiubiccitctricialyyysmmlmnmnlalsshohnymanosymsayohloaymmnmylnmonynsamyylmmhhhsslynhnomnymnmsssmhossaonslmosyysmshloaamhosymnhlaolymomhllayyhllanohhshslmayohsyymonhyhoahloyoasolyyyyyommamnhyhhlanaosaymmeweqqkdjfzvdzddqfkzjzqfkfzkkzkdedvzkevvwzzezfkevefeezdkvkfkzjdzevjqwdjdzkwkjdfqdvdkdfzjjvezqevkewqfkjvjjqvqqzqdkqqdeejwwdwfqqkqqzvvwqdjfdzzqkkezwkjeqzfvdzwjkzqkzzjdjjkwkzdjqvev");
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<endl;
	}
	return 0;
}