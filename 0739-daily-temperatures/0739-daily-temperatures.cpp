class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<int>s;
        int n=nums.size();
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--)
        {
            // if(!s.empty())
            // {
            //     if(nums[s.top()]>nums[i])
            //     {
            //         ans[i]=s.top()-i;
            //     }
            // }
            while(!s.empty() && nums[s.top()]<=nums[i])
            {
                s.pop();
            }
            if(!s.empty()) ans[i]=s.top()-i;
            s.push(i);
        }
        return ans;        
    }
};