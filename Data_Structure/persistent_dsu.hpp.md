---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_Structure/persistent_array.hpp
    title: Data_Structure/persistent_array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_unionfind.test.cpp
    title: test/yosupo/persistent_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Persistent Disjoint Set Union(\u6C38\u7D9AUnion-Find)"
    links: []
  bundledCode: "#line 2 \"Data_Structure/persistent_array.hpp\"\ntemplate<typename\
    \ T>\nstruct persistent_array{\n  struct node{\n    T val;\n    node*ch[16]={};\n\
    \  };\n  node*root=nullptr;\n  persistent_array(){}\n  persistent_array(const\
    \ vector<T>&a){\n    build(a);\n  }\n  void build(const vector<T>&a){\n    for(int\
    \ i=0;i<(int)a.size();i++){\n      destructive_set(i,a[i],root);\n    }\n  }\n\
    \  node*get_root(){return root;}\n  void destructive_set(int idx,T val,node*&t){\n\
    \    if(!t)t=new node();\n    if(idx==0)t->val=val;\n    else destructive_set(idx>>4,val,t->ch[idx&15]);\n\
    \  }\n  node*set(int idx,T val,node*const& t){\n    node*ret=new node();\n   \
    \ if(t){\n      memcpy(ret->ch,t->ch,sizeof(t->ch));\n      ret->val=t->val;\n\
    \    }\n    if(idx==0){\n      ret->val=val;\n    }\n    else{\n      ret->ch[idx&15]=set(idx>>4,val,ret->ch[idx&15]);\n\
    \    }\n    return ret;\n  }\n  T get(int idx, node*t){\n    if(!t)return 0;\n\
    \    if(idx==0)return t->val;\n    return get(idx>>4,t->ch[idx&15]);\n  }\n};\n\
    /**\n * @breif \u6C38\u7D9A\u914D\u5217(Persistent Array)\n*/\n#line 3 \"Data_Structure/persistent_dsu.hpp\"\
    \nstruct persistent_dsu{\n  private:\n  using pa=persistent_array<int>;\n  pa\
    \ p;\n  public:\n  using node=pa::node;\n  persistent_dsu(){}\n  persistent_dsu(int\
    \ n){\n    p.build(vector<int>(n,-1));\n  }\n  int root(int x,node*t){\n    if(p.get(x,t)<0)return\
    \ x;\n    return root(p.get(x,t),t);\n  }\n  bool same(int x,int y,node*t){\n\
    \    return root(x,t)==root(y,t);\n  }\n  int size(int x,node*t){\n    return\
    \ -p.get(root(x,t),t);\n  }\n  pair<int,node*>merge(int x,int y,node*t){\n   \
    \ x=root(x,t),y=root(y,t);\n    if(x==y)return {x,t};\n    if(p.get(x,t)>p.get(y,t))swap(x,y);\n\
    \    node*ret=p.set(y,x,p.set(x,p.get(x,t)+p.get(y,t),t));\n    return {x,ret};\n\
    \  }\n  node*get_root(){return p.get_root();}\n};\n/**\n * @brief Persistent Disjoint\
    \ Set Union(\u6C38\u7D9AUnion-Find)\n*/\n"
  code: "#pragma once\n#include\"persistent_array.hpp\"\nstruct persistent_dsu{\n\
    \  private:\n  using pa=persistent_array<int>;\n  pa p;\n  public:\n  using node=pa::node;\n\
    \  persistent_dsu(){}\n  persistent_dsu(int n){\n    p.build(vector<int>(n,-1));\n\
    \  }\n  int root(int x,node*t){\n    if(p.get(x,t)<0)return x;\n    return root(p.get(x,t),t);\n\
    \  }\n  bool same(int x,int y,node*t){\n    return root(x,t)==root(y,t);\n  }\n\
    \  int size(int x,node*t){\n    return -p.get(root(x,t),t);\n  }\n  pair<int,node*>merge(int\
    \ x,int y,node*t){\n    x=root(x,t),y=root(y,t);\n    if(x==y)return {x,t};\n\
    \    if(p.get(x,t)>p.get(y,t))swap(x,y);\n    node*ret=p.set(y,x,p.set(x,p.get(x,t)+p.get(y,t),t));\n\
    \    return {x,ret};\n  }\n  node*get_root(){return p.get_root();}\n};\n/**\n\
    \ * @brief Persistent Disjoint Set Union(\u6C38\u7D9AUnion-Find)\n*/"
  dependsOn:
  - Data_Structure/persistent_array.hpp
  isVerificationFile: false
  path: Data_Structure/persistent_dsu.hpp
  requiredBy: []
  timestamp: '2022-06-02 15:39:38+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/persistent_unionfind.test.cpp
documentation_of: Data_Structure/persistent_dsu.hpp
layout: document
redirect_from:
- /library/Data_Structure/persistent_dsu.hpp
- /library/Data_Structure/persistent_dsu.hpp.html
title: "Persistent Disjoint Set Union(\u6C38\u7D9AUnion-Find)"
---