
/*
  author : wajiul
  problem-link : https://www.hackerrank.com/challenges/pylons/problem

  Greedy - idea :
  In every k consecutive element there must be a 1 for valid answer .
  So we take the rightmost 1 that covering the leftmost uncovered house.

  ________X_____Y_____Y-K+1__Y+K_____________________

   if tower in pont Y covering X then ( X to Y-K+1 ) segment is covered .
   now we will look from Y+k.
     
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int n, k, p, prv[N];

int main() {

    scanf("%d %d", &n, &k);

    int last = -1, ans = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d", &p);
        if(p == 1) last = i;
        prv[i] = last;
    }

    for(int i = 0; i < n; ) {
        int take = prv[min(i + k - 1, n - 1)];
        if(take == -1 || take + k <= i) { printf("-1\n"); return 0; }
        i = take + k; ans++;
    }

    printf("%d\n", ans);

    return 0;

}
