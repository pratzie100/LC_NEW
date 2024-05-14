#include <vector>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
            return 0;
        
        int gold = grid[i][j];
        grid[i][j] = 0;  //visited
        int up = dfs(grid, i - 1, j);
        int down = dfs(grid, i + 1, j);
        int left = dfs(grid, i, j - 1);
        int right = dfs(grid, i, j + 1);
        grid[i][j] = gold; // Backtrack/Restore
        return gold + max({up, down, left, right});
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxGold = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) {
                    maxGold = max(maxGold, dfs(grid, i, j));
                }
            }
        }
        return maxGold;
    }
};
