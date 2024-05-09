class Solution {
public:
        #define ll long long
    long long maximumHappinessSum(vector<int>& nums, int k) {
       //priority_queue<ll>pq;
        sort(begin(nums),end(nums));
        stack<int>pq; 
        for(int i:nums)pq.push(i);
        ll c=0;
        ll s=0;
        while(k--)
        {
            s+=pq.top();
            pq.pop();
            if(pq.empty()){break;}
            c++;
            if(pq.top()-c<0){pq.pop(); pq.push(0);} //due to this pushing, switch from priority queue to (sort+stack)
            else
            {
                int x=pq.top();
                pq.pop(); pq.push(x-c); 
           }
        }
        return s;
    }
};