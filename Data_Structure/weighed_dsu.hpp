/**
 * @brief Weighed Disjoint Set Union(重み付きUnion Find)
*/ 
template<typename T>
struct weighed_dsu{
  vector<int>p;vector<T>diff;
  weighed_dsu(){}
  weighed_dsu(int n,T s=0):p(n,-1),diff(n,s){}
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
  void merge(int x,int y,T w){
    w+=weight(x),w-=weight(y);
    x=root(x),y=root(y);
    if(x==y)return ;
    if(p[x]>p[y])swap(x,y),w=-w;
    p[x]+=p[y];
    p[y]=x;
    diff[y]=w;
  }
  T dist(int x,int y){
    return weight(y)-weight(x);
  }
};