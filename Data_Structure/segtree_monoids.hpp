#pragma once
#include"../template/template.hpp"
#include"segtree.hpp"
#include"lazy_segtree.hpp"
#include"dual_segtree.hpp"
namespace monoid_segtree{
  template<class T>static constexpr T op1(T a,T b){return min<T>(a,b);}
  template<class T>static constexpr T op2(T a,T b){return max<T>(a,b);}
  template<class T>static constexpr T op3(T a,T b){return a+b;}
  template<class T>static constexpr T e1(){return INF<T>;}
  template<class T>static constexpr T e2(){return infinity<T>::mvalue;}
  template<class T>static constexpr T e3(){return T(0);}
  template<class T>using RmQ=segtree<T,op1<T>,e1<T>>;
  template<class T>using RMQ=segtree<T,op2<T>,e2<T>>;
  template<class T>using RSQ=segtree<T,op3<T>,e3<T>>;
}
using monoid_segtree::RmQ;
using monoid_segtree::RMQ;
using monoid_segtree::RSQ;
namespace monoid_lazy_segtree{

}
namespace monoid_dual_segtree{
}
