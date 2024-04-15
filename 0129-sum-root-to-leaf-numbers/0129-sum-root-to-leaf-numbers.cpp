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
    void f(TreeNode* root,string s,int&ans)
    {
        if(!root->left&&!root->right){ans+=stoi(s);return;}
        if(root->left) f(root->left,s+to_string(root->left->val),ans);
        if(root->right) f(root->right,s+to_string(root->right->val),ans);
    }
    int sumNumbers(TreeNode* root) {
        if(!root)return 0;
        int ans=0;
        f(root,to_string(root->val),ans);
        return ans;
    }
};