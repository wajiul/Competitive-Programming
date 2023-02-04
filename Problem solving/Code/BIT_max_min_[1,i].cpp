/**
 * Using BIT we can do max min query like[1, i] not in [l, r] 
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
#define dg_2(...) 42
#define dg_3(...) 42
#endif
using namespace std;
#define all(x) x.begin() , x.end()
#define clr(x , y) memset(x , y , sizeof x);
#define sz(x) (int)x.size()
using lint = long long int;
#define VI vector<int>
#define VL vector<long long>
#define VIN(a, n) for(int i = 0;i < n;i++) {cin >> a[i];} 
#define YN(ok) if(ok) puts("YES"); else puts("NO");
#define PR(a,n) for(int i = 0;i < n;i++) cout << a[i] << " \n"[i == n - 1];
#define Ts(ok) if(ok) { int t; cin >> t; while(t--) solve();} else { solve(); }
const int Mod = 1e9 + 7;
const lint inf = 1e18 + 10;
const int maxn = 2e9;

vector<int> a, b;

void add(int x, int v, int N) {
    while (x < N) {
        a[x] = min(a[x], v);
        b[x] = max(b[x], v);
        x += x & (-x);
    }
}

int findMin(int x) {
    int res = maxn;
    while (x > 0) {
        res = min(res, a[x]);
        x -= x & (-x);
    }
    return res;
}
int findMax(int x) {
    int res = -maxn;
    while(x > 0) {
        res = max(res, b[x]);
        x -= x & (-x);
    }
    return res;
}

void solve() {
    int n, q;
    cin >> n;
    a = vector<int> (n + 1, maxn);
    b = vector<int>(n + 1, -maxn);

    vector<int> c(n + 1);
    for(int i = 1;i <= n;i++) {
        cin >> c[i];
    }
    for(int i = 1;i <= n;i++) {
        add(i, c[i], n + 1);
    }

    int mn = findMin(5);
    int mx = findMax(5);
    dg(mn, mx);

}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Ts(false);
}
