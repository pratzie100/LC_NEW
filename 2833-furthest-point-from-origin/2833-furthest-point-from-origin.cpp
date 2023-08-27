class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
        int countl=0,countr=0,countd=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='L') countl++;
            else if(s[i]=='R') countr++;
            else countd++;
        }
        int countmax=max(countl,countr);
        int countmin=min(countl,countr);
        return countmax+countd-countmin;
    }
};