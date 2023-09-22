class Solution {
public:
    int dfs(vector<vector<int>>& mat,int row,int col,int r,int c,     vector<vector<int>>& move){
        if(r<0 || c<0 || r>=row || c>=col || mat[r][c]==0)
            return 0;
        mat[r][c]=0; //visited
        int currentland=1;
        for(int i=0;i<move.size();i++)
        {
            currentland+=dfs(mat,row,col,r+move[i][0],c+move[i][1],move);
        }
        return currentland;
    }
    int maxAreaOfIsland(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        int maxland=0;
        // down, up, right, and left
        vector<vector<int>>move{{1,0},{-1,0},{0,1},{0,-1}};
//for 8 directions:
 // down, up, right, and left, top-left, top-right, bottom-left, and bottom-right
    // vector<vector<int>>move{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
        
        for(int r=0;r<row;r++)
        {
            for(int c=0;c<col;c++)
            {
                if(mat[r][c]==1)
                    maxland=max(maxland,dfs(mat,row,col,r,c,move));
            }
        }
        return maxland;
    }
};