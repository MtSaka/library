---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Fast Fourier Transform(\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\
      \u63DB)"
    links: []
  bundledCode: "#line 1 \"math/convolution/fft.hpp\"\nvoid dft(vector<complex<double>>&a,double\
    \ inv){\n  const int sz=a.size();\n  if(sz==1)return;\n  const int mask=sz-1;\n\
    \  vector<complex<double>>b(sz);\n  for(int i=sz>>1;i>=1;i>>=1){\n    complex<double>z=polar(1.0,2*M_PI*i*inv/sz),w=1;\n\
    \    for(int j=0;j<sz;j+=i){\n      for(int k=0;k<i;k++)b[j+k]=a[((j<<1)&mask)+k]+w*a[(((j<<1)+i)&mask)+k];\n\
    \      w*=z;\n    }\n    swap(a,b);\n  }\n}\ntemplate<typename T>\nvector<double>multiply(const\
    \ vector<T>&a,const vector<T>&b){\n  int sz=1;\n  while(sz<(int)a.size()+b.size()-1)sz<<=1;\n\
    \  vector<complex<double>>ma(sz),mb(sz);\n  for(int i=0;i<(int)a.size();i++)ma[i]=a[i];\n\
    \  for(int i=0;i<(int)b.size();i++)mb[i]=b[i];\n  dft(ma,1);dft(mb,1);\n  for(int\
    \ i=0;i<sz;i++)ma[i]*=mb[i];\n  dft(ma,-1);\n  vector<double>res(a.size()+b.size()-1);\n\
    \  for(int i=0;i<(int)res.size();i++)res[i]=(ma[i].real())/(double)sz;\n  return\
    \ res;\n}\n/**\n * @brief Fast Fourier Transform(\u9AD8\u901F\u30D5\u30FC\u30EA\
    \u30A8\u5909\u63DB)\n*/\n"
  code: "void dft(vector<complex<double>>&a,double inv){\n  const int sz=a.size();\n\
    \  if(sz==1)return;\n  const int mask=sz-1;\n  vector<complex<double>>b(sz);\n\
    \  for(int i=sz>>1;i>=1;i>>=1){\n    complex<double>z=polar(1.0,2*M_PI*i*inv/sz),w=1;\n\
    \    for(int j=0;j<sz;j+=i){\n      for(int k=0;k<i;k++)b[j+k]=a[((j<<1)&mask)+k]+w*a[(((j<<1)+i)&mask)+k];\n\
    \      w*=z;\n    }\n    swap(a,b);\n  }\n}\ntemplate<typename T>\nvector<double>multiply(const\
    \ vector<T>&a,const vector<T>&b){\n  int sz=1;\n  while(sz<(int)a.size()+b.size()-1)sz<<=1;\n\
    \  vector<complex<double>>ma(sz),mb(sz);\n  for(int i=0;i<(int)a.size();i++)ma[i]=a[i];\n\
    \  for(int i=0;i<(int)b.size();i++)mb[i]=b[i];\n  dft(ma,1);dft(mb,1);\n  for(int\
    \ i=0;i<sz;i++)ma[i]*=mb[i];\n  dft(ma,-1);\n  vector<double>res(a.size()+b.size()-1);\n\
    \  for(int i=0;i<(int)res.size();i++)res[i]=(ma[i].real())/(double)sz;\n  return\
    \ res;\n}\n/**\n * @brief Fast Fourier Transform(\u9AD8\u901F\u30D5\u30FC\u30EA\
    \u30A8\u5909\u63DB)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: math/convolution/fft.hpp
  requiredBy: []
  timestamp: '2022-12-18 22:43:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/convolution/fft.hpp
layout: document
redirect_from:
- /library/math/convolution/fft.hpp
- /library/math/convolution/fft.hpp.html
title: "Fast Fourier Transform(\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB)"
---
