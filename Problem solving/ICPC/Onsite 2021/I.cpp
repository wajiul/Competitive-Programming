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
vector<int>subSum, subCnt, a;
vector<vector<int>> g;
vector<set<pair<int,int>,greater<pair<int,int>>>> Og;
vector<pair<int,int>> ans;
int K;
void dfs(int v, int p = -1) {
    subSum[v] = a[v];
    subCnt[v] = 1;
    for(auto i : g[v]) {
        if(i == p) continue;
        dfs(i, v);
        subSum[v] += subSum[i];
        subCnt[v] += subCnt[i];
        Og[v].insert({subSum[i] - (K * subCnt[i]) , i});
    }
}
int totSum = 0;
bool Ok = true;
void dfs2(int v, int p = -1) {
    for(auto i : Og[v]) {
        int u = i.second;
        if(u == p) continue;
        //going v -> u
        if(a[u] >= K) {
            totSum += a[u] - K;
            ans.push_back({u, -(a[u] - K)});
            a[u] = K;
        }
        else if(a[u] < K && totSum + a[u] >= K) {
            totSum -= (K - a[u]);
            ans.push_back({u, K - a[u]});
            a[u] = K;
        }
        else {
            ans.push_back({u, 0});
        }
        dfs2(u, v);
        //going u -> v
        if(a[v] < K && totSum + a[v] >= K) {
            totSum -= (K - a[v]);
            ans.push_back({v, K - a[v]});
            a[v] = K;
        }
        else {
            ans.push_back({v, 0});
        }

    }
}
int tc = 0;
void solve() {
    int n;
    cin >> n >> K;
    subSum = subCnt = a = vector<int>(n + 1, 0);
    g = vector<vector<int>>(n + 1);
    Og = vector<set<pair<int,int>,greater<pair<int,int>>>>(n + 1);
    ans.clear();

    for(int i = 0;i + 1 < n;i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1;i <= n ;i++) {
        cin >> a[i];
    }
    int root = 1;
    for(int i = 1;i <= n;i++) {
        if(a[i] >= K) {
            root = i;
            break;
        }
    }
    dfs(root);
    totSum = a[root] - K;
    ans.push_back({root, -totSum});
    dfs2(root);
    cout << "Case "<< ++tc << ": YES" << '\n';
    for(auto i : ans) {
        cout << i.first << " " << i.second << '\n';
    }

}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Ts(true);
}


