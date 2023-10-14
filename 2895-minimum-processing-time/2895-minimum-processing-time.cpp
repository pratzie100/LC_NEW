class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        int n = processorTime.size();
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(),tasks.end(),greater<int>());
        int p=0;
        int ans=0;
        for(int i=0;i<tasks.size();i++)
        {
            if(i>0 && i%4==0)
                p++;
            ans=max(ans,processorTime[p]+tasks[i]);
        }
        return ans;
    }
};
