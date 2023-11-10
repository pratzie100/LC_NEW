class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> g;
        vector<int> ans;

        for (const auto& pair : edges) {
            unordered_set<int> visited;

            stack<int> dfsStack;
            dfsStack.push(pair[0]);

            while (!dfsStack.empty()) {
                int current = dfsStack.top();
                dfsStack.pop();

                if (visited.count(current) == 0) {
                    visited.insert(current);

                    for (int neighbor : g[current]) {
                        dfsStack.push(neighbor);
                    }
                }
            }

            if (visited.count(pair[1]) != 0) {
                ans = pair;
            } else {
                g[pair[0]].push_back(pair[1]);
                g[pair[1]].push_back(pair[0]);
            }
        }

        return ans;
    }
};
