---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Data_Structure/persistent_dsu.hpp
    title: "Persistent Disjoint Set Union(\u6C38\u7D9AUnion-Find)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_unionfind.test.cpp
    title: test/yosupo/persistent_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6C38\u7D9A\u914D\u5217(Persistent Array)"
    links: []
  bundledCode: "#line 2 \"Data_Structure/persistent_array.hpp\"\ntemplate<typename\
    \ T,int N=1>\nstruct persistent_array{\n  struct node{\n    T val;\n    node*ch[1<<N]={};\n\
    \  };\n  node*root=nullptr;\n  static constexpr int bit=(1<<N)-1;\n  persistent_array(){}\n\
    \  persistent_array(const vector<T>&a){\n    build(a);\n  }\n  void build(const\
    \ vector<T>&a){\n    for(int i=0;i<(int)a.size();i++){\n      destructive_set(i,a[i],root);\n\
    \    }\n  }\n  node*get_root(){return root;}\n  void destructive_set(int idx,T\
    \ val,node*&t){\n    if(!t)t=new node();\n    if(idx==0)t->val=val;\n    else\
    \ destructive_set(idx>>N,val,t->ch[idx&bit]);\n  }\n  node*set(int idx,T val,node*const&\
    \ t){\n    node*ret=new node();\n    if(t){\n      memcpy(ret->ch,t->ch,sizeof(t->ch));\n\
    \      ret->val=t->val;\n    }\n    if(idx==0){\n      ret->val=val;\n    }\n\
    \    else{\n      ret->ch[idx&bit]=set(idx>>N,val,ret->ch[idx&bit]);\n    }\n\
    \    return ret;\n  }\n  T get(int idx, node*t){\n    if(!t)return 0;\n    if(idx==0)return\
    \ t->val;\n    return get(idx>>N,t->ch[idx&bit]);\n  }\n};\n/**\n * @brief \u6C38\
    \u7D9A\u914D\u5217(Persistent Array)\n*/\n"
  code: "#pragma once\ntemplate<typename T,int N=1>\nstruct persistent_array{\n  struct\
    \ node{\n    T val;\n    node*ch[1<<N]={};\n  };\n  node*root=nullptr;\n  static\
    \ constexpr int bit=(1<<N)-1;\n  persistent_array(){}\n  persistent_array(const\
    \ vector<T>&a){\n    build(a);\n  }\n  void build(const vector<T>&a){\n    for(int\
    \ i=0;i<(int)a.size();i++){\n      destructive_set(i,a[i],root);\n    }\n  }\n\
    \  node*get_root(){return root;}\n  void destructive_set(int idx,T val,node*&t){\n\
    \    if(!t)t=new node();\n    if(idx==0)t->val=val;\n    else destructive_set(idx>>N,val,t->ch[idx&bit]);\n\
    \  }\n  node*set(int idx,T val,node*const& t){\n    node*ret=new node();\n   \
    \ if(t){\n      memcpy(ret->ch,t->ch,sizeof(t->ch));\n      ret->val=t->val;\n\
    \    }\n    if(idx==0){\n      ret->val=val;\n    }\n    else{\n      ret->ch[idx&bit]=set(idx>>N,val,ret->ch[idx&bit]);\n\
    \    }\n    return ret;\n  }\n  T get(int idx, node*t){\n    if(!t)return 0;\n\
    \    if(idx==0)return t->val;\n    return get(idx>>N,t->ch[idx&bit]);\n  }\n};\n\
    /**\n * @brief \u6C38\u7D9A\u914D\u5217(Persistent Array)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/persistent_array.hpp
  requiredBy:
  - Data_Structure/persistent_dsu.hpp
  timestamp: '2022-08-23 09:51:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/persistent_unionfind.test.cpp
documentation_of: Data_Structure/persistent_array.hpp
layout: document
redirect_from:
- /library/Data_Structure/persistent_array.hpp
- /library/Data_Structure/persistent_array.hpp.html
title: "\u6C38\u7D9A\u914D\u5217(Persistent Array)"
---
