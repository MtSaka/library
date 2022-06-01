---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Data_Structure/presistent_array.hpp\"\ntemplate<typename\
    \ T>\nstruct persistent_array{\n  struct node{\n    T val;\n    node*ch[20]={};\n\
    \  };\n  node*root=nullptr;\n  persistent_array(){}\n  presistent_array(vector<t>&a){\n\
    \    for(int i=0;i<(int)a.size();i++){\n      root=set(i,a[i],root);\n    }\n\
    \  }\n  node*get_root(){return root;}\n  node*set(int idx,const T&val,node*&t){\n\
    \    node*ret=new node();\n    if(t){\n      memcpy(ret->ch,t->ch,sizeof(t->ch));\n\
    \      res->data=t->data;\n    }\n    if(idx==0){\n      ret->data=val;\n    }\n\
    \    else{\n      ret->ch[idx%20]=set(idx/20,val,ret->ch[idx%20]);\n    }\n  \
    \  return ret;\n  }\n  T get(int idx,node*t){\n    if(!t)return 0;\n    if(idx==0)return\
    \ t->data;\n    return get(idx/20,t->ch[idx%20]);\n  }\n};\n/**\n * @breif \u6C38\
    \u7D9A\u914D\u5217(Persistent Array)\n*/\n"
  code: "#pragma once\ntemplate<typename T>\nstruct persistent_array{\n  struct node{\n\
    \    T val;\n    node*ch[20]={};\n  };\n  node*root=nullptr;\n  persistent_array(){}\n\
    \  presistent_array(vector<t>&a){\n    for(int i=0;i<(int)a.size();i++){\n   \
    \   root=set(i,a[i],root);\n    }\n  }\n  node*get_root(){return root;}\n  node*set(int\
    \ idx,const T&val,node*&t){\n    node*ret=new node();\n    if(t){\n      memcpy(ret->ch,t->ch,sizeof(t->ch));\n\
    \      res->data=t->data;\n    }\n    if(idx==0){\n      ret->data=val;\n    }\n\
    \    else{\n      ret->ch[idx%20]=set(idx/20,val,ret->ch[idx%20]);\n    }\n  \
    \  return ret;\n  }\n  T get(int idx,node*t){\n    if(!t)return 0;\n    if(idx==0)return\
    \ t->data;\n    return get(idx/20,t->ch[idx%20]);\n  }\n};\n/**\n * @breif \u6C38\
    \u7D9A\u914D\u5217(Persistent Array)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/presistent_array.hpp
  requiredBy: []
  timestamp: '2022-06-01 21:36:07+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structure/presistent_array.hpp
layout: document
redirect_from:
- /library/Data_Structure/presistent_array.hpp
- /library/Data_Structure/presistent_array.hpp.html
title: Data_Structure/presistent_array.hpp
---
