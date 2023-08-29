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
        if(depth == 1) 
        {
            TreeNode* newroot = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int currentDepth = 1;
        while(!q.empty()) 
        {
            int size = q.size(); //nodes at current level of binary tree
            if(currentDepth!=depth-1)
            {
                for(int i=0; i<size; i++) 
                {
                    TreeNode* node = q.front();
                    q.pop();
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
                currentDepth++;
            }
            else  //main task
            {
                for(int i=0; i<size; i++) 
                {
                    TreeNode* curr = q.front();
                    q.pop();
                    
                    TreeNode* newLeft = new TreeNode(val);
                    TreeNode* newRight = new TreeNode(val);
                    
                    newLeft->left = curr->left;
                    newRight->right = curr->right;
                    
                    curr->left = newLeft;
                    curr->right = newRight;
                }
                break;
            }            
        }
        return root;
    }
};
