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
    vector<TreeNode*> allPossibleFBT(int n) {
        // Base case: If 'n' is 1, return a tree with a single node
        if (n == 1) 
        {
            return {new TreeNode(0)}; //Create single-node tree with value 0 and return
        }
        vector<TreeNode*> temp;  // Vector to store generated trees
        
        // Loop to partition 'n' nodes into left and right subtrees
        for(int i = 2; i < n; i++) 
        {
            // Generate all possible left subtrees with 'i - 1' nodes
            vector<TreeNode*> l = allPossibleFBT(i - 1);
            // Generate all possible right subtrees with 'n - i' nodes
            vector<TreeNode*> r = allPossibleFBT(n - i);
            // For each combination of l[j] (left subtree) and r[k] (right subtree), a new TreeNode is created. This TreeNode will serve as the root of the new full binary tree you're constructing.
            for (int j = 0; j < l.size(); j++) 
            {
                for (int k = 0; k < r.size(); k++) 
                {
                    TreeNode* root = new TreeNode(0);  // Create a new root node
                    root->left = l[j];  // Attach the left subtree
                    root->right = r[k];  // Attach the right subtree
                    temp.push_back(root);  // Add the generated tree to the vector
                }
            }
        }   
        return temp;  // Return the vector containing all generated trees
    }
};