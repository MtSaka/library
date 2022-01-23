#include"../graph_template.hpp"
template<typename T>
vector<T>bellman_ford(const Graph<T>&g,int s){
  const int n=g.size();
  const T MAX=numeric_limits<T>::max()/2;
  vector<T>d(n,MAX);
  d[s]=0;
  for(int i=0;i<n;i++){
    bool changed=false;
    for(int j=0;j<n;j++){
      for(auto &e:g[j]){
        if(d[j]!=MAX&&d[e]>d[j]+e.cost){
          d[e]=d[j]+e.cost;
          changed=true;
        }
      }
    }
    if(!changed)return d;
  }
  for(int i=0;i<n;i++)for(auto &e:g[i])if(d[i]!=MAX&&d[e]>d[i]+e.cost)d[e]=-MAX;
  for(int i=0;i<n-1;i++){
    bool changed=false;
    for(int j=0;j<n;j++){
      if(d[j]!=-MAX)continue;
      for(auto &e:g[j]){
        if(d[e]!=-MAX){
          d[e]=d[j];
          changed=true;
        }
      }
    }
    if(!changed)break;
  }
  return d;
}
/**
 * @brief Bellman-Ford(単一始点最短路)
*/