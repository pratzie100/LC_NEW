class Solution {
public:
    bool canCreateAlloys(int machine,int num_alloys,long long budget,vector<vector<int>>& composition,vector<int>&stock,vector<int>& cost) {
        for (int i=0; i<composition[machine].size(); i++) 
        {
            long long required_metal = 1LL*composition[machine][i]*num_alloys;
            if(required_metal>stock[i]) 
            {
                budget -= (required_metal-stock[i]) * 1LL * cost[i];
            }
            if(budget < 0) 
            {
                return false;
            }
        }
        return true;
    }

    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int low=0,high=INT_MAX;
       // int max_alloys=0;
        while(low<=high) 
        {
            int mid=low+(high-low)/2;
            bool can_create=false;
            for(int machine=0; machine<k; machine++) 
            {
                if(canCreateAlloys(machine,mid,budget,composition,stock,cost)) 
                {
                    //max_alloys=mid;
                    can_create=true;
                    low=mid+1;
                    break;
                }
            }
            if(!can_create) 
            {
                high=mid-1;
            }
        }
        //return max_alloys;
        return high;
    } 
};
