class Solution {
public:

#define ll long long
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        ll sumrolls=accumulate(begin(rolls),end(rolls),0ll);
        int totalsum=((m+n)*mean);
        int remsum=totalsum-sumrolls;
        if(remsum<n || remsum>6*n) return {};
        
        vector<int>ans(n,1); //taking smallest value of n throws ,i.e, n 1's

        int remaining_sum = remsum - n; 
        for (int i = 0; i < n; i++) {
            int increment = min(5, remaining_sum);
            ans[i] += increment;
            remaining_sum -= increment;
            if (remaining_sum == 0) 
                break;
        }
        return ans;
    }
};