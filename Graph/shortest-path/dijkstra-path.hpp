#pragma once
#include"../../template/template.hpp"
#include"../graph-template.hpp"

template<typename T=int>
pair<T,vector<int>>dijkstra_path(const Graph<T>&g,int s,int t){
  const int n=g.size();
  const T MAX=numeric_limits<T>::max()/2;
  vector<T>d(n,MAX);
  d[s]=0;
  vector<int>prev(n);
  priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>>q;
  q.emplace(0,s);
  while(!q.empty()){
    auto [d_u,u]=q.top();q.pop();
    if(d[u]<d_u)continue;
    for(auto &e:g[u]){
      if(d[e]>d[u]+e.cost){
        d[e]=d[u]+e.cost;
        prev[e]=u;
        q.emplace(d[e],e);
      }
    }
  }
  if(d[t]==MAX)return {-1,{}};
  vector<int>path;
  path.emplace_back(t);
  while(path.back()!=s)path.emplace_back(prev[path.back()]);
  reverse(path.begin(),path.end());
  return {d[t],path};
}
/**
 * @brief Dijkstra With Path(経路付き単一始点最短路)
*/