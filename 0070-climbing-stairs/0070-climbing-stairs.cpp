class Solution {
public:
    //same as calculating fibonaci (n+1)th term
    //no need to handle n==0 corner case due to constraints
    int climbStairs(int n) {
        int prev2=1,prev=1;
        for(int i=2;i<=n;i++)
        {
            int current=prev+prev2;
            prev2=prev;
            prev=current;
        }
        return prev;
    }
};