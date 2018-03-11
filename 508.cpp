#include<iostream>
#include<sstream>
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
//树的递归遍历，同时利用数组保存中间结果
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> v;
	int findSum(TreeNode* root){
		int Sum = root->val;
		if (root->left != NULL)
		{
			int leftSum = findSum(root->left);
			//v.push_back(leftSum);
			Sum += leftSum;
		}
		if (root->right != NULL)
		{
			int rightSum = findSum(root->right);
			//v.push_back(rightSum);
			Sum += rightSum;
		}
		v.push_back(Sum);
		return Sum;
	}
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(root == NULL) 
            return vector<int>();
    	int Sum = findSum(root);
    	std::map<int, int> Map;
    	int Max = -1;
    	for (int i = 0; i < v.size(); ++i)
    	{
            //cout<< v[i]<<endl;
    		if (Map.find(v[i]) != Map.end())
    		{
    			Map[v[i]] += 1;
    		}
    		else
    			Map[v[i]] = 1;
    		if (Map[v[i]] > Max)
    		{
    			Max = Map[v[i]];
    		}
    	}
    	std::vector<int> res;
    	for(auto x: Map)
    	{
    		if (x.second == Max )
    		{
    			res.push_back(x.first);
    		}
    	}
    	return res;

    }
};