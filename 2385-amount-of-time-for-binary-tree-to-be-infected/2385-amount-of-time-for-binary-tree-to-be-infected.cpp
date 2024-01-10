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
    void childParent(map<TreeNode*,TreeNode*>& mp, TreeNode* root, TreeNode*parent, TreeNode* & startNode, int start){
        if(root==NULL)return;
        mp[root]=parent;
        if(root->val==start)startNode=root;
        childParent(mp,root->left,root, startNode, start);
        childParent(mp,root->right,root, startNode, start);
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> mp;    // child parent mapping
        TreeNode* startNode=NULL;
        childParent(mp,root,NULL,startNode,start);
        queue<pair<int,TreeNode*>> q;
        vector<int> vis(1e6,0);
        q.push({0,startNode});
        int ans=0;


        while(!q.empty()){
            int time=q.front().first;
            TreeNode* node=q.front().second;
            q.pop();
            vis[node->val]=1;
            ans=max(ans,time);
            if(node->left && vis[node->left->val]!=1 ){
                q.push({time+1, node->left});
            }
            if(node->right && vis[node->right->val]!=1 ){
                q.push({time+1, node->right});
            }
            if(mp[node] && vis[mp[node]->val]!=1){
                q.push({time+1, mp[node]});
            }
        }
        return ans;
    }
};