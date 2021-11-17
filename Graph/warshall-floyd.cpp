vector<vector<long long>>warshall_floyd(vector<vector<long long>>g){
  int n=g.size();
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(g[k][j]!=2e18){
          g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
        }
      }
    }
  }
  return g;
}