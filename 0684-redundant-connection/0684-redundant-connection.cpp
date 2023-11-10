class Solution {
public:                
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>g;
        for(const auto& pair:edges)
        {
             //using dfs, check if there is already a path from pair[0] to pair[1] before adding edge
            unordered_set<int>visited;
            stack<int>dfsStack;
            dfsStack.push(pair[0]);
            while(!dfsStack.empty())
            {
                int current=dfsStack.top();
                dfsStack.pop();
                if(visited.count(current)==0)
                {
                    visited.insert(current);
                    for(const auto&x:g[current])
                    {
                        dfsStack.push(x);
                    }
                }
            }
            if(visited.find(pair[1])!=visited.end()) //this is main check
            {  //if node pair[1] already visited during dfs then adding the current edge would create a cycle because we have found an alternative path from pair[0] to pair[1]. Therefore this edge is a redundant connection that should be removed to maintain the tree structure.
                return {pair[0],pair[1]};
                
            }
            else
            {
                g[pair[0]].push_back(pair[1]);
                g[pair[1]].push_back(pair[0]);
            }
        }
        return {};
    }
};
