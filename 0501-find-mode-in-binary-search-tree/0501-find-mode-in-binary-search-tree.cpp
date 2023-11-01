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
    int currStreak = 0;
    int currNum = -1;
    int maxStreak = 0;
    vector<int> ans;
    void inorder(TreeNode *root) 
    {
        if(!root) return;
        
        inorder(root->left);
        
        if(root->val==currNum) currStreak++; 
        else 
        {
            currStreak = 1;
            currNum = root->val;
        }
        if(currStreak==maxStreak) ans.push_back(currNum);
        else if(currStreak>maxStreak) 
        {
            maxStreak=currStreak;
            ans={currNum};
        }
        
        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};
    // vector<int>v;
    // void inorder(TreeNode* root)
    // {
    //     if(!root) return;
    //     inorder(root->left);
    //     v.push_back(root->val);
    //     inorder(root->right);
    // }
    // vector<int> findMode(TreeNode* root) {
    //     inorder(root);
    //     map<int,int>m;
    //     for(int i=0;i<v.size();i++)
    //     {
    //         m[v[i]]++;
    //     }
    //     int l=INT_MIN;
    //     for(auto i:m)
    //     {
    //         if(i.second>l)
    //         {
    //             l=i.second;
    //         }
    //     }
    //     vector<int>ans;
    //     for(auto i:m)
    //     {
    //         if(i.second==l)
    //         {
    //             ans.push_back(i.first);
    //         }
    //     }
    //     return ans;
    // }
