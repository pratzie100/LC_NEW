class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int>m;
        vector<int>ans;
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(j<k-1)
            {
                m[nums[i]]++;
                j++;
            }
            else
            {
                m[nums[i]]++;
                auto it=m.end();it--;
                //auto it=m.rbegin();
                ans.push_back(it->first);
                m[nums[i-k+1]]--;
                if(m[nums[i-k+1]]==0) m.erase(nums[i-k+1]);
            }
        }
        return ans;
    }
};