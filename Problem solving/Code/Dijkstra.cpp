class Edge {
  public:
  int to , cost;
};

template<class T>
class Cmp {
public:
  int operator() (const T& e1, const T& e2) {
      return e1.cost > e2.cost;
  }
};

vector<vector<Edge>> g;

template<class T, class T1, class T2, class T3>
int Shortest_Path(T &graph, T1 &src, T2 &des , T3 &N) {
  priority_queue<Edge, vector<Edge> , Cmp<Edge>> Q;
  vector<int> Dist(N+1, inf);
  Dist[src] = 0;
  Q.push({src, 0});
  while(!Q.empty()) {
    auto it = Q.top();
    Q.pop();
    int from = it.to;
    for(auto i : graph[from]) {
      if(Dist[i.to] > Dist[from] + i.cost) {
        Dist[i.to] = Dist[from] + i.cost;
        Q.push({i.to , Dist[i.to]});
      }
    }
  }
  return Dist[des];
}
