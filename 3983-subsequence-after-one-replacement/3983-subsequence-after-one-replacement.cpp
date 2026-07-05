class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
       int n=s.size();
       int m=t.size();
       if(n>m) return 0;
       if(n==1) return 1;

       vector<int>pre(n,-1);
       vector<int>suf(n,-1);
       int j=0;
       for(int i=0;i<n;i++){
        while(j<m && t[j]!=s[i]) j++;
        if(j==m) break;
        pre[i]=j++;
       }
        j=m-1;
       for(int i=n-1;i>=0;i--){
        while(j>=0 && t[j]!=s[i]) j--;
        if(j==-1) break;
        suf[i]=j--;
       } 
       if(suf[1]>0) return 1; //replace only first char in s
       if(pre[n-2]!=-1 && pre[n-2]<m-1) return 1; //replace only last char in s
       for(int i=1;i<n-1;i++){
        //checking validity for replacing any one char of s present in middle
        if(pre[i-1]==-1 || suf[i+1]==-1) continue; //both prefix and suffix substrings before and after should be valid..this is invalid case
        
        if(suf[i+1]-pre[i-1]>=2) return true;
       }
       return false;
    }
};