class Solution {
public:
    bool isPowerOfTwo(int n) {
    //     if(n<=0) return false;
    //     long long x=n;
    //     long long k=0;
    //    // 10000
    //     while(n!=1)
    //     {
    //         cout<<n<<endl;
    //         n>>=1;
    //         k++;
    //     }
    //     return pow(2,k)==x;
        
        long long num=n;
        return num && (num & (num-1))==0;
    }
};