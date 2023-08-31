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
    //maxi should not be taken as global as testcases like below fail
    //[2,null,4,10,8,null,null,4]
    int count=0;
    void dfs(TreeNode* root,int maxi)
    {
        if(root==NULL)return;
        maxi=max(maxi,root->val);
        if(maxi==root->val)
            count++;
        dfs(root->left,maxi);
        dfs(root->right,maxi);
    }
    //Use DFS (Depth First Search) to traverse the tree, and constantly keep track of the current path maximum.
    int goodNodes(TreeNode* root) {
        dfs(root,INT_MIN);
        return count;
    }
};