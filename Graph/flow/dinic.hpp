#pragma once
template<typename T>
struct Dinic{
  struct edge{
    int to;
    T cap;
    int rev;
    bool isrev;
    int idx;
  };
  vector<vector<edge>>g;
  vector<int>min_cost,iter;
  const T INF;
  Dinic(int v):INF(numeric_limits<T>::max()/2),g(v){}
  void add_edge(int from,int to,T cap,int idx=-1){
    g[from].emplace_back(edge{to,cap,(int)g[to].size(),false,idx});
    g[to].emplace_back(edge{from,0,(int)g[from].size()-1,true,idx});
  }
  bool build_path(int s,int t){
    min_cost.assign(g.size(),-1);
    queue<int>q;
    min_cost[s]=0;
    q.push(s);
    while(!q.empty()&&min_cost[t]==-1){
      int v=q.front();q.pop();
      for(auto&e:g[v]){
        if(e.cap>0&&min_cost[e.to]==-1){
          min_cost[e.to]=min_cost[v]+1;
          q.push(e.to);
        }
      }
    }
    return min_cost[t]!=-1;
  }
  T find_path(int idx,const int t,T flow){
    if(idx==t)return flow;
    for(int &i=iter[idx];i<(int)g[idx].size();i++){
      edge&e=g[idx][i];
      if(e.cap>0&&min_cost[e.to]>min_cost[idx]){
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
    while(build_path(s,t)){
      iter.assign(g.size(),0);
      T f;
      while((f=find_path(s,t,INF))>0)flow+=f;
    }
    return flow;
  }
};
/**
 * @brief Dinic(最大流)
*/