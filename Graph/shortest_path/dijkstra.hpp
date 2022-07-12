#include"../graph_template.hpp"
template<typename T>
vector<T>dijkstra(const graph<T>&g,int s){
  const int n=g.size();
  const T MAX=numeric_limits<T>::max()/2;
  vector<T>d(n,MAX);
  d[s]=0;
  priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>>q;
  q.emplace(0,s);
  while(!q.empty()){
    auto [d_u,u]=q.top();q.pop();
    if(d[u]<d_u)continue;
    for(auto &e:g[u]){
      if(d[e]>d[u]+e.cost){
        d[e]=d[u]+e.cost;
        q.emplace(d[e],e);
      }
    }
  }
  return d;
}
/**
 * @brief Dijkstra(単一始点最短路)
*/