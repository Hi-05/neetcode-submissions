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
    void reorderList(ListNode* head) {
        
        unordered_map<ListNode*,ListNode*> mp;

        ListNode* last = head;

        while(last->next){

            mp[last->next] = last;
            last = last->next;
        }

        ListNode* first = head;

        while(first != last){

            ListNode* temp = first->next;
            first->next = last;
            first = temp;

            if(first == last) break;
            last->next = first;
            last = mp[last];
        }

        last->next = NULL;
    }
};
