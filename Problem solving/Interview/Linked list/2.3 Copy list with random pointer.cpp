/**
 * Add depclone node between each node
 *  A -> B -> C -> D -> null
 * A -> A' -> B -> B' -> C -> C' -> D -> D' -> null
 */

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
        Node *node = head, *nextNode;
        while (node) {
            nextNode = node->next;
            node->next = new Node(node->val);
            node->next->next = nextNode;
            node = nextNode;
        }
        node = head;
        while (node) {
            node->next->random = node->random ? node->random->next : nullptr;
            node = node->next->next;
        }
        Node *psuedoHead = new Node(0), *copyNode = psuedoHead;
        node = head;
        while (node) {
            copyNode->next = node->next;
            copyNode = node->next;
            node->next = node->next->next;
            node = node->next;
        }
         return psuedoHead->next;
        }
};
