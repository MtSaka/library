---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../template/template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include\"../../template/template.hpp\"\n\ntemplate<typename\
    \ Cont,typename Cmp>\nvector<pair<typename Cont::value_type,int>>run_length(const\
    \ Cont&c,const Cmp&cmp){\n  vector<pair<typename Cont::value_type,int>> ret;\n\
    \  if(c.empty())return ret;\n  ret.emplace_back(c.front(),1);\n  for(int i=1;i<(int)c.size();i++){\n\
    \    if(cmp(c[i],ret.back().first)){\n      ret.back().second++;\n    }else{\n\
    \      ret.emplace_back(c[i],1);\n    }\n  }\n  return ret;\n}\ntemplate<typename\
    \ Cont>vector<pair<typename Cont::value_type,int>>run_length(const Cont&c){return\
    \ run_length(c,equal_to<typename Cont::value_type>());}"
  dependsOn: []
  isVerificationFile: false
  path: string/run_length.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/run_length.hpp
layout: document
redirect_from:
- /library/string/run_length.hpp
- /library/string/run_length.hpp.html
title: string/run_length.hpp
---
