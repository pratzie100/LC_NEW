class Solution {
public:
    #define ll long long
    int findComplement(int num) {
        ll dig,rem;
        ll ans=0;
        ll mul=1;
        while(num){
            rem=num%2;
            dig=1-rem;
            ans+=dig*mul;
            num/=2;
            mul*=2;
        }
        return ans;
    }
};