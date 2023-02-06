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
vector<int> a, L;
vector<vector<int>> g;
vector<lint> h1, h2;

lint Pow(lint x , lint y){
  lint res = 1;
  while(y>0){
      if(y&1)
          res = (res*x) % Mod;
      y=y>>1;
      x = (x*x) % Mod;
  }
  return res % Mod;
}
        
lint Base = 31;
void dfs(int v, int p) {
    for(auto i : g[v]) {
        if(i == p) continue;
        L[i] = L[v] + 1;
        h1[i] = (h1[v] + (Pow(Base, L[v]) * a[i])) % Mod;
        h2[i] = ((h2[v] * Base) + a[i]) % Mod;
        dfs(i, v);
    }
}
int tc = 0;
void solve() {
    int n;
    cin >> n;
    a = L = vector<int>(n + 1);
    g = vector<vector<int>> (n + 1);
    h1 = h2 = vector<lint>(n + 1);
    string s;
    cin >> s;
    for(int i = 1;i <= n;i++) {
        a[i] = s[i - 1] - 'A';
    }

    for(int i = 0;i + 1 < n;i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    h1[1] = h2[1] = a[1];
    L[1] = 1;
    dfs(1, -1);
    int cnt = 0;
    for(int i = 1;i <= n;i++) {
        if(h1[i] == h2[i]) {
            cnt++;
        }
    }

    dg(cnt);
    int gc = __gcd(cnt, n);
    cnt /= gc;
    n /= gc;
    cout << "Case " << ++tc <<": " << cnt << "/" << n << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Ts(true);
}
