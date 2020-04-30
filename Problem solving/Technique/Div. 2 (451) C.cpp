/*
author : wajiul
problem link: https://codeforces.com/contest/898/problem/D

This type of approach is useful in many problem . I am considering one 
element at a time , removing element of last window(*St.begin() <= A[i] - x) ,
and its optimal to turn off the rightmost alarm clock . and in this way I have 
to turn off maximum one alarm at a time.

*/


#include<bits/stdc++.h>
using namespace std;

signed main(){
  ios::sync_with_stdio(false);cin.tie(0);
  int n , m , k;
  cin >> n >> m >> k;
  vector<int>A(n);
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  sort(A.begin() , A.end());
  set<int>St;
  int del = 0;
  for(int i=0;i<n;i++){
    St.insert(A[i]);

    while(!St.empty() && *St.begin() <= A[i] - m){
      St.erase(*St.begin());
    }
    if((int)St.size() >= k){
      St.erase(A[i]);
      del++;
    }
  }
  cout << del << '\n';

}
