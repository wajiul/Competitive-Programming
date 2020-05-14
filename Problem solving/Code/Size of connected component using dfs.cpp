int dfs(int x){
	if(vis[x]) return 0;
	vis[x] = 1;
	int res = 1;
	for(auto i : g[x]){
		res += dfs(i);
	}
	return res;
}
