#include<bits/stdc++.h>
using namespace std;
struct LCA{
  int lg=0;
  vector<int>dep;
  const vector<vector<int>>&g;
  vector<vector<int>>table;
  LCA(const vector<vector<int>>&g):g(g),dep(g.size()){
    while((1<<lg)<g.size())lg++;
    table.assign(lg,vector<int>(g.size(),-1));
    build();
  }
  void dfs(int idx,int par,int d){
    table[0][idx]=par;
    dep[idx]=d;
    for(auto &to:g[idx]){
      if(to!=par)dfs(to,idx,d+1);
    }
  }
  void build(){
    dfs(0,-1,0);
    for(int k=0;k+1<lg;k++){
      for(int i=0;i<table[k].size();i++){
        if(table[k][i]==-1)table[k+1][i]=-1;
        else table[k+1][i]=table[k][table[k][i]];
      }
    }
  }
  int query(int u,int v){
    if(dep[u]>dep[v])swap(u,v);
    for(int i=lg-1;i>=0;i--){
      if(((dep[v]-dep[u])>>i)&1)v=table[i][v];
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
};