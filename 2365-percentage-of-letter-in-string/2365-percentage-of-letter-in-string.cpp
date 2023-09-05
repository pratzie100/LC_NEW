class Solution {
public:
    int percentageLetter(string s, char letter) {
        unordered_map<int,int>m;
        for(char c:s)
        {
            m[c]++;
        }
        if(m.find(letter)!=m.end()) 
        return ((double)m[letter]/s.size())*100;
        else return 0;
    }
};