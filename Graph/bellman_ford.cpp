#include"graph_template.cpp"
template<typename T>
vector<T>bellman_ford(Graph<T>&g,int s){
  int n=g.size();
  T MAX=numerical_limits<T>::max()/2;
  vector<T>d(n,MAX);
  d[s]=0;
  while(true){
    bool update=false;
    for(int i=0;i<n;i++){
      for(auto &e:g[i])if(d[e]>d[i]+e.cost&&d[i]!=MAX){
        d[e]=d[i]+e.cost;
        update=true;
      }
    }
    if(!update)break;
  }
  return d;
}
template<typename T>
bool negative_cycle(Graph<T>&g){
  int n=g.size();
  T MAX=numerical_limits<T>::max()/2;
  vector<T>d(n,MAX);
  for(int i=0;i<n;i++){
    bool update=false;
    for(int j=0;j<n;j++){
      for(auto &e:g[j])if(d[e]>d[j]+e.cost&&d[j]!=MAX){
        d[e]=d[j]+e.cost;
        update=true;
        if(i==n-1)return true;
      }
    }
    if(!update)break;
  }
  return false;
}