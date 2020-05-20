/*

 author : wajiul
 problem-link : 

 topic : counting inversion in O(n)

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
#define dg(x) debug() << pp1(x)
#define dg1(x) debug() << pp(x)
#define dg2(x,y) debug() << pp(x) pp(y)
#define dg3(x,y,z) debug() << pp(x) pp(y) pp(z)
#define dg4(w,x,y,z) debug() << pp(w) pp(x) pp(y) pp(z)
#define int long long
#define all(x) x.begin() , x.end()
#define sz(x) (int)x.size()
template<typename T> void db(T x ){ debug() <<">>> " <<  x; }
template<typename T> void db(T x , T y){ debug() <<">>> " <<  x <<" , "<< y; }
template<typename T> void db(T x , T y , T z){ debug() <<">>> "<< x <<" , "<< y <<" , "<< z; }
template<typename T> void db(T x , T y , T z , T a){ debug() <<">>> "<< x <<" , " << y <<" , "<< z <<" , "<< a; }

const int xx = 2e5;
const int Mod = 1e9 + 7;
const int inf = 1e18;
const int Maxn = 20010;

int brute(vector<int>&A , int n){
  int cnt = 0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i < j && A[i] > A[j]) cnt++;
    }
  }
  return cnt;
}
signed main(){
  ios::sync_with_stdio(false);cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<int>A(n+1);
    for(int i=1;i<=n;i++){
      cin >> A[i];
    }

      dg(brute(A , n));
    int ans = 0;
    bool ok = true;
    for(int i=n;i>=1;i--){
      if(A[i] == i) continue;

      if(i > 1 && i == A[i-1]){
        ans++;
        swap(A[i] , A[i-1]);
      }
      else if(i > 2 && i == A[i-2]){
        ans+=2;
        swap(A[i-2] , A[i-1]);
        swap(A[i-1] , A[i]);
      }
      else ok = false;
    }
    if(ok){
      cout << ans << '\n';
    }
    else cout << "Too Chaotic" << '\n';
  }
}
