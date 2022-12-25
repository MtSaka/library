#pragma once
#include"../template/template.hpp"
/*
template<typename M>
struct SegmentTree{
  private:
  using T=typename M::value_type;
  int n,size;
  vector<T>data;
  inline static void update(int k){data[k]=M::op(data[k<<1],data[k<<1^1]);}
  public:
  SegmentTree():SegmentTree(0){}
  SegmentTree(int n):SegmentTree(vector<T>(n,M::id())){}
  SegmentTree(int n,const T&x):SegmentTree(vector<T>(n,x)){}
  SegmentTree(const vector<T>&v){init(v);}
  void init(const vector<T>&v){
    n=v.size();
    size=1<<ceil_log2(n);
    data.assign(size<<1,M::id());
    rep(i,n)data[size+i]=v[i];
    rrep(i,1,size)update(i);
  }
  template<class U>
  void update(int k,const U&upd){
    k+=size;
    data[k]=upd(data[k]);
    while(k>>=1)update(k);
  }
  void set(int k,const T&x){
    update(k,[&](T)->T {return x;});
  }
  void apply(int k,const T&x){
    update(k,[&](T y)->T {return M::op(y,x);});
  }
  T operator[](int k)const{return data[size+k];}
  T prod(int l,int r)const{
    l+=size,r+=size;
    T lprod=M::id(),rprod=M::id();
    while(l<r){
      if(l&1)lprod=M::op(lprod,data[l++]);
      if(r&1)rprod=M::op(data[--r],rprod);
      l>>=1,r>>=1;
    }
    return M::op(lprod,rprod);
  }
  T all_prod()const{return data[1];}
  template<class F>
  int max_right(int l,const F&f)const{
    if(l==n)return n;
    l+=size;
    T sum=M::id();
    do{
      while((l&1)==0)l>>=1;
      if(!f(M::op(sum,data[l]))){
        while(l<size){
          l<<=1;
          if(f(M::op(sum,data[l])))sum=M::op(sum,data[l++]);
        }
        return l-size;
      }
      sum=M::op(sum,data[l++]);
    }while((l&-l)!=l);
    return n;
  }
  template<class F>
  int min_left(int r,const F&f)const{
    if(r==0)return 0;
    r+=size;
    T sum=M::id();
    do{
      --r;
      while((r&1)&&r>1)r>>=1;
      if(!f(M::op(data[r],sum))){
        while(r<size){
          r=(r<<1)^1;
          if(f(M::op(data[r],sum)))sum=M::op(data[r--],sum);
        }
        return r+1-size;
      }
      sum=M::op(data[r],sum);
    }while((r&-r)!=r);
    return 0;
  }
};*/
template<class S,S (*op)(S,S),S (*e)()>
struct SegmentTree{
  private:
  int _n,size=1,idx=0;
  vector<S>seq;
  void update(int k){seq[k]=op(seq[k<<1],seq[k<<1^1]);}
  public:
  SegmentTree():SegmentTree(0){};
  SegmentTree(int n):SegmentTree(vector<S>(n,e())){}
  SegmentTree(const vector<S>&v):_n(int(v.size())){
    while(size<_n)size<<=1,idx++;
    seq=vector<S>(size<<1,e());
    for(int i=0;i<_n;i++)seq[size+i]=v[i];
    for(int i=size-1;i>=1;i--)update(i);
  }
  void set(int p,S x){
    p+=size;
    seq[p]=x;
    for(int i=1;i<=idx;i++)update(p>>i);
  }
  S operator[](int p)const{return seq[p+size];}
  S query(int l,int r)const{
    S sml=e(),smr=e();
    l+=size,r+=size;
    while(l<r){
      if(l&1)sml=op(sml,seq[l++]);
      if(r&1)smr=op(seq[--r],smr);
      l>>=1,r>>=1;
    }
    return op(sml,smr);
  }
  S all_query()const{return seq[1];}
  template<typename F>
  int find_right(int l,const F&f)const{
    if(l==_n)return _n;
    l+=size;
    S sum=e();
    do{
      while(!(l&1))l>>=1;
      if(!f(op(sum,seq[l]))){
        while(l<size){
          l<<=1;
          if(f(op(sum,seq[l])))sum=op(sum,seq[l++]);
        }
        return l-size;
      }
      sum=op(sum,seq[l++]);
    }while((l&-l)!=l);
    return _n;
  }
  template<typename F>
  int find_left(int r,const F&f)const{
    if(!r)return 0;
    r+=size;
    S sum=e();
    do{
      r--;
      while(r>1&&(r&1))r>>=1;
      if(!f(op(seq[r],sum))){
        while(r<size){
          (r<<=1)++;
          if(f(op(seq[r],sum)))sum=op(seq[r--],sum);
        }
        return r+1-size;
      }
      sum=op(seq[r],sum);
    }while((r&-r)!=r);
    return 0;
  }
};
/**
 * @brief Segment Tree(セグメント木)
*/