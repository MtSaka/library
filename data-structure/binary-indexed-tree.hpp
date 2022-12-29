#pragma once
#include"../template/template.hpp"
#include"../others/monoid.hpp"

template<typename M,bool=Monoid::is_monoid<M>::value>
struct BinaryIndexedTree{
  private:
  using T=typename M::value_type;
  int n;
  vector<T>data;
  public:
  BinaryIndexedTree():BinaryIndexedTree(0){}
  BinaryIndexedTree(int n_){init(n_);}
  void init(int n_){
    n=n_;
    data.assign(n+1,M::id());
  }
  void apply(int k,T x){
    k++;
    while(k<=n){
      data[k]=M::op(data[k],x);
      k+=k&-k;
    }
  }
  T prod(int k)const{
    T res=M::id();
    while(k){
      res=M::op(res,data[k]);
      k-=k&-k;
    }
    return res;
  }
  template<bool dummy=true,typename enable_if<Monoid::has_inv<M>::value&&dummy>::type* = nullptr>
  T prod(int l,int r)const{
    return M::inv(prod(r),prod(l));
  }
  T operator[](int k)const{return prod(k,k+1);}
  void set(int k,T x){apply(k,M::inv(x,(*this)[k]));}
};
template<typename T>
struct BinaryIndexedTree<T,false>:BinaryIndexedTree<Monoid::Sum<T>>{
  private:
  using Base=BinaryIndexedTree<Monoid::Sum<T>>;
  public:
  using Base::Base;
  void add(int k,T x){this->apply(k,x);}
  T sum(int k)const{return this->prod(k);}
  T sum(int l,int r)const{return this->prod(l,r);}
};
/**
 * @brief Binary Indexed Tree(Fenwick Tree, BIT)
*/