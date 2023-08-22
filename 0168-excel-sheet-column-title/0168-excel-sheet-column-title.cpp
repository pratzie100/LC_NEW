class Solution {
public:
    string convertToTitle(int col) {
        string ans="";
        while(col)
        {
            col--;
            ans+=(col%26)+'A';
            col/=26;
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};