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
    ListNode* vtoll(vector<int>&arr)
    {
        ListNode*head=NULL;
        ListNode*tail=NULL;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=0)
            {
                ListNode*newnode=new ListNode();
                newnode->val=arr[i];
                newnode->next=NULL;
                if(head==NULL)
                {
                    head=newnode;
                    tail=newnode;
                }
                else 
                {
                    tail->next=newnode;
                    tail=newnode;
                }
            }
        }
        return head;
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int>v;
        ListNode*ptr=head;
        while(ptr)
        {
            v.push_back(ptr->val);
            ptr=ptr->next;
        }
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=v[j];
                if(sum==0)
                {
                    for(int k=i;k<=j;k++)
                    {
                        v[k]=0;
                    }
                }
            }
        }
        if(v.empty()) return NULL;
        ListNode*ans=vtoll(v);
        return ans;
    }
};
// [1,2,3,-5,3,-4,6,2]=>[6,2]