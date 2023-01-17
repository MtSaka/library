#pragma once
#include"../template/template.hpp"

namespace Monoid{
  template<typename M,typename=void>struct has_op:false_type{};
  template<typename M>struct has_op<M,decltype((void)M::op)>:true_type{};
  template<typename M,typename=void>struct has_id:false_type{};
  template<typename M>struct has_id<M,decltype((void)M::id)>:true_type{};
  template<typename M,typename=void>struct has_inv:false_type{};
  template<typename M>struct has_inv<M,decltype((void)M::inv)>:true_type{};
  template<typename M,typename=void>struct has_get_inv:false_type{};
  template<typename M>struct has_get_inv<M,decltype((void)M::get_inv)>:true_type{};
  template<typename A,typename=void>struct has_mul_op:false_type{};
  template<typename A>struct has_mul_op<A,decltype((void)A::mul_op)>:true_type{};
  template<typename T,typename=void>struct is_semigroup:false_type{};
  template<typename T>struct is_semigroup<T,decltype(declval<typename T::value_type>(),(void)T::op)>:true_type{};
  template<typename T,typename=void>struct is_monoid:false_type{};
  template<typename T>struct is_monoid<T,decltype(declval<typename T::value_type>(),(void)T::op,(void)T::id)>:true_type{};
  template<typename T,typename=void>struct is_group:false_type{};
  template<typename T>struct is_group<T,decltype(declval<typename T::value_type>(),(void)T::op,(void)T::id,(void)T::get_inv)>:true_type{};
  template<typename T,typename=void>struct is_action:false_type{};
  template<typename T>struct is_action<T,typename enable_if<is_monoid<typename T::M>::value&&is_semigroup<typename T::E>::value&&(has_op<T>::value||has_mul_op<T>::value)>::type>:true_type{};
  template<typename T,typename=void>struct is_distributable_action:false_type{};
  template<typename T>struct is_distributable_action<T,typename enable_if<is_action<T>::value&&!has_mul_op<T>::value>::type>:true_type{};
  template<typename T>
  struct Sum{
    using value_type=T;
    static constexpr T op(const T&x,const T&y){return x+y;}
    static constexpr T id(){return T(0);}
    static constexpr T inv(const T&x,const T&y){return x-y;}
    static constexpr T get_inv(const T&x){return -x;}
  };
  template<typename T,T max_value=infinity<T>::value>
  struct Min{
    using value_type=T;
    static constexpr T op(const T&x,const T&y){return x<y?x:y;}
    static constexpr T id(){return max_value;}
  };
  template<typename T,T min_value=infinity<T>::mvalue>
  struct Max{
    using value_type=T;
    static constexpr T op(const T&x,const T&y){return x<y?y:x;}
    static constexpr T id(){return min_value;}
  };
  template<typename T>
  struct Assign{
    using value_type=T;
    static constexpr T op(const T&,const T&x){return x;}
  };
  template<typename T,T max_value=infinity<T>::value>
  struct AssignMin{
    using M=Min<T,max_value>;
    using E=Assign<T>;
    static constexpr T op(const T&x,const T&){return x;}
  };
  template<typename T,T min_value=infinity<T>::mvalue>
  struct AssignMax{
    using M=Max<T,min_value>;
    using E=Assign<T>;
    static constexpr T op(const T&x,const T&){return x;}
  };
  template<typename T>
  struct AssignSum{
    using M=Sum<T>;
    using E=Assign<T>;
    static constexpr T mul_op(const T&x,int sz,const T&){return x*sz;}
  };
  template<typename T,T max_value=infinity<T>::value>
  struct AddMin{
    using M=Min<T,max_value>;
    using E=Sum<T>;
    static constexpr T op(const T&a,const T&b){return b+a;}
  };
  template<typename T,T min_value=infinity<T>::mvalue>
  struct AddMax{
    using M=Max<T,min_value>;
    using E=Sum<T>;
    static constexpr T op(const T&a,const T&b){return b+a;}
  };
  template<typename T>
  struct AddSum{
    using M=Sum<T>;
    using E=Sum<T>;
    static constexpr T mul_op(const T&x,int sz,const T&y){return y+x*sz;}
  };
  template<typename T,T max_value=infinity<T>::value>
  struct ChminMin{
    using M=Min<T,max_value>;
    using E=Min<T>;
    static constexpr T op(const T&x,const T&y){return y<x?y:x;}
  };
  template<typename T,T min_value=infinity<T>::mvalue>
  struct ChminMax{
    using M=Max<T,min_value>;
    using E=Min<T>;
    static constexpr T op(const T&x,const T&y){return y<x?y:x;}
  };
  template<typename T,T max_value=infinity<T>::value>
  struct ChmaxMin{
    using M=Min<T,max_value>;
    using E=Max<T>;
    static constexpr T op(const T&x,const T&y){return x<y?y:x;}
  };
  template<typename T,T min_value=infinity<T>::mvalue>
  struct ChmaxMax{
    using M=Max<T,min_value>;
    using E=Max<T>;
    static constexpr T op(const T&x,const T&y){return x<y?y:x;}
  };
  template<typename E_>
  struct AttachMonoid{
    using M=E_;
    using E=E_;
    using T=typename E_::value_type;
    static T op(const T&x,const T&y){return E_::op(y,x);}
  };
}// namespace Monoid