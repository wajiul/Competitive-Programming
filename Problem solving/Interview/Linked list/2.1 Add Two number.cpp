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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h = new ListNode(-1);
        ListNode* ptr = h;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry) {
            int d = carry;
            if(l1 != NULL) {
                d += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL) {
                d += l2->val;
                l2 = l2->next;
            }
            carry = d / 10;
            ListNode* new_node = new ListNode(d % 10);
            ptr->next = new_node;
            ptr = ptr->next;
        }
        return h->next;
    }
};
