class Solution {
public:
    int bestClosingTime(string s) {
        int maxnopenaltytime=-1; // take so that +1 ,ie 0 is ans for "NNNN"
        int score=0;
        int maxscore=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='Y')score++;
            else score--;
            if(score>maxscore)
            {
                maxnopenaltytime=i; 
                maxscore=score;
            }
        }
        return maxnopenaltytime+1; //will be minimal penalty time
    }
};