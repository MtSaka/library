#pragma once
template<typename T>
struct weighted_dsu{
  vector<int>p;vector<T>diff;
  weighted_dsu(){}
  weighted_dsu(int n,T s=0):p(n,-1),diff(n,s){}
  int root(int x){
    if(p[x]<0)return x;
    int r=root(p[x]);
    diff[x]+=diff[p[x]];
    return p[x]=r;
  }
  T weight(int x){
    root(x);
    return diff[x];
  }
  bool same(int x,int y){return root(x)==root(y);}
  int size(int x){return -p[root(x)];}
  bool merge(int x,int y,T w){
    int xx=x,yy=y;T ww=w;
    w+=weight(x),w-=weight(y);
    x=root(x),y=root(y);
    if(x==y)return dist(xx,yy)==ww;
    if(p[x]>p[y])swap(x,y),w=-w;
    p[x]+=p[y];
    p[y]=x;
    diff[y]=w;
    return true;
  }
  T dist(int x,int y){
    return weight(y)-weight(x);
  }
};
/**
 * @brief Weighted Disjoint Set Union(重み付きUnion Find)
*/ 