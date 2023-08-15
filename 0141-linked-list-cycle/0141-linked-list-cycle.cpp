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
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false; //if one or no nodes
        // Floyd's Cycle Detection Algorithm, also known as the "tortoise and hare" algorithm. 
        //slow pointer moves one step at a time, while the fast pointer moves two steps at a time. If there is a cycle, the fast pointer will eventually catch up to the slow pointer, confirming the presence of a cycle. If there's no cycle, the fast pointer will reach the end of the linked list.
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(slow!=fast)
        {
            if(!fast || !fast->next) return false;
            slow=slow->next;
            fast=fast->next->next;
        }
        return true;
    }
};