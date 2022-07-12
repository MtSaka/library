#pragma once
#include"../graph_template.hpp"
template<typename T=int>
struct TreeDiameter:graph<T>{
  using graph<T>::graph;
  using graph<T>::g;
  vector<Edge<T>>path;
  T build(){
    to.assign(g.size(),-1);
    auto p=dfs(0,-1);
    auto q=dfs(p.second,-1);
    int now=p.second;
    while(now!=q.second){
      for(auto &e:g[now]){
        if(to[now]==e.to)path.emplace_back(e);
      }
      now=to[now];
    }
    return q.first;
  }
  TreeDiameter(const graph<T>&g):graph<T>(g){}
  private:
  vector<int>to;
  pair<T,int>dfs(int idx,int par){
    pair<T,int>res(0,idx);
    for(auto &e:g[idx])if(e.to!=par){
      auto cost=dfs(e.to,idx);
      cost.first+=e.cost;
      if(res<cost)res=cost,to[idx]=e.to;
    }
    return res;
  }
};
/**
 * @brief Tree Diameter(木の直径)
*/