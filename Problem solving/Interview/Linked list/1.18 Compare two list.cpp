/*
 * https://practice.geeksforgeeks.org/problems/identical-linked-lists/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
 */
bool areIdentical(struct Node *head1, struct Node *head2)
{
    while(head1 != NULL && head2!= NULL) {
        if(head1->data != head2->data) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    if(head1 != NULL || head2 != NULL) return false;
    return true;
}
