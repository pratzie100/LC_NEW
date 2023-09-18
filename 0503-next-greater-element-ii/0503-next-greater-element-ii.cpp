class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j!=i;j=(j+1)%n)
            {
                if(nums[j]>nums[i])
                {
                    ans[i]=nums[j];
                    break;
                }
            }
        }
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>nums[n-1])
            {
                ans[n-1]=nums[i];
                break;
            }
        }
        return ans;
    }
};