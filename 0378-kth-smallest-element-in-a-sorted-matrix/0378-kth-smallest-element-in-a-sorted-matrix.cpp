class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        multiset<int>s;
        int m=mat.size(),n=mat[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                s.insert(mat[i][j]);
            }
        }
        int c=1;
        for(auto it=begin(s);it!=end(s);it++)
        {
            int x=*it;
            if(c==k) return *it;
            c++;
        }
        return -1;
    }
};