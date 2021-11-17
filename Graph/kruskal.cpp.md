---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../Data_Structure/dsu.cpp:\
    \ line -1: no such header\n"
  code: "#include\"../../Data_Structure/dsu.cpp\"\nusing namespace std;\ntemplate<typename\
    \ T>\nstruct mst{\n  T cost;\n  vector<tuple<T,T,T>>edges;\n};\ntemplate<typename\
    \ T>\nmst<T> kruskal(vector<tuple<T,T,T>>edges,int v){\n  sort(edges.begin(),edges.end(),[](const\
    \ tuple<T,T,T>&a,const tuple<T,T,T>&b){\n    return get<2>(a)<get<2>(b);\n  });\n\
    \  dsu d(v);\n  T total=0;\n  vector<tuple<T,T,T>>es;\n  for(auto &e:edges){\n\
    \    if(!d.same(get<0>(e),get<1>(e))){\n      d.merge(get<0>(e),get<1>(e));\n\
    \      es.emplace_back(e);\n      total+=get<2>(e);\n    }\n  }\n  return {total,es};\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: Graph/kruskal.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/kruskal.cpp
layout: document
redirect_from:
- /library/Graph/kruskal.cpp
- /library/Graph/kruskal.cpp.html
title: Graph/kruskal.cpp
---
