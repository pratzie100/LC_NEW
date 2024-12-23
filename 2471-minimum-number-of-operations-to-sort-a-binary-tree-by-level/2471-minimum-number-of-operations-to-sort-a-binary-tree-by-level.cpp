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
    int minimumOperations(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return 0;

        queue<TreeNode*> q;
        q.push(root);

        // Perform level-order traversal and store each level in ans
        while (!q.empty()) {
            int n = q.size();
            vector<int> row(n);
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                row[i] = node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ans.push_back(row);
        }

        int totalOperations = 0;

        // Process each level
        for (auto& level : ans) {
            int n = level.size();
            vector<int> sortedLevel = level; 
            sort(sortedLevel.begin(), sortedLevel.end());
            for (int i = 0; i < n; i++) {
                if (level[i] != sortedLevel[i]) {
                    int idx = find(begin(level) + i, end(level), sortedLevel[i])-begin(level);
                    swap(level[i], level[idx]);
                    totalOperations++;
                }
            }
        }
        return totalOperations;
    }
};
