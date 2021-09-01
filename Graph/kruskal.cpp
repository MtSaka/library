#include<bits/stdc++.h>
#include<../../code/library/Data_Structure/dsu.cpp>
using namespace std;
template<typename T>
struct mst{
  T cost;
  vector<tuple<T,T,T>>edges;
};
template<typename T>
mst<T> kruskal(vector<tuple<T,T,T>>edges,int v){
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