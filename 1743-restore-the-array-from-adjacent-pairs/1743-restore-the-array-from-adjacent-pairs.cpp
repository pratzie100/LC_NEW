class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>>g;
        
        // Build the graph
        for(const auto& pair:adjacentPairs)
        {
            g[pair[0]].push_back(pair[1]);
            g[pair[1]].push_back(pair[0]);
        }
        
        // Find first element (it will only appear once in adjacentPairs)
        int start;
        for(const auto& entry:g)
        {
            if(entry.second.size()==1)
            {
                start=entry.first;
                break;
            }
        }
        
        // DFS to reconstruct the array
        unordered_set<int>vis;
        stack<int>dfsStack;
        dfsStack.push(start);
        vector<int>ans;
        while(!dfsStack.empty())
        {
            int current=dfsStack.top();
            dfsStack.pop();
            if(vis.count(current)==0)
            {
                vis.insert(current);
                ans.push_back(current);
                for(const auto& x: g[current])
                {
                    dfsStack.push(x);
                }
            }
        }
        return ans;
    }
};