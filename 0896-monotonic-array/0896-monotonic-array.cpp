class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool ans1=true,ans2=true;
        multiset<int>s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
            auto it1=s.rbegin();
            if(*it1!=nums[i]) ans1=false;
            auto it2=s.begin();
            if(*it2!=nums[i]) ans2=false;
        }
        // s.clear();
        // for(int i=0;i<nums.size();i++)
        // {
        //     s.insert(nums[i]);
        //     auto it=s.begin();
        //     if(*it!=nums[i]) ans2=false;
        // }  
        return ans1||ans2;
        
        // int pattern=0;
        // for(int i=0;i<nums.size()-1;i++)
        // {
        //     if(nums[i]<nums[i+1]) //if monotone increasing
        //     {
        //         if(pattern==0)
        //             pattern=1; //set increasing status
        //         else if(pattern==-1) // if found decreasing status in btw
        //             return false; 
        //     }
        //     else if(nums[i]>nums[i+1]) //if monotone decreasing
        //     {
        //         if(pattern==0)
        //             pattern=-1; //set decreasing status
        //         else if(pattern==1) //if found increasing status in btw
        //             return false;
        //     }
        // } //nums[i]==nums[i+1] case is always true
        // return true;
    }
};