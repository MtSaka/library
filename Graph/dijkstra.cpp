using P=pair<long long,long long>;
struct Edge {
  long long to;
  long long cost;
};
using Graph=vector<vector<Edge>>;
vector<long long>dijkstra(Graph g,int s){
  int n=g.size();
  vector<long long>d(n,2e18);
  d[s]=0;
  priority_queue<P,vector<P>,greater<P>>q;
  q.push({0,s});
  while(!q.empty()){
    auto [c,v]=q.top();
    q.pop();
    if(d[v]>=c){
      for(auto p:g[v]){
        int w=p.to;
        if(d[w]>d[v]+p.cost){
          d[w]=d[v]+p.cost;
          q.push({d[w],w});
        }
      }
    }
  }
  return d;
}
pair<long long,vector<long long>>dijkstra_path(Graph g,int s, int t){
  int n=g.size();
  vector<long long>d(n,2e18);
  d[s]=0;
  vector<long long>prev(n);
  priority_queue<P,vector<P>,greater<P>>q;
  q.push({0,s});
  while(!q.empty()){
    auto [c,v]=q.top();
    q.pop();
    if(d[v]>=c){
      for(auto p:g[v]){
        int w=p.to;
        if(d[w]>d[v]+p.cost){
          d[w]=d[v]+p.cost;
          q.push({d[w],w});
          prev[w]=v;
        }
      }
    }
  }
  if(d[t]==2e18)return {-1,vector<long long>()};
  else{
    vector<long long>path;
    path.push_back(t);
    while(path.back()!=s){
      path.push_back(prev[path.back()]);
    }
    reverse(path.begin(),path.end());
    return {d[t],path};
  }
}