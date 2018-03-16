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
//思路：左子树的最大值小于root，右子树的最小值大于root，递归即可
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int maxTree(TreeNode* root){
		if (root == NULL) return INT_MIN;
		else{
			return max(root->val, max(maxTree(root->left), maxTree(root->right)));
		}
	}
	int minTree(TreeNode* root){
		if (root == NULL) return INT_MAX;
		else{
			return min(root->val, min(minTree(root->left), minTree(root->right)));
		}
	}
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        if (root->left != NULL && root->right != NULL)
        {
            if(maxTree(root->left) >= root->val || minTree(root->right) <= root->val) return false; 
        	else return isValidBST(root->left) && isValidBST(root->right);
        }
        else if (root->right != NULL && root->left == NULL)
        {
            if(minTree(root->right) <= root->val) return false;
        	else return isValidBST(root->right);
        }
        else if(root->left != NULL && root->right == NULL)
        {
            if(maxTree(root->left) >= root->val) return false;
        	else return isValidBST(root->left);
        }
        if(root->left == NULL && root->right == NULL)
            return true;
        // cout<<minTree(root->right)<<endl;
        // return 1;
    }
};