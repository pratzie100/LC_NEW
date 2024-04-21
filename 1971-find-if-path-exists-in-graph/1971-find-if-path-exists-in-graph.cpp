class Solution {
public:
    void dfs(int u,vector<vector<int>>&g,vector<int>&visited){
        visited[u]=1;
        for(int v:g[u])
        {
            if(!visited[v])
            {
                dfs(v,g,visited);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>g(n);
        vector<int>visited(n,0);
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }   
        dfs(source,g,visited);
        return visited[destination]==1;
    }
};
