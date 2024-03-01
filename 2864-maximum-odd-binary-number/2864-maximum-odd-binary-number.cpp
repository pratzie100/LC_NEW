class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        // int n=s.size();
        // map<char,int>m;
        // for(char c:s) m[c]++;
        // string ans="";
        // for(int i=0;i<n-1;i++) 
        // {
        //     if(m['1']>1) 
        //     {
        //         ans+='1';
        //         m['1']--;
        //     } 
        //     else if(m['0']>=1) 
        //     {
        //         ans+='0';
        //         m['0']--;
        //     }
        // }
        // ans+='1';
        // return ans;
        multiset<char>m(begin(s),end(s));
        if(m.count('1')==1)
        {
            string s(m.count('0'),'0');
            s+='1';
            return s;
        }
        else
        {
            string x(m.count('1')-1,'1');
            string y(m.count('0'),'0');
            string ans=x+y+'1';
            return ans;
        }
        return "";
    }
};