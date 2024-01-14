class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> f1(26,0);
        vector<int> f2(26,0);
        for(int i=0;i<word1.size();i++)
        {
            f1[word1[i]-'a']++;
        }
        for(int i=0;i<word2.size();i++)
        {
            f2[word2[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if((f1[i]==0 && f2[i]!=0) || (f1[i]!=0 && f2[i]==0))return false;
        }
        sort(f1.begin(),f1.end());
        sort(f2.begin(),f2.end());
        for(int i=0;i<26;i++)
        {
            if(f1[i]!=f2[i])return false;
        }
        return true;
    }
};