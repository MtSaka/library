#pragma once
#include"../template/template.hpp"

template<typename T=int>
struct Edge{
  int from,to;
  T cost;
  int idx;
  Edge(){}
  Edge(int from,int to,T cost=1,int idx=-1):from(from),to(to),cost(cost),idx(idx){}
  operator int()const{return to;}
  friend bool operator<(const Edge&lhs,const Edge&rhs){return lhs.cost<rhs.cost;}
  friend bool operator>(const Edge&lhs,const Edge&rhs){return lhs.cost>rhs.cost;}
};
template<typename T=int>
using Edges=vector<Edge<T>>;
template<typename T=int>
struct Graph{
  vector<vector<Edge<T>>>g;
  int es;
  Graph(){}
  explicit Graph(int n):g(n),es(0){}
  size_t size()const{return g.size();}
  size_t edge_size()const{return es;}
  void add_edge(int from,int to,bool direct=false,T cost=1){
    g[from].emplace_back(from,to,cost,es);
    if(!direct)g[to].emplace_back(to,from,cost,es);
    es++;
  }
  inline vector<Edge<T>>&operator[](int idx){return g[idx];}
  inline const vector<Edge<T>>&operator[](int idx)const{return g[idx];}
  void read(int m,int padding=-1,bool weighted=false,bool direct=false){
    int a,b;
    T c=T(1);
    for(int i=0;i<m;i++){
      cin>>a>>b;
      a+=padding;
      b+=padding;
      if(weighted)cin>>c;
      add_edge(a,b,direct,c);
    }
  }
};
struct UnweightedEdge{
  template<class... Args>UnweightedEdge(const Args&...){}
  operator int()const{return 1;}
};
istream &operator>>(istream&is,UnweightedEdge&c){c=UnweightedEdge();return is;}
using UnweightedGraph=Graph<UnweightedEdge>;
/**
 * @brief Graph Template(グラフテンプレート)
*/