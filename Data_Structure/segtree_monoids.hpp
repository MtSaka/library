#pragma once
#include"../template/template.hpp"
#include"segtree.hpp"
#include"lazy_segtree.hpp"
#include"dual_segtree.hpp"
namespace monoid_segtree{
  template<class T>static constexpr T op1(T a,T b){return min<T>(a,b);}
  template<class T>static constexpr T op2(T a,T b){return max<T>(a,b);}
  template<class T>static constexpr T op3(T a,T b){return a+b;}
  template<class T>static constexpr T e1(){return infinity<T>::MAX;}
  template<class T>static constexpr T e2(){return infinity<T>::MIN;}
  template<class T>static constexpr T e3(){return T(0);}
  template<class T>using RmQ=segtree<T,op1<T>,e1<T>>;
  template<class T>using RMQ=segtree<T,op2<T>,e2<T>>;
  template<class T>using RSQ=segtree<T,op3<T>,e3<T>>;
}
using monoid_segtree::RmQ;
using monoid_segtree::RMQ;
using monoid_segtree::RSQ;
namespace monoid_lazy_segtree{
  template<class T>struct S{T value;int size;S(const T&a):value(a),size(1){}S(const T&a,const int&size):value(a),size(size){}operator T()const{return value;}};
  template<class T>static constexpr T op1(T a,T b){return min<T>(a,b);}
  template<class T>static constexpr T op2(T a,T b){return max<T>(a,b);}
  template<class T>static constexpr S<T> op3(S<T>a,S<T>b){return {a.value+b.value,a.size+b.size};}
  template<class T>static constexpr T e1(){return infinity<T>::MAX;}
  template<class T>static constexpr T e2(){return infinity<T>::MIN;}
  template<class T>static constexpr S<T> e3(){return {T(0),0};}
  template<class T>static constexpr T mapping1(T a,T b){return a==infinity<T>::MAX?b:a;}
  template<class T>static constexpr S<T> mapping2(T a,S<T>b){if(a!=infinity<T>::MAX)b.value=a*b.size;return b;}
  template<class T>static constexpr S<T> mapping3(T a,S<T>b){return {b.value+a*b.size,b.size};}
  template<class T>static constexpr T mapping4(T a,T b){return a+b;}
  template<class T>static constexpr T mapping5(T a,T b){return min<T>(a,b);}
  template<class T>static constexpr T mapping6(T a,T b){return max<T>(a,b);}
  template<class T>static constexpr T composition1(T a,T b){return a==infinity<T>::MAX?b:a;}
  template<class T>static constexpr T composition2(T a,T b){return a+b;}
  template<class T>static constexpr T composition3(T a,T b){return min<T>(a,b);}
  template<class T>static constexpr T composition4(T a,T b){return max<T>(a,b);}
  template<class T>static constexpr T id1(){return infinity<T>::MAX;}
  template<class T>static constexpr T id2(){return T(0);}
  template<class T>static constexpr T id3(){return infinity<T>::MIN;}
  template<class T>using RUQRmQ=lazy_segtree<T,op1<T>,e1<T>,T,mapping1<T>,composition1<T>,id1<T>>;
  template<class T>using RUQRMQ=lazy_segtree<T,op2<T>,e2<T>,T,mapping1<T>,composition1<T>,id1<T>>;
  template<class T>using RUQRSQ=lazy_segtree<S<T>,op3<T>,e3<T>,T,mapping2<T>,composition1<T>,id1<T>>;
  template<class T>using RAQRSQ=lazy_segtree<S<T>,op3<T>,e3<T>,T,mapping3<T>,composition2<T>,id2<T>>;
  template<class T>using RAQRmQ=lazy_segtree<T,op1<T>,e1<T>,T,mapping4<T>,composition2<T>,id2<T>>;
  template<class T>using RAQRMQ=lazy_segtree<T,op2<T>,e2<T>,T,mapping4<T>,composition2<T>,id2<T>>;
  template<class T>using RChminRmQ=lazy_segtree<T,op1<T>,e1<T>,T,mapping5<T>,composition3<T>,id1<T>>;
  template<class T>using RChminRMQ=lazy_segtree<T,op2<T>,e2<T>,T,mapping5<T>,composition3<T>,id1<T>>;
  template<class T>using RChmaxRmQ=lazy_segtree<T,op1<T>,e1<T>,T,mapping6<T>,composition4<T>,id3<T>>;
  template<class T>using RChmaxRMQ=lazy_segtree<T,op2<T>,e2<T>,T,mapping6<T>,composition4<T>,id3<T>>;
}
using monoid_lazy_segtree::RUQRmQ;
using monoid_lazy_segtree::RUQRMQ;
using monoid_lazy_segtree::RUQRSQ;
using monoid_lazy_segtree::RAQRSQ;
using monoid_lazy_segtree::RAQRmQ;
using monoid_lazy_segtree::RAQRMQ;
using monoid_lazy_segtree::RChminRmQ;
using monoid_lazy_segtree::RChminRMQ;
using monoid_lazy_segtree::RChmaxRmQ;
using monoid_lazy_segtree::RChmaxRMQ;
namespace monoid_dual_segtree{
  template<class T>static constexpr T mapping1(T a,T b){return a==infinity<T>::MAX?b:a;}
  template<class T>static constexpr T mapping2(T a,T b){return min<T>(a,b);}
  template<class T>static constexpr T mapping3(T a,T b){return max<T>(a,b);}
  template<class T>static constexpr T mapping4(T a,T b){return a+b;}
  template<class T>static constexpr T composition1(T a,T b){return a==infinity<T>::MAX?b:a;}
  template<class T>static constexpr T composition2(T a,T b){return min<T>(a,b);}
  template<class T>static constexpr T composition3(T a,T b){return max<T>(a,b);}
  template<class T>static constexpr T composition4(T a,T b){return a+b;}
  template<class T>static constexpr T id1(){return infinity<T>::MAX;}
  template<class T>static constexpr T id2(){return infinity<T>::MIN;}
  template<class T>static constexpr T id3(){return T(0);}
  template<class T>using RUQ=dual_segtree<T,T,mapping1<T>,composition1<T>,id1<T>>;
  template<class T>using RChminQ=dual_segtree<T,T,mapping2<T>,composition2<T>,id1<T>>;
  template<class T>using RChmaxQ=dual_segtree<T,T,mapping3<T>,composition3<T>,id2<T>>;
  template<class T>using RAQ=dual_segtree<T,T,mapping4<T>,composition4<T>,id3<T>>;
}
using monoid_dual_segtree::RUQ;
using monoid_dual_segtree::RChminQ;
using monoid_dual_segtree::RChmaxQ;
using monoid_dual_segtree::RAQ;
/**
 * @brief Monoids(モノイド)
 */