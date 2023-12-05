class Solution {
public:
    int numberOfMatches(int n) {
        if(n%2==0)
            return (n/2*2-1);
        else
            return(((n-1)/2)*2);
    }
};