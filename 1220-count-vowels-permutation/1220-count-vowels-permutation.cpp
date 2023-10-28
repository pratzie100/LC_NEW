class Solution {
public:
    int countVowelPermutation(int n) {
        // Define a constant for modulo operation
        long mod = 1e9 + 7;
        
        // Initialize variables to keep track of counts for each vowel
        long a = 1, e = 1, i = 1, o = 1, u = 1;
        long a2, e2, i2, o2, u2;
        
        // Loop from the second character (j = 2) up to the desired length 'n'
        for(int j = 2; j <= n; j++){
            // Calculate the new counts for each vowel based on the previous counts
            a2 = (e + i + u) % mod;
            e2 = (a + i) % mod;
            i2 = (e + o) % mod;
            o2 = (i) % mod;
            u2 = (i + o) % mod;
            
            // Update the counts for the next iteration
            a = a2, e = e2, i = i2, o = o2, u = u2;
        }
        
        // Calculate the sum of all counts for each vowel and take the modulo operation
        return (a + e + i + o + u) % mod;   
    }
};
