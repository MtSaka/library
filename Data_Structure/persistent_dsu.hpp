
#pragma once
#include"persistent_array.hpp"
struct persistent_dsu{
  private:
  using pa=persistent_array<int>;
  pa p;
  public:
  using node=pa::node;
  persistent_dsu(){}
  persistent_dsu(int n){
    p.build(vector<int>(n,-1));
  }
  int root(int x,node*t){
    if(p.get(x,t)<0)return x;
    return root(p.get(x,t),t);
  }
  bool same(int x,int y,node*t){
    return root(x,t)==root(y,t);
  }
  int size(int x,node*t){
    return -p.get(root(x,t),t);
  }
  pair<int,node*>merge(int x,int y,node*t){
    x=root(x,t),y=root(y,t);
    if(x==y)return {x,t};
    if(p.get(x,t)>p.get(y,t))swap(x,y);
    node*ret=p.set(y,x,p.set(x,p.get(x,t)+p.get(y,t),t));
    return {x,ret};
  }
};
/**
 * @brief persistent Disjoint Set Union(永続Union-Find)
*/