class Solution {
public:
    char nextGreatestLetter(vector<char>& a, char target) {
        // auto it=upper_bound(begin(letters),end(letters),target);
        // if(it==end(letters)){
        //     return *begin(letters);
        // }
        // return *it;

        int n=a.size();

        int low=0;
        int high=n-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(a[mid]<=target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        if(low<0 || low>=n) return a[0];
        return a[low];
    }
};