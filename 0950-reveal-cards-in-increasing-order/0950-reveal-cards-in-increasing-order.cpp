class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
    sort(deck.begin(),deck.end());
        vector<int>ans(deck.size(),-1);
        int count=0;
        int f=0;
        int j=0;
        while(count<deck.size())
        {
            for(int i=0;i<deck.size();i++)
            {
                if(ans[i]==-1)
                {
                    if(f==0)
                    {
                        ans[i]=deck[j];
                        j++;
                        count++;
                        f=1;
                    }
                    else{f=0;}
                }
            }
        }

        return ans;
    }
};