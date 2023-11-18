class Solution {
public:
    int minMoves(vector<int>& nums) {
        // unordered_set<int>s(begin(nums),end(nums));
        // if(s.size()==1) return 0;
        //return *max_element(begin(nums),end(nums));
        sort(begin(nums),end(nums));
        int sum=0;
        for(int x:nums)
        {
            sum+=x-nums[0];
        }
        return sum;
    }
};