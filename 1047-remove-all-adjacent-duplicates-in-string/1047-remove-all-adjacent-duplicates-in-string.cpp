class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        int r=0;
        int n=s.size();
        while(r<n)
        {
            if(r==0 || st.empty()){st.push(s[r]);r++;continue;}
            if(s[r]!=st.top())st.push(s[r]);
            else st.pop();
            r++;
        }
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