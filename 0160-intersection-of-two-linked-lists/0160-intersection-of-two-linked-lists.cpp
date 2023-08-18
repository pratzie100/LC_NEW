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
//by simultaneously traversing the linked lists and "restarting" the pointers at the opposite head when they reach the end of their lists, the pointers will eventually align either at the intersection point or at the end of the lists.
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA;
		ListNode *ptr2 = headB;
		while(ptr1 != ptr2){
            ptr1= (ptr1 == NULL) ? headB:ptr1->next;
            ptr2= (ptr2 == NULL) ? headA:ptr2->next;
		}
		return ptr1;
    }
};