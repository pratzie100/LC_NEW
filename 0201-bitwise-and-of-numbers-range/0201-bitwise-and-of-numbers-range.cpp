class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        int c=0;
        while(l!=r)
        {
            r>>=1;
            l>>=1;
            c++;
        }
        int x=r;
       // x=x<<c;
        return x<<c;
    }
};
// 101
// 110
// 111
//1000
// 1,10,11,100,101,110,111,1000,1001,1010,1011,1100,,