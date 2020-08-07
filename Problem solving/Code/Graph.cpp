

class Graph {
  private:
  int N;

  public:
  vector<vector<int>> g;
  vector<int> Cnt ,wt ,stc , vis , depth, par;

  Graph(int n){
    this -> N = n;
    g = vector<vector<int>>(n);
    Cnt = wt = vector<int>(n);
  }
  void build(int n) {
    for(int i = 0; i < n; i++ ) {
      int u , v;
      cin >> u >> v;
      u--,v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }
  int cal_stc(int n , int p) {
    stc[n] = 1;
    for(auto i : g[n]) {
      if(i != p) {
        stc[n] += cal_stc(i, n);
      }
    } 
    return stc[n];
  }
  void cal_depth(int n, int p) {
    for(auto i : g[n]) {
      if(i != p) {
        depth[i] = depth[n] + 1;
        cal_depth(i , n);
      }
    }
  }
  void watch_graph() {
    for(int i = 0; i < N; i++) {
      dg2(i , g[i]);
   }
  }
  int cal(int a);
  int cal(int a,int b);
};


