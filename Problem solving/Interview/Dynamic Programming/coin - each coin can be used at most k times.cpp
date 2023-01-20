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
const int N = 2e6;
const int maxn = 2e9;
int a[200];
int dp[105][10005];
int cal(int n, int amount, int k) {
    if(amount == 0) return 1;
    if(n <= 0 || amount < 0) return 0;
    if(k <= 0) return 0;
    if(dp[n][amount] != -1) return dp[n][amount];
    return dp[n][amount] = ( cal(n, amount - a[n - 1], k - 1) + cal(n - 1, amount, k) % Mod) % Mod;
}
int tc = 0;
void solve() {
    int n, k;
    cin >> n >> k;
    memset(dp, -1, sizeof dp);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    int ans = cal(n, k, k);
    cout << "Case " << ++tc <<": " << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Ts(true);
}
