/**
 * Time: O(n)
 * Space: O(1)
 * 
 */
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
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
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
int main() {
    ListNode* h = new ListNode(-1);
	vector<int> a = {1, 2, 3, 4, 5};
	makelist(h, a);
	h = h->next;

	ListNode *prev = NULL;
	ListNode *cur = h;

	PrintList(h);
	while(cur != NULL) {
		ListNode *tmp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = tmp;
	}
	PrintList(prev);
}
