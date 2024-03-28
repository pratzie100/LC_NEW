class Solution {
public:
    #define ll long long
    ll f(vector<int>&b,ll m)
    {
        ll ans=0;
        int n=b.size();
        //int c=0;
        for(int i=n-1;i>=0;i--)
        {
            ans+=(1ll*b[i]*be(10,i+1-n,m));
            //ans+=(1ll*b[i]*)))%m;
        }
        return ans;
    }
    ll be(ll a,ll b,ll m)
    {
       // ll res=1;
       if(b==0) return 1;
        ll x= be(a,b/2,m);
        if(b&1)return (1ll*a*(1ll*x*x)%m)%m;
        else return (1ll*x*x)%m;
    }
    int superPow(int a, vector<int>& b) {
        ll exp=f(b,1140); 
        return be(a,exp,1337);       
    }
};