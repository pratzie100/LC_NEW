class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        int n=s.size();
        string z=s;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='('){st.push(i);}
            else if(s[i]==')' && !st.empty())st.pop();
            else if(s[i]==')' && st.empty()) z[i]='#'; 
        }
        while(!st.empty())
        {
            z[st.top()]='#';
            st.pop();
        }
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(z[i]!='#') ans+=z[i];
        }
        return ans;
    }
};