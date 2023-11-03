class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int targetIndex = 0; // Index to track the target array.
        
        for (int i = 1; i <= n; ++i) {
            if (targetIndex == target.size()) {
                // If we have already matched the target, break out of the loop.
                break;
            }
            
            if (i == target[targetIndex]) {
                // If the current number matches the target, Push it to the stack.
                result.push_back("Push");
                targetIndex++;
            } else {
                // If the current number doesn't match the target, Push and Pop it.
                result.push_back("Push");
                result.push_back("Pop");
            }
        }
        
        return result;
    }
};
