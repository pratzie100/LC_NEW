class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans[i][j]=mat[j][i];
            }
        }
        return ans;
    }
};