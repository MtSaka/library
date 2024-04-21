---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u6C38\u7D9A\u914D\u5217(Persistent Array)"
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
  code: "#pragma once\n#include\"../template/template.hpp\"\n\ntemplate<typename T,int\
    \ N=1>\nstruct PersistentArray{\n  struct node{\n    T val;\n    node*ch[1<<N]={};\n\
    \  };\n  node*root=nullptr;\n  static constexpr int bit=(1<<N)-1;\n  PersistentArray(){}\n\
    \  PersistentArray(const vector<T>&a){\n    build(a);\n  }\n  void build(const\
    \ vector<T>&a){\n    for(int i=0;i<(int)a.size();i++){\n      destructive_set(i,a[i],root);\n\
    \    }\n  }\n  node*get_root(){return root;}\n  void destructive_set(int idx,T\
    \ val,node*&t){\n    if(!t)t=new node();\n    if(idx==0)t->val=val;\n    else\
    \ destructive_set(idx>>N,val,t->ch[idx&bit]);\n  }\n  node*set(int idx,T val,node*const&\
    \ t){\n    node*ret=new node();\n    if(t){\n      memcpy(ret->ch,t->ch,sizeof(t->ch));\n\
    \      ret->val=t->val;\n    }\n    if(idx==0){\n      ret->val=val;\n    }\n\
    \    else{\n      ret->ch[idx&bit]=set(idx>>N,val,ret->ch[idx&bit]);\n    }\n\
    \    return ret;\n  }\n  T get(int idx, node*t){\n    if(!t)return 0;\n    if(idx==0)return\
    \ t->val;\n    return get(idx>>N,t->ch[idx&bit]);\n  }\n};\n/**\n * @brief \u6C38\
    \u7D9A\u914D\u5217(Persistent Array)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: ds/others/persistent-array.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/others/persistent-array.hpp
layout: document
redirect_from:
- /library/ds/others/persistent-array.hpp
- /library/ds/others/persistent-array.hpp.html
title: "\u6C38\u7D9A\u914D\u5217(Persistent Array)"
---
