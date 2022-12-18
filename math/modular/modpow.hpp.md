---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/convolution/convolution.hpp
    title: "Convolution(\u7573\u307F\u8FBC\u307F)"
  - icon: ':heavy_check_mark:'
    path: math/convolution/convolution_mod.hpp
    title: "Arbitrary Mod Convolution(\u4EFB\u610Fmod\u7573\u307F\u8FBC\u307F)"
  - icon: ':question:'
    path: math/convolution/ntt.hpp
    title: "Number Theoretic Transform(\u6570\u8AD6\u5909\u63DB)"
  - icon: ':question:'
    path: math/fps/fps.hpp
    title: "Formal Power Series(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)"
  - icon: ':x:'
    path: math/fps/multipoint_evaluation.hpp
    title: "Multipoint Evaluation(\u591A\u70B9\u8A55\u4FA1)"
  - icon: ':x:'
    path: math/fps/polynomial_interpolation.hpp
    title: "Polynomial Interpolation(\u591A\u9805\u5F0F\u88DC\u9593)"
  - icon: ':x:'
    path: math/fps/subset_sum.hpp
    title: Count Subset Sum
  - icon: ':x:'
    path: math/fps/taylor_shift.hpp
    title: "Taylor Shift(\u591A\u9805\u5F0F\u306E\u5E73\u884C\u79FB\u52D5)"
  - icon: ':heavy_check_mark:'
    path: math/modular/mod_log.hpp
    title: "Mod Log(\u96E2\u6563\u5BFE\u6570)"
  - icon: ':x:'
    path: math/modular/mod_sqrt.hpp
    title: "Mod Square Root(\u5E73\u65B9\u5270\u4F59)"
  - icon: ':question:'
    path: math/number/primitive_root.hpp
    title: "Primitive Root(\u539F\u59CB\u6839)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL/NTL_1_B.test.cpp
    title: test/aoj/NTL/NTL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod.test.cpp
    title: test/yosupo/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod_1000000007.test.cpp
    title: test/yosupo/convolution_mod_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/discrete-logarithm-mod.test.cpp
    title: test/yosupo/discrete-logarithm-mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/division_of_polynomials.test.cpp
    title: test/yosupo/division_of_polynomials.test.cpp
  - icon: ':x:'
    path: test/yosupo/exp_of_formal_power_series.test.cpp
    title: test/yosupo/exp_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/log_of_formal_power_series.test.cpp
    title: test/yosupo/log_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/multipoint_evaluation.test.cpp
    title: test/yosupo/multipoint_evaluation.test.cpp
  - icon: ':x:'
    path: test/yosupo/polynomial_interpolation.test.cpp
    title: test/yosupo/polynomial_interpolation.test.cpp
  - icon: ':x:'
    path: test/yosupo/polynomial_taylor_shift.test.cpp
    title: test/yosupo/polynomial_taylor_shift.test.cpp
  - icon: ':x:'
    path: test/yosupo/pow_of_formal_power_series.test.cpp
    title: test/yosupo/pow_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/sharp_p_subset_sum.test.cpp
    title: test/yosupo/sharp_p_subset_sum.test.cpp
  - icon: ':x:'
    path: test/yosupo/sqrt_mod.test.cpp
    title: test/yosupo/sqrt_mod.test.cpp
  - icon: ':x:'
    path: test/yosupo/sqrt_of_formal_power_series.test.cpp
    title: test/yosupo/sqrt_of_formal_power_series.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "Mod Pow(\u3079\u304D\u4E57)"
    links: []
  bundledCode: "#line 2 \"math/modular/modpow.hpp\"\ntemplate<typename T,typename\
    \ S>\nT modpow(T a,S b,T m){\n  T ret=1;\n  while(b){\n    if(b&1)ret=ret*a%m;\n\
    \    a=a*a%m;\n    b>>=1;\n  }\n  return ret;\n}\n/**\n * @brief Mod Pow(\u3079\
    \u304D\u4E57)\n*/\n"
  code: "#pragma once\ntemplate<typename T,typename S>\nT modpow(T a,S b,T m){\n \
    \ T ret=1;\n  while(b){\n    if(b&1)ret=ret*a%m;\n    a=a*a%m;\n    b>>=1;\n \
    \ }\n  return ret;\n}\n/**\n * @brief Mod Pow(\u3079\u304D\u4E57)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: math/modular/modpow.hpp
  requiredBy:
  - math/number/primitive_root.hpp
  - math/fps/fps.hpp
  - math/fps/polynomial_interpolation.hpp
  - math/fps/taylor_shift.hpp
  - math/fps/multipoint_evaluation.hpp
  - math/fps/subset_sum.hpp
  - math/modular/mod_sqrt.hpp
  - math/modular/mod_log.hpp
  - math/convolution/convolution_mod.hpp
  - math/convolution/convolution.hpp
  - math/convolution/ntt.hpp
  timestamp: '2022-12-18 22:43:53+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/NTL/NTL_1_B.test.cpp
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/yosupo/division_of_polynomials.test.cpp
  - test/yosupo/sqrt_mod.test.cpp
  - test/yosupo/convolution_mod.test.cpp
  - test/yosupo/polynomial_taylor_shift.test.cpp
  - test/yosupo/pow_of_formal_power_series.test.cpp
  - test/yosupo/convolution_mod_1000000007.test.cpp
  - test/yosupo/sharp_p_subset_sum.test.cpp
  - test/yosupo/discrete-logarithm-mod.test.cpp
  - test/yosupo/sqrt_of_formal_power_series.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
  - test/yosupo/polynomial_interpolation.test.cpp
  - test/yosupo/multipoint_evaluation.test.cpp
  - test/yosupo/inv_of_formal_power_series.test.cpp
documentation_of: math/modular/modpow.hpp
layout: document
redirect_from:
- /library/math/modular/modpow.hpp
- /library/math/modular/modpow.hpp.html
title: "Mod Pow(\u3079\u304D\u4E57)"
---
