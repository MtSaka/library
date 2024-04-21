---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Sparse Table
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../template/template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include\"../template/template.hpp\"\n#include\"../others/monoid.hpp\"\
    \n\ntemplate<typename M>\nstruct SparseTable{\n  private:\n  using T=typename\
    \ M::value_type;\n  int lg,n;\n  vector<vector<T>>table;\n  vector<int>log_table;\n\
    \  T internal_prod(int l,int r)const{\n    int d=log_table[r-l];\n    return M::op(table[d][l],table[d][r-(1<<d)]);\n\
    \  }\n  public:\n  SparseTable()=default;\n  SparseTable(const vector<T>&v){init(v);}\n\
    \  void init(const vector<T>&v){\n    n=v.size();\n    lg=ceil_log2(n)+1;\n  \
    \  table.assign(lg,vector<T>(n));\n    table[0]=v;\n    rep(i,1,lg)rep(j,n-(1<<i)+1)table[i][j]=M::op(table[i-1][j],table[i-1][j+(1<<(i-1))]);\n\
    \    log_table.assign(n+1,0);\n    log_table[1]=0;\n    rep(i,2,n+1)log_table[i]=log_table[i>>1]+1;\n\
    \  }\n  template<bool dummy=true,typename enable_if<Monoid::has_id<M>::value&&dummy>::type*\
    \ = nullptr>\n  T prod(int l,int r)const{\n    if(l==r)return M::id();\n    return\
    \ internal_prod(l,r);\n  }\n  template<bool dummy=true,typename enable_if<!Monoid::has_id<M>::value&&dummy>::type*\
    \ = nullptr>\n  T prod(int l,int r)const{\n    if(l==r)return T{};\n    return\
    \ internal_prod(l,r);\n  }\n};\n/**\n * @brief Sparse Table\n*/"
  dependsOn: []
  isVerificationFile: false
  path: ds/segment/sparse-table.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segment/sparse-table.hpp
layout: document
redirect_from:
- /library/ds/segment/sparse-table.hpp
- /library/ds/segment/sparse-table.hpp.html
title: Sparse Table
---
