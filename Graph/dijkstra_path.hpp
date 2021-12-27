/**
 * @brief Dijkstra With Path(経路付き単一始点最短路)
*/
#include"dijkstra.hpp"
template<typename T>
pair<T,vector<int>>dijkstra_path(const Graph<T>&g,int s,int t){
  auto d=dijkstra(g,s);
  if(d[t]==MAX)return {-1,{}};
  vector<int>path;
  path.emplace_back(t);
  while(path.back()!=s){
    path.emplace_back(prev[path.back()]);
  }
  reverse(path.begin(),path.end());
  return {d[t],path};
}