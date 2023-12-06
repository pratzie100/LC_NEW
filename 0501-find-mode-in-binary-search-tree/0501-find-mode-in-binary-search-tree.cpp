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
    vector<int>ans;
    void inorder(TreeNode* root)
    {
        if(!root) return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        unordered_map<int,int>m;
        for(int i=0;i<ans.size();i++)
        {
            m[ans[i]]++;
        }
        int maxi=INT_MIN;
        for(auto i:m)
        {
            maxi=max(maxi,i.second);
        }
        vector<int>x;
        for(auto i:m)
        {
            if(i.second==maxi)
                x.push_back(i.first);
        }
        return x;
    }
};