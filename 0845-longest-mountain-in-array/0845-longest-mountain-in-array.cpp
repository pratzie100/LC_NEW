class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        //int s=-1;
        if(n==0 || n==1 || n==2) return 0;
        //int p=-1;
        int ans=0;
        for(int i=1;i<n-1;)
        {
            // if(arr[i+1]>arr[i]){p=i;  break;}
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
            {
                int l=i;
                int r=i;
                while(l>0 && arr[l]>arr[l-1]) l--;
                while(r<n-1 && arr[r+1]<arr[r] ) r++;
                ans=max(ans,r-l+1);
                i=r;
            }
            else
            {
                i++;
            }
        }
        return ans>=3?ans:0;
        // if(p==n || p==-1) return 0;
        // int l=p;
        // int r=p;
        // //cout<<p;
        // //int curr=-1;
        // //cout<<1;
        // int ans=0;
        // while(r<n)
        // {
        //     int curr=-1;
        //     bool one=0;
        //     bool two=0;
        //     while(r<n && arr[r]>curr)
        //     {
        //         curr=arr[r];
        //         r++;
        //         one=1;
        //     }
        //     int prev=curr;
        //     //cout<<prev;
        //     while(r<n && arr[r]<prev)
        //     {
        //         prev=arr[r];
        //         r++;
        //         two=1;
        //     }
        //     if(!one || !two)break;
        //     r--;
        //     //cout<<r;
        //     ans=max(ans,r-l+1);
        //     l=r;
        // }
        // return ans;
        
    }
};