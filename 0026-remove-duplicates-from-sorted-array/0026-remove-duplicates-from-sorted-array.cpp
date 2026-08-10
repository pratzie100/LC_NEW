class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 1;
        }   
        int slow=0;
        int fast=1;
        while(fast<n){
            if(nums[slow]==nums[fast]){
                fast++;
            }
            else{
                slow++;
                nums[slow]=nums[fast];
                fast++;
            }
        }
        return slow+1;
    }
};