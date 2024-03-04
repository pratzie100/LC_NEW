class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(begin(tokens),end(tokens));
        int n=tokens.size();
        int j=n-1;
        int score=0;
        unordered_multiset<int>s;
        for(int i=0;i<n;i++)
        {
            if(tokens[i]<=power)
            {
                power-=tokens[i];
                score++;
                s.insert(tokens[i]);
                if(s.size()==n) break;
                //if(power==0) break;
            }
            else
            {
                if(s.size()==n-1) break;
                if(score>=1)
                {
                    power+=tokens[j];
                    score--;
                    j--;
                    i--; //to stabilize
                    s.insert(tokens[i]);
                    if(s.size()==n) break;
                }
            }
        }
        return score; 
    }
};
// [3,18,35,50] p=10
// p=7,s=1
// p=57,s=0
// p=39,s=1
// p=4,s=2
// [10,33,34,41,47,48,70,84,91,98] p=43
// p=33 s=1
