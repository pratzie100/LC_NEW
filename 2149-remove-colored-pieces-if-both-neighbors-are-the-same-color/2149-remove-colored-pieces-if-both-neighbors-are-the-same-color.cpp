class Solution {
public:
    bool winnerOfGame(string s) {
        int n=s.size();
        if(n<=2) return false;
        unordered_multiset<char>bada;
        unordered_multiset<char>badb;
        for(int i=1;i<n-1;i++)
        {
            if(s[i]==s[i-1] && s[i]==s[i+1])
            {
                if(s[i]=='A') bada.insert(s[i]);
                else badb.insert(s[i]);
            }
        }
        cout<<bada.size()<<" "<<badb.size();
        return bada.size()>badb.size();
    }
};