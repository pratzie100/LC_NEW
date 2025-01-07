class Solution {
public:
    bool check(string s1,string s2){
        int n=s1.size();
        int m=s2.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(s1[i]==s2[j]) {j++;if(j==m) return true;}
            else {
                if(j!=0&&s1[i]==s2[j-1]) continue; 
                else j=0;
            }
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        unordered_set<string>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && check(words[i],words[j])){
                    ans.insert(words[j]);
                }
            }
        }
        vector<string>answer(begin(ans),end(ans));
        return answer;
    }
};