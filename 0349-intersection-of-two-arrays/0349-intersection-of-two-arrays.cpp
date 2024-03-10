class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s; //this is better than set (nlogn)
        unordered_set<int>s_one;
        s.insert(begin(nums1),end(nums1));
        s_one.insert(begin(nums2),end(nums2));
        vector<int>ans;
        for(int i:s_one)
        {
            if(s.count(i)>0)
                ans.push_back(i);
        }
        return ans;
    }
};