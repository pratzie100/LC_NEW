class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // map<int,int>m;
        // for(vector<int>&v:flowers)
        // {
        //     for(int i=v[0];i<=v[1];i++)
        //     {
        //         m[i]++;
        //     }
        // }
        // vector<int>ans;
        // for(int i=0;i<people.size();i++)
        // {
        //     ans.push_back(m[people[i]]);
        // }
        // return ans;

        int n = flowers.size();
        int m = people.size();
        
        vector<int> ans(m);
        vector<pair<int, int>> StartTimes, EndTimes;
        
        // Sort flowers by start and end times
        for (int i = 0; i < n; i++) 
        {
            StartTimes.push_back({flowers[i][0], i});
            EndTimes.push_back({flowers[i][1], i});
        }
        
        sort(StartTimes.begin(), StartTimes.end());
        sort(EndTimes.begin(), EndTimes.end());
        
        for (int i = 0; i < m; i++) {
            int query = people[i];
            
            // Use binary search to find upper bound index in StartTimes
            int startIdx = upper_bound(StartTimes.begin(), StartTimes.end(), make_pair(query, n)) - StartTimes.begin();
            
            // Use binary search to find lower bound index in EndTimes
            int endIdx = lower_bound(EndTimes.begin(), EndTimes.end(), make_pair(query, -1)) - EndTimes.begin();
            
            // Calculate the count of bloomed flowers
            ans[i] = startIdx - endIdx;
        }

        return ans;
    }
};