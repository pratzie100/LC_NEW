class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;
        int i=0,j=0;
        for(int i=0;i<t.size();i++)
        {
            if(s[j]==t[i])
                j++;
        }
        return j==s.size();
    }
};