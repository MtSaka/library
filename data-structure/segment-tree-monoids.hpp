#pragma once
#include"../template/template.hpp"
#include"segment-tree.hpp"
#include"lazy-segment-tree.hpp"
#include"dual-segment-tree.hpp"

namespace MonoidSegmentTree{
  template<class T>static constexpr T op1(T a,T b){return min<T>(a,b);}
  template<class T>static constexpr T op2(T a,T b){return max<T>(a,b);}
  template<class T>static constexpr T op3(T a,T b){return a+b;}
  template<class T>static constexpr T e1(){return infinity<T>::MAX;}
  template<class T>static constexpr T e2(){return infinity<T>::MIN;}
  template<class T>static constexpr T e3(){return T(0);}
  template<class T>using RmQ=SegmentTree<T,op1<T>,e1<T>>;
  template<class T>using RMQ=SegmentTree<T,op2<T>,e2<T>>;
  template<class T>using RSQ=SegmentTree<T,op3<T>,e3<T>>;
}
using MonoidSegmentTree::RmQ;
using MonoidSegmentTree::RMQ;
using MonoidSegmentTree::RSQ;
namespace MonoidLazySegmentTree{
  template<class T>struct S{T value;int size;S(const T&a):value(a),size(1){}S(const T&a,const int&size):value(a),size(size){}operator T()const{return value;}};
  template<class T>static constexpr T op1(T a,T b){return min<T>(a,b);}
  template<class T>static constexpr T op2(T a,T b){return max<T>(a,b);}
  template<class T>static constexpr S<T> op3(S<T>a,S<T>b){return {a.value+b.value,a.size+b.size};}
  template<class T>static constexpr T e1(){return infinity<T>::MAX;}
  template<class T>static constexpr T e2(){return infinity<T>::MIN;}
  template<class T>static constexpr S<T> e3(){return {T(0),1};}
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
  template<class T>using RUQRmQ=LazySegmentTree<T,op1<T>,e1<T>,T,mapping1<T>,composition1<T>,id1<T>>;
  template<class T>using RUQRMQ=LazySegmentTree<T,op2<T>,e2<T>,T,mapping1<T>,composition1<T>,id1<T>>;
  template<class T>using RUQRSQ=LazySegmentTree<S<T>,op3<T>,e3<T>,T,mapping2<T>,composition1<T>,id1<T>>;
  template<class T>using RAQRSQ=LazySegmentTree<S<T>,op3<T>,e3<T>,T,mapping3<T>,composition2<T>,id2<T>>;
  template<class T>using RAQRmQ=LazySegmentTree<T,op1<T>,e1<T>,T,mapping4<T>,composition2<T>,id2<T>>;
  template<class T>using RAQRMQ=LazySegmentTree<T,op2<T>,e2<T>,T,mapping4<T>,composition2<T>,id2<T>>;
  template<class T>using RChminRmQ=LazySegmentTree<T,op1<T>,e1<T>,T,mapping5<T>,composition3<T>,id1<T>>;
  template<class T>using RChminRMQ=LazySegmentTree<T,op2<T>,e2<T>,T,mapping5<T>,composition3<T>,id1<T>>;
  template<class T>using RChmaxRmQ=LazySegmentTree<T,op1<T>,e1<T>,T,mapping6<T>,composition4<T>,id3<T>>;
  template<class T>using RChmaxRMQ=LazySegmentTree<T,op2<T>,e2<T>,T,mapping6<T>,composition4<T>,id3<T>>;
}
using MonoidLazySegmentTree::RUQRmQ;
using MonoidLazySegmentTree::RUQRMQ;
using MonoidLazySegmentTree::RUQRSQ;
using MonoidLazySegmentTree::RAQRSQ;
using MonoidLazySegmentTree::RAQRmQ;
using MonoidLazySegmentTree::RAQRMQ;
using MonoidLazySegmentTree::RChminRmQ;
using MonoidLazySegmentTree::RChminRMQ;
using MonoidLazySegmentTree::RChmaxRmQ;
using MonoidLazySegmentTree::RChmaxRMQ;
namespace MonoidDualSegmentTree{
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
  template<class T>using RUQ=DualSegmentTree<T,T,mapping1<T>,composition1<T>,id1<T>>;
  template<class T>using RChminQ=DualSegmentTree<T,T,mapping2<T>,composition2<T>,id1<T>>;
  template<class T>using RChmaxQ=DualSegmentTree<T,T,mapping3<T>,composition3<T>,id2<T>>;
  template<class T>using RAQ=DualSegmentTree<T,T,mapping4<T>,composition4<T>,id3<T>>;
}
using MonoidDualSegmentTree::RUQ;
using MonoidDualSegmentTree::RChminQ;
using MonoidDualSegmentTree::RChmaxQ;
using MonoidDualSegmentTree::RAQ;
/**
 * @brief Monoids(モノイド)
 */