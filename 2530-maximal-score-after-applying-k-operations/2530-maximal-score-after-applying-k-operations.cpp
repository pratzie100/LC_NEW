class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int i:nums) pq.push(i);
        long long ans=0;
        while(k--){
            int x=pq.top();
            ans+=x;
            pq.pop();
            pq.push(ceil(x/3.0));
        }
        return ans;
    }
};