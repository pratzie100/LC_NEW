class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        string word="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
            {
                word+=s[i];
            }
            else
            {
                v.push_back(word);
                word="";
            }
        }
        v.push_back(word);
        string ans="";
        for(string str:v)
        {
            reverse(begin(str),end(str));
            ans+=str+' ';
        }
        string updated_ans(begin(ans),end(ans)-1);
        return updated_ans;
    }
};