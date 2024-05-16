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
    bool evaluateTree(TreeNode* root) {
         if (root == nullptr)
        return false;

    // If the node is a leaf node, return its value
    if (root->left == nullptr && root->right == nullptr)
        return root->val;

    // Recursively evaluate left and right subtrees
    bool left_value = evaluateTree(root->left);
    bool right_value = evaluateTree(root->right);

    // Apply boolean operation based on node's value
    if (root->val == 2)  // OR operation
        return left_value || right_value;
    else if (root->val == 3)  // AND operation
        return left_value && right_value;
    
    return false; 
    }
};