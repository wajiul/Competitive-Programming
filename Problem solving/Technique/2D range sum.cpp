/*
  author : wajiul
  problem-link : https://codeforces.com/contest/835/problem/C

  topic : 2D range sum queries in O(1).
  
  build : C[x][y] = C[x-1][y] + C[x][y-1] - C[x-1][y-1];
  query : In range( (x1 , y1) to (x2 , y2)) = C[x2][y2] - C[x1-1][y2] - C[x2][y1-1] + C[x1-1][y1-1];
  
*/


#include <bits/stdc++.h>
 
using namespace std;
 
const int N = (int) 1e5 + 123;
const int C = 101;
const int P = 11;
 
int n, q, c;
int cnt[P][C][C];
 
int main() {
    scanf("%d%d%d", &n, &q, &c);
    for (int i = 0; i < n; i++) {
        int x, y, s;
        scanf("%d%d%d", &x, &y, &s);
        cnt[s][x][y]++;
    }
    
    for (int p = 0; p <= c; p++) {
        for (int i = 1; i < C; i++) {
            for (int j = 1; j < C; j++) {
                cnt[p][i][j] += cnt[p][i - 1][j] + cnt[p][i][j - 1] - cnt[p][i - 1][j - 1];
            }
        }
    }
    
    for (int i = 0; i < q; i++) {
        int t, x1, y1, x2, y2;
        scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
        int ans = 0;
        for (int p = 0; p <= c; p++) {
            int brightness = (p + t) % (c + 1);
            int amount = cnt[p][x2][y2] - cnt[p][x1 - 1][y2] - cnt[p][x2][y1 - 1] + cnt[p][x1 - 1][y1 - 1];
            ans += brightness * amount;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
