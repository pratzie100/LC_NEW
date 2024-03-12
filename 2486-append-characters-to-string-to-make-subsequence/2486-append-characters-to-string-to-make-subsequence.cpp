class Solution {
public:
    int appendCharacters(string s, string t) {
        if(s.find(t)!=string::npos) return 0;
        int i=0,j=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==t[j])
                j++;
        }
        if(j==t.size()) return 0;
//        else
        
            string x=t.substr(j);
        return x.size();
  //      }
//        return s;
        //return j==s.size();
    }
};
//if(s.empty()) return true;
       