class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        sort(begin(skill),end(skill));
        //vector<vector<int>>v;
        unordered_set<int>s;
        for(int i=0;i<n/2;i++)
        {
            //v.push_back({skill[i],skill[n-i-1]});
            s.insert(skill[i]+skill[n-i-1]);
        }
        if(s.size()!=1) return -1;
        long long sum=0;
        for(int i=0;i<n/2;i++)
        {
            sum+=skill[i]*skill[n-i-1];
        }
        return sum;
    }
};

//1 2 3 3 4 5