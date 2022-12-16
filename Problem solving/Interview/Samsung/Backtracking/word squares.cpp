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
map<string,vector<int>> mp;
vector<string> wlist;
int sqSize = 0;

void getPrefix(string s, int id) {
    string prefix = "";
    for(int i = 0;i < s.size();i++) {
        prefix += s[i];
        mp[prefix].push_back(id);
    }
}
void getSquares(int st, vector<string> square, vector<vector<string>> &res) {
    if(st == sqSize) {
        res.push_back(square);
        return;
    }
    string prefix = "";
    for(int i = 1, j = 0;i <= st;i++, j++) {
        prefix += square[j][st];
    }

    if(mp.find(prefix) != mp.end()) {
        for(int id: mp[prefix]) {
            square[st] = list[id];
            getSquares(st + 1, square, res);
        }
    }
}
vector<vector<string>> wordSquares(vector<string> &arr) {
    vector<vector<string>> res;
    mp.clear();
    list.clear();
    if(arr.size() == 0) return res;
    list = arr;
    sqSize = arr[0].size();

    for(int i = 0;i < arr.size();i++) {
        getPrefix(arr[i], i);
    }

    for(auto i : arr) {
        vector<string> sq(sqSize, i);
        getSquares(1, sq, res);
    }
    return res;
}
void solve() {
    int n;
    cin >> n;
    vector<string> word(n);
    for(int i = 0;i < n;i++) {
        cin >> word[i];
    }
    vector<vector<string>> ans = wordSquares(word);
    dg(ans);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Ts(true);
}
