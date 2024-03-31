class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(int i=0;i<s.size();i++)
        {
            if(!st.empty() && st.top().first==s[i])
            {
                st.top().second++;
                if(st.top().second==k)st.pop();
            }
            else st.push({s[i],1});
        }
        string ans="";
        while(!st.empty())
        {
            string x(st.top().second,st.top().first);
            ans+=x;
            st.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};