class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>m;
        for(int i=0;i<words.size();i++)
        {
            m[words[i]]++;
        }
        vector<pair<string,int>>v;
        for(auto i:m)
        {
            v.push_back({i.first,i.second});
        }
        sort(begin(v),end(v),[&](pair<string,int>&a,pair<string,int>&b)
        {
            if(a.second!=b.second)
            {
                return a.second>b.second;
            }
            else
            {
                return a.first<b.first;
            }
        });
        vector<string>ans;
        for(int i=0;i<v.size();i++)
        {
            ans.push_back(v[i].first);
            k--;
            if(k==0) break;
        }
        return ans;
    }
};