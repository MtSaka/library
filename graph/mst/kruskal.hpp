#pragma once
#include"../../template/template.hpp"
#include"../../ds/union-find/union-find.hpp"
#include"../graph-template.hpp"

template<typename T>
pair<T,Edges<T>>kruskal(Edges<T>&ed,int v){
  sort(ed.begin(),ed.end());
  UnionFind d(v);
  T total=0;
  Edges<T>es;
  for(auto &e:ed){
    if(!d.same(e.to,e.from)){
      d.merge(e.to,e.from);
      es.emplace_back(e);
      total+=e.cost;
    }
  }
  return {total,es};
}
/**
 * @brief Kruskal(最小全域木)
*/