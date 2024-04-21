---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "RMQ Lowest Common Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148\
      )"
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../ds/sparse-table.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include\"../graph-template.hpp\"\n#include\"../../ds/sparse-table.hpp\"\
    \n\nnamespace Monoid{\n  struct PairMinForLCA{\n    using value_type=pair<int,int>;\n\
    \    static value_type op(const value_type&a,const value_type&b){\n      return\
    \ a.first<b.first?a:b;\n    }\n    static value_type id(){return {infinity<int>::value,-1};}\n\
    \  };\n}//namespace Monoid\ntemplate<typename T=UnweightedEdge>\nstruct RMQ_LCA:Graph<T>{\n\
    \  using Graph<T>::g;\n  vector<int>in;\n  RMQ_LCA(int n):Graph<T>(n){}\n  RMQ_LCA(const\
    \ Graph<T>&g):Graph<T>(g){}\n  void build(int root=0){\n    in.resize(g.size());\n\
    \    dfs(root,-1,0);\n    RMQ.init(rmqvec);\n  }\n  int lca(int u,int v)const{\n\
    \    if(in[u]>in[v])swap(u,v);\n    return u==v?u:RMQ.prod(in[u],in[v]).second;\n\
    \  }\n  private:\n  vector<pair<int,int>>rmqvec;\n  SparseTable<Monoid::PairMinForLCA>RMQ;\n\
    \  void dfs(int idx,int par,int d){\n    in[idx]=(int)rmqvec.size();\n    rmqvec.emplace_back(d,idx);\n\
    \    for(auto &e:g[idx])if(e!=par){\n      dfs(e,idx,d+1);\n      rmqvec.emplace_back(d,idx);\
    \  \n    }\n  }\n};\n/**\n * @brief RMQ Lowest Common Ancestor(\u6700\u5C0F\u5171\
    \u901A\u7956\u5148)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/RMQ_lowest_common_ancestor.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/RMQ_lowest_common_ancestor.hpp
layout: document
redirect_from:
- /library/graph/tree/RMQ_lowest_common_ancestor.hpp
- /library/graph/tree/RMQ_lowest_common_ancestor.hpp.html
title: "RMQ Lowest Common Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148)"
---
