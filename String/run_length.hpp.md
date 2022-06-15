---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1469.test.cpp
    title: test/yukicoder/1469.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"String/run_length.hpp\"\ntemplate<typename Cont,typename\
    \ Cmp>\nvector<pair<typename Cont::value_type,int>>run_length(const Cont&c,const\
    \ Cmp&cmp){\n  vector<pair<typename Cont::value_type,int>> ret;\n  if(c.empty())return\
    \ ret;\n  ret.emplace_back(c.front(),1);\n  for(int i=1;i<(int)c.size();i++){\n\
    \    if(cmp(c[i],ret.back().first)){\n      ret.back().second++;\n    }else{\n\
    \      ret.emplace_back(c[i],1);\n    }\n  }\n  return ret;\n}\ntemplate<typename\
    \ Cont>vector<pair<typename Cont::value_type,int>>run_length(const Cont&c){return\
    \ runlength(c,equal_to<typename Cont::value_type>());}\n"
  code: "#pragma once\ntemplate<typename Cont,typename Cmp>\nvector<pair<typename\
    \ Cont::value_type,int>>run_length(const Cont&c,const Cmp&cmp){\n  vector<pair<typename\
    \ Cont::value_type,int>> ret;\n  if(c.empty())return ret;\n  ret.emplace_back(c.front(),1);\n\
    \  for(int i=1;i<(int)c.size();i++){\n    if(cmp(c[i],ret.back().first)){\n  \
    \    ret.back().second++;\n    }else{\n      ret.emplace_back(c[i],1);\n    }\n\
    \  }\n  return ret;\n}\ntemplate<typename Cont>vector<pair<typename Cont::value_type,int>>run_length(const\
    \ Cont&c){return runlength(c,equal_to<typename Cont::value_type>());}\n"
  dependsOn: []
  isVerificationFile: false
  path: String/run_length.hpp
  requiredBy: []
  timestamp: '2022-06-15 21:02:15+01:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1469.test.cpp
documentation_of: String/run_length.hpp
layout: document
redirect_from:
- /library/String/run_length.hpp
- /library/String/run_length.hpp.html
title: String/run_length.hpp
---
