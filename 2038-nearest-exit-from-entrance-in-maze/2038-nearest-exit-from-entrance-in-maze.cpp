class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        vector<vector<int>>moves{{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>>q;
        int starti=entrance[0];
        int startj=entrance[1];
        q.push({starti,startj});
        visited[starti][startj]=true;
        int steps=0;
        while(!q.empty())
        {
            int qsize=q.size();
            for(int size=0;size < qsize;size++)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if((i!=starti||j!=startj)&&(i==0||i==m-1||j==0||j==n-1))
                {
                    return steps;
                }
                for(const vector<int>&move:moves)
                {
                    int newi=i+move[0];
                    int newj=j+move[1];
                    if(newi>=0 && newi<=m-1 && newj>=0 && newj<=n-1 && maze[newi][newj]=='.' && !visited[newi][newj])
                    {
                        q.push({newi,newj});
                        visited[newi][newj]=true;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
