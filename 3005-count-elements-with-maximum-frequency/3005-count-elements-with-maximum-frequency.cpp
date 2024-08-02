class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i:nums)m[i]++;
        int maxi=INT_MIN;
        for(auto i:m){
            maxi=max(maxi,i.second);
        }
        int c=0;
        for(int i:nums){
            if(m[i]==maxi) c++;
        }
        return c;
    }
};