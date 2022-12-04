/*
Time Complexity: O(n)
Auxilary Spave: O(1)

We don't requre to create another list with values, just work with the addresses of given two list
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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(-1);
        ListNode* tmp = head;
        while(list1 != NULL && list2 != NULL) {
            if(list1->val < list2->val) {
                tmp->next = list1;
                list1 = list1->next;
            } 
            else {
                tmp->next = list2;
                list2 = list2->next;
            }
            tmp = tmp->next;
        }

        if(list1 != NULL) {
            tmp->next = list1;
        } else {
            tmp->next = list2;
        }
        return head->next;
    }
};

int main() {
    ListNode* l1 = new ListNode(-1);
	ListNode* l2 = new ListNode(-2);

	vector<int> a = {1, 2, 5, 8};
	vector<int> b = {3, 4, 6, 7};

	makelist(l1, a);
	makelist(l2, b);

	l1 = l1->next;
	l2 = l2->next;

	Solution sln;
	ListNode* head = sln.mergeTwoLists(l1, l2);
	PrintList(head);
}
