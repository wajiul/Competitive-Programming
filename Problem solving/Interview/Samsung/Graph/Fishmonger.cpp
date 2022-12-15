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
#define inf 0x3f3f3f3f
const int N = 2e6;
const int maxn = 2e9;
vector<vector<pair<int,int>>> g;
int Tm[55][55];
int cost[55][1005], vis[55][55];
void SPF(int src, int des, int m) {
    memset(vis, 0, sizeof vis);
    memset(cost, inf, sizeof cost);
    queue<pair<int,int>> q;
    q.push({src, 0});
    cost[src][0] = 0;

    while(!q.empty()) {
        auto [v, t] = q.front(); q.pop();
        vis[v][t] = false;
        for(auto to : g[v]) {
            int new_time = t + Tm[v][to.first];
            if(new_time > m) continue;
            if(cost[to.first][new_time] > cost[v][t] + to.second) {
                cost[to.first][new_time] = cost[v][t] + to.second;
                vis[to.first][new_time] = true;
                q.push({to.first, new_time});
            }
        }
    }

    int ans = maxn, t = maxn;
    for(int i = 0;i <= m;i++) {
        if(cost[des - 1][i] < ans) {
            ans = cost[des - 1][i];
            t = i;
        }
    }

    cout << ans << " " << t << '\n';

}
void solve(int n, int m) {
    g = vector<vector<pair<int,int>>>(n + 1);

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cin >> Tm[i][j];
        }
    }
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            int x;
            cin >> x;
            if(i == j) continue;
            g[i].push_back({j, x});
        }
    }
    SPF(0, n, m);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while(cin >> n >> m) {
        if(!n && !m) break;
        solve(n, m);
    }
}
