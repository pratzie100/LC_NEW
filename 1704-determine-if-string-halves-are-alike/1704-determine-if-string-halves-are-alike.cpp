class Solution {
public:
    bool halvesAreAlike(string s) {
        string s1="";
        string s2="";
        for(int i=0;i<s.size();i++)
        {
            if(i<s.size()/2) s1+=s[i];
            else s2+=s[i];
        }
        if(vowelcount(s1)==vowelcount(s2)) return true;
        return false;
    }
    int vowelcount(string s)
    {
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' ||s[i]=='A' ||s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U') count++;
        }
        return count;
    }
};