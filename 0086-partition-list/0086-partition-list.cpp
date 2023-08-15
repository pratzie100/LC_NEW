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
    ListNode* vtoll(vector<int>& res)
    {
        ListNode* head=nullptr;
        ListNode* tail=nullptr;
        for(int i=0;i<res.size();i++)
        {
            ListNode* newnode=new ListNode;
            newnode->val=res[i];
            newnode->next=nullptr;
            if(head==nullptr)
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
        return head;
    }
    ListNode* partition(ListNode* head, int x) {
        vector<int> vec;
        ListNode* ptr=head;
        while(ptr!=nullptr)
        {
            vec.push_back(ptr->val);
            ptr=ptr->next;
        }
        vector<int>ans;
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]<x)
            {
                ans.push_back(vec[i]);
            }
        }
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]>=x)
            {
                ans.push_back(vec[i]);
            }
        }
        ListNode* start=vtoll(ans);
        return start;
    }
};