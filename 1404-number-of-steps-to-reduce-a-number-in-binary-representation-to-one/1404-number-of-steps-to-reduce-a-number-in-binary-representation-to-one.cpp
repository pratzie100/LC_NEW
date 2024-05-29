class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        
        while (s != "1") {
            if (s.back() == '0') {
                // If even, remove the last character (divide by 2)
                s.pop_back();
            } else {
                // If odd, add 1 to the binary string
                int i = s.size() - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }
                if (i >= 0) {
                    s[i] = '1';
                } else { //handle 11 to 100
                    s = "1" + s;
                }
            }
            // Increment step count
            steps++;
        }
        
        return steps;
    }
};