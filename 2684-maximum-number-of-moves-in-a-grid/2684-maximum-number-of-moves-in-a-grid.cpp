class Solution {
    int dfs(int i, int j, int prev, int& maxMoves,vector<vector<int>>& grid,int m, int n) {
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] <= prev) 
            return 0;
        
        int newprev = grid[i][j];
        grid[i][j] = INT_MIN;
        //calculate max length among three possible moves(in current path)
        int ans = 1 + max({dfs(i-1,j+1,newprev,maxMoves,grid,m,n), dfs(i,j+1,newprev, maxMoves,grid,m,n), dfs(i+1, j+1, newprev, maxMoves,grid,m,n)});
        
        maxMoves = max(maxMoves, ans); //stores overall answer
    
        return ans;
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        
        for (int i=0; i<m; i++) 
        {
            dfs(i,0,-1,res,grid,m,n);
        }
    
        return res-1; //without including the initial cell
    }
};
