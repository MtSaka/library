#pragma once
#include"../template/template.hpp"

namespace Monoid{
  template<typename T>
  struct Sum{
    using value_type=T;
    static constexpr T op(const T&x,const T&y){return x+y;}
    static constexpr T id(){return T(0);}
    static constexpr T inv(const T&x,const T&y){return x-y;}
    static constexpr T get_inv(const T&x){return -x;}
  };
  template<typename T,T max_value=infinity<T>::max>
  struct Min{
    using value_type=T;
    static constexpr T op(const T&x,const T&y){return x<y?x:y;}
    static constexpr T id(){return max_value;}
  };
  template<typename T,T min_value=-infinity<T>::min>
  struct Max{
    using value_type=T;
    static constexpr T op(const T&x,const T&y){return x<y?y:x;}
    static constexpr T id(){return min_value;}
  };
  template<typename T>
  struct Assign{
    using value_type=T;
    static constexpr T op(const T&x,const T&y){return y;}
  };
  template<typename T,T max_value=infinity<T>::max>
  struct AssignMin{
    using value_type=T;
    using M=Min<T,max_value>;
    using E=Assign<T>;
    static constexpr T op(const T&x,const T&y){return x;}
  };
  template<typename T,T min_value=-infinity<T>::min>
  struct AssignMax{
    using value_type=T;
    using M=Max<T,min_value>;
    using E=Assign<T>;
    static constexpr T op(const T&x,const T&y){return x;}
  };
}// namespace Monoid