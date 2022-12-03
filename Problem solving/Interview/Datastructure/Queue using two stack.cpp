/*
push element in stack a.
when front() is asked and b is empty then push all element of a to b
and do similar for pop
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
const int N = 2e6;
const int maxn = 2e9;
stack<int> a, b;
void push(int n) {
	a.push(n);
}
int front() {
	if(b.empty()) {
		while(!a.empty()) {
			b.push(a.top());
			a.pop();
		}
	}
	return b.top();
}
void pop() {
	if(b.empty()) {
		while(!a.empty()) {
			b.push(a.top());
			a.pop();
		}
	}
	b.pop();
}
void solve() {
	
	push(4);
	push(5);
	cout << front() << endl;
	pop();
	push(10);
	cout << front() << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	Ts(false);
}
