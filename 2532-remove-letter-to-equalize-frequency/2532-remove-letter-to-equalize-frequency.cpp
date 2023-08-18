class Solution {
public:
    bool check(int ind,string str)
    {
        str.erase(ind,1);
        unordered_map<int,int>m;
        for(int i=0;i<str.size();i++)
        {
            m[str[i]]++;
        }
        for(int i=1;i<str.size();i++)
        {
            if(m[str[i]]!=m[str[i-1]]) return false;
        }
        return true;
    }
    bool equalFrequency(string word) {
        for(int i=0;i<word.size();i++)
        {
            if(check(i,word))
                return true;
        }
        return false;
    }
};