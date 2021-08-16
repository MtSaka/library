#include<bits/stdc++.h>
using namespace std;
struct dsu{
  vector<int>size,par;
  dsu(){}
  dsu(int n){
    size.resize(n,1);
    par.resize(n,0);
    for(int i=0;i<n;i++)par[i]=i;
  }
  int root(int x){
    if(x==par[x])return x;
    return par[x]==root(par[x]);
  }
  bool same(int x,int y){return root(x)==root(y);}
  int size(int x){return size[root(x)];}
  void unite(int x,int y){
    x=root(x),y=root(y);
    if(x==y)return ;
    if(size[x]>size[y]){
      par[y]=x;
      size[x]+=size[y];
    }
    else{
      par[x]=y;
      size[y]+=size[x];
    }
  }
};
