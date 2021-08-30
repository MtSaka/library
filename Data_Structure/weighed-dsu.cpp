#include<bits/stdc++.h>
using namespace std;
template<typename T>
struct weighed_dsu{
  vector<int>sz,par;
  vector<T>diff;
  weighed_dsu(){}
  weighed_dsu(int n,T s=0){
    sz.resize(n,1);
    par.resize(n,0);
    diff.resize(n,s);
    for(int i=0;i<n;i++)par[i]=i;
  }
  int root(int x){
    if(x==par[x])return x;
    int r=root(par[x]);
    diff[x]+=diff[par[x]];
    return par[x]=r;
  }
  T weight(int x){
    root(x);
    return diff[x];
  }
  bool same(int x,int y){return root(x)==root(y);}
  int size(int x){return sz[root(x)];}
  void merge(int x,int y,T w){
    w+=weight(x),w-=weight(y);
    x=root(x),y=root(y);
    if(x==y)return ;
    if(sz[x]<sz[y])swap(x,y),w=-w;
    sz[x]+=sz[y];
    par[y]=x;
    diff[y]=w;
  }
  T dist(int x,int y){
    return weight(y)-weight(x);
  }
};