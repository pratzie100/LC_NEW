class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int count = 0; 
        string str = ""; 
        while(str.find(b) == string::npos) 
        {
            if(str.size() > a.size() + b.size()) 
            {
                return -1; // If str becomes larger than a + b, it's not possible to form b
            }
            str += a; 
            count++; 
        }
        return count;
    }
};
