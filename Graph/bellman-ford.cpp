struct Edge{
  long long to;
  long long cost;
};
using Graph=vector<vector<Edge>>;
vector<long long>bellman_ford(Graph g,int s){
  int n=g.size();
  vector<long long>d(n,2e18);
  d[s]=0;
  while(true){
    bool update=false;
    for(int i=0;i<n;i++){
      for(int j=0;j<g[i].size();j++){
        long long c=g[i][j].to,v=g[i][j].cost;
        if(d[v]>d[i]+c&&d[i]!=2e18){
          d[v]=d[i]+c;
          update=true;
        }
      }
    }
    if(!update)break;
  }
  return d;
}
bool negative_cycle(Graph g){
  int n=g.size();
  vector<long long>d(n,0);
  for(int i=0;i<n;i++){
    bool update=false;
    for(int j=0;j<n;j++){
      for(int k=0;k<g[j].size();k++){
        long long c=g[j][k].to,v=g[j][k].cost;
        if(d[v]>d[j]+c&&d[j]!=2e18){
          d[v]=d[j]+c;
          update=true;
          if(i==n-1)return true;
        }
      }
    }
    if(!update)break;
  }
  return false;
}