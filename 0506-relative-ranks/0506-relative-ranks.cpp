class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int>v=score;
        sort(begin(v),end(v),greater<int>());
        vector<string>ans(score.size());
        int n=v.size();
        for(int i=0;i<n;i++)
        {
           if(i==0) ans[i]="Gold Medal";
            else if(i==1) ans[i]="Silver Medal";
            else if(i==2) ans[i]="Bronze Medal";
            else ans[i]=to_string(i + 1);
        }
        unordered_map<int,string>m;
        for(int i=0;i<n;i++)
        {
            m[v[i]]=ans[i];
        }
        vector<string>fin;
        for(int i=0;i<n;i++)
        {
            fin.push_back(m[score[i]]);
        }
        return fin;
    }
};