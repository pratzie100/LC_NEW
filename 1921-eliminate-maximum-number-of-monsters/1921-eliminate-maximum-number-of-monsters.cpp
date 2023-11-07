class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<float,vector<float>,greater<float>>pq;
        for(int i=0;i<dist.size();i++) 
        {
            pq.push((float)dist[i]/speed[i]);
        }
        int ans = 0;
        while(!pq.empty()) 
        {
            //At each timestep check if the arrival of a monster is less or equal to zero. If thats the case the game is over. Otherwise remove a monster and increment the kill count. The kill count is also equal to minutes played since we kill 1 monster per minute.
            if(pq.top()-ans<=0) return ans; 
            ans++;
            pq.pop();
        }
        return ans;
    }
};