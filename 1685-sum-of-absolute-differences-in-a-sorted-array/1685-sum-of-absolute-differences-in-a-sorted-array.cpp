class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        //bruteforce->tle
        
        int n=nums.size();
        vector<int>ans(n);
        vector<int>ps(n+1,0);//maintain prefix sum
        vector<int>ss(n+1,0);//maintain suffix sum
        for(int i=1;i<=n;i++)
        {
            ps[i]=ps[i-1]+nums[i-1];
        }
        // for(int i:ps) cout<<i<<" ";
        cout<<endl;
        for(int i=1;i<=n;i++)
        {
            ss[i]=ss[i-1]+nums[n-i];
        }
        // for(int i:ss) cout<<i<<" ";
        for(int i=0;i<n;i++)
        {
            int leftsum=(nums[i]*i)-ps[i];
            int rightsum=ss[n-i-1]-(nums[i]*(n-i-1));
            // cout<<endl;
            // cout<<leftsum<<" "<<rightsum<<endl;
            ans[i]=leftsum+rightsum;
        }
        return ans;
    }   

};