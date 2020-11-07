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
#include<bitset>
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

// #define int long long
#define all(x) x.begin() , x.end()
#define clr(x , y) memset(x , y , sizeof x);
#define sz(x) (int)x.size()

const int Mod = 1e9 + 7;
// const int inf = 1e18;

const int Max = 1e4 + 2;
bitset<Max>B[Max];
vector<vector<int>>g , P;
vector<int>L , T;
void dfs(int n, int p)
{
  for(auto i : g[n]) {
    if(i == p) continue;
    T[i] = n;
    L[i] = L[n] + 1;
    dfs(i , n);
  }
}
 
int lca(int p, int q)
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
 
void lca_init(int N)
  {
      
      P = vector<vector<int>>(N + 1 , vector<int>(22, -1));
      int i, j;
       for (i = 0; i < N; i++)
          P[i][0] = T[i];
      for (j = 1; 1 << j < N; j++)
         for (i = 0; i < N; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];
 }
 void Reset(int n) {
   for(int i = 0;i <= n; i++) {
     B[i].reset();
   }
 }
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, cs = 0;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    g = vector<vector<int>>(n + 1);
    T = L = vector<int>(n + 1);
    Reset(n);

    for(int i = 0; i + 1 < n; i++) {
      int a , b;
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    dfs(1,1);
    lca_init(n+1);
    for(int i = 1; i <= n; i++) {
      int parent = i;
      while(1) {
        B[i][parent] = 1;
        if(parent == 1) break;
        parent = T[parent];
      }
    }

    int q;
    cin >> q;
    dg(q);
    cout << "Case " << ++cs <<":" << '\n';
    while(q--){
      bitset<Max> ans;
      ans.set();
      int k;
      cin >> k;
      dg(k);
      for(int i = 0;i < k; i++) {
        int a, b;
        cin >> a >> b;
        int Lc = lca(a,b);
        if(Lc == 1) {
          ans = ans & (B[a] | B[b]);
        }else{
          ans = ans & ((B[a] | B[b]) ^ B[T[Lc]]);
        }
      }
      cout << ans.count() << '\n';
    }
  }
}
