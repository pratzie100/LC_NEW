class Solution {
public:
    vector<vector<int>> moves{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    const int MOD = 1e9 + 7;

    int dfs(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid) {
        if (dp[i][j] != -1) return dp[i][j];

        int paths = 1; //current cell is always included
        for (auto& move : moves) 
        {
            int newi = i + move[0];
            int newj = j + move[1];
            if (newi >= 0 && newi < grid.size() && newj >= 0 && newj < grid[0].size() &&
                grid[newi][newj] > grid[i][j]) 
            {
                paths = (paths + dfs(newi, newj, dp, grid)) % MOD;
            }
        }
        return dp[i][j] = (paths) % MOD; 
    }

    int countPaths(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int totalPaths = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                totalPaths = (totalPaths + dfs(i, j, dp, grid)) % MOD;
            }
        }
        return totalPaths;
    }
};