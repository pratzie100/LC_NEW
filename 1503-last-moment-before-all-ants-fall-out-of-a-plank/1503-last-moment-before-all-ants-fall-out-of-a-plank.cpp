class Solution {
public:

int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // An ant walking left, will take (index) time to fall off.
        // Example, n = 4
        // _ _ _ X (index 3)
        // _ _ X _ 
        // _ X _ _ 
        // X _ _ _ (it took index = 3 iterations)!

        // An ant walking right, will take: (n - index) time to to fall off.
        // Example, n = 4
        // X _ _ _ (index 0)
        // _ X _ _ 
        // _ _ X _ 
        // _ _ _ X (it took 3 - 0 = 3 iterations!)
    

        int ans = 0;

        for (int antIndex : left) {
            ans = max(ans, antIndex);
        }
        
        for (int antIndex : right) {
            ans = max(ans, n - antIndex);
        }

        return ans;
    }
};