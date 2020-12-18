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
// const int inf = 1e18;
const int Maxn = 1e5;
vector<vector<pair<int,int>>> g;
vector<int>subt;
vector<pair<int,int>> cont;
int tot = 0, sum = 0  ;
int dfs(int n, int wt , int p = -1) {
  subt[n] = 1;
  for(auto i : g[n]) {
    if(i.first == p) continue;
    subt[n] += dfs(i.first , i.second , n);
  }
  if(p > -1ll) {
    int c = tot - subt[n];
    int d = (c * subt[n]);
    sum += (d * wt);
    dg_4(n , subt[n] , d , wt);
    if(wt < 0) {
      cont.push_back({d , wt});
    }
  }
  return subt[n];
}
signed main() {
  int t, cs = 0;
  scanf("%lld", &t);
  while(t--) {
    int n;
    scanf("%lld", &n);
    g = vector<vector<pair<int,int>>>(n + 1);
    subt = vector<int>(n + 1,0);
    cont.clear();
    tot = n , sum = 0;
    for(int i = 1; i < n;i++) {
      int u , v , w;
      scanf("%lld %lld %lld", &u, &v, &w);
      g[u].push_back({v , w});
      g[v].push_back({u, w});
    }
    dfs(1, 0);
    dg(subt);
    sort(cont.rbegin() , cont.rend());
    dg(cont);
    int ans  = 0;
    int need = abs(sum);
    dg(sum);
    if(sum < 0)  {
      for(int i = 0;i < sz(cont) && need > 0; i++) {
        int Maxinc = (cont[i].second * -1ll);
        int oneinc = cont[i].first;
        int cnt = need / oneinc + (need % oneinc != 0);
        int x = min(Maxinc , cnt);
        dg(Maxinc , oneinc , cnt , x);
        dg(x * oneinc, need);
        need -= (x * oneinc);
        ans += x;
      }
    }
    printf("Case %lld: %lld\n", ++cs, ans);
  }
}
