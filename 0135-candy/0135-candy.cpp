class Solution {
public:
    int candy(vector<int>& nums) {
        int n=nums.size();
        vector<int>l(n,1); 
        vector<int>r(n,1);
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1]) //compare with left child
            {
                l[i]=l[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>nums[i+1])  //compare with right child
            {
                r[i]=r[i+1]+1;
            }
        }
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=max(l[i],r[i]);
        }
        return ans;
    }
};