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
class FindElements {
public:
    TreeNode* rt;
    FindElements(TreeNode* root) {
        rt=root;
        recover(rt,0);
    }
    void recover(TreeNode* node, int val) {
        if(node==NULL) return;
        node->val = val; // Recover the current node's value
        recover(node->left, 2*val+1); // Recover left subtree
        recover(node->right, 2*val+2); // Recover right subtree
    }

    bool flag;
    bool find(int target) {
        flag=false; //reset flag before each search
        preorder(rt,target);
        return flag;
    }
    void preorder(TreeNode* root,int target)
    {
        if(root==NULL) return;
        if(root->val==target) 
        {
            flag=true; 
            return;
        }
        preorder(root->left,target);
        preorder(root->right,target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */