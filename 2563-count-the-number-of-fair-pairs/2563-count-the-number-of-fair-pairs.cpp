class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // int n=nums.size();
        // long long c=0;
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         long long x=nums[i]+nums[j];
        //         if(x>=lower && x<=upper){
        //             c++;
        //         }
        //     }
        // }
        // return c;

        sort(begin(nums),end(nums));
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            // Use lower_bound to find the first j where nums[i] + nums[j] >= lower
            int jlow=lower_bound(begin(nums)+i+1,end(nums),lower-nums[i])-begin(nums);
            // Use upper_bound to find the first j where nums[i] + nums[j] > upper,
            // meaning all previous elements satisfy nums[i] + nums[j] <= upper
            int jhigh=upper_bound(begin(nums)+i+1,end(nums),upper-nums[i])-begin(nums);
            ans+=jhigh-jlow;
        }
        return ans;

    }
};
// 0 1 4 4 5 7
 