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
void solve(TreeNode* root, vector<int>& path, vector<vector<int>>& v) {
    if(!root) return;
    path.push_back(root->val);
    if (!root->left && !root->right) v.push_back(path);
    solve(root->left, path, v);
    solve(root->right, path, v);
    path.pop_back(); 
}

int maxAncestorDiff(TreeNode* root) {
    vector<vector<int>> v;
    vector<int> path;
    solve(root, path, v);
    // for (vector<int>& paths : v) {
    //     for (int i = 0; i < paths.size(); i++) {
    //         cout << paths[i] << " ";
    //     }
    //     cout << endl;
    // }
    int maxi=INT_MIN;
    for(vector<int>&nums:v)
    {
        maxi=max(maxi,abs(*max_element(nums.begin(),nums.end())-*min_element(nums.begin(),nums.end())));
    }
    return maxi;
}

};