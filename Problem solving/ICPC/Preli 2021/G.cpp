#include<bits/stdc++.h>


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
vector<vector<int>> g;
vector<int> dist;

void dfs(int v, int p = -1) {
    for(auto i : g[v]) {
        if(i == p) continue;
        dist[i] = dist[v] + 1;
        dfs(i, v);
    }
}
int tc = 0;
void solve() {
    int n;
    cin >> n;
    vector<int> w(n + 1);
    dist = vector<int>(n + 1, 0);
    g = vector<vector<int>>(n + 1);
    for(int i = 1;i <= n;i++) {
        cin >> w[i];
    }
    for(int i = 2;i <= n;i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    vector<int> sum(2, 0), cnt(2, 0);
    for(int i = 1;i <= n;i++) {
        sum[dist[i] % 2] += w[i];
        cnt[dist[i] % 2] += 1;
    }

    int vertex = 1;
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        int id = dist[i] % 2;
        int cur = ((w[i] * cnt[id]) - (sum[id])) + ((sum[id ^ 1]) - (w[i] * cnt[id ^ 1]));
        if(cur > ans) {
            ans = cur;
            vertex = i;
        }
    }
    cout << "Case " << ++tc << ": " << vertex << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Ts(true);
}
