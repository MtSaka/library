---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Formal Power Series(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: fast-prime.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include\"../../template/template.hpp\"\n#include\"../convolution/ntt.hpp\"\
    \n\ntemplate<int m>\nstruct FormalPowerSeries:vector<ModInt<m>>{\n  using mint=ModInt<m>;\n\
    \  using vector<mint>::vector;\n  using vector<mint>::operator=;\n  void shrink(){while(!(*this).empty()&&(*this).back()==mint())(*this).pop_back();}\n\
    \  FormalPowerSeries inv(int d=-1)const{\n    NTT<m>ntt;\n    const int n=(*this).size();\n\
    \    if(d==-1)d=n;\n    FormalPowerSeries res{(*this)[0].inv()};\n    for(int\
    \ sz=1;sz<d;sz<<=1){\n      FormalPowerSeries f((*this).begin(),(*this).begin()+min(n,2*sz));\n\
    \      FormalPowerSeries g(res);\n      f.resize(2*sz),g.resize(2*sz);\n     \
    \ ntt.dft(f,1),ntt.dft(g,1);\n      for(int i=0;i<2*sz;i++)f[i]*=g[i];\n     \
    \ ntt.dft(f,-1);\n      f.erase(f.begin(),f.begin()+sz);\n      f.resize(2*sz);ntt.dft(f,1);\n\
    \      for(int i=0;i<2*sz;i++)f[i]*=g[i];\n      ntt.dft(f,-1);\n      mint iz=mint(2*sz).inv();iz*=-iz;\n\
    \      for(int i=0;i<sz;i++)f[i]*=iz;\n      res.insert(res.end(),f.begin(),f.begin()+sz);\n\
    \    }\n    res.resize(d);\n    return res;\n  }\n  FormalPowerSeries operator+(const\
    \ mint&r)const{return FormalPowerSeries(*this)+=r;}\n  FormalPowerSeries operator-(const\
    \ mint&r)const{return FormalPowerSeries(*this)-=r;}\n  FormalPowerSeries operator*(const\
    \ mint&r)const{return FormalPowerSeries(*this)*=r;}\n  FormalPowerSeries operator/(const\
    \ mint&r)const{return FormalPowerSeries(*this)/=r;}\n  FormalPowerSeries operator+(const\
    \ FormalPowerSeries&r)const{return FormalPowerSeries(*this)+=r;}\n  FormalPowerSeries\
    \ operator-(const FormalPowerSeries&r)const{return FormalPowerSeries(*this)-=r;}\n\
    \  FormalPowerSeries operator<<(const int&d)const{return FormalPowerSeries(*this)<<=d;}\n\
    \  FormalPowerSeries operator>>(const int&d)const{return FormalPowerSeries(*this)>>=d;}\n\
    \  FormalPowerSeries operator*(const FormalPowerSeries&r)const{return FormalPowerSeries(*this)*=r;}\n\
    \  FormalPowerSeries operator/(const FormalPowerSeries&r)const{return FormalPowerSeries(*this)/=r;}\n\
    \  FormalPowerSeries operator%(const FormalPowerSeries&r)const{return FormalPowerSeries(*this)%=r;}\n\
    \  FormalPowerSeries operator-()const{\n    FormalPowerSeries ret(*this);\n  \
    \  for(auto &i:ret)i=-i;\n    return ret;\n  }\n  FormalPowerSeries &operator+=(const\
    \ mint&r){\n    if((*this).empty())(*this).resize(1);\n    (*this)[0]+=r;\n  \
    \  return *this;\n  }\n  FormalPowerSeries &operator-=(const mint&r){\n    if((*this).empty())(*this).resize(1);\n\
    \    (*this)[0]-=r;\n    return *this;\n  }\n  FormalPowerSeries &operator*=(const\
    \ mint&r){\n    for(auto &i:*this)i*=r;\n    return *this;\n  }\n  FormalPowerSeries\
    \ &operator/=(const mint&r){\n    (*this)*=r.inv();\n    return *this;\n  }\n\
    \  FormalPowerSeries &operator+=(const FormalPowerSeries&r){\n    const int n=(*this).size(),sz=r.size();\n\
    \    (*this).resize(max(n,sz));\n    for(int i=0;i<sz;i++)(*this)[i]+=r[i];\n\
    \    return *this;\n  }\n  FormalPowerSeries &operator-=(const FormalPowerSeries&r){\n\
    \    const int n=(*this).size(),sz=r.size();\n    (*this).resize(max(n,sz));\n\
    \    for(int i=0;i<sz;i++)(*this)[i]-=r[i];\n    return *this;\n  }\n  FormalPowerSeries\
    \ &operator<<=(const long long&d){\n    (*this).insert((*this).begin(),d,mint(0));\n\
    \    return *this;\n  }\n  FormalPowerSeries &operator>>=(const long long&d){\n\
    \    (*this).erase((*this).begin(),(*this).begin()+d);\n    return *this;\n  }\n\
    \  FormalPowerSeries &operator*=(const FormalPowerSeries&r){\n    (*this)=NTT<m>::multiply((*this),r);\n\
    \    return *this;\n  }\n  FormalPowerSeries &operator/=(FormalPowerSeries r){\n\
    \    const int n=(*this).size(),n1=r.size();\n    if(n<n1){\n      (*this).clear();\n\
    \      return *this;\n    }\n    const int sz=n-n1+1;\n    reverse((*this).begin(),(*this).end());\n\
    \    reverse(r.begin(),r.end());\n    (*this).resize(sz);\n    (*this)*=r.inv(sz);\n\
    \    (*this).resize(sz);\n    reverse((*this).begin(),(*this).end());\n    return\
    \ (*this);\n  }\n  FormalPowerSeries &operator%=(const FormalPowerSeries&r){\n\
    \    const int n=(*this).size(),sz=r.size();\n    if(n<sz)return (*this);\n  \
    \  (*this)-=(*this)/r*r;\n    (*this).resize(sz-1);\n    shrink();\n    return\
    \ (*this);\n  }\n  pair<FormalPowerSeries,FormalPowerSeries>div_mod(const FormalPowerSeries&r){\n\
    \    FormalPowerSeries p=*this/r,q=*this-p*r;\n    q.shrink();\n    return {p,q};\n\
    \  }\n  mint operator()(const mint&x)const{\n    mint ret(0),w(1);\n    for(auto\
    \ &e:*this){\n      ret+=e*w;\n      w*=x;\n    }\n    return ret;\n  }\n  FormalPowerSeries\
    \ diff()const{\n    const int n=(*this).size();\n    FormalPowerSeries ret(max(0,n-1));\n\
    \    for(int i=1;i<n;i++)ret[i-1]=(*this)[i]*mint(i);\n    return ret;\n  }\n\
    \  FormalPowerSeries integral()const{\n    const int n=(*this).size();\n    vector<mint>inv(n+1);\n\
    \    inv[1]=mint(1);\n    for(int i=2;i<=n;i++)inv[i]=-inv[m%i]*mint(m/i);\n \
    \   FormalPowerSeries ret(n+1);\n    for(int i=0;i<n;i++)ret[i+1]=(*this)[i]*inv[i+1];\n\
    \    return ret;\n  }\n  FormalPowerSeries log(int d=-1)const{\n    const int\
    \ n=(*this).size();\n    if(d==-1)d=n;\n    FormalPowerSeries res=diff()*inv(d);\n\
    \    res.resize(d-1);\n    return res.integral();\n  }\n  FormalPowerSeries exp(int\
    \ d=-1)const{\n    const int n=(*this).size();\n    if(d==-1)d=n;\n    FormalPowerSeries\
    \ f={mint(1)+(*this)[0],(*this)[1]},res{1,1<n?(*this)[1]:0};\n    for(int sz=2;sz<d;sz<<=1){\n\
    \      f.insert(f.end(),(*this).begin()+min(sz,n),(*this).begin()+min(n,2*sz));\n\
    \      if((int)f.size()<2*sz)f.resize(2*sz);\n      res=res*(f-res.log(2*sz));\n\
    \      res.resize(2*sz);\n    }\n    res.resize(d);\n    return res;\n  }\n  FormalPowerSeries\
    \ pow(long long k,int d=-1)const{\n    const int n=(*this).size();\n    if(d==-1)d=n;\n\
    \    if(k==0){\n      FormalPowerSeries ans(d,mint(0));\n      ans[0]=1;\n   \
    \   return ans;\n    }\n    for(int i=0;i<n;i++){\n      if((*this)[i]!=mint()){\n\
    \        if(i>d/k)return FormalPowerSeries(d,mint(0));\n        mint rev=(*this)[i].inv();\n\
    \        FormalPowerSeries ret=(((*this*rev)>>i).log(d)*k).exp(d)*((*this)[i].pow(k));\n\
    \        ret=(ret<<(i*k));\n        ret.resize(d);\n        return ret;\n    \
    \  }\n    }\n    return FormalPowerSeries(d,mint(0));\n  }\n  FormalPowerSeries\
    \ sqrt(int d=-1,const function<mint(mint)>&get_sqrt=[](mint){return mint(1);})const{\n\
    \    const int n=(*this).size();\n    if(d==-1)d=n;\n    if((*this)[0]==mint(0)){\n\
    \      for(int i=1;i<n;i++){\n        if((*this)[i]!=mint(0)){\n          if(i&1)return\
    \ {};\n          if(d-i/2<=0)break;\n          auto ret=(*this>>i).sqrt(d-i/2,get_sqrt);\n\
    \          if(ret.empty())return {};\n          ret=ret<<(i/2);\n          if((int)ret.size()<d)ret.resize(d);\n\
    \          return ret;\n        }\n      }\n      return FormalPowerSeries(d);\n\
    \    }\n    auto sqr=get_sqrt((*this)[0]);\n    if(sqr*sqr!=(*this)[0])return\
    \ {};\n    FormalPowerSeries ret{sqr};\n    mint inv2=mint(2).inv();\n    FormalPowerSeries\
    \ f={(*this)[0]};\n    for(int i=1;i<d;i<<=1){\n      if(i<n)f.insert(f.end(),(*this).begin()+i,(*this).begin()+min(n,i<<1));\n\
    \      if((int)f.size()<(i<<1))f.resize(i<<1);\n      ret=(ret+f*ret.inv(i<<1))*inv2;\n\
    \    }\n    ret.resize(d);\n    return ret;\n  }\n};\n/**\n * @brief Formal Power\
    \ Series(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: math/fps/fps.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fps/fps.hpp
layout: document
redirect_from:
- /library/math/fps/fps.hpp
- /library/math/fps/fps.hpp.html
title: "Formal Power Series(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)"
---
