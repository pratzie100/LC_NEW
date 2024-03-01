class Solution {
public:
    string maximumOddBinaryNumber(string s) {
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