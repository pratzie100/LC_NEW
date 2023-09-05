class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,vector<int>>m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]].push_back(i);
        }
        int cc;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it=m.begin();it!=m.end();it++)
        {
            vector<int>v=it->second;
            if(v.size()>=2)
            {
                pq.push(v[1]);
            }
        }
        cc=pq.top();
        for(auto it=m.begin();it!=m.end();it++)
        {
            vector<int>v=it->second;
            if(v.size()>=2)
            {
                if(v[1]==cc) return it->first;
            }
        }
        return 'a';
    }
};