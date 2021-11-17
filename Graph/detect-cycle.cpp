bool detect_cylce(vector<vector<int>>g){
  int n=g.size();
  vector<int>deg(n,0);
  for(int i=0;i<n;i++){
    for(int j:g[i]){
      deg[j]++;
    }
  }
  queue<int>q;
  for(int i=0;i<n;i++)if(deg[i]==0)q.push(i);
  while(!q.empty()){
    int v=q.front();
    q.pop();
    for(int w:g[v]){
      deg[w]--;
      if(deg[w]==0)q.push(0);
    }
  }
  for(int i=0;i<n;i++)if(deg[i]!=0)return true;
  return false;
}