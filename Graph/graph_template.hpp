#pragma once
template<typename T=int>
struct Edge{
  int from,to;
  T cost;
  int idx;
  Edge(){}
  Edge(int from,int to,T cost=1,int idx=-1):from(from),to(to),cost(cost),idx(idx){}
  operator int()const{return to;}
  bool operator<(const Edge&e)const{return cost<e.cost;}
};
template<typename T=int>
struct Graph{
  vector<vector<Edge<T>>>g;
  int es;
  Graph(){}
  explicit Graph(int n):g(n),es(0){}
  size_t size()const{return g.size();}
  size_t edge_size()const{return es;}
  void add_directed_edge(int from,int to,T cost=1){
    g[from].emplace_back(from,to,cost,es++);
  }
  void add_edge(int from,int to,T cost=1){
    g[from].emplace_back(from,to,cost,es);
    g[to].emplace_back(to,from,cost,es++);
  }
  inline vector<Edge<T>>&operator[](int idx){return g[idx];}
  inline const vector<Edge<T>>&operator[](int idx)const{return g[idx];}
  void read(int m,int padding=-1,bool weighed=false,bool direct=false){
    int a,b;
    T c;
    for(int i=0;i<m;i++){
      cin>>a>>b;
      a+=padding;
      b+=padding;
      c=1;
      if(weighed)cin>>c;
      if(direct)add_directed_edge(a,b,c);
      else add_edge(a,b,c);
    }
  }
};
template<typename T=int>
using Edges=vector<Edge<T>>;
/**
 * @brief Graph Template(グラフテンプレート)
*/