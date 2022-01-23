#include"../../Data_Structure/dsu.hpp"
#include"../graph_template.hpp"
template<typename T>
struct mst{
  T cost;
  Edges<T>edges;
};
template<typename T>
mst<T>kruskal(Edges<T>&edges,int v){
  sort(edges.begin(),edges.end());
  dsu d(v);
  T total=0;
  Edges<T>es;
  for(auto &e:edges){
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