---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/matrix_det.test.cpp
    title: test/yosupo/matrix_det.test.cpp
  - icon: ':x:'
    path: test/yosupo/matrix_product.test.cpp
    title: test/yosupo/matrix_product.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Matrix(\u884C\u5217)"
    links: []
  bundledCode: "#line 1 \"math/others/matrix.hpp\"\ntemplate<typename T>\nstruct Matrix{\n\
    \  private:\n  vector<vector<T>>A;\n  public:\n  Matrix(){}\n  Matrix(size_t n,size_t\
    \ m):A(n,vector<T>(m,0)){}\n  Matrix(size_t n):A(n,vector<T>(n,0)){};\n  Matrix(const\
    \ vector<vector<T>>&a):A(a){}\n  size_t height()const{return (A.size());}\n  size_t\
    \ width()const{return (A[0].size());}\n  inline const vector<T>&operator[](int\
    \ k)const{return A.at(k);}\n  inline vector<T>&operator[](int k){return A.at(k);}\n\
    \  static Matrix I(size_t n){\n    Matrix mat(n);\n    for(size_t i=0;i<n;i++)mat[i][i]=1;\n\
    \    return mat;\n  }\n  Matrix &operator+=(const Matrix&B){\n    const size_t\
    \ n=height(),m=width();\n    for(size_t i=0;i<n;i++)for(size_t j=0;j<m;j++)(*this)[i][j]+=B[i][j];\n\
    \    return *this;\n  }\n  Matrix &operator-=(const Matrix&B){\n    const size_t\
    \ n=height(),m=width();\n    for(size_t i=0;i<n;i++)for(size_t j=0;j<m;j++)(*this)[i][j]-=B[i][j];\n\
    \    return *this;\n  }\n  Matrix &operator*=(const Matrix&B) {\n    const size_t\
    \ n=height(),m=B.width(),p=width();\n    vector<vector<T>>C(n,vector<T>(m,0));\n\
    \    for(size_t i=0;i<n;i++)for(size_t j=0;j<m;j++)for(size_t k=0;k<p;k++)C[i][j]+=(*this)[i][k]*B[k][j];\n\
    \    A.swap(C);\n    return *this;\n  }\n  Matrix &operator^=(long long k){\n\
    \    Matrix B=Matrix::I(height());\n    while(k>0){\n      if(k&1)B*=*this;\n\
    \      *this*=*this;\n      k>>=1LL;\n    }\n    A.swap(B.A);\n    return *this;\n\
    \  }\n  Matrix pow(long long k)const{return Matrix(*this)^=k;}\n  friend Matrix\
    \ operator+(const Matrix&A,const Matrix&B){return Matrix(A)+=B;}\n  friend Matrix\
    \ operator-(const Matrix&A,const Matrix&B){return Matrix(A)-=B;}\n  friend Matrix\
    \ operator*(const Matrix&A,const Matrix&B){return Matrix(A)*=B;}\n  friend Matrix\
    \ operator^(const Matrix&A,const long long&k){return Matrix(A)^=k;}\n  T determinant()const{\n\
    \    Matrix b(*this);\n    T ret=1;\n    for(int i=0;i<(int)width();i++){\n  \
    \    int idx=-1;\n      for(int j=i;j<(int)width();j++)if(b[j][i]!=0){idx=j;break;}\n\
    \      if(idx==-1)return T(0);\n      if(i!=idx){\n        ret*=T(-1);\n     \
    \   swap(b[i],b[idx]);\n      }\n      ret*=b[i][i];\n      T tmp=b[i][i];\n \
    \     for(int j=0;j<(int)width();j++)b[i][j]/=tmp;\n      for(int j=i+1;j<(int)width();j++){\n\
    \        T now=b[j][i];\n        for(int k=0;k<(int)width();k++)b[j][k]-=b[i][k]*now;\n\
    \      }\n    }\n    return ret;\n  }\n};\n/**\n * @brief Matrix(\u884C\u5217\
    )\n*/\n"
  code: "template<typename T>\nstruct Matrix{\n  private:\n  vector<vector<T>>A;\n\
    \  public:\n  Matrix(){}\n  Matrix(size_t n,size_t m):A(n,vector<T>(m,0)){}\n\
    \  Matrix(size_t n):A(n,vector<T>(n,0)){};\n  Matrix(const vector<vector<T>>&a):A(a){}\n\
    \  size_t height()const{return (A.size());}\n  size_t width()const{return (A[0].size());}\n\
    \  inline const vector<T>&operator[](int k)const{return A.at(k);}\n  inline vector<T>&operator[](int\
    \ k){return A.at(k);}\n  static Matrix I(size_t n){\n    Matrix mat(n);\n    for(size_t\
    \ i=0;i<n;i++)mat[i][i]=1;\n    return mat;\n  }\n  Matrix &operator+=(const Matrix&B){\n\
    \    const size_t n=height(),m=width();\n    for(size_t i=0;i<n;i++)for(size_t\
    \ j=0;j<m;j++)(*this)[i][j]+=B[i][j];\n    return *this;\n  }\n  Matrix &operator-=(const\
    \ Matrix&B){\n    const size_t n=height(),m=width();\n    for(size_t i=0;i<n;i++)for(size_t\
    \ j=0;j<m;j++)(*this)[i][j]-=B[i][j];\n    return *this;\n  }\n  Matrix &operator*=(const\
    \ Matrix&B) {\n    const size_t n=height(),m=B.width(),p=width();\n    vector<vector<T>>C(n,vector<T>(m,0));\n\
    \    for(size_t i=0;i<n;i++)for(size_t j=0;j<m;j++)for(size_t k=0;k<p;k++)C[i][j]+=(*this)[i][k]*B[k][j];\n\
    \    A.swap(C);\n    return *this;\n  }\n  Matrix &operator^=(long long k){\n\
    \    Matrix B=Matrix::I(height());\n    while(k>0){\n      if(k&1)B*=*this;\n\
    \      *this*=*this;\n      k>>=1LL;\n    }\n    A.swap(B.A);\n    return *this;\n\
    \  }\n  Matrix pow(long long k)const{return Matrix(*this)^=k;}\n  friend Matrix\
    \ operator+(const Matrix&A,const Matrix&B){return Matrix(A)+=B;}\n  friend Matrix\
    \ operator-(const Matrix&A,const Matrix&B){return Matrix(A)-=B;}\n  friend Matrix\
    \ operator*(const Matrix&A,const Matrix&B){return Matrix(A)*=B;}\n  friend Matrix\
    \ operator^(const Matrix&A,const long long&k){return Matrix(A)^=k;}\n  T determinant()const{\n\
    \    Matrix b(*this);\n    T ret=1;\n    for(int i=0;i<(int)width();i++){\n  \
    \    int idx=-1;\n      for(int j=i;j<(int)width();j++)if(b[j][i]!=0){idx=j;break;}\n\
    \      if(idx==-1)return T(0);\n      if(i!=idx){\n        ret*=T(-1);\n     \
    \   swap(b[i],b[idx]);\n      }\n      ret*=b[i][i];\n      T tmp=b[i][i];\n \
    \     for(int j=0;j<(int)width();j++)b[i][j]/=tmp;\n      for(int j=i+1;j<(int)width();j++){\n\
    \        T now=b[j][i];\n        for(int k=0;k<(int)width();k++)b[j][k]-=b[i][k]*now;\n\
    \      }\n    }\n    return ret;\n  }\n};\n/**\n * @brief Matrix(\u884C\u5217\
    )\n*/"
  dependsOn: []
  isVerificationFile: false
  path: math/others/matrix.hpp
  requiredBy: []
  timestamp: '2022-12-18 22:43:53+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/matrix_product.test.cpp
  - test/yosupo/matrix_det.test.cpp
documentation_of: math/others/matrix.hpp
layout: document
redirect_from:
- /library/math/others/matrix.hpp
- /library/math/others/matrix.hpp.html
title: "Matrix(\u884C\u5217)"
---
