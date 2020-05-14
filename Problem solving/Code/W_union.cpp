int arr[xx],wt[xx];

void init(int n){
    for(int i=0;i<n;i++){
        arr[i]  = i;
        wt[i]  = 1;
    }
}

int root(int i){
    while(arr[i]!=i){
        arr[i]  = arr[arr[i]];
        i = arr[i];
    }
    return i;
}

void unite(int A,int B){
    int rA = root(A);
    int rB = root(B);
    if(rA == rB) return;
    if(wt[rA] < wt[rB]){
        arr[rA] = arr[rB];
        wt[rB] =wt[rB]+wt[rA];
    }
    else{
        arr[rB] = arr[rA];
        wt[rA] = wt[rA]+wt[rB];
    }
}
