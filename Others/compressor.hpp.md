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
  bundledCode: "#line 2 \"Others/compressor.hpp\"\ntemplate<class T,class comp=less<T>>\n\
    class compressor{\n  private:\n  vector<T>data;\n  comp cmp;\n  bool sorted=false;\n\
    \  public:\n  compressor():compressor(comp()){}\n  compressor(const comp&cmp):cmp(cmp){}\n\
    \  compressor(const vector<T>&dat,const comp&cmp=comp()):data(dat),cmp(cmp){}\n\
    \  compressor(vector<T>&&dat,const comp&cmp=comp()):data(move(dat)),cmp(cmp){}\n\
    \  compressor(initializer_list<T>li,const comp&cmp=comp()):data(li.begin(),li.end()),cmp(cmp){}\n\
    \  void push_back(const T&v){assert(!sorted);data.push_back(v);}\n  void push_back(T&&v){assert(!sorted);data.push_back(move(v));}\n\
    \  void push(const vector<T>&v){\n    assert(!sorted);\n    const int n=data.size();\n\
    \    data.resize(v.size()+n);\n    for(int i=0;i<(int)v.size();i++)data[i+n]=v[i];\n\
    \  }\n  void build(){\n    assert(!sorted);sorted=1;\n    sort(data.begin(),data.end(),cmp);\n\
    \    data.erase(unique(data.begin(),data.end(),[&](const T&l,const T&r)->bool{return\
    \ !cmp(l,r)&&!cmp(r,l);}),data.end());\n  }\n  const T&operator[](int k)const&{\n\
    \    assert(sorted);\n    return data[k];\n  }\n  int get_index(const T&v)const{\n\
    \    assert(sorted);\n    return int(lower_bound(data.begin(),data.end(),v,cmp)-data.begin());\n\
    \  }\n  void press(vector<T>&v)const{\n    assert(sorted);\n    for(auto&&i:v)i=get_index(i);\n\
    \  }\n  vector<int>pressed(const vector<T>&v)const{\n    assert(sorted);\n   \
    \ vector<int>ret(v.size());\n    for(int i=0;i<(int)v.size();i++)ret[i]=get_index(v[i]);\n\
    \    return ret;\n  }\n  int size()const{\n    assert(sorted);\n    return data.size();\n\
    \  }\n};\n"
  code: "#pragma once\ntemplate<class T,class comp=less<T>>\nclass compressor{\n \
    \ private:\n  vector<T>data;\n  comp cmp;\n  bool sorted=false;\n  public:\n \
    \ compressor():compressor(comp()){}\n  compressor(const comp&cmp):cmp(cmp){}\n\
    \  compressor(const vector<T>&dat,const comp&cmp=comp()):data(dat),cmp(cmp){}\n\
    \  compressor(vector<T>&&dat,const comp&cmp=comp()):data(move(dat)),cmp(cmp){}\n\
    \  compressor(initializer_list<T>li,const comp&cmp=comp()):data(li.begin(),li.end()),cmp(cmp){}\n\
    \  void push_back(const T&v){assert(!sorted);data.push_back(v);}\n  void push_back(T&&v){assert(!sorted);data.push_back(move(v));}\n\
    \  void push(const vector<T>&v){\n    assert(!sorted);\n    const int n=data.size();\n\
    \    data.resize(v.size()+n);\n    for(int i=0;i<(int)v.size();i++)data[i+n]=v[i];\n\
    \  }\n  void build(){\n    assert(!sorted);sorted=1;\n    sort(data.begin(),data.end(),cmp);\n\
    \    data.erase(unique(data.begin(),data.end(),[&](const T&l,const T&r)->bool{return\
    \ !cmp(l,r)&&!cmp(r,l);}),data.end());\n  }\n  const T&operator[](int k)const&{\n\
    \    assert(sorted);\n    return data[k];\n  }\n  int get_index(const T&v)const{\n\
    \    assert(sorted);\n    return int(lower_bound(data.begin(),data.end(),v,cmp)-data.begin());\n\
    \  }\n  void press(vector<T>&v)const{\n    assert(sorted);\n    for(auto&&i:v)i=get_index(i);\n\
    \  }\n  vector<int>pressed(const vector<T>&v)const{\n    assert(sorted);\n   \
    \ vector<int>ret(v.size());\n    for(int i=0;i<(int)v.size();i++)ret[i]=get_index(v[i]);\n\
    \    return ret;\n  }\n  int size()const{\n    assert(sorted);\n    return data.size();\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Others/compressor.hpp
  requiredBy: []
  timestamp: '2022-07-01 16:11:37+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Others/compressor.hpp
layout: document
redirect_from:
- /library/Others/compressor.hpp
- /library/Others/compressor.hpp.html
title: Others/compressor.hpp
---
