class Solution {
public:

    long long minimumSteps(string s) {
        int c=0;
        long long ans=0;
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            int x=n-1-i;
            if(s[i]=='1') {ans+=x-c; c++;}
        }
        return ans;
    }
};