class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool ans1=true,ans2=true;
        multiset<int>s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
            auto it=s.rbegin();
            if(*it!=nums[i]) ans1=false;
        }
        s.clear();
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
            auto it=s.begin();
            if(*it!=nums[i]) ans2=false;
        }  
        return ans1||ans2;
    }
};