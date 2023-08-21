class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int count = 0; // Initialize the count to 1 (at least one repetition)
        string str = ""; // Initialize str with a
        while (str.find(b) == string::npos) {
            if (str.size() > a.size() + b.size()) {
                return -1; // If str becomes larger than a + b, it's not possible to form b
            }
            str += a; // Append a to str
            count++; // Increment the count
        }
        return count;
    }
};
