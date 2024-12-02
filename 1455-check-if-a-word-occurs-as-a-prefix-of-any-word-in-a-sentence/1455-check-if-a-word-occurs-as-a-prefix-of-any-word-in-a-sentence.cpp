class Solution {
public:
    int isPrefixOfWord(string s, string sw) {
        int n=s.size();
        int c=0;
        string str="";
        for(int i=0;i<n;i++){
            if(s[i]==' ')
            {
                cout<<str<<endl;
                c++;
                int k=0;
                for(int j=0;j<str.size();j++){
                    if(str[j]!=sw[k]) break;
                    else k++;
                }
                if(k==sw.size()) return c;
                str="";
            }
            else str+=s[i];
        }
        int k=0; //last word check
                for(int j=0;j<str.size();j++){
                    if(str[j]!=sw[k]) break;
                    else k++;
                }
                if(k==sw.size()) return c+1;
        return -1;
    }
};