class Solution {
public:
    bool f(char c)
    {
        return c=='a' ||c=='e' ||c=='i' ||c=='o' || c=='u' ||c=='A' ||c=='E' ||c=='I' ||c=='O' ||c=='U';
    }
    bool halvesAreAlike(string s) {
        int o=0,t=0,n=s.size();
        for(int i=0;i<n;i++)
        {
            if(i<n/2 && f(s[i]))
                o++;
            if(i>=n/2 && f(s[i]))
                t++;
        }
        return o==t;
    }
};