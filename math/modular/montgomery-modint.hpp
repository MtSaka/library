#pragma once
#include"../../template/template.hpp"

template<typename T>
struct MontgomeryReduction{
  static_assert(is_integral<T>::value,"template argument must be integral");
  static_assert(is_unsigned<T>::value,"template argument must be unsigned");
  private:
  
  public:

};