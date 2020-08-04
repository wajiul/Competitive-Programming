class DSU {
  private:
  vector<int> par;
  vector<int> wt;
  public:
  DSU(int n) : par(n), wt(n){
    for(int i = 0; i < n; i++) {
      par[i] = i , wt[i] = 1;
    }
  }
  int root(int n) {
    if(n == par[n]) return n;
    return root(par[n]);
  } 
  void unite(int a, int b) {
    int Ra = root(a), Rb = root(b);
    if(Ra == Rb) return;
    if(wt[Ra] < wt[Rb]){
      par[Ra] = par[Rb];
      wt[Rb] += wt[Ra];
    } else{
      par[Rb] = par[Ra];
      wt[Ra] += wt[Rb];
    }
  }
  int Rank(int n) {
    return wt[root(n)];
  }
  bool ispar(int n) {
    return par[n] == n;
  }
  bool same(int a, int b) {
    return root(a) == root(b);
  }
};
