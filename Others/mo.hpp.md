---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_inversions_query.test.cpp
    title: test/yosupo/static_range_inversions_query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Mo's Algorithm
    links: []
  bundledCode: "#line 2 \"Others/mo.hpp\"\nstruct Mo{\n  int n;\n  vector<int>left,right;\n\
    \  Mo(int n):n(n){}\n  void add(int l,int r){\n    left.push_back(l);\n    right.push_back(r);\n\
    \  }\n  template<typename AL,typename AR,typename DL,typename DR,typename REM>\n\
    \  void run(const AL&add_left,const AR&add_right,const DL&delete_left,const DR&delete_right,const\
    \ REM&rem){\n    int q=left.size(),width=max<int>(1,n/sqrt(q));\n    vector<int>order(q);\n\
    \    iota(order.begin(),order.end(),0);\n    sort(order.begin(),order.end(),[&](int\
    \ a,int b){\n      int ablock=left[a]/width,bblock=left[b]/width;\n      if(ablock!=bblock)return\
    \ ablock<bblock;\n      return (ablock&1)?(right[a]>right[b]):(right[a]<right[b]);\n\
    \    });\n    int l=0,r=0;\n    for(auto idx:order){\n      while(l>left[idx])add_left(--l);\n\
    \      while(r<right[idx])add_right(r++);\n      while(l<left[idx])delete_left(l++);\n\
    \      while(r>right[idx])delete_right(--r); \n      rem(idx);\n    }\n  }\n \
    \ template<typename A,typename D,typename REM>\n  void run(const A&add,const D&del,const\
    \ REM&rem){\n    run(add,add,del,del,rem);\n  }\n};\n/**\n * @brief Mo's Algorithm\n\
    */\n"
  code: "#pragma once\nstruct Mo{\n  int n;\n  vector<int>left,right;\n  Mo(int n):n(n){}\n\
    \  void add(int l,int r){\n    left.push_back(l);\n    right.push_back(r);\n \
    \ }\n  template<typename AL,typename AR,typename DL,typename DR,typename REM>\n\
    \  void run(const AL&add_left,const AR&add_right,const DL&delete_left,const DR&delete_right,const\
    \ REM&rem){\n    int q=left.size(),width=max<int>(1,n/sqrt(q));\n    vector<int>order(q);\n\
    \    iota(order.begin(),order.end(),0);\n    sort(order.begin(),order.end(),[&](int\
    \ a,int b){\n      int ablock=left[a]/width,bblock=left[b]/width;\n      if(ablock!=bblock)return\
    \ ablock<bblock;\n      return (ablock&1)?(right[a]>right[b]):(right[a]<right[b]);\n\
    \    });\n    int l=0,r=0;\n    for(auto idx:order){\n      while(l>left[idx])add_left(--l);\n\
    \      while(r<right[idx])add_right(r++);\n      while(l<left[idx])delete_left(l++);\n\
    \      while(r>right[idx])delete_right(--r); \n      rem(idx);\n    }\n  }\n \
    \ template<typename A,typename D,typename REM>\n  void run(const A&add,const D&del,const\
    \ REM&rem){\n    run(add,add,del,del,rem);\n  }\n};\n/**\n * @brief Mo's Algorithm\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: Others/mo.hpp
  requiredBy: []
  timestamp: '2022-03-05 17:45:16+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/static_range_inversions_query.test.cpp
documentation_of: Others/mo.hpp
layout: document
redirect_from:
- /library/Others/mo.hpp
- /library/Others/mo.hpp.html
title: Mo's Algorithm
---
