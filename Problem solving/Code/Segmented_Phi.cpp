//https://www.hackerearth.com/practice/math/number-theory/totient-function/practice-problems/algorithm/monk-and-etf/

#include<bits/stdc++.h>
using namespace std;
#define maxl 1000000
typedef long long ll ;
 
 
void make_sieve(vector<bool> &sieve, int n)
{
    int sq = sqrt(n) ;
    for(int i = 2; i <= sq ; i++)
    {
        if(sieve[i] == true)
        {
            for(int j = i*i ; j <= n ; j+=i)
            {
                sieve[j] = false ;
			}
		}
	}
}
 
ll next_nearest(ll num , ll k)
{
	if(num%k == 0)
    {
        return num ;
	}
    else
    {
        return (num/k + 1)*k ;
    }
}
 
void make_phi(vector<ll> &phi , ll l , ll r , vector<bool> & sieve)
{
    vector<ll> temp(r - l + 1) ;
    for(ll i = l ; i <= r ; i++)
    {
        phi[i - l] = i ;
        temp[i - l] = i ; 
	}
    
	ll sq = sqrt(r) ;
    
    for(ll i = 2 ; i <= sq ;i++)
    {
        if(sieve[i] == true)
        {
            for(ll j = next_nearest(l , i) ; j <= r ; j+=i)
            {
                if(i == j)
                {
                    continue ;
				}
                phi[j - l] = phi[j - l] * (i - 1) / i ;
                while(temp[j-l]%i == 0)
                {
                    temp[j - l] = temp[j - l]/i ;
                }
			}
		}
        
	}
    
    for(ll i = l ; i <= r ; i++)
    {
        if(temp[i - l] != 1)
        {
            ll prime = temp[i - l] ;
            phi[i - l] = phi[i - l] * (prime - 1) / prime ;
        }
        if(l!=1 && phi[i - l] == i )
        {
            phi[i - l]-- ;
		}
	}
}
 
int main() {
 
	// Write your code here
	vector<bool> sieve(maxl + 1 , true) ;
	make_sieve(sieve , maxl) ;
    int t ;
    cin >> t;
    while(t--)
    {
        ll l , r , k ;
        cin >> l >> r >> k ;
        vector<ll> phi(r - l + 1) ;
        make_phi(phi , l , r , sieve) ; 
        ll num_div = 0 ;
        for(int i = 0 ; i < phi.size() ; i++)
        {
            if(phi[i]%k == 0)
            {
                num_div ++ ;
            }
        }
        cout <<fixed<<setprecision(6)<< num_div*1.0/(r - l + 1) << "\n" ;
	}
}
