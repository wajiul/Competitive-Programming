/*
   Leetcode: (876) https://leetcode.com/problems/middle-of-the-linked-list/description/
   Delete the middle node in linked list
*/
class Solution
{
    public:
        ListNode* middleNode(ListNode *head)
        {
            ListNode *fast = head;
            ListNode *slow = head;
            while(fast != NULL && fast->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;

        }
};
