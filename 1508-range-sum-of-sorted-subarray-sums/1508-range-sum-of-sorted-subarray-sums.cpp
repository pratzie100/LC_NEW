class Solution {
public:
    int mod=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
   
    vector<int>v;
   
    for (int i = 0; i < n; ++i) {
        
        for (int j = i; j < n; ++j) {
            int s=0;

            for (int k = i; k <= j; ++k) {
                s=(s%mod)+(nums[k]%mod);
                
            }
            v.push_back(s);
          
        }
    }
        sort(begin(v),end(v));
        int ans=0;
        for(int i=left;i<=right;i++){
            ans=(ans%mod)+(v[i-1]%mod);
        }
        return ans%mod;
    }
};