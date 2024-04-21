---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Kruskal(\u6700\u5C0F\u5168\u57DF\u6728)"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../template/template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include\"../../template/template.hpp\"\n#include\"../../ds/union-find/union-find.hpp\"\
    \n#include\"../graph-template.hpp\"\n\ntemplate<typename T>\nstruct mst{\n  T\
    \ cost;\n  Edges<T>es;\n};\ntemplate<typename T>\nmst<T>kruskal(Edges<T>&ed,int\
    \ v){\n  sort(ed.begin(),ed.end());\n  UnionFind d(v);\n  T total=0;\n  Edges<T>es;\n\
    \  for(auto &e:ed){\n    if(!d.same(e.to,e.from)){\n      d.merge(e.to,e.from);\n\
    \      es.emplace_back(e);\n      total+=e.cost;\n    }\n  }\n  return {total,es};\n\
    }\n/**\n * @brief Kruskal(\u6700\u5C0F\u5168\u57DF\u6728)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: graph/mst/kruskal.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/mst/kruskal.hpp
layout: document
redirect_from:
- /library/graph/mst/kruskal.hpp
- /library/graph/mst/kruskal.hpp.html
title: "Kruskal(\u6700\u5C0F\u5168\u57DF\u6728)"
---
