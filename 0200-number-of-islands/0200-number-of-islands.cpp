class Solution {
public:

    void bfs(int dr[],int dc[],vector<vector<char>>&g,vector<vector<int>>&v,int i,int j,int m,int n)
    {
        v[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int a=0;a<4;a++)
            {
                int b=x+dr[a];int c=y+dc[a];
                if(b>=0&&b<m&&c>=0&&c<n&&!v[b][c]&&g[b][c]=='1'){
                   q.push({b,c}); 
                    v[b][c]=1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
         int m=grid.size();
        int n=grid[0].size();
        int c=0;
        vector<vector<int>>v(m,vector<int>(n,0));
        int dr[]= {-1,0,1,0};
        int dc[]= {0,1,0,-1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
            {
                if(!v[i][j] && grid[i][j]=='1'){
                    c++;
                    bfs(dr,dc,grid,v,i,j,m,n);
                }
            }
        }
        return c;
    }
};