class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string ans="";
        for(string & z:words)
        {
            ans+=z[0];
        }
        return ans==s;
    }
};