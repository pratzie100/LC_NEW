class Solution {
public:
    vector<int> countBits(int n) {
        //Method 1
        // vector<int> ans;
        // for(int i=0;i<=n;i++)
        // {
        //     int sum=0;
        //     int num=i;
        //     while(num>0)
        //     {
        //         // sum+=num%2;
        //         // num=num/2;
        //         sum+=num&1;
        //         num>>=1;
        //     }
        //     ans.push_back(sum);
        // }
        // return ans;

        //Method 2
        // vector<int> ans;
        // for(int i=0;i<=n;i++)
        //     ans.push_back(__builtin_popcount(i));
        // return ans;

        //Method 3
        vector<int> dp(n+1);
        dp[0]=0;
        //no. of ones = no. of ones without lsb(right shift) + lsb
        for(int i = 1; i<=n; i++)
        {
            dp[i] = dp[i/2] + i%2;
        }
         return dp;

    }
};