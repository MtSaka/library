#pragma once
#include"../../template/template.hpp"
#include"../../data-structure/union-find.hpp"
#include"../graph-template.hpp"

template<typename T>
struct mst{
  T cost;
  Edges<T>es;
};
template<typename T>
mst<T>kruskal(Edges<T>&ed,int v){
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