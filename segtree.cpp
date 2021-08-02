#include<bits/stdc++.h>
using namespace std;
template<class S,S (*op)(S,S),S (*e)()>
struct segtree{
  private:
  int _n,size,log=0;
  vector<S>d;
  void update(int k){d[k]=op(d[2*k],d[2*k+1]);}
  public:
  segtree():segtree(0){};
  explicit segtree(int n):segtree(vector<S>(n,e())){}
  explicit segtree(const vector<S>&v):_n(v.size()){
    while((1<<log)<_n)log++;
    size=1<<log;
    d=vector<S>(2*size,e());
    for(int i=0;i<_n;i++)d[size+i]=v[i];
    for(int i=size-1;i>=1;i--)update(i);
  }
  void set(int p,S x){
    p+=size;
    d[p]=x;
    for(int i=1;i<=log;i++)update(p>>i);
  }
  S get(int p)const{return d[p+size];}
  S query(int l,int r)const{
    S sml=e(),smr=e();
    l+=size;
    r+=size;
    while(l<r){
      if(l&1)sml=op(sml,d[l++]);
      if(r&1)smr=op(smr,d[--r]);
      l>>=1;
      r>>=1;
    }
    return op(sml,smr);
  }
};
