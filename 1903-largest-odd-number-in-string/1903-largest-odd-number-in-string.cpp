class Solution {
public:
    string largestOddNumber(string s) {
        int z=-1;
        for(int i=s.size()-1;i>=0;i--)
        {
            if((s[i]-'0')%2!=0)
            {
                z=i;
                break;
            }
        }
        if(z==-1) return "";
        else return s.substr(0,z+1);
    }
};