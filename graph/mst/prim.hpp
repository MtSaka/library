#pragma once
#include"../../template/template.hpp"
#include"../graph-template.hpp"

template<typename T>
pair<T,Edges<T>>prim(const Graph<T>&g){
  T sum=T();
  vector<bool>used(g.size(),false);
  vector<Edge<T>>dist(g.size());
  priority_queue<pair<T,int>,vector<pair<T,int>>,greater<>>q;
  q.emplace(T(),0);
  Edges<T>es;
  while(!q.empty()){
    auto p=q.top();q.pop();
    if(used[p.second])continue;
    used[p.second]=true;
    sum+=p.first;
    if(dist[p.second])es.emplace_back(dist[p.second]);
    for(auto &e:g[p.second]){
      if(used[e]||(dist[e]&&dist[e].cost<=e.cost))continue;
      q.emplace(e.cost,e.to);
    }
  }
  return {sum,es};
}
/**
 * @brief Prim(最小全域木)
*/