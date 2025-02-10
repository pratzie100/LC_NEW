class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]>=48 && s[i]<=57){
                st.pop();
            }
            else st.push(s[i]);
        }
        string ans="";
        while(!st.empty()){
            char x=st.top();
            st.pop();
            ans+=x;
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};