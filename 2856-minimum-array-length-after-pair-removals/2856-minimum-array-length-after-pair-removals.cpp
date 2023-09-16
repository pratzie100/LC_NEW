class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        // map<int,int>m;
        // for(int i=0;i<nums.size();i++)
        // {
        //     m[nums[i]]++;
        // }
        // int maxi=-1;
        // for(auto i:m)
        // {
        //     maxi=max(maxi,i.second);
        // }
        // int ans=2*maxi-nums.size();
        // if(ans<0) return nums.size()&1;
        // else return ans;

        int n=nums.size();
        int count=0;
        int left=0; //start index
        int right=(n+1)/2; //middle index
        
        while(left<n/2 && right<n) 
        {
            if(nums[left]<nums[right]) 
            {
                nums[left]=0;
                nums[right]=0;
            }
            left++;
            right++;
        }
        for(int x:nums) 
        {
            if(x==0) count++;
        }
        return nums.size()-count;
    }
};