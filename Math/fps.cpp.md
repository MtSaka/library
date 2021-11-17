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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../code/library/Math/ntt.cpp:\
    \ line -1: no such header\n"
  code: "#include<bits/stdc++.h>\n#include\"../../code/library/Math/ntt.cpp\"\nusing\
    \ namespace std;\ntemplate<long long m>\nstruct FPS{\n  using mint=modint<m>;\n\
    \  vector<mint>val;\n  NTT<m>ntt;\n  FPS(){}\n  FPS(int sz):val(sz){}\n  FPS(const\
    \ vector<mint>&a):val(a){}\n  FPS(vector<mint>&&a):val(move(a)){}\n  FPS(const\
    \ FPS &other):val(other.val){}\n  FPS(FPS &&other):val(move(other.val)){}\n  mint\
    \ &operator[](int i){return val[i];}\n  size_t size()const{return val.size();}\n\
    \  void resize(const int sz){val.resize(sz);}\n  void shrink(){while(!val.empty()&&val.back()==mint(0))val.pop_back();}\n\
    \  FPS &operator=(const FPS &other){\n    val=other.val;\n    return *this;\n\
    \  }\n  FPS &operator=(FPS &&other){\n    val=move(other.val);\n    return *this;\n\
    \  }\n  FPS inv(int mx=-1)const{\n    if(mx==-1)mx=size();\n    FPS g(1);\n  \
    \  g[0]=val[0].inv();\n    int now=1;\n    while(now<mx){\n      now<<=1;\n  \
    \    FPS t=(*this);\n      t.resize(now);\n      t*=-g;\n      t[0]+=2,g*=t;\n\
    \      g.resize(now);\n    }\n    g.resize(mx);\n    return g;\n  }\n  FPS operator+(const\
    \ FPS&r)const{return FPS(*this)+=r;}\n  FPS operator-(const FPS&r)const{return\
    \ FPS(*this)-=r;}\n  FPS operator*(const FPS&r)const{return FPS(*this)*=r;}\n\
    \  FPS operator/(const FPS&r)const{return FPS(*this)/=r;}\n  FPS operator%(const\
    \ FPS&r)const{return FPS(*this)%=r;}\n  FPS operator-()const{\n    FPS ret(val);\n\
    \    for(int i=0;i<val.size();i++)ret[i]=-ret[i];\n    return ret;\n  }\n  FPS\
    \ operator+=(FPS r){\n    if(r.size()>val.size())val.resize(r.size());\n    for(int\
    \ i=0;i<r.size();i++)val[i]+=r[i];\n    return *this;\n  }\n  FPS operator-=(FPS\
    \ r){\n    if(r.size()>val.size())val.resize(r.size());\n    for(int i=0;i<r.size();i++)val[i]-=r[i];\n\
    \    return *this;\n  }\n  FPS operator*=(FPS r){\n    val=ntt.multiply(val,r.val);\n\
    \    return *this;\n  }\n  FPS operator/=(FPS r){\n    if(val.size()<r.size()){\n\
    \      val.clear();\n      return *this;\n    }\n    int sz=val.size()-r.size()+1;\n\
    \    reverse(val.begin(),val.end());\n    reverse(r.val.begin(),r.val.end());\n\
    \    val.resize(sz);\n    (*this)*=r.inv(sz);\n    val.resize(sz);\n    reverse(val.begin(),val.end());\n\
    \    return (*this);\n  }\n  FPS operator%=(FPS r){\n    if(val.size()<r.size())return\
    \ (*this);\n    (*this)-=(*this)/r*r;\n    val.resize(r.size()-1);\n    shrink();\n\
    \    return (*this);\n  }\n  FPS diff()const{\n    int n=size();\n    FPS ret(max(0,n-1));\n\
    \    for(int i=1;i<n;i++)ret[i-1]=val[i]*mint(i);\n    return ret;\n  }\n  FPS\
    \ integral()const{\n    int n=size();\n    FPS ret(n+1);\n    for(int i=0;i<n;i++)ret[i+1]=val[i]/mint(i+1);\n\
    \    return ret;\n  }\n  FPS log(int mx=-1)const{\n    if(mx==-1)mx=size();\n\
    \    FPS res=diff()*inv(mx);\n    res.resize(mx-1);\n    return res.integral();\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/fps.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/fps.cpp
layout: document
redirect_from:
- /library/Math/fps.cpp
- /library/Math/fps.cpp.html
title: Math/fps.cpp
---
