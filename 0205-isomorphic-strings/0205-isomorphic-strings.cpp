class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,unordered_set<char>>m;
        unordered_set<char>st(begin(t),end(t));
        for(int i=0;i<s.size();i++)
        {
            m[s[i]].insert(t[i]);
        }
        if(m.size()!=st.size())return false;
        for(auto i:m){
            if(i.second.size()>1)return false;
        }
        
        return true;
    }
};