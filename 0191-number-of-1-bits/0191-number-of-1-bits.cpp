class Solution {
public:
    int hammingWeight(uint32_t n) {
        // int count=0;
        // while(n>0)
        // {
        //     count+=n%2;
        //     n/=2;    
        // }
        // return count;
        // int count=0;
        // while(n)
        // {
        //     count+=n&1;
        //     n>>=1;
        // }
        // return count;
        //string s=to_string(n);
        
        string s = bitset<32>(n).to_string(); // Convert the unsigned integer to a binary string
        bitset<32>bit_string(s);
        return bit_string.count();
    }
};