class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            int y=__builtin_popcount(i);
            if(y==k) sum+=nums[i];
        }
        return sum;
        
    }
};