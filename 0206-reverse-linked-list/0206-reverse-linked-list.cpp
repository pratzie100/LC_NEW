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
ListNode* ans=NULL;
class Solution {
public:
    void reverse(ListNode* prev,ListNode*cur)
    {
        if(cur)
        {
            reverse(cur,cur->next);
            cur->next=prev;
        }
        else
        {
            ::ans=prev;
        }
    }
    ListNode* reverseList(ListNode* head) {
        reverse(NULL,head);
        return ::ans;
    }
};