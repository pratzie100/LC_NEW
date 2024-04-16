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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode*newroot=new TreeNode(val);
            newroot->left=root;
            return newroot;
        }
        queue<TreeNode*>q;
        int c=1;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            if(c==depth-1)
            {
                for(int i=0;i<n;i++)
                {
                    TreeNode*curr=q.front();
                    q.pop();
                    TreeNode*newl=new TreeNode(val);
                    TreeNode*newr=new TreeNode(val);
                    newl->left=curr->left;
                    newr->right=curr->right;
                    curr->left=newl;
                    curr->right=newr;
                }
                break;
            }
            else
            {
                for(int i=0;i<n;i++)
                {
                    TreeNode*curr=q.front();
                    q.pop();
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
                c++;
            }
        }
        return root;
    }
};