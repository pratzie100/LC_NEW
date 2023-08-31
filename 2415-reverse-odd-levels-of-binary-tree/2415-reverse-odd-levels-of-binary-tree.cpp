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
    void dfs(TreeNode* rootL,TreeNode* rootR,int level)
    {
        if(rootL==NULL && rootR==NULL) return;
        if(level%2==1) swap(rootL->val,rootR->val);
        level++;
        dfs(rootL->left,rootR->right,level);
        dfs(rootL->right,rootR->left,level);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left,root->right,1);
        return root;
    }
};