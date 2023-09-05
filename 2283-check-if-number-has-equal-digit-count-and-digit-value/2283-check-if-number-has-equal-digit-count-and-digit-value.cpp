class Solution {
public:
    bool digitCount(string num) {
        bool ans=true;
        map<int,int>m;
        for(char c:num)
        {
            m[c-'0']++;
        }
        for(int i=0;i<num.size();i++)
        {
            if(!(m[i]==num[i]-'0')) return false;
        }
        return ans;
    }
};