class Solution {
public:
    string largestGoodInteger(string s) {
        priority_queue<int>pq;
        int n=s.size();
        for(int i=0;i<=n-3;i++)
        {
            if(s[i]==s[i+1] && s[i+1]==s[i+2])
            {
                pq.push(s[i]-'0');
            }
        }
        if(pq.empty()) return "";
        char c=pq.top()+'0'; //int to char
        string ans(3,c);
        return ans;
    }
};
