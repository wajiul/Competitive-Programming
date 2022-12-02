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

template<typename T>
class MyStack {
  private:
  struct Node {
    T data;
    Node *next;
    Node(T n, Node *nxt) {
      data = n;
      next = nxt;
    }
  }*head;

  public:
  MyStack() {
    head = NULL;
  }

  void push(T n) {
    Node* cur_node = new Node(n, head);
    cur_node->next = head;
    head = cur_node;
  }
  void pop() {
    head = head->next;
  }
  T top() {
    return head->data;
  }
  bool empty() {
    return head == NULL;
  }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    MyStack<char> stk;
    stk.push('a');
    stk.push('b');

    while(!stk.empty()) {
      cout << stk.top() << endl;
      stk.pop();
    }

    MyStack<string> sts;
    sts.push("abc");
    sts.push("hgh");

    while(!sts.empty()) {
      cout << sts.top() << endl;
      sts.pop();
    }
}
