class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long sum=0;
        int k=-1;
        int n=nums.size();
        sort(begin(nums),end(nums));
        for(int i=0;i<n;i++)
        {
            //sum+=nums[i];
            if(i<2) {sum+=nums[i]; continue;}
            if(sum>nums[i]){ 
                k=i;sum+=nums[i];}
            else sum+=nums[i];
        }
        if(k==-1) return -1;
        sum=0;
        for(int i=0;i<=k;i++) sum+=nums[i];
        return sum;
    }
};
//1 1 2 3 5  12 50 