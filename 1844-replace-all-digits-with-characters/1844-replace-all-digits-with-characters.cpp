class Solution {
public:
    char shift(char c,int x)
    {
        return c+x;
    }
    string replaceDigits(string s) {
        for(int i=0;i<s.size();i++)
        {
            if(i%2==1)
            {
               s[i]=shift(s[i-1],s[i]-'0'); 
            }
        }
        return s;
    }
};