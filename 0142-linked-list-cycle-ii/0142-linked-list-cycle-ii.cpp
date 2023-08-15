/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL; //if one or no nodes
        ListNode* slow=head;
        ListNode* fast=head;
        while(true)
        {
            if(!fast || !fast->next) return NULL; // No cycle
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) // Cycle detected
            {
                ListNode* ptr1=head;
                ListNode* ptr2=slow;
                while(ptr1!=ptr2)
                {
                    ptr1=ptr1->next;
                    ptr2=ptr2->next;
                }
                return ptr1; // Return the starting node of the cycle
            }
        }
        return NULL;
    }
};