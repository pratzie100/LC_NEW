class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        int maxl=INT_MIN;
        //int p;
        for(auto i:m)
        {
            if(i.second>maxl)
            {
                maxl=i.second;
                //p=i.first;
            }
        }
        vector<vector<int>>ans(maxl);
        m.clear();
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
            ans[m[nums[i]]-1].push_back(nums[i]);
        }
        return ans;
    }
};