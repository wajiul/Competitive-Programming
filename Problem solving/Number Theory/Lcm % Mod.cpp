
/*
  problem-link: https://atcoder.jp/contests/abc152/tasks/abc152_e
  
     To find Lcm % Mod we need to calculate it from prime factorization.
     Normal Lcm = a * (b / __gcd(a,b)) don't work.
*/

#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<math.h>
#include<tuple>
#include<string.h>
#include <numeric> 
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std; 
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define pp(...) "\033[94m [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]\033[0m"
#define pp1(...) "\033[1;47;35m" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]\033[0m"
#define dg(x) debug() << pp1(x)
#define dg1(x) debug() << pp(x)
#define dg2(x,y) debug() << pp(x) pp(y)
#define dg3(x,y,z) debug() << pp(x) pp(y) pp(z)
#define dg4(w,x,y,z) debug() << pp(w) pp(x) pp(y) pp(z)
#define int long long
#define all(x) x.begin() , x.end()
#define clr(x) memset(x , 0 , sizeof x);
#define sz(x) (int)x.size()
template<typename T> void db(T x ){ debug() <<">>> " <<  x; }
template<typename T> void db(T x , T y){ debug() <<">>> " <<  x <<" , "<< y; }
template<typename T> void db(T x , T y , T z){ debug() <<">>> "<< x <<" , "<< y <<" , "<< z; }
template<typename T> void db(T x , T y , T z , T a){ debug() <<">>> "<< x <<" , " << y <<" , "<< z <<" , "<< a; }
const int xx = 2e6 ;
const int Mod = 1e9 + 7;
const int inf = 1e18;
const int Maxn = 20010;

int Pow(int x , int y , int mod){
  int res = 1;
  while(y>0){
      if(y&1)
          res = (res*x) % mod;
      y=y>>1;
      x = (x*x) % mod;
  }
  return res % mod;
}

vector<int> prime;
int p[xx + 10], pw[xx + 10];

void Sieve(int n) {
  for(int i = 2; i * i <= n; i++) {
    if(p[i]) continue;
    for(int j = i * i; j <= n; j += i) {
      p[j] = 1;
    }
  }
  prime.push_back(2);
  for(int i = 3; i <= n; i++) {
    if(!p[i]) prime.push_back(i);
  }
}

void factorize(int n) {
  for(int i = 0; prime[i] <= n; i++) {
    int x = prime[i];
    if(x * x > n ) x = n;
    if(n % x == 0) {
      int cnt = 0;
      while(n % x == 0) { 
        n /= x;
        cnt++;
      }
      pw[x] = max(pw[x] , cnt);
    }
  }
} 
signed main(){
  ios::sync_with_stdio(false);cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int Mx = *max_element(all(a));
  Sieve(Mx);
  for(int i = 0; i < n; i++) {
    factorize(a[i]);
  }
  dg1(pw);
  int Lcm = 1;
  for(int i = 0; i <= Mx; i++ ) {
    if(pw[i] != 0) {
      Lcm = Lcm * Pow(i , pw[i] , Mod);
      Lcm = Lcm % Mod;
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans += (Lcm * Pow(a[i] , Mod - 2 , Mod));
    ans = ans % Mod;
  }
  cout << ans << '\n';
}
