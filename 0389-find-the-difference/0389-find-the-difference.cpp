class Solution {
public:
    char findTheDifference(string s, string t) {
        int x=0;
        int y=0;
        for(char c:s)
        {
            x+=int(c);
        }
        for(char c:t)
        {
            y+=int(c);
        }
        return char(y-x);

    }
};