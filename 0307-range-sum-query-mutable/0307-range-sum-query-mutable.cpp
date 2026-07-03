class NumArray {
private:
    // member variables, accessible by ALL methods in this class.
    vector<int> arr;    
    vector<int> blocks;   
    int n;    // Size of the original array
    int p;   // Size of each block (sqrt(n))

public:
   // vector<int> square_rootdecom(vector<int>& arr, int &p){
    vector<int> square_rootdecom(vector<int>& arr){
      //  n=arr.size();
        vector<int>blocks(p);
        for(int i=0;i<n;i++){
            blocks[i/p]+=arr[i];
        }
        return blocks;
    }
    NumArray(vector<int>& nums) {
        arr=nums; // Copying original array to member variable 'arr'
        n=nums.size();
        p=ceil(sqrt(n));
       // blocks=square_rootdecom(arr,p);
        blocks=square_rootdecom(arr);
    }
    
    void update(int index, int val) {
      //  n=arr.size();
        int change_val= val-arr[index];
        arr[index]=val;
      //  p=ceil(sqrt(n));
        blocks[index/p]+=change_val;
    }
    
    int sumRange(int left, int right) {
     //   n=arr.size();
     //   p=ceil(sqrt(n));
        int start_block=left/p;
        int end_block=right/p;
        int ans=0;
        
        if(start_block==end_block){
            for(int i=left;i<=right;i++){
                ans+=arr[i];
            }
            return ans;
        }


        for(int i=start_block+1;i<end_block;i++){
            ans+=blocks[i];
        }
        int j=left;
        while(j!=(start_block+1)*p){
            ans+=arr[j];
            j++;
        }
        j=(end_block*p);
        while(j!=right+1){
            ans+=arr[j];
            j++;
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */