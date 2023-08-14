class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // multiset<int>s;
        // s.insert(begin(nums),end(nums));
        // auto it=s.rbegin();
        // advance(it,k-1);
        // return *it;


        sort(nums.begin(),nums.end());
        return(nums[nums.size()-k]);
    }
};