class Solution {
public:
    int f(int mid,vector<int>arr)
    {
        int c=0;
        for(int i:arr)
        {
            if(i<mid) c++;
        }
        return c;
    }
    int findDuplicate(vector<int>& nums) {
        // while(nums[0]!=nums[nums[0]])
        // {
        //     swap(nums[0],nums[nums[0]]);
        // }
        // return nums[0];
        
        // map<int,int>m;
        // for(int i=0;i<nums.size();i++)
        // {
        //     m[nums[i]]++;
        // }
        // for(auto i:m)
        // {
        //     if(i.second>1) return i.first;
        // }
        // return -1;
    
        int n=nums.size();
        int l=0;
        int h=n-1;
        while(l<h)
        {
            int mid=l+(h-l)/2;
            int c=f(mid+1,nums);
            if(c<mid+1) l=mid+1;
            else h=mid;
        }
        return l;
    }
    //[7,3,2,4,1,5,7,6]
};