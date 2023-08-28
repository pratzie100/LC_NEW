class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&moves,vector<vector<int>>&grid,int m,int n){
        if(i<0 || i>m-1 || j<0 || j>n-1 || grid[i][j]!=0)
            return;
        grid[i][j]=1; //mark cell visited
        for(auto&move:moves)
        {
            int newi=i+move[0];
            int newj=j+move[1];
            if(newi>=0 && newi<=m-1 && newj>=0 && newj<=n-1 && grid[newi][newj]==0)
            {
                dfs(newi,newj,moves,grid,m,n);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>moves{{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1)
                {
                    if(grid[i][j]==0)
                    {
                        dfs(i,j,moves,grid,m,n);
                    }
                }
            }
        }
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    count++;
                    dfs(i,j,moves,grid,m,n);
                }
            }
        }
        return count;
    }
};