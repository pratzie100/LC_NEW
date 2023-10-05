class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        vector<int>ans;
        for(auto i:m)
        {
            if(i.second>floor(n/3.0))
                ans.push_back(i.first);
        }
        return ans;
    }
};