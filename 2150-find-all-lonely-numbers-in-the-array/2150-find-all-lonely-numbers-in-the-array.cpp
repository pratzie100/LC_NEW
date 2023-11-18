class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int>m;
        unordered_set<int>z;
        for(int i=0;i<nums.size();i++)
        {
            z.insert(nums[i]);
            m[nums[i]]++;
        }
        vector<int>v;
        for(auto i:m)
        {
            if(i.second==1)
                v.push_back(i.first);
        }
        vector<int>ans;
        for(int i=0;i<v.size();i++)
        {
            if(z.find(v[i]-1)==z.end() && z.find(v[i]+1)==z.end())
            {
                ans.push_back(v[i]);
            }
        }
        return ans;
    }
};