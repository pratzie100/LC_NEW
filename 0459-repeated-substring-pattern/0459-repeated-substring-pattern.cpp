class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // return (s+s).find(s, 1) < s.size();
        string str=s+s;
        auto it = str.find(s, 1);
        if(it != string::npos) 
        {
            if (it < s.size()) 
            {
                return true;
            }
        }
        return false;
    }
};