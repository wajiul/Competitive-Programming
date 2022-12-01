
/*
Suppose 5 matrices A, B, C, D, E
So cost of multiplying (AB) | (BCD)
                   = dimension of product AB = axb
                   and dimension of product BCD = b x d
                  cost = a x b x d + f(i, k) + f(k + 1, j)
*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[105][105];
    int solve(int i, int j, int arr[]) {
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int MN = 1e9;
        for(int k = i;k < j;k++) {
            int step = (arr[i - 1] * arr[k] * arr[j]) + solve(i, k, arr) + solve(k + 1, j, arr);
            MN = min(MN, step);
        }
        return dp[i][j] =  MN;
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp, -1, sizeof dp);
        int ans = solve(1, N - 1, arr);
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
