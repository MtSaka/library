#pragma once
#include"../template/template.hpp"

template<class S,class F,S (*mapping)(F,S),F (*composition)(F,F),F (*id)()>
struct DualSegmentTree{
  private:
  int _n,size=1,idx=0;
  vector<S>seq;
  vector<F>lazy;
  void all_apply(int k,F f){
    if(k<size)lazy[k]=composition(f,lazy[k]);
    else if(k<size+_n)seq[k-size]=mapping(f,seq[k-size]);
  }
  void eval(int k){
    all_apply(k<<1,lazy[k]);
    all_apply(k<<1^1,lazy[k]);
    lazy[k]=id();
  }
  public:
  DualSegmentTree():DualSegmentTree(0){}
  DualSegmentTree(int n,S e=S()):DualSegmentTree(vector<S>(n,e)){};
  DualSegmentTree(const vector<S>&v):_n(v.size()){
    while(size<_n)size<<=1,idx++;
    seq=v;lazy=vector<F>(size,id());
  }
  void set(int p,S x){
    p+=size;
    for(int i=idx;i>=1;i--)eval(p>>i);
    seq[p-size]=x;
  }
  S operator[](int p){
    p+=size;
    for(int i=idx;i>=1;i--)eval(p>>i);
    return seq[p-size];
  }
  void apply(int p,F f){
    p+=size;
    for(int i=idx;i>=1;i--)eval(p>>i);
    seq[p-size]=mapping(f,seq[p-size]);
  }
  void apply(int l,int r,F f){
    if(l==r)return;
    l+=size;r+=size;
    for(int i=idx;i>=1;i--){
      if(((l>>i)<<i)!=l)eval(l>>i);
      if(((r>>i)<<i)!=r)eval(r>>i);
    }
    while(l<r){
      if(l&1)all_apply(l++,f);
      if(r&1)all_apply(--r,f);
      l>>=1,r>>=1;
    }
  }
};
/**
 *@brief Dual Segment Tree(双対セグメント木)
*/