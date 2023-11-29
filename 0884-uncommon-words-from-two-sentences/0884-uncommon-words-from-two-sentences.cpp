class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss1(s1);
        stringstream ss2(s2);
        vector<string>v;
        string word;
        while(ss1>>word)
        {
            v.push_back(word);
        }
        while(ss2>>word)
        {
            v.push_back(word);
        }
        unordered_map<string,int>m;
        for(int i=0;i<v.size();i++)
        {
            m[v[i]]++;
        }
        vector<string>ans;
        for(auto i:m)
        {
            if(i.second==1)
                ans.push_back(i.first);
        }
        return  ans;
    }
};