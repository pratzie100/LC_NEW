class Solution {
public:
    unordered_set<string>S;
    void f(string s, string t) {
        if(!s.empty()) 
        {
            S.insert(s);
            //return;
        }
        for(int i=0;i<t.size();i++) 
        {
            string x=s+t[i];
            string y=t.substr(0,i)+t.substr(i+1);
            f(x,y);
        }
    }
    int numTilePossibilities(string tiles) {
        string s="";
        f(s,tiles);
        return S.size();
    }
};
