class Solution {
public:
    int lengthOfLastWord(string s) {
        //int  spaceoccur=false;
        int cnt=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            while(s[i]==' ' && cnt==0) {i--;continue;}
            if(s[i]!=' ')cnt++;
            else break;
        }
        return cnt;
    }
};