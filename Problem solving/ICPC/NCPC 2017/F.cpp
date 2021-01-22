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
#include<stdio.h>
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

#define sf(...)   PP_MACRO_OVERLOAD(sf, __VA_ARGS__)
#define sf_1(x)   scanf("%d",&x);
#define sf_2(x, y) scanf("%d %d", &x,&y);
#define sf_3(x, y, z) scanf("%d %d %d", &x,&y,&z);

// #define int long long
#define all(x) x.begin() , x.end()
#define clr(x , y) memset(x , y , sizeof x);
#define sz(x) (int)x.size()
using lint = long long int;
const int Mod = 1e9 + 7;
const lint inf = 1e18;
const int N = 2e5 + 10;
int P[N][25];
int L[N] , T[N];
void lca_init(int node) {
  P[node][0] = T[node];
  for(int i = 1; (1 << i) < N; i++) {
    if(P[node][i - 1] != -1) {
      P[node][i] = P[P[node][i - 1]][i - 1];
    }
  }
}
int lca_query(int p, int q) 
  {
      int tmp, log, i;

      if (L[p] < L[q])
          tmp = p, p = q, q = tmp;

        log=1;
      while(1) {
        int next=log+1;
        if((1<<next)>L[p])break;
        log++;

      }

        for (i = log; i >= 0; i--)
          if (L[p] - (1 << i) >= L[q])
              p = P[p][i];

      if (p == q)
          return p;

        for (i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
              p = P[p][i], q = P[q][i];

      return T[p];
  }

signed main() {
  int t , cs = 0;
    sf(t);
  while(t--) {
    memset(P, -1, sizeof P);
    memset(L, 0, sizeof L);
    memset(T, 0, sizeof T);
    int q;
    sf(q);
    unordered_map<int,int>mp;
    mp[1] = 0;
    L[0] = 0;
    lca_init(0);
    int curId = 1;

    printf("Case %d:\n",++cs);
    while(q--) {
      int id , u , v;
      sf(id , u, v);

      if(id == 1) {
        mp[v] = curId;
        curId++;
        int parent = mp[u];
        int child = mp[v];
        T[child] = parent;
        L[child] = L[parent] + 1;
        lca_init(child);
      }
      else if(id == 2) {
        int cur = mp[u];
        mp.erase(u);
        mp[v] = cur;
      }
      else {
        int a = mp[u];
        int b = mp[v];
        int l = lca_query(a, b);
        int ans = L[a] + L[b] - 2*L[l];
        printf("%d\n",ans); 
      }
    }
  }
}
