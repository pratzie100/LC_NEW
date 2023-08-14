class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //O(n)
        // unordered_set<int>s; //this is better than set (nlogn)
        // unordered_set<int>s_one;
        // s.insert(begin(nums1),end(nums1));
        // s_one.insert(begin(nums2),end(nums2));
        // vector<int>ans;
        // for(int i:s_one)
        // {
        //     if(s.count(i)>0)
        //         ans.push_back(i);
        // }
        // return ans;
        
        //two pointer //tc(nlogn for sort then linear) //but actually better for larger inputs
        sort(begin(nums1),end(nums1));
        sort(begin(nums2),end(nums2));
        int m=nums1.size();
        int n=nums2.size();
        int i=0,j=0;
        vector<int>ans;
        while(i<m && j<n)
        {
            if(nums1[i]==nums2[j])
            {
                //to skip duplicates
                if(find(begin(ans),end(ans),nums1[i])==ans.end()) 
                    ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j])
            {
                i++;
            }
            else if(nums2[j]<nums1[i])
            {
                j++;
            }
        }
        return ans;
    }    
};