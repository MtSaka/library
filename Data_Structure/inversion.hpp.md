---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Data_Structure/BIT.hpp
    title: Binary Indexed Tree(BIT)
  - icon: ':heavy_check_mark:'
    path: Others/compressor.hpp
    title: Others/compressor.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1/ALDS1_5_D.test.cpp
    title: test/aoj/ALDS1/ALDS1_5_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Inversion Number(\u8EE2\u5012\u6570)"
    links: []
  bundledCode: "#line 2 \"Data_Structure/BIT.hpp\"\ntemplate<typename T>\nstruct BIT{\n\
    \  private:\n  int N;\n  vector<T>bit;\n  public:\n  BIT(int n){\n    N=1;\n \
    \   while(N<n)N<<=1;\n    bit=vector<T>(N+1,0);\n  }\n  void add(int i,T x){\n\
    \    i++;\n    while(i<=N){\n      bit[i]+=x;\n      i+=i&-i;    \n    }\n  }\n\
    \  T sum(int i){\n    T ans=0;\n    while(i>0)ans+=bit[i],i-=i&-i;\n    return\
    \ ans;\n  }\n  T query(int l,int r){\n    return sum(r)-sum(l);\n  }\n};\n/**\n\
    \ * @brief Binary Indexed Tree(BIT)\n*/\n#line 2 \"Others/compressor.hpp\"\ntemplate<class\
    \ T,class comp=less<T>>\nclass compressor{\n  private:\n  vector<T>data;\n  comp\
    \ cmp;\n  bool sorted=false;\n  public:\n  compressor():compressor(comp()){}\n\
    \  compressor(const comp&cmp):cmp(cmp){}\n  compressor(const vector<T>&dat,const\
    \ comp&cmp=comp()):data(dat),cmp(cmp){}\n  compressor(vector<T>&&dat,const comp&cmp=comp()):data(move(dat)),cmp(cmp){}\n\
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
    \  }\n};\n#line 4 \"Data_Structure/inversion.hpp\"\ntemplate<typename T>\nlong\
    \ long inversion(vector<T>a){\n  int n=a.size();\n  compressor<T>c(a);\n  c.build();\n\
    \  a=c.pressed(a);\n  long long ans=0;\n  BIT<int>bit(c.size());\n  for(int i=0;i<n;i++){\n\
    \    ans+=i-bit.sum(a[i]+1);\n    bit.add(a[i],1);\n  }\n  return ans;\n}\n/**\n\
    \ * @brief Inversion Number(\u8EE2\u5012\u6570)\n*/\n"
  code: "#pragma once\n#include\"BIT.hpp\"\n#include\"../Others/compressor.hpp\"\n\
    template<typename T>\nlong long inversion(vector<T>a){\n  int n=a.size();\n  compressor<T>c(a);\n\
    \  c.build();\n  a=c.pressed(a);\n  long long ans=0;\n  BIT<int>bit(c.size());\n\
    \  for(int i=0;i<n;i++){\n    ans+=i-bit.sum(a[i]+1);\n    bit.add(a[i],1);\n\
    \  }\n  return ans;\n}\n/**\n * @brief Inversion Number(\u8EE2\u5012\u6570)\n\
    */"
  dependsOn:
  - Data_Structure/BIT.hpp
  - Others/compressor.hpp
  isVerificationFile: false
  path: Data_Structure/inversion.hpp
  requiredBy: []
  timestamp: '2022-07-01 22:17:42+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1/ALDS1_5_D.test.cpp
documentation_of: Data_Structure/inversion.hpp
layout: document
redirect_from:
- /library/Data_Structure/inversion.hpp
- /library/Data_Structure/inversion.hpp.html
title: "Inversion Number(\u8EE2\u5012\u6570)"
---
