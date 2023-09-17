class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(nums);
        sort(begin(v),end(v));
        if(nums==v) return 0;
        for(int shift=0; shift<n;shift++) 
        {
            rotate(nums.rbegin(), nums.rbegin()+1, nums.rend());
            if(nums==v) return shift+1;
        }   
        return -1; 
    }
};