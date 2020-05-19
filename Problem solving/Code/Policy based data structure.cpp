/*
  author : wajiul
  topic : policy based datastructure


  St = set name

  St.find_by_order(pnt) // returns value at index pnt
  [  auto x = *St.find_by_order(pnt); ]

  St.order_of_key(val) // returns index of val

If the element does not appear in the set, we get the position that the element
would have in the set.

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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std; 
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
#define sz(x) (int)x.size()
template<typename T> void db(T x ){ debug() << x; }
template<typename T> void db(T x , T y){ debug() << x <<" "<< y; }
template<typename T> void db(T x , T y , T z){ debug() << x <<" "<< y <<" "<< z; }
template<typename T> void db(T x , T y , T z , T a){ debug() << x <<" " << y <<" "<< z <<" "<< a; }

const int xx = 2e5;
const int Mod = 1e9 + 7;
const int inf = 1e18;
const int Maxn = 20010;

signed main(){
  ios::sync_with_stdio(false);cin.tie(0);

  oset<int>St;
  oset<pair<int,int>>Stp;

}
