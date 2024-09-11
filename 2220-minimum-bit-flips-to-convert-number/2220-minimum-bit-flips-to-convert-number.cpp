class Solution {
public:
    int minBitFlips(int start, int goal) {
        //no. of digits to be considered for start and goal should be same,
        //difference in bits of two binary numbers can be marked
        // by doing xor of bits and same corresponding places
        // since 0 xor 1 = 1, 1 xor 0 = 1, so we can count minimum bits
        //difference by counting number of 1's in xor of start and goal.
        return __builtin_popcount(start^goal);
    }
};