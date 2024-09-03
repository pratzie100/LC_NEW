class Solution {
public:
    #define ll long long
    ll sod(ll n){ 
        ll sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int getLucky(string s, int k) {
        ll x=0;
        for(char c:s){
           x+=sod(c-'a'+1);
        }
        //cout<<x<<endl;
        k--; //since we have already calculated 1st transformation by now
        ll p;
        while(k--){
            p=sod(x);
            x=p;
        }
        return p;
    }
};