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
const int maxn = 200000;

struct Gate{
    int pos, cnt_men;
}gates[4];

int ans, n;
bool spots[100];
int findLeft(int p) {
    for(int i = p;i > 0;i--) {
        if(!spots[i]) {
            return i;
        }
    }
    return maxn;
}

int findRight(int p) {
    for(int i = p + 1;i <= n;i++) {
        if(!spots[i]) {
            return i;
        }
    }
    return maxn;
}

void solve(vector<int> p, int cur_gate, int cost) {
    if(cost > ans) return;
    if(gates[cur_gate].cnt_men == 0) {
		if(cur_gate == p.back()) {
			ans = min(ans, cost);
			return;
		}
		for(int i = 0;i + 1 < (int)p.size();i++) {
			if(cur_gate == p[i]) {
				cur_gate = p[i + 1];
				break;
			}
		}
    }

    int L = findLeft(gates[cur_gate].pos);
    int R = findRight(gates[cur_gate].pos);
    int cL = abs(gates[cur_gate].pos - L) + 1;
    int cR = abs(gates[cur_gate].pos - R) + 1;
    bool goLeft = true, goRight = true;

    if(cL > cR) goLeft = false;
    if(cR > cL) goRight = false;

    if(goLeft) {
        spots[L] = true;
        gates[cur_gate].cnt_men--;
        solve(p ,cur_gate, cost + cL);
        spots[L] = false;
        gates[cur_gate].cnt_men++;
    }

    if(goRight) {
        spots[R] = true;
        gates[cur_gate].cnt_men--;
        solve(p, cur_gate, cost + cR);
        spots[R] = false;
        gates[cur_gate].cnt_men++;
    }
}
void solve() {
    
    cin >> n;
    for(int i = 1;i <= 3;i++) {
        cin >> gates[i].pos >> gates[i].cnt_men;
    }
    vector<int> g = {1, 2, 3};
    for(int i = 0;i < 100;i++) {
        spots[i] = false;
    }
    ans = maxn;   
    do {
        solve(g, g[0], 0);
        dg(ans, g);  
    } while(next_permutation(g.begin(), g.end())); 

    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Ts(true);
}
