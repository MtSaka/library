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
  bundledCode: "#line 1 \"Math/fft.cpp\"\nstruct FFT{\n  void dft(vector<complex<double>>&a,double\
    \ inv){\n    int sz=a.size();\n    if(sz==1)return;\n    int mask=sz-1;\n    vector<complex<double>>b(sz);\n\
    \    for(int i=sz>>1;i>=1;i>>=1){\n      complex<double>z=polar(1.0,2*pi*i*inv/sz),w=1;\n\
    \      for(int j=0;j<sz;j+=i){\n        for(int k=0;k<i;k++)b[j+k]=a[((j<<1)&mask)+k]+w*a[(((j<<1)+i)&mask)+k];\n\
    \        w*=z;\n      }\n      swap(a,b);\n    }\n  }\n  template<typename T>\n\
    \  vector<double>multiply(vector<T>a,vector<T>b){\n    int sz=1;\n    while(sz<a.size()+b.size()-1)sz<<=1;\n\
    \    vector<complex<double>>ma(sz),mb(sz);\n    for(int i=0;i<a.size();i++)ma[i]=a[i];\n\
    \    for(int i=0;i<b.size();i++)mb[i]=b[i];\n    dft(ma,1);\n    dft(mb,1);\n\
    \    for(int i=0;i<sz;i++)ma[i]*=mb[i];\n    dft(ma,-1);\n    vector<double>res(a.size()+b.size()-1);\n\
    \    for(int i=0;i<res.size();i++)res[i]=(ma[i].real())/(double)sz;\n    return\
    \ res;\n  }\n};\n"
  code: "struct FFT{\n  void dft(vector<complex<double>>&a,double inv){\n    int sz=a.size();\n\
    \    if(sz==1)return;\n    int mask=sz-1;\n    vector<complex<double>>b(sz);\n\
    \    for(int i=sz>>1;i>=1;i>>=1){\n      complex<double>z=polar(1.0,2*pi*i*inv/sz),w=1;\n\
    \      for(int j=0;j<sz;j+=i){\n        for(int k=0;k<i;k++)b[j+k]=a[((j<<1)&mask)+k]+w*a[(((j<<1)+i)&mask)+k];\n\
    \        w*=z;\n      }\n      swap(a,b);\n    }\n  }\n  template<typename T>\n\
    \  vector<double>multiply(vector<T>a,vector<T>b){\n    int sz=1;\n    while(sz<a.size()+b.size()-1)sz<<=1;\n\
    \    vector<complex<double>>ma(sz),mb(sz);\n    for(int i=0;i<a.size();i++)ma[i]=a[i];\n\
    \    for(int i=0;i<b.size();i++)mb[i]=b[i];\n    dft(ma,1);\n    dft(mb,1);\n\
    \    for(int i=0;i<sz;i++)ma[i]*=mb[i];\n    dft(ma,-1);\n    vector<double>res(a.size()+b.size()-1);\n\
    \    for(int i=0;i<res.size();i++)res[i]=(ma[i].real())/(double)sz;\n    return\
    \ res;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/fft.cpp
  requiredBy: []
  timestamp: '2021-11-17 20:52:48+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/fft.cpp
layout: document
redirect_from:
- /library/Math/fft.cpp
- /library/Math/fft.cpp.html
title: Math/fft.cpp
---
