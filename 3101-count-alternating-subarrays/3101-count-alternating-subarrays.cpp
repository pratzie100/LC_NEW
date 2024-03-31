class Solution {
public:
//     You are given a binary array nums.

// We call a subarray alternating if no two adjacent elements in the subarray have the same value.

// Return the number of alternating subarrays in nums.

 

// Example 1:

// Input: nums = [0,1,1,1]

// Output: 5

// Explanation:


// The following subarrays are alternating: [0], [1], [1], [1], and [0,1].
//     Input: nums = [1,0,1,0]

// Output: 10
   // 1 1 0 0 0
    #define ll long long
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        ll ans=1;
        int l=0;
        for(int r=1;r<n;r++)
        {
            if(nums[r]==nums[r-1]) l=r;
            ans+=r-l+1;
        }
        return ans;
    }
};