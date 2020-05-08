/*

   author : wajiul
   problem-link: https://www.hackerrank.com/challenges/maximum-palindromes/problem

   key - concept :
   find number of distinc permutation of a string .
   distinc permutation of "ABCCDEEEEF" is
   
   1A + 1B + 2C + 4E + 1F = 10

   ANS = (10!) / (1! * 1! * 2! * 4! * 1!);

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
template<typename T> void db(T x ){ debug() << x; }
template<typename T> void db(T x , T y){ debug() << x <<" "<< y; }
template<typename T> void db(T x , T y , T z){ debug() << x <<" "<< y <<" "<< z; }
template<typename T> void db(T x , T y , T z , T a){ debug() << x <<" " << y <<" "<< z <<" "<< a; }

const int xx = 2e5;
const int Mod = 1e9 + 7;
const int inf = 1e18;
const int Maxn = 20010;
typedef long long ll;
int Cnt[xx][50];
int factorial[xx];

vector<int> fac, facInv, inv;
void facInit(int nmax)
{
    fac = facInv = inv = vector<int>(nmax + 1, 1);
    for (int i = 2; i <= nmax; i++)
    {
        fac[i] = fac[i-1] * i % Mod;
        inv[i] = Mod - inv[Mod%i] * (Mod/i) % Mod;
        facInv[i] = facInv[i-1] * inv[i] % Mod;
    }
}


signed main(){
  ios::sync_with_stdio(false);cin.tie(0);

  string s;
  int q;
  cin >> s;
  cin >> q;
  int N = sz(s);
  facInit(N);

  for(int i=0;i < N;i++){
     for(char j='a';j<='z';j++){
       int x = j - 'a' + 1;
       Cnt[i+1][x] += Cnt[i][x];
       Cnt[i+1][x] += (s[i] == j);
     }
  }

  while(q--){
    int l , r;
    cin >> l >> r;
    int ans = 1;
    int Mxl = 0 , odd = 0;
    vector<int>invc;

    for(int i=1;i<=26;i++){
      int x = Cnt[r][i] - Cnt[l-1][i];
      Mxl += x/2;
      odd += x % 2;
      if(x / 2) invc.push_back(x/2);
    }
    dg2(Mxl , odd);
    dg(invc);
    odd = max(odd , 1ll);
    ans = fac[Mxl];
    dg1(ans);
    for(auto i : invc){
      ans = ans * facInv[i];
      ans = ans % Mod;
    }
    ans = (ans * odd) % Mod;

    cout << ans << '\n';

  }
}
