class Solution {
public:
      #define ll long long
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        vector<ll>ans;
        unordered_map<ll,ll>m;
        multiset<ll>ms;
        for(int i=0;i<nums.size();i++)
        {
            ll prev=m[nums[i]];
            if(prev>0)ms.erase(ms.find(prev));
            m[nums[i]]+=freq[i];
            if(m[nums[i]]>0) ms.insert(m[nums[i]]);
            if(ms.empty()){ans.push_back(0);continue;}
            ans.push_back(*ms.rbegin());      
        }
        return ans;
//         vector<ll>ans;
//         unordered_map<ll,ll>m;
//         ll maxoc=INT_MIN;
//         multiset<ll>ms;
//         for(int i=0;i<nums.size();i++)
//         {
//             ll z=m[nums[i]];
//             m[nums[i]]+=freq[i];
//             if(m[nums[i]]==0)
//             {
//                 // auto it=ms.end();
//                 // it--;
//                 // ll x=freq[i]+(*it);
//                 // if(x==0)
//                 // {
//                 //     ms.erase(*it);
//                 // }
//                 m.erase(nums[i]);
//                 ms.erase(z);
//                 if(m.empty()){ans.push_back(0);continue;}
                
//             }
//             ms.insert(m[nums[i]]);
//             auto it=ms.end();
//             it--;
//              maxoc=max(maxoc,*it);
//             ans.push_back(maxoc);
//         }
//         return ans;
        
        
        // vector<ll>ans;
        // unordered_map<ll,ll>m;
        // multiset<ll>ms;
        // ll maxoc = 0; 
        // for(int i=0;i<nums.size();i++) 
        // {
        //     ll prevFreq=m[nums[i]];
        //     m[nums[i]]+=freq[i];
        //     if(prevFreq > 0)
        //         ms.erase(ms.find(prevFreq));
        //     if(m[nums[i]] > 0)
        //         ms.insert(m[nums[i]]);
        //     if(ms.empty()) {
        //         ans.push_back(0);
        //         continue;
        //     }
        //     maxoc = *ms.rbegin();
        //     ans.push_back(maxoc);
        // }
        // return ans;
    }
    // [7,3,3,9,3]
    // [2,5,5,3,-10]
    // [2,5,10,10,3]
//     [2,3,2,5,6]
// [2,2,-2,2,1]
    // [2,2,2,2,2]
};

