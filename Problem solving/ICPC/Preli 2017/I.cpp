/*
 source: https://cp-algorithms.com/algebra/phi-function.html
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
//Macro overload
#define PP_CAT( A, B ) A ## B
#define PP_EXPAND(...) __VA_ARGS__

// Macro overloading feature support
#define PP_VA_ARG_SIZE(...) PP_EXPAND(PP_APPLY_ARG_N((PP_ZERO_ARGS_DETECT(__VA_ARGS__), PP_RSEQ_N)))

#define PP_ZERO_ARGS_DETECT(...) PP_EXPAND(PP_ZERO_ARGS_DETECT_PREFIX_ ## __VA_ARGS__ ## _ZERO_ARGS_DETECT_SUFFIX)
#define PP_ZERO_ARGS_DETECT_PREFIX__ZERO_ARGS_DETECT_SUFFIX ,,,,,,,,,,,0

#define PP_APPLY_ARG_N(ARGS) PP_EXPAND(PP_ARG_N ARGS)
#define PP_ARG_N(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N,...) N
#define PP_RSEQ_N 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0

#define PP_OVERLOAD_SELECT(NAME, NUM) PP_CAT( NAME ## _, NUM)
#define PP_MACRO_OVERLOAD(NAME, ...) PP_OVERLOAD_SELECT(NAME, PP_VA_ARG_SIZE(__VA_ARGS__))(__VA_ARGS__)
//Overload dg_
#define dg(...)       PP_MACRO_OVERLOAD(dg, __VA_ARGS__)
#define dg_1(x) debug() <<"\033[0;33mLine(" << __LINE__ <<")\033[0m"<<"\033[1;36m->"<<"\033[0m"<< pp(x)
#define dg_2(x,y) debug() << "\033[0;33mLine(" << __LINE__ <<")\033[0m"<<"\033[1;36m->"<<"\033[0m"<< pp(x) pp(y)
#define dg_3(x,y,z) debug() << "\033[0;33mLine(" << __LINE__ <<")\033[0m"<<"\033[1;36m->"<<"\033[0m"<< pp(x) pp(y) pp(z)
#define dg_4(w,x,y,z) debug() << "\033[0;33mLine(" << __LINE__ <<")\033[0m"<<"\033[1;36m->"<<"\033[0m"<< pp(w) pp(x) pp(y) pp(z)
#define dg_5(w,x,y,z,z1) debug() << "\033[0;33mLine(" << __LINE__ <<")\033[0m"<<"\033[1;36m->"<<"\033[0m"<< pp(w) pp(x) pp(y) pp(z) pp(z1)
#define dg_6(w,x,y,z,z1,z2) debug() << "\033[0;33mLine(" << __LINE__ <<")\033[0m"<<"\033[1;36m->"<<"\033[0m"<< pp(w) pp(x) pp(y) pp(z) pp(z1) pp(z2)

#define int long long
#define all(x) x.begin() , x.end()
#define clr(x , y) memset(x , y , sizeof x);
#define sz(x) (int)x.size()

const int Mod = 1e9 + 7;
const int inf = 1e18;
typedef long long LL;
LL StringMod( string s , LL m) {
    LL ret = 0;
    for( int i = 0; i < s.size(); i++ ) {
        ret = ( (ret%m*10%m)%m+(s[i]-'0')%m )%m;
    }
    return ret%m;
}


int Pow(int x , int y , int mod = 9){
  int res = 1;
  while(y>0){
      if(y&1)
          res = (res*x) % mod;
      y=y>>1;
      x = (x*x) % mod;
  }
  return res % mod;
}
int to_int(string s) {
	int ans = 0;
	for(int i = 0;i < sz(s); i++) {
		ans = (ans * 10) + (s[i] - '0');
	}
	return ans;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t,cs=0;
  cin >> t;
  while(t--){
	  string a , b;
	  cin >> a;
	  cin >> b;
	  int ans = 0;
	  if(sz(b) <= 2) {
		  int p = to_int(b);
		  int base = StringMod(a, 9);
		  ans = Pow(base , p);
	  }
	  else {
		int p = StringMod(b , 6);
		int base = StringMod(a, 9);
		p += 6;
		ans = Pow(base , p);
	  }
	  if(ans == 0 && a[0] != '0') ans = 9;
	  cout << "Case " << ++cs <<": " << ans << '\n'; 
  }
}
