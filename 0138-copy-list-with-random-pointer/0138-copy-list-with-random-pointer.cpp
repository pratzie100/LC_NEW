/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>m;
        Node* ptr=head;
        while(ptr)
        {
            Node* copy=new Node(ptr->val); //make cpoy of real node
            m[ptr]=copy; //mapping real node to its copy
            ptr=ptr->next;
        }
        ptr=head;
        while(ptr)
        {
            m[ptr]->next=m[ptr->next]; //copy's next should point to real node's next's copy
            m[ptr]->random=m[ptr->random]; //copy's random should point to real node's random's copy
            ptr=ptr->next;
        }
        return m[head]; //return copy of real head
    }
};