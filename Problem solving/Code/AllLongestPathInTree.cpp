#ifndef ONLINE_JUDGE
#include "header.h"
#else
#include<bits/stdc++.h>
#endif

#ifdef LOCAL
#include "debug.h"
#else
#define dg(...) 42
#define dg_2(...) 42
#define dg_3(...) 42
#endif
using namespace std;
#define all(x) x.begin() , x.end()
#define clr(x , y) memset(x , y , sizeof x);
#define sz(x) (int)x.size()
using lint = long long int;
const int Mod = 1e9 + 7;
const lint inf = 1e18 + 10;
const int N = 2e6;
vector<vector<int>> g;
vector<pair<int,int>> dist;
vector<int> fnode;
void dfs(int v, int p = -1) {
  for(auto i : g[v]) {
    if(i == p) continue;
    dfs(i, v);
    if(1 + dist[i].first > dist[v].first) {
      dist[v].second = dist[v].first;
      dist[v].first = 1 + dist[i].first;
    }
    else if(1 + dist[i].first > dist[v].second) {
      dist[v].second = 1 + dist[i].first;
    }
  }
  if(sz(g[v]) == 1) {
    dist[v] = {1, 1};
  }
}
void dfs2(int v, int p = -1) {
  for(auto i : g[v]) {
    if(i == p) continue;
    dg_3(v,i, dist[i]);
    if(dist[i].first + 1 == fnode[v]) {
      dg(000);
      fnode[i] = max(dist[i].first, dist[v].second);
      if(dist[v].first == dist[i].first + 1) {
        fnode[i] = max({fnode[i], dist[i].first, dist[v].second + 1});
      }
      else {
        fnode[i] = max({fnode[i], dist[i].first, dist[v].first + 1});
      }
    }
    else {
      dg(111);
      fnode[i] = max(fnode[i], fnode[v] + 1);
    }
    dg_2(i, fnode[i]);
    dfs2(i, v);
  }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    g = vector<vector<int>>(n + 1);
    dist = vector<pair<int,int>>(n + 1, {0, 0});
    fnode = vector<int>(n + 1, 0);
    for(int i = 0;i + 1 < n;i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(1);
    dg(dist);
    fnode[1] = dist[1].first;
    dfs2(1);
    dg(fnode);

}
