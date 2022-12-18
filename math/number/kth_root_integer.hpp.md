---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/kth_root_integer.test.cpp
    title: test/yosupo/kth_root_integer.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Kth Root Integer
    links: []
  bundledCode: "#line 1 \"math/number/kth_root_integer.hpp\"\nuint64_t kth_root_integer(uint64_t\
    \ a,int k){\n  if(k==1)return a;\n  auto check=[&](uint64_t x){\n    uint64_t\
    \ mul=1;\n    for(int j=0;j<k;j++){\n      if(__builtin_mul_overflow(mul,x,&mul))return\
    \ false;\n    }\n    return mul<=a;\n  };\n  uint64_t ret=0;\n  for(int i=31;i>=0;i--){\n\
    \    if(check(ret|(1u<<i)))ret|=1u<<i;\n  }\n  return ret;\n}\n/**\n * @brief\
    \ Kth Root Integer\n*/\n"
  code: "uint64_t kth_root_integer(uint64_t a,int k){\n  if(k==1)return a;\n  auto\
    \ check=[&](uint64_t x){\n    uint64_t mul=1;\n    for(int j=0;j<k;j++){\n   \
    \   if(__builtin_mul_overflow(mul,x,&mul))return false;\n    }\n    return mul<=a;\n\
    \  };\n  uint64_t ret=0;\n  for(int i=31;i>=0;i--){\n    if(check(ret|(1u<<i)))ret|=1u<<i;\n\
    \  }\n  return ret;\n}\n/**\n * @brief Kth Root Integer\n*/"
  dependsOn: []
  isVerificationFile: false
  path: math/number/kth_root_integer.hpp
  requiredBy: []
  timestamp: '2022-12-18 22:43:53+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/kth_root_integer.test.cpp
documentation_of: math/number/kth_root_integer.hpp
layout: document
redirect_from:
- /library/math/number/kth_root_integer.hpp
- /library/math/number/kth_root_integer.hpp.html
title: Kth Root Integer
---
