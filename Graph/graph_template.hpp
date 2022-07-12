#pragma once
template<typename T=int>
struct edge{
  int from,to;
  T cost;
  int idx;
  edge(){}
  edge(int from,int to,T cost=1,int idx=-1):from(from),to(to),cost(cost),idx(idx){}
  operator int()const{return to;}
  bool operator<(const edge&e)const{return cost<e.cost;}
};
template<typename T=int>
using edges=vector<edge<T>>;
template<typename T=int>
struct graph{
  vector<vector<edge<T>>>g;
  int es;
  graph(){}
  explicit graph(int n):g(n),es(0){}
  size_t size()const{return g.size();}
  size_t edge_size()const{return es;}
  void add_edge(int from,int to,T cost=1,bool direct=false){
    g[from].emplace_back(from,to,cost,es);
    if(!direct)g[to].emplace_back(to,from,cost,es);
    es++;
  }
  void add_edge(int from,int to,bool direct=false){
    g[from].emplace_back(from,to,1,es);
    if(!direct)g[to].emplace_back(to,from,1,es);
  }
  inline vector<edge<T>>&operator[](int idx){return g[idx];}
  inline const vector<edge<T>>&operator[](int idx)const{return g[idx];}
  void read(int m,int padding=-1,bool weighed=false,bool direct=false){
    int a,b;
    T c=T(1);
    for(int i=0;i<m;i++){
      cin>>a>>b;
      a+=padding;
      b+=padding;
      if(weighed)cin>>c;
      add_edge(a,b,c,direct);
    }
  }
};
struct unweighted_edge{
  template<class... Args>unweighted_edge(const Args&...){}
  operator int()const{return 1;}
};
using unweighted_graph=graph<unweighted_edge>;
/**
 * @brief graph Template(グラフテンプレート)
*/