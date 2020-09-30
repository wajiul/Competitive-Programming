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
#define dg1(x) debug() << "[line : " << __LINE__ <<"]"<< pp(x)
#define dg2(x,y) debug() << "[line : " << __LINE__ <<"]"<< pp(x) pp(y)
#define dg3(x,y,z) debug() << "[line : " << __LINE__ <<"]"<< pp(x) pp(y) pp(z)
#define dg4(w,x,y,z) debug() << "[line : " << __LINE__ <<"]"<< pp(w) pp(x) pp(y) pp(z)
template<typename T> void db(T x ){ debug() <<">>> " <<  x; }
template<typename T> void db(T x , T y){ debug() <<">>> " <<  x <<" , "<< y; }
template<typename T> void db(T x , T y , T z){ debug() <<">>> "<< x <<" , "<< y <<" , "<< z; }
template<typename T> void db(T x , T y , T z , T a){ debug() <<">>> "<< x <<" , " << y <<" , "<< z <<" , "<< a; }
#define int long long
#define all(x) x.begin() , x.end()
#define clr(x , y) memset(x , y , sizeof x);
#define sz(x) (int)x.size()
const int Mod = 1e9 + 7;

class Mint {
  private:
  int value;
  static const int MOD = 1e9 + 7;
  public:
  int M = MOD;
  Mint(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
  Mint(long long a, long long b) : value(0){ *this += a; *this /= b;}

  Mint& operator+=(Mint const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
  Mint& operator-=(Mint const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
  Mint& operator*=(Mint const& b) {value = (long long)value * b.value % MOD;return *this;}

  friend Mint mexp(Mint a, long long e) {
    Mint res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
    return res;
  }
  friend Mint inverse(Mint a) { return mexp(a, MOD - 2); }

  Mint& operator/=(Mint const& b) { return *this *= inverse(b); }
  friend Mint operator+(Mint a, Mint const b) { return a += b; }
  friend Mint operator-(Mint a, Mint const b) { return a -= b; }
  friend Mint operator-(Mint const a) { return 0 - a; }
  friend Mint operator*(Mint a, Mint const b) { return a *= b; }
  friend Mint operator/(Mint a, Mint const b) { return a /= b; }
  friend std::ostream& operator<<(std::ostream& os, Mint const& a) {return os << a.value;}
  friend bool operator==(Mint const& a, Mint const& b) {return a.value == b.value;}
  friend bool operator!=(Mint const& a, Mint const& b) {return a.value != b.value;}
  friend bool operator>(Mint const& a, Mint const& b) {return a.value > b.value;}
  friend bool operator>=(Mint const& a, Mint const& b) {return a.value >= b.value;}
  friend bool operator<(Mint const& a, Mint const& b) {return a.value < b.value;}
  friend bool operator<=(Mint const& a, Mint const& b) {return a.value <= b.value;}
};
vector<Mint> fac , facInv , inv;
void genC(int n) {
  fac = facInv = inv = vector<Mint>(n+1 , 1);
  Mint tmp; int MOD = tmp.M;
  for(int i = 2; i <= n; i++) {
      fac[i] = fac[i-1] * i ;
      inv[i] = MOD - ( inv[MOD%i] * (MOD/i) );
      facInv[i] = facInv[i-1] * inv[i];
    }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<Mint> v(3,1);
  Mint a,b;
  b = 3;
  // b++;
  int c = 5;
  b = c - b;
  a = mexp(b, 3);
  cout << " >" << b.M << '\n';
  cout << a << '\n';
  genC(10);
  for(int i = 1; i <= 7; i++) {
    cout << fac[i] << " " << facInv[i] << '\n';
  }
  int x = 10000;
  int y = 1000000;
  int z = 100000;
  Mint mul = x * y * z;
  cout << mul << '\n';
  //------------------------
  // Mint a;
  // a = 5;
  // Mint b = 4;
  // Mint c;
  // c = mexp(b,2);
  // cout << c << '\n';
  // cout << a << '\n';
}
