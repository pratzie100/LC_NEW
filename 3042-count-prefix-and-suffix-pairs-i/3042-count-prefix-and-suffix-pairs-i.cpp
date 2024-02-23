class Solution {
public:
    bool isPrefixAndSuffix(string&str1,string&str2)
    {
        if(str1.size()>str2.size()) return false;
        if(str1==str2) return true;
        if(str2.substr(0,str1.size())==str1 && str2.substr(str2.size()-str1.size(),str1.size())==str1) return true;
        
        // int i=0;
        // string s="",t="";
        // int j=str2.size()-str1.size();
        // while(j<str2.size())
        // {
        //     if(str2[i]!=str2[j]) 
        return false;
        //     i++;
        //     j++;
        // }
       // return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int c=0;
        for(int i=0;i<words.size()-1;i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if(isPrefixAndSuffix(words[i], words[j]))
                {
                    c++;
                    cout<<words[i]<<" "<<words[j]<<endl;
                }
            }
        }
        return c;
    }
};