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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return solve(l1, l2, 0);
    }
private:
ListNode* solve(ListNode* l1, ListNode* l2, int carry) {
    // Base case: If both linked lists are empty and no carry is left, return NULL.
    if (!l1 && !l2) 
    {
        if (carry == 0)
            return NULL;
        // If there's a carry, create a new node with the carry as its value.
        return new ListNode(carry);
    }
    // Calculate the sum of the current digits and the carry.
    int sum = carry;
    if (l1)
        sum += l1->val;
    if (l2)
        sum += l2->val;
        
    // Calculate the new carry and the value for the current node.
    int new_carry = sum / 10;
    int value = sum % 10;

    // Create a new node with the calculated value.
    ListNode* result = new ListNode(value);

    // Move to the next nodes in the linked lists, if they exist.
    if (l1)
        l1 = l1->next;
    if (l2)
        l2 = l2->next;

    // Recursively build the rest of the linked list and connect it to the current node.
    result->next = solve(l1, l2, new_carry);

    // Return the current node.
    return result;
}

};
