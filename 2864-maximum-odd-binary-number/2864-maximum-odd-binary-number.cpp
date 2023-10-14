class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.size();
        map<char,int>m;
        for(char c:s) m[c]++;
        string ans="";
        for(int i=0;i<n-1;i++) 
        {
            if(m['1']>1) 
            {
                ans+='1';
                m['1']--;
            } 
            else if(m['0']>=1) 
            {
                ans+='0';
                m['0']--;
            }
        }
        ans+='1';
        return ans;
    }
};