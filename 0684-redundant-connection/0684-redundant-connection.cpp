class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>g;
        vector<int> ans;
        for(const auto& pair:edges) 
        {
            // check if there is already a path from pair[0] to pair[1] before adding edge
            // using dfs
            unordered_set<int>visited;
            stack<int>dfsStack;
            dfsStack.push(pair[0]);
            while(!dfsStack.empty()) 
            {
                int current = dfsStack.top();
                dfsStack.pop();
                if(visited.count(current)== 0) 
                {
                    visited.insert(current);
                    for (int neighbor : g[current]) 
                    {
                        dfsStack.push(neighbor);
                    }
                }
            }
            if(visited.count(pair[1]) != 0)  //this is main check 
            {
                //(if node pair[1] already visited then adding the current edge would create a cycle because we have found an alternative path from pair[0] to pair[1]. Therefore, we consider this edge as a redundant connection that should be removed to maintain the tree structure.)
                //ans = pair; 
                return {pair[0],pair[1]}; 
            } 
            else 
            {
                g[pair[0]].push_back(pair[1]);
                g[pair[1]].push_back(pair[0]);
            }
        }
        return ans; 
        
    }
};
