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
    //Modified Floyd Cycle Detection Algorithm:
    //once the fast and slow pointers meet inside the cycle, we reset one pointer back to the head and then move both pointers at the same pace until they meet again. The meeting point is the starting node of the cycle. This approach ensures that the returned node is the starting node of the cycle
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