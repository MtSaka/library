#include<bits/stdc++.h>
using namespace std;
struct dsu{
  vector<int>sz,par;
  dsu(){}
  dsu(int n){
    sz.resize(n,1);
    par.resize(n,0);
    for(int i=0;i<n;i++)par[i]=i;
  }
  int root(int x){
    if(x==par[x])return x;
    return par[x]=root(par[x]);
  }
  bool same(int x,int y){return root(x)==root(y);}
  int size(int x){return sz[root(x)];}
  void merge(int x,int y){
    x=root(x),y=root(y);
    if(x==y)return ;
    if(sz[x]>sz[y]){
      par[y]=x;
      sz[x]+=sz[y];
    }
    else{
      par[x]=y;
      sz[y]+=sz[x];
    }
  }
};
