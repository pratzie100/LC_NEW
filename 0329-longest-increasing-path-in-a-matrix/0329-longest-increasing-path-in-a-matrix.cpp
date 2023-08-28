class Solution {
public:
    vector<vector<int>> moves{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dfs(int i, int j, vector<vector<int>>& dp,vector<vector<int>>& mat) {
        if(dp[i][j] != -1) return dp[i][j];

        int maxPath = 1;
        for(auto& move : moves) 
        {
            int newi = i + move[0];
            int newj = j + move[1];
            if(newi>=0 && newi<mat.size() && newj>=0 && newj<mat[0].size()&& mat[newi][newj] > mat[i][j]) 
            {
                maxPath = max(maxPath, 1 + dfs(newi,newj,dp,mat));
            }
        }
        return dp[i][j] = maxPath;
    }

    int longestIncreasingPath(vector<vector<int>>& mat) {
        if (mat.empty()) return 0;
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        int maxLength = 0;
        for(int i=0;i<m; i++) 
        {
            for(int j=0;j<n;j++) 
            {
                maxLength = max(maxLength, dfs(i,j,dp,mat));
            }
        }
        return maxLength;
    }
};