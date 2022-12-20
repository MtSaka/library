#pragma once
#include"../template/template.hpp"

template<typename Engine>
struct Random{
private:
  Engine rnd;
public:
  using result_type=typename Engine::result_type;
  Random():Random(random_device{}()){}
  result_type operator()(){return rnd();}
  template<typename IntType=ll>
  IntType uniform(IntType l,IntType r){
    static_assert(is_integral<IntType>::value,"template argument must be an integral type");
    return uniform_int_distribution<IntType>{l,r}(rnd);
  }
  template<typename RealType=double>
  RealType uniform(RealType l,RealType r){
    static_assert(is_floating_point<RealType>::value,"template argument must be a floating point type");
    return uniform_real_distribution<RealType>{l,r}(rnd);
  }
  bool uniform_bool(){return uniform<int>(0,1);}
  template<typename T=ll>
  pair<T,T> uniform_pair(T l,T r){
    T a,b;
    do{
      a=uniform<T>(l,r);
      b=uniform<T>(l,r);
    }while(a==b);
    if(a>b)swap(a,b);
    return {a,b};
  }
  template<typename Iter>
  void shuffle(const Iter&first,const Iter&last){
    shuffle(first,last,rnd);
  }
  template<class T>
  vector<T>permutalion(T n){
    static_assert(is_integral<T>::value,"template argument must be an integral type");
    vector<T>res(n);
    iota(res.begin(),res.end(),T());
    shuffle(all(res));
    return res;
  }
};
using Random32=Random<mt19937>;
using Random64=Random<mt19937_64>;
Random32 rand32;
Random64 rand64;
/**
 * @brief Random(乱数)
*/