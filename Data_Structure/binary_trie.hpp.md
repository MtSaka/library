---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/set_xor_min.test.cpp
    title: test/yosupo/set_xor_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Binary Trie
    links: []
  bundledCode: "#line 2 \"Data_Structure/binary_trie.hpp\"\ntemplate<class S,int B=(sizeof(S)*8-1)>\n\
    struct binary_trie{\n  private:\n  struct node{\n    node*ch[2];\n    int count;\n\
    \    node():ch{nullptr,nullptr},count(0){}\n  };\n  node*root;\n  S xor_all=0;\n\
    \  node* find(S x,S xor_val=0)const{\n    xor_val^=xor_all;\n    node*u=root;\n\
    \    for(int i=B-1;i>=0;i--){\n      int b=(x>>i)&1;\n      if((xor_val>>i)&1)b^=1;\n\
    \      if(u->ch[b]==nullptr)return nullptr;\n      u=u->ch[b];\n    }\n    return\
    \ u;\n  }\n  public:\n  binary_trie():root(new node()){}\n  void insert(S x,S\
    \ xor_val=0){add(x,1,xor_val);}\n  void erase(S x,S xor_val=0){add(x,-1,xor_val);}\n\
    \  void add(S x,int a,S xor_val=0){\n    xor_val^=xor_all;\n    node*u=root;\n\
    \    u->count+=a;\n    for(int i=B-1;i>=0;i--){\n      int b=(x>>i)&1;\n     \
    \ if((xor_val>>i)&1)b^=1;\n      if(u->ch[b]==nullptr)u->ch[b]=new node();\n \
    \     u=u->ch[b];\n      u->count+=a;\n    }\n  }\n  S min_element(S xor_val=0)const{return\
    \ kth_element(0,xor_val);}\n  S max_element(S xor_val=0)const{return kth_element(size()-1,xor_val);}\n\
    \  S kth_element(int k,S xor_val=0)const{\n    xor_val^=xor_all;\n    node*u=root;\n\
    \    S ret=0;\n    for(int i=B-1;i>=0;i--){\n      bool f=(xor_val>>i)&1;\n  \
    \    node*u0=(f?u->ch[1]:u->ch[0]);\n      node*u1=(f?u->ch[0]:u->ch[1]);\n  \
    \    if(u0==nullptr||u0->count<=k){\n        if(u0!=nullptr)k-=u0->count;\n  \
    \      u=u1;\n        ret|=(S(1)<<i);\n      }\n      else u=u0;\n    }\n    return\
    \ ret;\n  }\n  int order(S k,S xor_val=0)const{\n    xor_val^=xor_all;\n    node*u=root;\n\
    \    int order=0;\n    for(int i=B-1;i>=0;i--){\n      bool b=(k>>i)&1;\n    \
    \  bool f=(xor_val>>i)&1;\n      node*u0=(f?u->ch[1]:u->ch[0]);\n      node*u1=(f?u->ch[0]:u->ch[1]);\n\
    \      if(b){\n        if(u0!=nullptr)order+=u0->count;\n        u=u1;\n     \
    \ }\n      else u=u0;\n      if(u==nullptr)break;\n    }\n    return order;\n\
    \  }\n  S lower_bound(S k,S xor_val=0)const{\n    return kth_element(order(k,xor_val));\n\
    \  }\n  S upper_bound(S k,S xor_val=0)const{\n    return kth_element(order(k+1,xor_val));\n\
    \  }\n  void all_xor(S x){xor_all^=x;}\n  int count(S x)const{\n    node*tmp=find(x);\n\
    \    return (tmp==nullptr?0:tmp->count);\n  }\n  int size()const{return root->count;}\n\
    };\n/**\n * @brief Binary Trie\n*/\n"
  code: "#pragma once\ntemplate<class S,int B=(sizeof(S)*8-1)>\nstruct binary_trie{\n\
    \  private:\n  struct node{\n    node*ch[2];\n    int count;\n    node():ch{nullptr,nullptr},count(0){}\n\
    \  };\n  node*root;\n  S xor_all=0;\n  node* find(S x,S xor_val=0)const{\n   \
    \ xor_val^=xor_all;\n    node*u=root;\n    for(int i=B-1;i>=0;i--){\n      int\
    \ b=(x>>i)&1;\n      if((xor_val>>i)&1)b^=1;\n      if(u->ch[b]==nullptr)return\
    \ nullptr;\n      u=u->ch[b];\n    }\n    return u;\n  }\n  public:\n  binary_trie():root(new\
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
    };\n/**\n * @brief Binary Trie\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/binary_trie.hpp
  requiredBy: []
  timestamp: '2022-07-05 16:12:29+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/set_xor_min.test.cpp
documentation_of: Data_Structure/binary_trie.hpp
layout: document
redirect_from:
- /library/Data_Structure/binary_trie.hpp
- /library/Data_Structure/binary_trie.hpp.html
title: Binary Trie
---
