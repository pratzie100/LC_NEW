class Solution {
public:
    int func(int mid,vector<int>&nums)
    {
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=mid)
                count++;
        }
        return count;
    }
    int specialArray(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int maxi=*max_element(begin(nums),end(nums));
        int low=0;
        int high=maxi;
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(func(mid,nums)==mid)
            {
                return mid;
            }
            else if(func(mid,nums)<mid) //look for better answer on left as smaller one will have better chance EX [3,5,6,7,8]
            {
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return -1;
    }
};