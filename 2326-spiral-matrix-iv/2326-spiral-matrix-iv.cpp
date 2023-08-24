/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<int>nums;
        ListNode* ptr=head;
        while(ptr)
        {
            nums.push_back(ptr->val);
            ptr=ptr->next;
        }
        vector<vector<int>>ans(m,vector<int>(n,-1));
        int count=0;
        int left=0,right=n-1,top=0,bottom=m-1;
        int dir=1;
        while(left<=right && top<=bottom)
        {
            if(count==nums.size()) break;
            if(dir==1)
            {
                for(int i=left;i<=right;i++)
                {
                    if(count==nums.size()) break;
                    ans[top][i]=nums[count++];
                }
                top++;
                dir=2;
            }
            else if(dir==2)
            {
                for(int i=top;i<=bottom;i++)
                {
                    if(count==nums.size()) break;
                    ans[i][right]=nums[count++];
                }
                right--;
                dir=3;
            }
            else if(dir==3)
            {
                for(int i=right;i>=left;i--)
                {
                    if(count==nums.size()) break;
                    ans[bottom][i]=nums[count++];
                }
                bottom--;
                dir=4;
            }
            else if(dir==4)
            {
                for(int i=bottom;i>=top;i--)
                {
                    if(count==nums.size()) break;
                    ans[i][left]=nums[count++];
                }
                left++;
                dir=1;
            }
        }
        return ans;
    }
};