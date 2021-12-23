#include"../Data_Structure/dsu.cpp"
#include"graph_template.cpp"
template<typename T>
struct mst{
  T cost;
  vector<tuple<T,T,T>>edges;
};
template<typename T>
mst<T>kruskal(const Graph<T>&g,int v){
  vector<tuple<T,T,T>>edges;
  for(int i=0;i<g.size();i++){
    for(auto &e:g[i])if(e<i)edges.emplace_back(e,i,e.cost);
  }
  sort(edges.begin(),edges.end(),[](const tuple<T,T,T>&a,const tuple<T,T,T>&b){
    return get<2>(a)<get<2>(b);
  });
  dsu d(v);
  T total=0;
  vector<tuple<T,T,T>>es;
  for(auto &e:edges){
    if(!d.same(get<0>(e),get<1>(e))){
      d.merge(get<0>(e),get<1>(e));
      es.emplace_back(e);
      total+=get<2>(e);
    }
  }
  return {total,es};
}