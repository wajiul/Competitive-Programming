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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = head;
        while(cur != NULL) {
            ListNode *prev = dummy;
            while(prev->next != NULL && prev->next->val <= cur->val) {
                prev = prev->next;
            }
            ListNode *nxt = cur->next;
            cur->next = prev->next;
            prev->next = cur;
            cur = nxt;
        }
      return dummy->next;
    }
};
