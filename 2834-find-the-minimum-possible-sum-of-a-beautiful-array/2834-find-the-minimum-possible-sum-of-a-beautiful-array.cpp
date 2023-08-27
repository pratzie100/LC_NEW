class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        long long sum=0;
        long long i=1;
        set<long long>s;
        while(s.size()<n)
        {
            if(s.count(target-i)==0)
            {
                sum+=i;
                s.insert(i);
            }
            i++;
        }
        return sum;
    }
};