class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>>graph;
        // Build the graph
        for(const auto& pair : adjacentPairs) 
        {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }
        // Find the first element (it will only appear once in adjacentPairs)
        int start;
        for(const auto& entry : graph) 
        {
            if(entry.second.size()==1) 
            {
                start = entry.first;
                break;
            }
        }
        // DFS to reconstruct the array
        unordered_set<int> visited;
        stack<int> dfsStack;
        vector<int> result;
        dfsStack.push(start);
        while(!dfsStack.empty()) 
        {
            int current = dfsStack.top();
            dfsStack.pop();
            if(visited.count(current) == 0) 
            {
                visited.insert(current);
                result.push_back(current);
                for(int neighbor : graph[current]) 
                {
                    dfsStack.push(neighbor);
                }
            }
        }
        return result;
    }
};