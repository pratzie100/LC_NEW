class Solution {
public:
    vector<vector<int>> moves{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int row, int col) {
        if(dp[row][col] != -1) return dp[row][col];
        
        int maxPath = 1;
        for(auto& move : moves) 
        {
            int newRow = row + move[0];
            int newCol = col + move[1];
            if(newRow>=0 && newRow<matrix.size() && newCol>=0 && newCol< matrix[0].size() && matrix[newRow][newCol] > matrix[row][col]) 
            {
                maxPath = max(maxPath, 1 + dfs(matrix, dp, newRow, newCol));
            }
        }
        return dp[row][col] = maxPath;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int maxLength = 0;
        for(int i=0; i<m; i++) 
        {
            for(int j=0;j<n;j++) 
            {
                maxLength = max(maxLength, dfs(matrix, dp, i, j));
            }
        }
        return maxLength;
    }
};