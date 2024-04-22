#pragma once
#include"../../template/template.hpp"
#include"../graph-template.hpp"

template<typename T>
pair<T,Edges<T>>prim(const Graph<T>&g){
  T sum=T();
  Edges<T>es;
  if(g.size()==0)return {sum,es};
  vector<bool>used(g.size(),false);
  priority_queue<Edge<T>,vector<Edge<T>>,greater<>>q;
  used[0]=true;
  for(auto e:g[0])q.emplace(e);
  while(!q.empty()){
    const auto p=q.top();q.pop();
    if(used[p.to])continue;
    used[p.to]=true;
    sum+=p.cost;
    es.emplace_back(p);
    for(auto &e:g[p.second])if(!used[e.to]){
      q.emplace(e);
    }
  }
  return {sum,es};
}
/**
 * @brief Prim(最小全域木)
*/