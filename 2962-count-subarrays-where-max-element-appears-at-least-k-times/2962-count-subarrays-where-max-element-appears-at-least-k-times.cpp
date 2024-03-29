class Solution {
public:
    #define ll long long
    long long countSubarrays(vector<int>& nums, int k) {
        unordered_map<ll,ll>m;
        ll maxele=*max_element(begin(nums),end(nums));
       // for(ll i:nums)m[i]++;
       // if(m[maxele]<k)return 0;
        ll n=nums.size();
        ll cnt=0;
        ll l=0;
        //ll p=k;
     //   int c=0;
        for(ll r=0;r<n;r++)
        {
            m[nums[r]]++;
            //ll z=0;

            while(m[maxele]>=k)
            {
                cnt+=n-r;
                // if(nums[l]==maxele)
                // {
                //     z++;
                    m[nums[l]]--;
                    l++;
                //}
                // else
                //     l++;
            }
            // m[maxele]+=z;
            // l=0;
            //k=p;
        }
        return cnt;
    }
};