class Solution {
public:
      #define ll long long
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        vector<ll>ans;
        unordered_map<ll,ll>m;
        multiset<ll>ms;
        for(int i=0;i<nums.size();i++)
        {
            ll prev=m[nums[i]];
            if(prev>0)ms.erase(ms.find(prev));
            m[nums[i]]+=freq[i];
            if(m[nums[i]]>0) ms.insert(m[nums[i]]);
            if(ms.empty()){ans.push_back(0);continue;}
            ans.push_back(*ms.rbegin());      
        }
        return ans;
    }
};

