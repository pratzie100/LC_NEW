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
    bool f(ListNode*& head,ListNode*curr,bool ans)
    {
        if(!curr) return true;
        ans=f(head,curr->next,ans);
        //cout<<ans<<" ";
        if(!ans) return false; //recursively send back false
        //if(curr->next==head) return true;
        ans=(curr->val==head->val);
        
        //if(!ans) return false;
        head=head->next;
        return ans;
    }

    bool isPalindrome(ListNode* head) {
       return f(head,head,true);
    }
};