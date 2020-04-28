/*
 author : wajiul
 date : 28 - april - 2020
 problem link: https://codeforces.com/contest/1342/problem/C

 It's quite easy to see that ((ab+x) mod a)mod b=(x mod a)mod b.
 What does it mean? The property given in the statement holds for x if and only if it holds 
 for  x mod ab . And these values of (x % ab) will be [0 - max(a,b)-1].

 Let's say X=x+kab
 If (X%a) % b = (X%b) % a then ((x+kab) % a) % b = ((x+kab)%b) % a that means (x%a)%b = (x%b)%a
 So if X satisfies the condition, so does X mod ab.

 Pattern of the solution below:

 Basically all the numbers which fall in the range of [k*lcm, k*lcm + max(a,b) - 1]
 (k is any integer) have equal moduli.

*/

#include<bits/stdc++.h>
using namespace std; 
signed main(){
  ios::sync_with_stdio(false);cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int a, b , q;
    cin >> a >> b >> q;
    int lcm = a*b/(__gcd(a,b));
    int M = max(a,b);
    auto query = [&](int n){
      int k = n / lcm;
      int ans = k * M;
      int x = min(k * lcm + M - 1 , n) - (k * lcm);
      ans += x;
      return ans;
    };
    while(q--){
      int l , r;
      cin >> l >> r;
      int x = (r - l + 1) - (query(r) - query(l-1));
      cout << x << " ";
    }
    cout << '\n';
  }
}
