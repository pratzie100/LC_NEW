class Solution {
public:
    int poorPigs(int totalBuckets, int minutesToDie, int minutesToTest) {
        // Calculate how many test intervals can be conducted within the total time.
        int testIntervals = minutesToTest / minutesToDie;
        
        // Calculate the number of buckets that can be detected in each test interval.
        int bucketsDetectedPerInterval = testIntervals + 1;
        
        // Calculate the minimum number of pigs needed to determine the poisonous bucket.
        // Use logarithmic approach to find the minimum number of pigs.
        int minPigsNeeded = ceil(log2(totalBuckets) / log2(bucketsDetectedPerInterval));
        
        return minPigsNeeded;
    }
};
