class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        unordered_map<char,int>m;
        for(int i=0;i<4;i+=2)
        {
            m[s1[i]]++;
            m[s2[i]]--;
        }
        for(auto i:m)
        {
            if(i.second!=0) return false;
        }
        for(int j=1;j<4;j+=2)
        {
            m[s1[j]]++;
            m[s2[j]]--;
        }
        for(auto i:m)
        {
            if(i.second!=0) return false;
        }
        return true;

    }
};