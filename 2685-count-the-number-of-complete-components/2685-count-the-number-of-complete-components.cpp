class Solution {
public:
    int z=0;
    vector<int>dd;
    void dfs(int node,vector<vector<int>>&g,unordered_set<int>&visited)
    {
        visited.insert(node);
        z++;
        dd.push_back(g[node].size());
        for(int x:g[node])
        {
            if(visited.find(x)==visited.end())
            {
                visited.insert(x);
                dfs(x,g,visited);
            }
        }
        
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>g;
        g.resize(n);
        for(int i=0;i<edges.size();i++)
        {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_set<int>visited;
        int x=0;
        for(int i=0;i<n;i++)
        {
            if(visited.find(i)==visited.end())
            {
                z=0;
                dd.clear();
                dfs(i,g,visited);
                // bool ccc=true;
                // for(int f:visited)
                // {
                //     if(g[f].size()!=z-1)
                //         ccc=false;
                //     //visited.erase(f);
                // }
                // if(ccc) x++;
                unordered_set<int>de(begin(dd),end(dd));
                if(de.size()==1 && dd[0]==z-1) x++;
                
            }
        }
        return x;
    }
};