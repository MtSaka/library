#pragma once
template<typename T>
struct FordFulkerson{
  struct Edge{
    int to;
    T cap;
    int rev;
    bool isrev;
    int idx;
  };
  const T INF;
  vector<vector<Edge>>g;
  vector<int>used;
  int timer;
  FordFulkerson(int v):INF(numeric_limits<T>::max()/2),g(v),used(v,-1),timer(0){}
  void add_edge(int from,int to,T cap,int idx=-1){
    g[from].emplace_back(Edge{to,cap,(int)g[to].size(),false,idx});
    g[to].emplace_back(Edge{from,0,(int)g[from].size()-1,true,idx});
  }
  T find_path(int idx,const int t,T flow){
    if(idx==t)return flow;
    used[idx]=timer;
    for(auto&e:g[idx]){
      if(e.cap>0&&used[e.to]!=timer){
        T d=find_path(e.to,t,min(flow,e.cap));
        if(d>0){
          e.cap-=d;
          g[e.to][e.rev].cap+=d;
          return d;
        }
      }
    }
    return 0;
  }
  T max_flow(int s,int t){
    T flow=0;
    for(T f;(f=find_path(s,t,INF));timer++)flow+=f;
    return flow;
  }
};
/**
 * @brief Ford Fulkerson(最大流)
*/