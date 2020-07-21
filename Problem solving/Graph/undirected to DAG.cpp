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
typedef vector<vector<int>> graph;
const int xx = 2e5;
const int Mod = 1e9 + 7;
const int inf = 1e18;
const int Maxn = 20010;

graph g;
vector<int>vis;

signed main(){
  ios::sync_with_stdio(false);cin.tie(0);

  int n , m;
  cin >> n >> m;
  g = graph(n);
  vector<pair<int,int>>edges;
  for(int i = 0; i < m; i++) {
    int u , v;
    cin >> u >> v;
    u-- , v--;
    g[u].push_back(v);
    g[v].push_back(u);
    edges.push_back({u , v});
  }
  vis = vector<int>(n);
  map<pair<int,int>,int>dir;
  queue<int>Q;
  Q.push(0);
  vis[0] = 1;
  while(!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for(auto i : g[u]) {
      if(vis[i]) {
        if(dir[{u , i}] == 0 && dir[{i, u}] == 0) {
          dir[{u , i}] = 1;
        }
        continue;
      }
      vis[i] = 1;
      Q.push(i);
      dir[{u , i}] = 1;
    }
  }
  for(auto [x,y] : edges) {
    if(dir[{x, y}]) {
      cout << x + 1 <<" " << y + 1 << '\n';
    } else{
      cout << y + 1 <<" " << x + 1 << '\n';
    }
  }
}
