class Solution {
public:
    //Check if characters at even and odd indices in both strings match.(same as 2839)
    bool checkStrings(string s1, string s2) {
        unordered_map<char,int>m;
        for(int i=0;i<s1.size();i+=2)
        {
            m[s1[i]]++;
            m[s2[i]]--;
        }
        for(auto i:m)
        {
            if(i.second!=0) return false;
        }
        for(int j=1;j<s1.size();j+=2)
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