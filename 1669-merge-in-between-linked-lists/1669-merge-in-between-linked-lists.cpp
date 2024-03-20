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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode*ptr1=list1;
        ListNode*ptr2=list2;
        vector<int>res;
        int i=0;
        while(i<a)
        {
            res.push_back(ptr1->val);
            i++;
            ptr1=ptr1->next;
        }
        while(ptr2!=nullptr)
        {
            res.push_back(ptr2->val);
            ptr2=ptr2->next;
        }
        ptr1=list1;
        for(int i=0;i<=b;i++)
            ptr1=ptr1->next;
        while(ptr1!=nullptr)
        {
            res.push_back(ptr1->val);
            ptr1=ptr1->next;
        }        ListNode* head=nullptr;
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
};