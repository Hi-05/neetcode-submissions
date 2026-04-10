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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int cnt = 0;
        ListNode* curr = head;

        while(curr){
            cnt++;
            curr = curr->next;
        }

        n = cnt - n;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        curr = dummy;
        while(curr && n){

            n--;
            curr = curr->next;
        }

    
        if(curr->next != NULL) curr->next = curr->next->next;
        else return NULL;
        return dummy->next;
    }
};
