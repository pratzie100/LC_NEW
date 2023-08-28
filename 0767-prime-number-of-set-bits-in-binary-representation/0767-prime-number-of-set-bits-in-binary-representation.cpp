class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        //2^20 is 1,048,576
        //so according to constraint max setbits will be 19
        unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
        int count = 0;
        for(int i = left; i <= right; i++) 
        {
            int setBits = __builtin_popcount(i); 
            if(primes.find(setBits) != primes.end()) 
            {
                count++;
            }
        }
        return count;
    }
};