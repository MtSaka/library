---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Prim(\u6700\u5C0F\u5168\u57DF\u6728)"
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../template/template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include\"../template/template.hpp\"\n#include\"../graph-template.hpp\"\
    \n\ntemplate<typename T>\nstruct mst{\n  T cost;\n  Edges<T>es;\n};\ntemplate<typename\
    \ T>\nmst<T>prim(const Graph<T>&g){\n  T sum=T();\n  vector<bool>used(g.size(),false);\n\
    \  vector<Edge<T>>dist(g.size());\n  using pi=pair<T,int>;\n  priority_queue<pi,vector<pi>,greater<>>q;\n\
    \  q.emplace(T(),0);\n  Edges<T>es;\n  while(!q.empty()){\n    auto p=q.top();q.pop();\n\
    \    if(used[p.second])continue;\n    used[p.second]=true;\n    sum+=p.first;\n\
    \    if(dist[p.second])es.emplace_back(dist[p.second]);\n    for(auto &e:g[p.second]){\n\
    \      if(used[e]||(dist[e]&&dist[e].cost<=e.cost))continue;\n      q.emplace(e.cost,e.to);\n\
    \    }\n  }\n  return {sum,es};\n}\n/**\n * @brief Prim(\u6700\u5C0F\u5168\u57DF\
    \u6728)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Graph/mst/prim.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/mst/prim.hpp
layout: document
redirect_from:
- /library/Graph/mst/prim.hpp
- /library/Graph/mst/prim.hpp.html
title: "Prim(\u6700\u5C0F\u5168\u57DF\u6728)"
---
