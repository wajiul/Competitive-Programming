#ifndef ONLINE_JUDGE
#include "header.h"
#else
#include<bits/stdc++.h>
#endif

#ifdef LOCAL
#include "debug.h"
#else
#define dg(...) 42
#define dg_1(...) 42
#endif
using namespace std;
#define all(x) x.begin() , x.end()
#define clr(x , y) memset(x , y , sizeof x);
#define sz(x) (int)x.size()
using lint = long long int;
const int Mod = 1e9 + 7;
const lint inf = 1e18 + 10;
const int N = 2e6;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode *prev;
     ListNode() : val(0), next(nullptr), prev(nullptr) {}
     ListNode(int data) : val(data), next(nullptr), prev(nullptr) {}

};



void PrintList(ListNode *head) {
    ListNode *cur = head;
    while(cur != NULL) {
        cout << (cur->val) << " ";
        cur = cur->next;
    }
    cout << '\n';
}
void makelist(ListNode *head, vector<int> a) {
	for(int i : a) {
		ListNode* cur = new ListNode();
		cur->val = i;
		head->next = cur;
		head = head->next;
	}
}
ListNode* addFront(ListNode* h, int val) {
    ListNode* new_node = new ListNode(val);
    new_node->next = h;
    h->prev = new_node;
    h = new_node;
    return h;
} 
void addTail(ListNode *h, int val) {
    while(h->next != NULL) {
        h = h->next;
    }
    ListNode* new_node = new ListNode(val);
    new_node->prev = h;
    h->next = new_node;
}
void check(ListNode* h) {
    cout << "checking doubly link \n";
    ListNode* preh;
    while(h != NULL) {
        cout << (h->val) <<" ";
        preh = h;
        h = h->next;
    }
    cout << endl;
    while(preh != NULL) {
        cout << (preh->val) << " ";
        preh = preh->prev;
    }
    cout << endl;
}

ListNode* ReverseList(ListNode* h) {
    ListNode* pre = NULL;
    while(h != NULL) {
        ListNode* tmp = h->next;
        h->prev = h->next;
        h->next = pre;
        pre = h;
        h = tmp;
    }
    return pre;
}
int main() {
    ListNode* h = new ListNode(-1);

    h = addFront(h, 2);
    h = addFront(h, 4);
    addTail(h, 5);
    PrintList(h);
    // check(h);
    h = ReverseList(h);
    PrintList(h);
    check(h);
}
