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
    TreeNode* createBinaryTree(vector<vector<int>>& vect) {
        unordered_set<int>s; 
        for(auto i:vect)
        {
            s.insert(i[0]); //add parent
            s.insert(i[1]); //add child
        }
        for(auto i:vect)
        {
            if(s.count(i[1])) 
            {
                s.erase(i[1]); //remove child if present
            }
        }
        int root=*(s.begin()); //root of required tree

        //making node for every distinct value 
        unordered_map<int,TreeNode*>m;
        for(auto i:vect)
        {
            if(m.find(i[0])==m.end()) m[i[0]]=new TreeNode(i[0]);
            if(m.find(i[1])==m.end()) m[i[1]]=new TreeNode(i[1]);
        }
        for(auto i:vect)
        {
            int parent=i[0];
            int child=i[1];
            int isLeft=i[2];
            if(isLeft)
                m[parent]->left=m[child];
            else
                m[parent]->right=m[child];
        }
        return m[root];
    }
};