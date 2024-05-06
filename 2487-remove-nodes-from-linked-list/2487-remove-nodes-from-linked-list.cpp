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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>st;
        ListNode* c=head;
        while(c)
        {
            st.push(c);
            c=c->next;
        }
        ListNode* ptr=st.top();
        int maxvalue=ptr->val;
        st.pop();
        ListNode* ansList=new ListNode(ptr->val);
        while(!st.empty())
        {
            ListNode*u=st.top();
            st.pop();
            int z=u->val;
            if(z>=maxvalue)
            {
                ListNode* newnode=new ListNode(u->val);
                newnode->next=ansList;
                ansList=newnode;
                maxvalue=z;
            }
        }
        return ansList;
    }
};