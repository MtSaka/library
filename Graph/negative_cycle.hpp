/**
 * @brief Negative Cycle Detection(負閉路検出)
*/
#pragma once
#include"graph_template.hpp"
template<typename T>
bool negative_cycle(const Graph<T>&g){
  int n=g.size();
  T MAX=numeric_limits<T>::max()/2;
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