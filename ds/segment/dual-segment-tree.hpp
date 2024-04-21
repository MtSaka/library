#pragma once
#include"../../template/template.hpp"
#include"../../others/monoid.hpp"

template<typename A,bool =Monoid::is_semigroup<A>::value>
struct DualSegmentTree{
  static_assert(Monoid::is_semigroup<typename A::M>::value,"A::M must be semigroup");
  static_assert(Monoid::is_semigroup<typename A::E>::value,"A::E must be action");
  static_assert(Monoid::has_op<A>::value||Monoid::has_mul_op<A>::value,"A must have op");
  private:
  using M=typename A::M;
  using E=typename A::E;
  using T=typename M::value_type;
  using U=typename E::value_type;
  int lg,n,size;
  vector<T>data;
  vector<U>lazy;
  vector<bool>lazy_flag;
  template<bool dummy=true,typename enable_if<!Monoid::has_mul_op<A>::value&&dummy>::type* = nullptr>
  inline static T Aop(const U&a,const T&b,int){
    return A::op(a,b);
  }
  template<bool dummy=true,typename enable_if<Monoid::has_mul_op<A>::value&&dummy>::type* = nullptr>
  inline static T Aop(const U&a,const T&b,int sz){
    return A::mul_op(a,sz,b);
  }
  void all_apply(int k,U x){
    if(k<size){
      if(lazy_flag[k])lazy[k]=E::op(lazy[k],x);
      else lazy[k]=x,lazy_flag[k]=true;
    }
    else if(k<n+size){
      data[k-size]=Aop(x,data[k-size],1);
    }
  }
  void eval(int k){
    if(lazy_flag[k]){
      all_apply(k<<1,lazy[k]);
      all_apply(k<<1^1,lazy[k]);
      lazy_flag[k]=false;
    }
  }
  public:
  DualSegmentTree():DualSegmentTree(0){}
  DualSegmentTree(int n,const T&e=T{}):DualSegmentTree(vector<T>(n,e)){};
  DualSegmentTree(const vector<T>&v){init(v);}
  void init(const vector<T>&v){
    n=v.size();
    lg=ceil_log2(n);
    size=1<<lg;
    data=v;
    lazy.resize(size);
    lazy_flag.assign(size,false);
  }
  T operator[](int k){
    k+=size;
    rrep(i,1,lg+1)eval(k>>i);
    return data[k-size];
  }
  template<typename Upd>
  void update(int k,const Upd&upd){
    k+=size;
    rrep(i,1,lg+1)eval(k>>i);
    data[k-size]=upd(data[k-size]);
  }
  void set(int k,const T&x){
    update(k,[&](T)->T {return x;});
  }
  void apply(int k,const U&x){
    update(k,[&](const T&y)->T {return Aop(x,y,1);});
  }
  void apply(int l,int r,const U&x){
    l+=size,r+=size;
    rrep(i,1,lg+1){
      bool f=false;
      if(((l>>i)<<i)!=l)eval(l>>i),f=true;
      if(((r>>i)<<i)!=r)eval((r-1)>>i),f=true;
      if(!f)break;
    }
    while(l!=r){
      if(l&1)all_apply(l++,x);
      if(r&1)all_apply(--r,x);
      l>>=1,r>>=1;
    }
  }
};
template<typename E>
struct DualSegmentTree<E,true>:DualSegmentTree<Monoid::AttachMonoid<E>>{
  private:
  using Base=DualSegmentTree<Monoid::AttachMonoid<E>>;
  public:
  using Base::Base;
};
template<typename T>using RangeUpdateQuery=DualSegmentTree<Monoid::Assign<T>>;
template<typename T>using RangeAddQuery=DualSegmentTree<Monoid::Sum<T>>;
template<typename T,T max_value=infinity<T>::max>using RangeChminQuery=DualSegmentTree<Monoid::Min<T,max_value>>;
template<typename T,T min_value=infinity<T>::min>using RangeChmaxQuery=DualSegmentTree<Monoid::Max<T,min_value>>;
/**
 *@brief Dual Segment Tree(双対セグメント木)
*/