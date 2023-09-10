class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<vector<int>>v;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<grid[i][j];k++) 
                    v.push_back({i,j});
            }
        }
        sort(begin(v),end(v));
        int ans = 1e9;
        do{
            int cur = 0;
            for (int i = 0; i < 9; i++) 
            {
                int curRow = v[i][0];  // Current row
                int curCol = v[i][1];  // Current column
                int targetRow = i / 3;  // Target row
                int targetCol = i % 3;  // Target column
                cur += abs(curRow - targetRow) + abs(curCol - targetCol);
            }
            ans = min(ans, cur);
        } while (next_permutation(begin(v), end(v)));
        return ans;
    }
};
