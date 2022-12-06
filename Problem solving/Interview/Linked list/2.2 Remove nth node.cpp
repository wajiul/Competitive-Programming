/** Leetcode 19
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
        ListNode* h = new ListNode(-1);
        ListNode* tmp = h;
        ListNode* dummy = h;
        h->next = head;
        int cnt = -1;
        while(h != NULL) {
            h = h->next;
            if(cnt < n) {
                cnt++;
            }
            else {
                tmp = tmp->next;
            }
        }

        if(tmp->next) {
            tmp->next = tmp->next->next;
        }
        // return tmp;
        return dummy->next;
    }
};
