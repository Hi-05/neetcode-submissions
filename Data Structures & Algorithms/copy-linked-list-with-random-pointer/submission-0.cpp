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
        
        unordered_map<Node*,Node*> mp;
        Node* curr = head;

        while(curr){

            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        for(auto &it : mp){

            Node* orig = it.first;
            Node* copy = it.second;

            if(orig->next) copy->next = mp[orig->next];
            if(orig->random) copy->random = mp[orig->random];
        }

        return mp[head];
    }
};
