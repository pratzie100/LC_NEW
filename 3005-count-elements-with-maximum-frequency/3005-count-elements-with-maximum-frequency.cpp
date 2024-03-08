class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>m;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        int mx=0;
        for(auto i:m)
        {
            mx=max(mx,i.second);
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(m[nums[i]]==mx) c++;
        }
        return c;
    }
};