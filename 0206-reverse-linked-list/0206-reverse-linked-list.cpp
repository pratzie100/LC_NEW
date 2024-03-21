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
    // ListNode* ans=NULL;
    // void reverse(ListNode* prev,ListNode*cur)
    // {
    //     if(cur)
    //     {
    //         reverse(cur,cur->next);
    //         cur->next=prev;
    //     }
    //     else
    //     {
    //         ans=prev;
    //     }
    // }
    // ListNode* reverseList(ListNode* head) {
    //     reverse(NULL,head);
    //     return ans;
    // }
    ListNode* solve(ListNode* prev, ListNode* node,ListNode* ans) {
        if(node)
        {
            ans=solve(node,node->next,ans);
            node->next=prev;
        }
        else ans=prev;
        return ans;
    }
    
    ListNode* reverseList(ListNode* head) {       
        return solve(NULL,head,NULL); 
    }
};