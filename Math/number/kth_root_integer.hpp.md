---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/kth_root_integer.test.cpp
    title: test/yosupo/kth_root_integer.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Kth Root Integer
    links: []
  bundledCode: "#line 1 \"Math/number/kth_root_integer.hpp\"\nuint64_t kth_root_integer(uint64_t\
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
  path: Math/number/kth_root_integer.hpp
  requiredBy: []
  timestamp: '2022-03-22 22:15:18+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/kth_root_integer.test.cpp
documentation_of: Math/number/kth_root_integer.hpp
layout: document
redirect_from:
- /library/Math/number/kth_root_integer.hpp
- /library/Math/number/kth_root_integer.hpp.html
title: Kth Root Integer
---
