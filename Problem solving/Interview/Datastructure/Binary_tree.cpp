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

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int n) {
        data = n;
        left = NULL;
        right = NULL;
    }
};

Node* create_node(int n) {
    Node* new_node = new Node(n);
    return new_node;
}
void add_left_child(Node* root, Node* child) {
    root->left = child;
}
void add_right_child(Node* root, Node* child) {
    root->right = child;
}

void dfs(Node *root) {
    cout << root->data << endl;
    if(root->left != NULL) {
       dfs(root->left);
    }
    if(root->right != NULL) {
        dfs(root->right);
    }
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Node* root = NULL;

    Node* two = create_node(2);
    root = two;
    Node *three = create_node(3);
    Node *five = create_node(5);
    Node *seven = create_node(7);
    Node *nine = create_node(9);


    add_left_child(two, three);
    add_right_child(two, five);
    add_left_child(five, seven);
    add_right_child(five, nine);

    dfs(root);
    
    // cout << root->data << endl;
    // root = root->right;
    // cout << root->data << endl;
    // root = root->right;
    // cout << root->data << endl;
}
