class Solution {
public:
    int scoreOfString(string s) {
        int sm=0;
        int n=s.size();
        for(int i=0;i<n-1;i++)
        {
            int x=int(s[i]);
            int y=int(s[i+1]);
            sm+=abs(x-y);
        }
        return sm;
    }
};