/*
  author : wajiul
  problem link : https://www.hackerrank.com/challenges/salary-blues/problem


  Gcd(a , b) = Gcd(a , b - a) [b > a]
  Gcd(a , b , c) = Gcd(a, b - a , c - a);
  Gcd(a+k , b+k , c+k) = Gcd(a+k , b+k-a-k , c+k-a-k);
                       = Gcd(a+k , b - a , c - a);




Euclid developed an alternative algorithm1 over 2000 years ago, and the
only operation students need apply is subtraction. You begin with your original
numbers, say 24 and 60, and subtract the smaller from the larger:
60 − 24 = 36
The two smallest numbers in this set are 24 and 36. Again, we subtract the
smaller from the larger:
36 − 24 = 12
And again:
24 − 12 = 12
And again, until we get down to 0 for an answer:
12 − 12 = 0
Once we got to 0, the number we subtracted from itself (12) is our greatest
common factor: 24 = 2 × 12 and 60 = 5 × 12



*/


#include<bits/stdc++.h>
using namespace std;

signed main(){
  ios::sync_with_stdio(false);cin.tie(0);
  int n , q;
  cin >> n >> q;
  vector<int>A(n);
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  sort(A.begin() , A.end());
  int g = 0;
  for(int i=1;i<n;i++){
    g = __gcd(g , A[i] - A[0]);
  }

  while(q--){
    int k;
    cin >> k;
    int ans = __gcd(A[0] + k , g);
    cout << ans << '\n';
  }
}
