#include<bits/stdc++.h>
using namespace std;
struct UnionFind {
  vector<int>parent; 
  UnionFind(int n):parent(n){
    for(int i=0;i<n;i++)parent[i]=i;
  }
  int root(int x){
    if(par[x]==x)return x;
    return par[x]=root(parent[x]);
  }
  void unite(int x,int y){  
    if(root(x)==root(y))return; 
    parent[root(x)]=root(y);
  }
  bool same(int x,int y) {
    return root(x)==root(y);
  }
};
