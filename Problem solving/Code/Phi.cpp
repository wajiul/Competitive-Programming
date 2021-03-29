vector<int> Phi;
void genPhi(int n) {
    Phi = vector<int> (n + 1);
    Phi[0] = 0 , Phi[1] = 1;

    for (int i = 2; i <= n; i++) {
      Phi[i] = i;
    }
    for (int i = 2; i <= n; i++) {
      if(Phi[i] != i) continue;
      for(int j = i;j <= n; j += i) {
        Phi[j] -= Phi[j] / i;
      }  
    }
}
