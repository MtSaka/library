/**
 * @brief Bellman-Ford(単一始点最短路)
*/
#include"graph_template.hpp"
template<typename T>
vector<T>bellman_ford(const Graph<T>&g,int s){
  int n=g.size();
  T MAX=numeric_limits<T>::max()/2;
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