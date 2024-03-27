class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int>mp;
        for(char c:letters)mp[c]++;
        int n=words.size();
        int ans=0;
        for (int mask=0;mask<(1<<n);mask++)
        {
            unordered_map<char,int>m=mp;
            int cur=0;
            for(int i=n-1;i>=0;i--)
            {
                if((mask>>i) & 1)
                {
                    bool isvalid=true;
                    for(char c:words[i])
                    {
                        if(m[c]==0){isvalid=false;break;}
                        m[c]--;
                        cur+=score[c-'a'];
                    }
                    if(!isvalid) {cur=0;break;}
                }
            }
            ans=max(ans,cur);
        }
        return ans;
    }
};