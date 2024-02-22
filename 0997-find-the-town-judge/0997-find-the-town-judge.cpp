class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_set<int>s;
        unordered_map<int,vector<int>>m;
        for(vector<int>v:trust)
        {
            s.insert(v[0]);
            m[v[1]].push_back(v[0]);
        }
        for(int i=1;i<=n;i++)
        {
            if(!s.count(i) && m[i].size()==n-1) return i;
        }
        return -1;
    }
};