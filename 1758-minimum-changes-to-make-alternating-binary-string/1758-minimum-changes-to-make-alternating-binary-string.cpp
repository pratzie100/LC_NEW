class Solution {
public:
    int minOperations(string s) {
        int zero_one=0;
        int one_zero=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            int x=i%2;
            int y=(i%2==0);
            if(s[i]-'0'!=x) zero_one++;
            else if(s[i]-'0'!=y) one_zero++;
        }
        int ans=min(zero_one,one_zero);
        return ans;
    }
};