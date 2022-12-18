#pragma once
#include"../graph-template.hpp"
template<typename T=UnweightedEdge>
struct Doubling_LCA:Graph<T>{
  using Graph<T>::g;
  const int lg;
  vector<int>dep;
  vector<T>sum;
  vector<vector<int>>table;
  Doubling_LCA(int n):Graph<T>(n),lg(32-__builtin_clz(n)){}
  Doubling_LCA(const Graph<T>&g):Graph<T>(g),lg(32-__builtin_clz(g.size())){}
  void build(int root=0){
    dep.assign(g.size(),0);
    sum.assign(g.size(),0);
    table.assign(lg,vector<int>(g.size(),-1));
    dfs(root,-1,0);
    for(int k=0;k+1<lg;k++){
      for(int i=0;i<(int)table[k].size();i++){
        if(table[k][i]==-1)table[k+1][i]=-1;
        else table[k+1][i]=table[k][table[k][i]];
      }
    }
  }
  int lca(int u,int v){
    if(dep[u]>dep[v])swap(u,v);
    int k=dep[v]-dep[u];
    if(dep[v]<k)return -1;
    for(int i=lg-1;i>=0;i--){
      if((k>>i)&1)v=table[i][v];
    }
    if(u==v)return u;
    for(int i=lg-1;i>=0;i--){
      if(table[i][u]!=table[i][v]){
        u=table[i][u];
        v=table[i][v];
      }
    }
    return table[0][u];
  }
  T dist(int u,int v){return sum[u]+sum[v]-2*sum[lca(u,v)];}
  private:
  void dfs(int idx,int par,int d){
    table[0][idx]=par;
    dep[idx]=d;
    for(auto &e:g[idx])if(e!=par){
      sum[e]=sum[idx]+e.cost;
      dfs(e,idx,d+1);
    }
  }
};
/**
 * @brief Doubling Lowest Common Ancestor(最小共通祖先)
*/