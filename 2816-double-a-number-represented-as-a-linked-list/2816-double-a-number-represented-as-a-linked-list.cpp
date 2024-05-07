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
    ListNode* doubleIt(ListNode* head) {
        if (!head) return nullptr;

        stack<ListNode*> nodeStack;

        ListNode* current = head;
        while (current) {
            nodeStack.push(current);
            current = current->next;
        }

        int carry = 0;
        ListNode* newHead = nullptr;

        while (!nodeStack.empty()) {
            ListNode* node = nodeStack.top();
            nodeStack.pop();

            int newVal = node->val * 2 + carry;
            node->val = newVal % 10;
            carry = newVal / 10;

            if (carry > 0) {
                ListNode* newCarry = new ListNode(carry);
                newCarry->next = node;
                newHead = newCarry;
            }
            else {
                newHead = node;
            }
        }

        return newHead;
    }
};