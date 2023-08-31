class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            unordered_map<char,int>m;
            for(int j=i;j<n;j++)
            {
                m[s[j]]++;
                int maxFreq=INT_MIN, minFreq=INT_MAX;
                for(auto i:m) 
                {
                    maxFreq = max(maxFreq, i.second);
                    minFreq = min(minFreq, i.second);
                    //note for "aa" maxfreq=minfreq 
                    //difference will occur for two different characters only
                }
                sum+=maxFreq-minFreq;
            }
        }
        return sum;
    }
};