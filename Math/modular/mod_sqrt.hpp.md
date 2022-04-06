---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/modular/modpow.hpp
    title: "Mod Pow(\u3079\u304D\u4E57)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sqrt_mod.test.cpp
    title: test/yosupo/sqrt_mod.test.cpp
  - icon: ':x:'
    path: test/yosupo/sqrt_of_formal_power_series.test.cpp
    title: test/yosupo/sqrt_of_formal_power_series.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "Mod Square Root(\u5E73\u65B9\u5270\u4F59)"
    links: []
  bundledCode: "#line 2 \"Math/modular/modpow.hpp\"\ntemplate<typename T,typename\
    \ S>\nT modpow(T a,S b,T m){\n  T ret=1;\n  while(b){\n    if(b&1)ret=ret*a%m;\n\
    \    a=a*a%m;\n    b>>=1;\n  }\n  return ret;\n}\n/**\n * @brief Mod Pow(\u3079\
    \u304D\u4E57)\n*/\n#line 3 \"Math/modular/mod_sqrt.hpp\"\ntemplate<typename T,typename\
    \ S>\nS mod_sqrt(T a,S p){\n  a%=p;\n  if(a==0)return 0;\n  if(p==2)return a;\n\
    \  if(modpow(a,(p-1)/2,p)!=1)return -1;\n  if((p&3)==3)return modpow(a,(p+1)/4,p);\n\
    \  S q=p-1,s=0,z=2;\n  while(!(q&1))q>>=1,s++;\n  while(modpow(z,(p-1)/2,p)==1)z++;\n\
    \  S m=s,c=modpow(z,q,p),t=modpow(a,q,p),r=modpow(a,(q+1)/2,p);\n  while(t!=1){\n\
    \    S pow_t=t*t%p,m_update;\n    for(int j=1;j<m;j++){\n      if(pow_t==1){\n\
    \        m_update=j;\n        break;\n      }\n      pow_t=pow_t*pow_t%p;\n  \
    \  }\n    S b=modpow(c,S(1)<<(m-m_update-1),p);\n    m=m_update,c=modpow(b,2,p),t=(t*b%p)*b%p,r=r*b%p;\n\
    \  }\n  return r;\n}\n/**\n * @brief Mod Square Root(\u5E73\u65B9\u5270\u4F59\
    )\n*/\n"
  code: "#pragma once\n#include\"modpow.hpp\"\ntemplate<typename T,typename S>\nS\
    \ mod_sqrt(T a,S p){\n  a%=p;\n  if(a==0)return 0;\n  if(p==2)return a;\n  if(modpow(a,(p-1)/2,p)!=1)return\
    \ -1;\n  if((p&3)==3)return modpow(a,(p+1)/4,p);\n  S q=p-1,s=0,z=2;\n  while(!(q&1))q>>=1,s++;\n\
    \  while(modpow(z,(p-1)/2,p)==1)z++;\n  S m=s,c=modpow(z,q,p),t=modpow(a,q,p),r=modpow(a,(q+1)/2,p);\n\
    \  while(t!=1){\n    S pow_t=t*t%p,m_update;\n    for(int j=1;j<m;j++){\n    \
    \  if(pow_t==1){\n        m_update=j;\n        break;\n      }\n      pow_t=pow_t*pow_t%p;\n\
    \    }\n    S b=modpow(c,S(1)<<(m-m_update-1),p);\n    m=m_update,c=modpow(b,2,p),t=(t*b%p)*b%p,r=r*b%p;\n\
    \  }\n  return r;\n}\n/**\n * @brief Mod Square Root(\u5E73\u65B9\u5270\u4F59\
    )\n*/"
  dependsOn:
  - Math/modular/modpow.hpp
  isVerificationFile: false
  path: Math/modular/mod_sqrt.hpp
  requiredBy: []
  timestamp: '2022-03-25 21:53:48+00:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/sqrt_mod.test.cpp
  - test/yosupo/sqrt_of_formal_power_series.test.cpp
documentation_of: Math/modular/mod_sqrt.hpp
layout: document
redirect_from:
- /library/Math/modular/mod_sqrt.hpp
- /library/Math/modular/mod_sqrt.hpp.html
title: "Mod Square Root(\u5E73\u65B9\u5270\u4F59)"
---
