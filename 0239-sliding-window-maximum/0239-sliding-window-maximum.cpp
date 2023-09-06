class Solution {
public:
    vector<int>maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int>m;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            if(i<k-1)
            {
                m[nums[i]]++;
            }
            else
            {
                m[nums[i]]++;
                auto it=m.rbegin();
                ans.push_back(it->first);
                m[nums[i-k+1]]--; 
                if(m[nums[i-k+1]]==0)
                {
                    m.erase(nums[i-k+1]);
                }
            }
        }
        return ans;
    }
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     vector<int>ans;
    //     deque<int>dq;
    //     int n=nums.size();
    //     for(int i=0;i<n;i++)
    //     {
    //         while(!dq.empty() && dq.back()<nums[i]) 
    //         {
    //             dq.pop_back();
    //         }
    //         if(!dq.empty() && i>=k && dq.front()==nums[i-k])
    //         {
    //             dq.pop_front();
    //         }
    //         dq.push_back(nums[i]);
    //         if(i>=k-1)
    //         {
    //             ans.push_back(dq.front());
    //         }
    //     }
    //     return ans;

    // }
};