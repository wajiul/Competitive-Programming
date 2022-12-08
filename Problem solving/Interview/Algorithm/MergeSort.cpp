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

template<typename T>
void Merge(vector<T> &a, int l, int Mid, int r) {
    int p1 = Mid - l + 1;
    int p2 = r - Mid;
    T L[p1], R[p2];
    for(int i = 0;i < p1;i++) {
        L[i] = a[l + i];
    }
    for(int i = 0;i < p2;i++) {
        R[i] = a[Mid + 1 + i];
    }
    int li = 0, ri = 0, k = l;
    while(li < p1 && ri < p2) {
        if(L[li] < R[ri]) {
            a[k] = L[li];
            li++;
        }
        else{
            a[k] = R[ri];
            ri++;
        }
        k++;
    }

    while(li < p1) {
        a[k] = L[li];
        li++;
        k++;
    }
    while(ri < p2) {
        a[k] = R[ri];
        ri++;
        k++;
    }
}

template<typename T>
void MergeSort(vector<T> &a, int l, int r) {
    if(l < r) {
        int Mid = l + (r - l)/2;
        MergeSort(a, l, Mid);
        MergeSort(a, Mid + 1, r);
        Merge(a, l, Mid, r);
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    MergeSort(a, 0, n - 1);
    dg(a);
}
