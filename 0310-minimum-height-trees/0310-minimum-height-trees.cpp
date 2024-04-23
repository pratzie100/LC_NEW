class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n);
        vector<int> ans;
        if(n==1) return {0};
        for(auto& edge : edges){
            int u = edge[0], v = edge[1];
            indegree[u]++; indegree[v]++;
            adj[u].push_back(v); adj[v].push_back(u);
        }
        queue<int> que;
        for(int i=0; i<n; i++){
            if(indegree[i]==1)
                que.push(i);
        }
        while(n>2){
            int size = que.size();
            n = n-size;
            while(size--){
                int node = que.front();
                que.pop();
                for(int &v : adj[node]){
                    indegree[v]--;
                    if(indegree[v]==1){
                        que.push(v);
                    }
                }
            }
        }
        while(!que.empty()){
            ans.push_back(que.front());
            que.pop();
        }
        return ans;
    }
};