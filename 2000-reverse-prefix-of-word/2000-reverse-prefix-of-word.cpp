class Solution {
public:
    string reversePrefix(string s, char ch) {
        int n=s.size();
        string a="";
        bool f=0;
        int i;
        for(i=0;i<n;i++)
        {
            if(s[i]==ch)
            {
                f=1;
                a+=ch;
                break;
            }
            else
            {
                a+=s[i];
            }
        }
        if(!f) return s;
        reverse(begin(a),end(a));
        return a+s.substr(i+1);
        
    }
};