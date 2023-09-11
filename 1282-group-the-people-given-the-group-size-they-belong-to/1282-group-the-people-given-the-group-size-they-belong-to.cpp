class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& nums) {
        vector<vector<int>>ans;
        unordered_map<int,vector<int>>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]].push_back(i);
            if(m[nums[i]].size()==nums[i])
            {
                ans.push_back(m[nums[i]]);
                m[nums[i]].clear();
            }
        }
        return ans;
    }
};