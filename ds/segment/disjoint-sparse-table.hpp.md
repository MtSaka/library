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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../template/template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include\"../template/template.hpp\"\n#include\"../others/monoid.hpp\"\
    \n\ntemplate<typename M>\nstruct DisjointSparseTable{\n  private:\n  using T=typename\
    \ M::value_type;\n  int lg,n;\n  vector<int>log_table;\n  vector<vector<T>>table;\n\
    \  T internal_prod(int l,int r)const{\n    r--;\n    if(l==r)return table[0][l];\n\
    \    int d=log_table[r^l];\n    return M::op(table[d][l],table[d][r]);\n  }\n\
    \  public:\n  DisjointSparseTable()=default;\n  DisjointSparseTable(const vector<T>&v){init(v);}\n\
    \  void init(const vector<T>&v){\n    n=v.size(),lg=ceil_log2(n+1);\n    table.resize(lg,vector<T>(n));\n\
    \    table[0]=v;\n    int shift=1;\n    rep(i,1,lg){\n      shift<<=1;\n     \
    \ rep(j,0,n,shift<<1){\n        int l=min<int>(j+shift,n);\n        table[i][l-1]=v[l-1];\n\
    \        rrep(k,j,l-1)table[i][k]=M::op(v[k],table[i][k+1]);\n        if(n==l)break;\n\
    \        table[i][l]=v[l];\n        int r=min<int>(l+shift,n);\n        rep(k,l+1,r)table[i][k]=M::op(table[i][k-1],v[k]);\n\
    \      }\n    }\n    log_table.resize(1<<lg);\n    rep(i,2,1<<lg)log_table[i]=log_table[i>>1]+1;\n\
    \  }\n  template<bool dummy=true,typename enable_if<Monoid::has_id<M>::value&&dummy>::type*\
    \ = nullptr>\n  T prod(int l,int r)const{\n    if(l==r)return M::id();\n    return\
    \ internal_prod(l,r);\n  }\n  template<bool dummy=true,typename enable_if<!Monoid::has_id<M>::value&&dummy>::type*\
    \ = nullptr>\n  T prod(int l,int r)const{\n    return internal_prod(l,r);\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: ds/segment/disjoint-sparse-table.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segment/disjoint-sparse-table.hpp
layout: document
redirect_from:
- /library/ds/segment/disjoint-sparse-table.hpp
- /library/ds/segment/disjoint-sparse-table.hpp.html
title: ds/segment/disjoint-sparse-table.hpp
---
