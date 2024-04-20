class Solution {
public:
    void bfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>& land,int &maxr,int &maxc)
    {
        int dx[]={0,1,-1,0};
        int dy[]={1,0,0,-1};

        queue<pair<int,int>>q;

        maxr=i,maxc=j;

        q.push({i,j});
        vis[i][j]=1;
       
        while(!q.empty())
        {
            auto curr=q.front();
            q.pop();

            int r=curr.first;
            int c=curr.second;
           
            for(int i=0;i<4;i++)
            {
                int nr=r+dx[i];
                int nc=c+dy[i];

            if(nr < land.size() and nr >=0 and nc >=0 and nc < land[0].size()  and land[nr][nc]==1 and vis[nr][nc]==0)
            {
                    maxr=nr;
                    maxc=nc;
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }

        }
       
        
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>ans;
        int m=land.size();
        int n=land[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==0 and land[i][j]==1)
                {
                    
                    int sr=i,sc=j,maxr=0,maxc=0;
                    bfs(i,j,vis,land,maxr,maxc);
                    ans.push_back({sr,sc,maxr,maxc});
                }
            }
        }
        return ans;
    }
};