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
  bundledCode: "#line 1 \"Graph/kruskal.cpp\"\n#include<bits/stdc++.h>\n#include<../../code/library/Data_Structure/dsu.cpp>\n\
    using namespace std;\ntemplate<typename T>\nstruct mst{\n  T cost;\n  vector<tuple<T,T,T>>edges;\n\
    };\ntemplate<typename T>\nmst<T> kruskal(vector<tuple<T,T,T>>edges,int v){\n \
    \ sort(edges.begin(),edges.end(),[](const tuple<T,T,T>&a,const tuple<T,T,T>&b){\n\
    \    return get<2>(a)<get<2>(b);\n  });\n  dsu d(v);\n  T total=0;\n  vector<tuple<T,T,T>>es;\n\
    \  for(auto &e:edges){\n    if(!d.same(get<0>(e),get<1>(e))){\n      d.merge(get<0>(e),get<1>(e));\n\
    \      es.emplace_back(e);\n      total+=get<2>(e);\n    }\n  }\n  return {total,es};\n\
    }\n"
  code: "#include<bits/stdc++.h>\n#include<../../code/library/Data_Structure/dsu.cpp>\n\
    using namespace std;\ntemplate<typename T>\nstruct mst{\n  T cost;\n  vector<tuple<T,T,T>>edges;\n\
    };\ntemplate<typename T>\nmst<T> kruskal(vector<tuple<T,T,T>>edges,int v){\n \
    \ sort(edges.begin(),edges.end(),[](const tuple<T,T,T>&a,const tuple<T,T,T>&b){\n\
    \    return get<2>(a)<get<2>(b);\n  });\n  dsu d(v);\n  T total=0;\n  vector<tuple<T,T,T>>es;\n\
    \  for(auto &e:edges){\n    if(!d.same(get<0>(e),get<1>(e))){\n      d.merge(get<0>(e),get<1>(e));\n\
    \      es.emplace_back(e);\n      total+=get<2>(e);\n    }\n  }\n  return {total,es};\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: Graph/kruskal.cpp
  requiredBy: []
  timestamp: '2021-09-01 16:43:39+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/kruskal.cpp
layout: document
redirect_from:
- /library/Graph/kruskal.cpp
- /library/Graph/kruskal.cpp.html
title: Graph/kruskal.cpp
---
