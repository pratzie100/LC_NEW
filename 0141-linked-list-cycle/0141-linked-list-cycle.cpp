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
        ListNode* slow=head;
        ListNode* fast=head->next;  //intially fast pointer has to be ahead of slow otherwise If both the slow and fast pointers start at the same node (i.e., head),while loop will not be executed, and the algorithm would mistakenly detect a cycle. This is because the initial positions of the pointers would be the same, and they would be immediately pointing to the same node. As a result, the algorithm would falsely conclude that there's a cycle even if there isn't one.
// Starting the fast pointer at head->next instead of head is crucial to ensure that there is an initial separation between the pointers. This initial separation is necessary so that the fast pointer can move ahead of the slow pointer and eventually enter the cycle. This allows the algorithm to correctly detect a cycle if one exists.
        while(slow!=fast)
        {
            if(!fast || !fast->next) return false;
            //slow pointer moves one step at a time, while the fast pointer moves two steps at a time. If there is a cycle, the fast pointer will eventually catch up to the slow pointer, confirming the presence of a cycle. If there's no cycle, the fast pointer will reach the end of the linked list.
            slow=slow->next;
            fast=fast->next->next;
        }
        return true;
    }
};