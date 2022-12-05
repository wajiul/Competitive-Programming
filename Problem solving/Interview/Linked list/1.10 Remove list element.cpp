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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* h = new ListNode(-1);
        ListNode* dummy = h;
        h->next = head;

        while(h != NULL && h->next != NULL) {
            if(h->next->val == val) {
                h->next = h->next->next;
            }
            else h = h->next;
        }
        dummy = dummy->next;
        return dummy;
    }
};
