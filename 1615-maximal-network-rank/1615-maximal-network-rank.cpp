class Solution {
public:
// Suppose you have two cities A and B. City A has 3 roads directly connected to it and city B has 2 roads directly connected to it. We have to find the network rank of two cities which is the sum of number of roads connected to city A and city B.
// If city A and city B are directly connected then reduce the network rank by 1 else do nothing. If A and B are directly connected then network rank is 3 + 2 - 1. If they are not connected then network rank is 3+2.
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>>graph(n);
        for(auto road: roads) 
        {
            int a=road[0];
            int b=road[1];
            graph[a].insert(b);
            graph[b].insert(a);
        }
        int res = INT_MIN;
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (i == j) continue;
                int a = graph[i].size();
                int b = graph[j].size();

                if(graph[i].count(j)) res=max(res, a + b - 1);
                else res = max(res, a + b);
            }
        }
        return res;
    }
};