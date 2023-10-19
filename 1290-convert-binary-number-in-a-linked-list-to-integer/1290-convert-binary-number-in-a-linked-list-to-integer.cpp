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
    int getDecimalValue(ListNode* head) {
        ListNode*ptr=head;
        vector<int>arr;
        while(ptr)
        {
            arr.push_back(ptr->val);
            ptr=ptr->next;
        }
        int d=0;
        int c=0;
        for(int i=arr.size()-1;i>=0;i--)
        {
            d+=arr[i]*pow(2,c++);
        }
        return d;
    }
};