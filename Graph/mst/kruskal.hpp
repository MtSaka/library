#include"../../data-structure/union-find.hpp"
#include"../graph_template.hpp"
template<typename T>
struct mst{
  T cost;
  edges<T>es;
};
template<typename T>
mst<T>kruskal(edges<T>&ed,int v){
  sort(ed.begin(),ed.end());
  UnionFind d(v);
  T total=0;
  edges<T>es;
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