const int N = 1e5+1;
int par[N];
int root(int x){
    if(x!=par[x])
        par[x] = root(par[x]);
    return par[x];
}
void unite(int a,int b){
    int x = root(a);
    int y= root(b);
    if(x==y) return;
    par[y]=x;
}
void init(int n){
    for(int i=1;i<=n;i++){
        par[i] = i;
    }
}
