class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& nums) {
        // int count=0;
        // int n=nums.size();
        // for(int i=0;i<n-1;i++)
        // {
        //     for(int j=i+1;j<n;j++)
        //     {
        //         if((nums[i]+nums[j])%60==0)
        //         {
        //             count++;
        //         }
        //     }
        // }
        // return count;


//      (a + b) % K = 0
//  =>    a%K + b%K = 0
//  =>    a%K + b%K = K%K
//  =>    b%K = K%K - a%K
//  =>     b%K = (K - a%K) % K.     {Range of a%K => [0,K-1]}
// The idea is a can be paired with (K — a%K) % K. Now we have to find the same for each a present in the given array.


        // vector<int>v(60,0);
        // int ans=0;
        // for(int i=0;i<nums.size();i++)
        // {
        //     int rem=nums[i]%60;
        //     ans+=v[(60-rem)%60];
        //     v[rem]++;
        // }
        // return ans;
        
        unordered_map<int, int>m;
        int cnt = 0;
        for(int i=0;i<nums.size();i++) 
        {
            int rem=nums[i]%60;
            if(rem == 0) cnt += m[0];
            else cnt += m[60 - rem];
            m[rem]++;
        }
        return cnt;
    }
};