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
    ListNode* middleNode(ListNode* head) {
int c=0;
        ListNode*ptr=head;
        while(ptr)
        {
            ptr=ptr->next;
            c++;
        }
        ListNode*ptr1=head;
        int m=0;
        while(ptr1)
        {
            if(m==c/2)
            {
                return ptr1;
            }
            ptr1=ptr1->next;
            m++;
        }
        return ptr1;
    }
};