#pragma once
#include"../template/template.hpp"

template<typename A>
struct LazySegmentTree{
  static_assert(Monoid::is_action<A>::value,"A must be action");
  private:
  using M=typename A::M;
  using E=typename A::E;
  using T=typename M::value_type;
  using U=typename E::value_type;
  int lg,n,size;
  vector<T>data;
  vector<U>lazy;
  vector<bool>lazy_flag;
  template<typename enable_if<Monoid::has_mul_op<A>>::type* = nullptr>
  inline static T Aop(const U&a,const T&b,int sz){
    return A::mul_op(a,sz,b);
  }
  template<typename enable_if<!Monoid::has_mul_op<A>>::type* = nullptr>
  inline static T Aop(const U&a,const T&b,int sz){
    return A::op(a,b);
  }
  void update(int k){data[k]=M::op(data[k<<1],data[k<<1^1]);}
  void all_apply(int k,const U&x,int sz){
    data[k]=Aop(x,data[k],sz);
    if(k<size){
      if(lazy_flag[k])lazy[k]=E::op(lazy[k],x);
      else lazy[k]=x,lazy_flag[k]=true;
    }
  }
  void eval(int k,int sz){
    if(lazy_flag[k]){
      all_apply(k<<1,lazy[k],sz>>1);
      all_apply(k<<1^1,lazy[k],sz>>1);
      lazy_flag[k]=false;
    }
  }
  public:
  LazySegmentTree():LazySegmentTree(0){}
  LazySegmentTree(int n):LazySegmentTree(vector<T>(n,M::id())){}
  LazySegmentTree(int n,T x):LazySegmentTree(vector<T>(n,x)){}
  LazySegmentTree(const vector<T>&v){init(v);}
  void init(const vecotr<T>&v){
    n=v.size();
    lg=ceil_log2(n);
    size=1<<lg;
    data.assign(size<<1,M::id());
    lazy.resize(size);
    lazy_flag.assign(size,false);
    rep(i,n)data[size+i]=v[i];
    rrep(i,1,size)update(i);
  }
  T prod(T l,T r){
    if(l==r)return M::id();
    l+=size,r+=size;
    rrep(i,1,lg+1){
      bool f=false;
      if(((l>>i)<<i)!=l)eval(l>>i,1<<i),f=true;
      if(((r>>i)<<i)!=r)eval((r-1)>>i,1<<i),f=true;
      if(!f)break;
    }
    T sml=M::id(),smr=M::id();
    while(l<r){
      if(l&1)sml=M::op(sml,data[l++]);
      if(r&1)smr=M::op(data[--r],smr);
      l>>=1,r>>=1;
    }
    return M::op(sml,smr);
  }
  T operator[](int k){
    k+=size;
    rrep(i,1,lg+1)eval(k>>i,1<<i);
    return data[k];
  }
  T all_prod()const{return data[1];}
  template<typename Upd>
  void update(int k,const Upd&upd){
    k+=size;
    rrep(i,1,lg+1)eval(k>>i,1<<i);
    data[k]=upd(data[k]);
    rep(i,1,lg+1)update(k>>i);
  }
  void set(int k,const T&x){
    update(k,[&](const T&y)->T {return x;});
  }
  template<typename enable_if<Monoid::has_mul_op<A>>::type* = nullptr>
  void apply(int k,const U&x){
    update(k,[&](const T&y)->T {return A::op(x,y);});
  }
  void apply(int l,int r,const U&x){
    if(l==r)return;
    l+=size,r+=size;
    int lst=lg+1;
    rrep(i,1,lg+1){
      if(((l>>i)<<i)!=l)eval(l>>i,1<<i),lst=i;
      if(((r>>i)<<i)!=r)eval((r-1)>>i,1<<i),lst=i;
      if(lst!=i)break;
    }
    for(int l2=l,r2=r,sz=1;l2<r2;l2>>=1,r2>>=1,sz<<=1){
      if(l2&1)all_apply(l2++,x,sz);
      if(r2&1)all_apply(--r2,x,sz);
    }
    rep(i,lst,lg+1){
      if(((l>>i)<<i)!=l)update(l>>i);
      if(((r>>i)<<i)!=r)update((r-1)>>i);
    }
  }

};
template<typename T,T max_value=infinity<T>::max>
using RangeUpdateQueryRangeMinimumQuery=LazySegmentTree<Monoid::AssignMin<T,max_value>>;
template<typename T,T min_value=infinity<T>::min>
using RangeUpdateQueryRangeMaximumQuery=LazySegmentTree<Monoid::AssignMax<T,min_value>>;
template<typename T>
using RangeUpdateQueryRangeSumQuery=LazySegmentTree<Monoid::AssignSum<T>>;
template<typename T,T max_value=infinity<T>::max>
using RangeAddQueryRangeMinimumQuery=LazySegmentTree<Monoid::AddMin<T,max_value>>;
template<typename T,T min_value=infinity<T>::min>
using RangeAddQueryRangeMaximumQuery=LazySegmentTree<Monoid::AddMax<T,min_value>>;
template<typename T>
using RangeAddQueryRangeSumQuery=LazySegmentTree<Monoid::AddSum<T>>;
template<typename T,T max_value=infinity<T>::max>
using RangeChminQueryRangeMinimumQuery=LazySegmentTree<Monoid::ChminMin<T,max_value>>;
template<typename T,T min_value=infinity<T>::min>
using RangeChminQueryRangeMaximumQuery=LazySegmentTree<Monoid::ChminMax<T,min_value>>;
template<typename T,T max_value=infinity<T>::max>
using RangeChmaxQueryRangeMinimumQuery=LazySegmentTree<Monoid::ChmaxMin<T,max_value>>;
template<typename T,T min_value=infinity<T>::min>
using RangeChmaxQueryRangeMaximumQuery=LazySegmentTree<Monoid::ChmaxMax<T,min_value>>;
/**
 * @brief Lazy Segment Tree(遅延セグメント木)
*/