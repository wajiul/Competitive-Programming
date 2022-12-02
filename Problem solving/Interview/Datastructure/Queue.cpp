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
class MyQueue {
    private:
    struct Node {
        int data;
        Node *link;
    }*Front, *Rear;
    public:
    MyQueue() {
        Front = NULL, Rear = NULL;
    }
    void push(T n) {
        Node* curNode = new Node();
        curNode->data = n;
        curNode->link = NULL;
        if(Front == NULL) {
            Front = curNode;
            Rear = curNode;
        }
        else {
            Rear->link = curNode;
            Rear = curNode;
        }
    }

    T front() {
        return Front->data;
    }
    T rear() {
        return Rear->data;
    }
    void pop() {
        Front = Front->link;
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    MyQueue<char> q;
    q.push('a');
    q.push('c');
    q.push('d');
    q.push('e');
    cout << q.front() << endl;
    cout << q.rear() << endl;
}
