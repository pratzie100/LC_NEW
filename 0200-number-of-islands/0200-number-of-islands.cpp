class Solution {
public:
    void dfs(int i,int j,int m,int n,vector<vector<char>>&grid,vector<vector<bool>>&visited,vector<vector<int>>&moves){
        visited[i][j]=true;
        for(int k=0;k<4;k++){
            int newi=i+moves[k][0];
            int newj=j+moves[k][1];
            if(newi>=0 && newi<m && newj>=0 && newj<n && !visited[newi][newj] && grid[newi][newj]=='1'){
                dfs(newi,newj,m,n,grid,visited, moves);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<bool>>visited(m,vector<bool>(n,0));
        vector<vector<int>>moves{{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(i,j,m,n,grid,visited,moves);
                }
            }
        }
        return count;
    }
};