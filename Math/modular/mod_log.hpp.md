---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/modular/modpow.hpp
    title: "Mod Pow(\u3079\u304D\u4E57)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/discrete-logarithm-mod.test.cpp
    title: test/yosupo/discrete-logarithm-mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Mod Log(\u96E2\u6563\u5BFE\u6570)"
    links: []
  bundledCode: "#line 2 \"Math/modular/modpow.hpp\"\ntemplate<typename T,typename\
    \ S>\nT modpow(T a,S b,T m){\n  T ret=1;\n  while(b){\n    if(b&1)ret=ret*a%m;\n\
    \    a=a*a%m;\n    b>>=1;\n  }\n  return ret;\n}\n/**\n * @brief Mod Pow(\u3079\
    \u304D\u4E57)\n*/\n#line 2 \"Math/modular/mod_log.hpp\"\ntemplate<typename T>\n\
    T discrete_logarithm(T x,T y,T m){\n  x%=m,y%=m;\n  if(y==1||m==1)return 0;\n\
    \  if(x==0)return y==0?1:-1;\n  T add=0,g,k=1%m;\n  while((g=gcd(x,m))>1){\n \
    \   if(y==k)return add;\n    if(y%g)return -1;\n    y/=g,m/=g,add++;\n    k=(k*(x/g))%m;\n\
    \  }\n  T n=sqrt(m)+1;\n  T tmp=modpow(x,n,m);\n  unordered_map<T,T>mp;\n  for(T\
    \ i=0,now=y;i<=n;i++){\n    mp[now]=i;\n    now=(now*x)%m;\n  }\n  for(T i=1,now=k;i<=n;i++){\n\
    \    now=(now*tmp)%m;\n    if(mp.count(now))return n*i-mp[now]+add;\n  }\n  return\
    \ -1;\n}\n/**\n * @brief Mod Log(\u96E2\u6563\u5BFE\u6570)\n*/\n"
  code: "#include\"modpow.hpp\"\ntemplate<typename T>\nT discrete_logarithm(T x,T\
    \ y,T m){\n  x%=m,y%=m;\n  if(y==1||m==1)return 0;\n  if(x==0)return y==0?1:-1;\n\
    \  T add=0,g,k=1%m;\n  while((g=gcd(x,m))>1){\n    if(y==k)return add;\n    if(y%g)return\
    \ -1;\n    y/=g,m/=g,add++;\n    k=(k*(x/g))%m;\n  }\n  T n=sqrt(m)+1;\n  T tmp=modpow(x,n,m);\n\
    \  unordered_map<T,T>mp;\n  for(T i=0,now=y;i<=n;i++){\n    mp[now]=i;\n    now=(now*x)%m;\n\
    \  }\n  for(T i=1,now=k;i<=n;i++){\n    now=(now*tmp)%m;\n    if(mp.count(now))return\
    \ n*i-mp[now]+add;\n  }\n  return -1;\n}\n/**\n * @brief Mod Log(\u96E2\u6563\u5BFE\
    \u6570)\n*/"
  dependsOn:
  - Math/modular/modpow.hpp
  isVerificationFile: false
  path: Math/modular/mod_log.hpp
  requiredBy: []
  timestamp: '2022-03-23 20:57:45+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/discrete-logarithm-mod.test.cpp
documentation_of: Math/modular/mod_log.hpp
layout: document
redirect_from:
- /library/Math/modular/mod_log.hpp
- /library/Math/modular/mod_log.hpp.html
title: "Mod Log(\u96E2\u6563\u5BFE\u6570)"
---
