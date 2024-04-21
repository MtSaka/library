---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Binary Trie
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
  code: "#pragma once\n#include\"../template/template.hpp\"\n\ntemplate<class S,int\
    \ B=(sizeof(S)*8-1)>\nstruct BinaryTrie{\n  private:\n  struct node{\n    int\
    \ ch[2];\n    int count;\n    node():ch{-1,-1},count(0){}\n  };\n  int sz=1;\n\
    \  vector<node>v;\n  S xor_all=0;\n  int find(S x,S xor_val=0)const{\n    xor_val^=xor_all;\n\
    \    int idx=0;\n    for(int i=B-1;i>=0;i--){\n      int b=(x>>i)&1;\n      if((xor_val>>i)&1)b^=1;\n\
    \      if(v[idx].ch[b]==-1)return -1;\n      idx=v[idx].ch[b];\n    }\n    return\
    \ idx;\n  }\n  int make(){v.emplace_back(node());return sz++;}\n  public:\n  BinaryTrie():v(1){}\n\
    \  void insert(S x,S xor_val=0){add(x,1,xor_val);}\n  void erase(S x,S xor_val=0){add(x,-1,xor_val);}\n\
    \  void add(S x,int a,S xor_val=0){\n    xor_val^=xor_all;\n    int idx=0;\n \
    \   v[idx].count+=a;\n    for(int i=B-1;i>=0;i--){\n      int b=(x>>i)&1;\n  \
    \    if((xor_val>>i)&1)b^=1;\n      if(v[idx].ch[b]==-1)v[idx].ch[b]=make();\n\
    \      idx=v[idx].ch[b];\n      v[idx].count+=a;\n    }\n  }\n  S min_element(S\
    \ xor_val=0)const{return kth_element(0,xor_val);}\n  S max_element(S xor_val=0)const{return\
    \ kth_element(size()-1,xor_val);}\n  S kth_element(int k,S xor_val=0)const{\n\
    \    xor_val^=xor_all;\n    int idx=0;\n    S ret=0;\n    for(int i=B-1;i>=0;i--){\n\
    \      bool f=(xor_val>>i)&1;\n      int u0=(f?v[idx].ch[1]:v[idx].ch[0]);\n \
    \     int u1=(f?v[idx].ch[0]:v[idx].ch[1]);\n      if(u0==-1||v[u0].count<=k){\n\
    \        if(u0!=-1)k-=v[u0].count;\n        idx=u1;\n        ret|=(S(1)<<i);\n\
    \      }\n      else idx=u0;\n    }\n    return ret;\n  }\n  int order(S k,S xor_val=0)const{\n\
    \    xor_val^=xor_all;\n    int idx=0;\n    int order=0;\n    for(int i=B-1;i>=0;i--){\n\
    \      bool b=(k>>i)&1;\n      bool f=(xor_val>>i)&1;\n      int u0=(f?v[idx].ch[1]:v[idx].ch[0]);\n\
    \      int u1=(f?v[idx].ch[0]:v[idx].ch[1]);\n      if(b){\n        if(u0!=-1)order+=v[u0].count;\n\
    \        idx=u1;\n      }\n      else idx=u0;\n      if(idx==-1)break;\n    }\n\
    \    return order;\n  }\n  S lower_bound(S k,S xor_val=0)const{\n    return kth_element(order(k,xor_val));\n\
    \  }\n  S upper_bound(S k,S xor_val=0)const{\n    return kth_element(order(k+1,xor_val));\n\
    \  }\n  void all_xor(S x){xor_all^=x;}\n  int count(S x)const{\n    int tmp=find(x);\n\
    \    return (tmp==-1?0:v[tmp].count);\n  }\n  int size()const{return v[0].count;}\n\
    };\n/*\ntemplate<class S,int B=(sizeof(S)*8-1)>\nstruct BinaryTrie{\n  private:\n\
    \  struct node{\n    node*ch[2];\n    int count;\n    node():ch{nullptr,nullptr},count(0){}\n\
    \  };\n  node*root;\n  S xor_all=0;\n  node* find(S x,S xor_val=0)const{\n   \
    \ xor_val^=xor_all;\n    node*u=root;\n    for(int i=B-1;i>=0;i--){\n      int\
    \ b=(x>>i)&1;\n      if((xor_val>>i)&1)b^=1;\n      if(u->ch[b]==nullptr)return\
    \ nullptr;\n      u=u->ch[b];\n    }\n    return u;\n  }\n  public:\n  BinaryTrie():root(new\
    \ node()){}\n  void insert(S x,S xor_val=0){add(x,1,xor_val);}\n  void erase(S\
    \ x,S xor_val=0){add(x,-1,xor_val);}\n  void add(S x,int a,S xor_val=0){\n   \
    \ xor_val^=xor_all;\n    node*u=root;\n    u->count+=a;\n    for(int i=B-1;i>=0;i--){\n\
    \      int b=(x>>i)&1;\n      if((xor_val>>i)&1)b^=1;\n      if(u->ch[b]==nullptr)u->ch[b]=new\
    \ node();\n      u=u->ch[b];\n      u->count+=a;\n    }\n  }\n  S min_element(S\
    \ xor_val=0)const{return kth_element(0,xor_val);}\n  S max_element(S xor_val=0)const{return\
    \ kth_element(size()-1,xor_val);}\n  S kth_element(int k,S xor_val=0)const{\n\
    \    xor_val^=xor_all;\n    node*u=root;\n    S ret=0;\n    for(int i=B-1;i>=0;i--){\n\
    \      bool f=(xor_val>>i)&1;\n      node*u0=(f?u->ch[1]:u->ch[0]);\n      node*u1=(f?u->ch[0]:u->ch[1]);\n\
    \      if(u0==nullptr||u0->count<=k){\n        if(u0!=nullptr)k-=u0->count;\n\
    \        u=u1;\n        ret|=(S(1)<<i);\n      }\n      else u=u0;\n    }\n  \
    \  return ret;\n  }\n  int order(S k,S xor_val=0)const{\n    xor_val^=xor_all;\n\
    \    node*u=root;\n    int order=0;\n    for(int i=B-1;i>=0;i--){\n      bool\
    \ b=(k>>i)&1;\n      bool f=(xor_val>>i)&1;\n      node*u0=(f?u->ch[1]:u->ch[0]);\n\
    \      node*u1=(f?u->ch[0]:u->ch[1]);\n      if(b){\n        if(u0!=nullptr)order+=u0->count;\n\
    \        u=u1;\n      }\n      else u=u0;\n      if(u==nullptr)break;\n    }\n\
    \    return order;\n  }\n  S lower_bound(S k,S xor_val=0)const{\n    return kth_element(order(k,xor_val));\n\
    \  }\n  S upper_bound(S k,S xor_val=0)const{\n    return kth_element(order(k+1,xor_val));\n\
    \  }\n  void all_xor(S x){xor_all^=x;}\n  int count(S x)const{\n    node*tmp=find(x);\n\
    \    return (tmp==nullptr?0:tmp->count);\n  }\n  int size()const{return root->count;}\n\
    };\n*/\n/**\n * @brief Binary Trie\n*/"
  dependsOn: []
  isVerificationFile: false
  path: ds/others/binary-trie.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/others/binary-trie.hpp
layout: document
redirect_from:
- /library/ds/others/binary-trie.hpp
- /library/ds/others/binary-trie.hpp.html
title: Binary Trie
---
