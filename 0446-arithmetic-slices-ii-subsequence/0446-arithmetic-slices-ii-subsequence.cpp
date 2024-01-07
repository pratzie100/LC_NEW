class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        long long i, n=a.size(), ans=0, curr, prev, diff;
        vector<unordered_map<long long, long long>> dp(n);
        for(curr=0;curr<n;curr++) {
            for(prev=0;prev<curr;prev++) {
                diff=1LL*a[curr]-1LL*a[prev];
                dp[curr][diff] += dp[prev][diff]+1;
                ans += dp[prev][diff];
            }
        }
        return int(ans);
    }
};