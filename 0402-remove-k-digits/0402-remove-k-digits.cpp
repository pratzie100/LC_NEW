class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char>s;
        for(int i=0;i<n;i++)
        {
            while(k && !s.empty() && num[i]<s.top())
            {
                k--;
                s.pop();
            }
            s.push(num[i]);
            if(s.size()==1 && s.top()=='0')
            {
                s.pop();
            }
        }
        while(k && !s.empty())
        {
            k--;
            s.pop();
        }
        string res="";
        while(!s.empty())
        {
            res+=s.top();
            s.pop();
        }
        reverse(begin(res),end(res));
        if(res.empty()) return "0";
        return res;
    }
};