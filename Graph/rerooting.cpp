#include<bits/stdc++.h>
using namespace std;
template<typename S,typename T=S>
struct ReRooting{
  struct Edge{
    int from,to;
    S cost;
    T dp,ndp;
  };
  using F=function<T(T,T)>;
  using G=function<T(T,Edge)>;
  vector<vector<Edge>> g;
  const F f;
  const G gg;
  const T id;
  vector<T> subdp,dp;
  void add_edge(int u,int v,const S &d) {
    g[u].emplace_back(Edge{u,v,d,id,id});
    g[v].emplace_back(Edge{v,u,d,id,id});
  }
  ReRooting(int n,const F &f,const G &g,const T &id=T{}):g(n),f(f),gg(g),id(id),subdp(n,id),dp(n,id) {}
  void dfs_sub(int x,int p) {
    for(auto &e:g[x])if(e.to!=p){
      dfs_sub(e.to,x);
      e.dp=gg(subdp[e.to], e);
      subdp[x]=f(subdp[x], e.dp);
    }
  }
  void dfs_all(int x,int p,T top) {
    T now = id;
    for(auto &e:g[x]){
      e.ndp=now;
      if(e.to==p)e.dp=gg(top, e);
      now=f(now,e.dp);
    }
    dp[x]=now;
    now=id;
    for(int i=(int)g[x].size()-1;i>=0;i--){
      auto &e=g[x][i];
      if(e.to!= p)dfs_all(e.to,x,f(e.ndp,now));
      now=f(now,e.dp);
    }
  }
  vector<T>solve(){
    dfs_sub(0,-1);
    dfs_all(0,-1,id);
    return dp;
  }
};