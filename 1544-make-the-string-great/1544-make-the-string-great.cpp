class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(i==0){st.push(s[i]);continue;}
           // char ch=st.top()-32;
            if(!st.empty() && (s[i]==st.top()-32  || s[i]==st.top()+32))  st.pop();
            else st.push(s[i]);
        }
        if(st.empty()) return "";
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};