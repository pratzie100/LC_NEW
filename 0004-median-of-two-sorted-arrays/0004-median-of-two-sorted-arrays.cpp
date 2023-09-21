class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged(nums1.size()+nums2.size());
        merge(begin(nums1),end(nums1),begin(nums2),end(nums2),begin(merged));
        int k=merged.size();
        if(k%2==0)
        {
            return(double(merged[k/2]+merged[k/2-1])/2);
        }
        else
            return(merged[k/2]);
    }
};