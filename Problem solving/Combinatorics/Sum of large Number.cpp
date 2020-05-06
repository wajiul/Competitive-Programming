
/*
   author : wajiul
   problem-link : https://atcoder.jp/contests/abc163/tasks/abc163_d

   serise : 1 , 2 , 3 , 4 , 5 , ----- N
   We can chose 2 element with C(N,2) pair then
   Sum of all pair will be between Min(A,B) to Max(A,B)
   Similarly it can be done for K element.
*/

#include<bits/stdc++.h>
using namespace std; 

signed main(){
  ios::sync_with_stdio(false);cin.tie(0);
  int n , k;
  cin >> n >> k;
  int ans = 0;
  int Mn = 0 , Mx = 0;
  int l = 1 , r = n+1;
  while(l <= n+1){
    Mn += l;
    Mx += r;
    if(l >= k)
    ans = (ans + (Mx - Mn + 1)) % Mod;

    l++;
    r--;
  }
  cout << ans << '\n';
}
