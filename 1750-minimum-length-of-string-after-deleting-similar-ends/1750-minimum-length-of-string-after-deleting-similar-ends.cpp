class Solution {
public:
    int minimumLength(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j]) break;
        //     // i++;
        //     // j--;


        //     if(s[i]==s[j])
        //     {

        //         if((s[i+1]==s[j] && i+1<j) && (s[j-1]!=s[i]))//aabca
        //         {
        //             i++;
        //         }
        //         // else if((s[i+1]==s[j] && i+1<j) && (s[j-1]==s[i] && j-1>i))
        //         // {
        //         //     i++;
        //         //     j--;
        //         // }

        //         else if((s[j-1]==s[i] && j-1>i) && (s[i+1]!=s[j-1])) //abcaa
        //         {
        //             j--;
        //         }
        //         // else if((s[j-1]==s[i] && j-1!=i) && (s[i+1]==s[j-1] && i+1<j-1))
        //         // {
        //         //     j--;
        //         // }
        //         else
        //         {
        //                i++;
        //                 j--;
        //                // if(s[i]==s[j] && s[i+1]==s[j]) return 0;
        //     //                        string s1(begin(s)+i,begin(s)+j+1);
        //     // unordered_set<char>se(begin(s1),end(s1));
        //     // if(se.size()==1) return 0;
        //         }
        //    }
        //     else
        //     {
                
        //         break;
        //     }
            char prevch=s[i];
          
            while(i<j && prevch==s[i])
                i++;
            while(j>=i && prevch==s[j])
                j--;
        }
        //if(i==j) return 0;
        cout<<i<<" "<<j;
        return j-i+1;
        
    }
};