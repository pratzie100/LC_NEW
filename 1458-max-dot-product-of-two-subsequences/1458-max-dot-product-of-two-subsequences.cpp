class Solution {
public:
    int solve(int i,int j,vector<int>&nums1,vector<int>&nums2,vector<vector<int>>&dp)
    {
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==nums1.size() || j==nums2.size()) return 0;
        int use=nums1[i]*nums2[j]+solve(i+1,j+1,nums1,nums2,dp);
        return dp[i][j]=max({use,solve(i+1,j,nums1,nums2,dp),solve(i,j+1,nums1,nums2,dp)});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int maxi1=*max_element(begin(nums1),end(nums1));
        int maxi2=*max_element(begin(nums2),end(nums2));
        int mini1=*min_element(begin(nums1),end(nums1));
        int mini2=*min_element(begin(nums2),end(nums2));
        if(maxi1<0 && mini2>0) return maxi1*mini2;
        if(maxi2<0 && mini1>0) return maxi2*mini1;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,nums1,nums2,dp);
    }
};