#pragma once
#include"../graph_template.hpp"
#include"../../Data_Structure/sparse_table.hpp"
template<typename T=int>
struct RMQ_LCA:Graph<T>{
  using Graph<T>::g;
  using F=function<int(int,int)>;
  vector<int>ord,dep,in;
  RMQ_LCA(int n):Graph<T>(n){}
  RMQ_LCA(const Graph<T>&g):Graph<T>(g){}
  void build(int root=0){
    in.resize(g.size());
    dfs(root,-1,0);
    vector<int>v(g.size()*2-1);
    iota(v.begin(),v.end(),0);
    F f=[&](int a,int b){return dep[a]<dep[b]?a:b;};
    st=sparse_table<int,F>(v,f);
  }
  int lca(int u,int v){
    if(in[u]>in[v])swap(u,v);
    return u==v?u:ord[st.query(in[u],in[v])];
  }
  private:
  sparse_table<int,F>st;
  void dfs(int idx,int par,int d){
    in[idx]=(int)ord.size();
    ord.emplace_back(idx);
    dep.emplace_back(d);
    for(auto &e:g[idx])if(e!=par){
      dfs(e,idx,d+1);
      ord.emplace_back(idx);
      dep.emplace_back(d);
    }
  }
};
/**
 * @brief RMQ Lowest Common Ancestor(最小共通祖先)
*/