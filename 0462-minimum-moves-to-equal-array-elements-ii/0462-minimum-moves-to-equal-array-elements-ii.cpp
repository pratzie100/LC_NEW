class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        int sum=0;
        for(int x:nums)
        {
            sum+=abs(x-nums[n/2]);
        }
        return sum;
    }
};

// 1 2 9 10

