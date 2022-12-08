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
int Partition(vector<T> &a, int l, int r) {
    int pivot = a[r];
    int index = l - 1;
    for(int i = l;i <= r - 1;i++) {
        if(a[i] < pivot) {
            index++;
            swap(a[index], a[i]);
        }
    }
    swap(a[index + 1], a[r]);
    return index + 1;
}

template<typename T>
void QuickSort(vector<T> &a, int l, int r) {
    if(l < r) {
        int pind = Partition(a, l, r);
        QuickSort(a, l, pind - 1);
        QuickSort(a, pind + 1, r);
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
    QuickSort(a, 0, n - 1);
    dg(a);
}
