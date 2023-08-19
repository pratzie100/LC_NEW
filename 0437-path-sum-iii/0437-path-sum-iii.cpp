/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long current(TreeNode* root,long long ts)
    {
        if(!root) return 0;
        long long tc=0;
        if(root->val==ts) tc++;
        tc+=current(root->left,ts-(root->val));
        tc+=current(root->right,ts-(root->val));
        return tc;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return pathSum(root->left,targetSum) + current(root,targetSum) + pathSum(root->right,targetSum);
    }
};