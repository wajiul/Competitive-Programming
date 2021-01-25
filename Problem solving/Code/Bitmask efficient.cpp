#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ll n, INF = (ll) 1e18 + 1;
    int k;
    cin >> n >> k;
    vector <ll> a(k), lcm(1 << k);
    for(ll &x : a)
        cin >> x;
 
    auto myLcm = [&](ll a, ll b){
        if (a == INF || b == INF)
            return INF;
        a /= __gcd(a, b);
        if (b > n / a)
            return INF;
        return min(INF, a * b);
    };
 
    lcm[0] = 1;
    for(int mask = 1; mask < (1 << k); mask++){
        int p = 31 - __builtin_clz(mask);
        // cout <<" >> " << p <<" " << __builtin_clz(mask) << '\n';
        // int x = mask ^ (1 << p);
        // cout << " ->> " << mask << " " << x << '\n';
        // cout << "(p, x)" << p << " " << x << '\n';
        lcm[mask] = myLcm(lcm[mask ^ (1 << p)], a[p]);
    }
    ll answer = 0;
    for(int mask = 1; mask < (1 << k); mask++)
        if (__builtin_popcount(mask) % 2)
            answer += n / lcm[mask];
        else
            answer -= n / lcm[mask];
    cout << answer;
    return 0;
}
