class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int>ans(k,0);
        unordered_map<int,unordered_set<int>>m;
        for(auto&log:logs)
        {
            m[log[0]].insert(log[1]);
        }
        vector<int>v;
        for(auto it=m.begin();it!=m.end();it++)
        {
            unordered_set<int>s=(it)->second;
            v.push_back(s.size());
        }
        for(int i=0;i<v.size();i++)
        {
            ans[v[i]-1]++;
        }
        return ans;
    }
};