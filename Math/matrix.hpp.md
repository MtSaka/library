---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/matrix_product.test.cpp
    title: test/yosupo/matrix_product.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Matrix(\u884C\u5217)"
    links: []
  bundledCode: "#line 1 \"Math/matrix.hpp\"\n/**\n * @brief Matrix(\u884C\u5217)\n\
    */\ntemplate<class T>\nstruct Matrix {\n  vector<vector<T>>A;\n  Matrix() {}\n\
    \  Matrix(size_t n,size_t m):A(n,vector<T>(m,0)){}\n  Matrix(size_t n):A(n,vector<T>(n,0)){};\n\
    \  size_t height(){\n    return (A.size());\n  }\n  size_t width(){\n    return\
    \ (A[0].size());\n  }\n  inline const vector<T>&operator[](int k)const{\n    return\
    \ (A.at(k));\n  }\n  inline vector<T>&operator[](int k){\n    return (A.at(k));\n\
    \  }\n  static Matrix E(size_t n){\n    Matrix mat(n);\n    for(int i=0;i<n;i++)mat[i][i]=1;\n\
    \    return (mat);\n  }\n  Matrix &operator+=(Matrix&B){\n    size_t n=height(),m=width();\n\
    \    for(int i=0;i<n;i++)for(int j=0;j<m;j++)(*this)[i][j]+=B[i][j];\n    return\
    \ (*this);\n  }\n  Matrix &operator-=(Matrix&B){\n    size_t n=height(),m=width();\n\
    \    for(int i=0;i<n;i++)for(int j=0;j<m;j++)(*this)[i][j]-=B[i][j];\n    return\
    \ (*this);\n  }\n  Matrix &operator*=(Matrix&B) {\n    size_t n=height(),m=B.width(),p=width();\n\
    \    vector<vector<T>> C(n,vector<T>(m,0));\n    for(int i=0;i<n;i++)for(int j=0;j<m;j++)for(int\
    \ k=0;k<p;k++)C[i][j]+=(*this)[i][k]*B[k][j];\n    A.swap(C);\n    return (*this);\n\
    \  }\n  Matrix &operator^=(long long k){\n    Matrix B=Matrix::E(height());\n\
    \    while(k>0){\n      if(k&1)B*=*this;\n      *this*=*this;\n      k>>=1LL;\n\
    \    }\n    A.swap(B.A);\n    return (*this);\n  }\n  Matrix operator+(Matrix&B){\n\
    \    return (Matrix(*this)+=B);\n  }\n  Matrix operator-(Matrix &B){\n    return\
    \ (Matrix(*this)-=B);\n  }\n  Matrix operator*(Matrix&B){\n    return (Matrix(*this)*=B);\n\
    \  }\n  Matrix operator^(long long k){\n    return (Matrix(*this)^=k);\n  }\n\
    };\n"
  code: "/**\n * @brief Matrix(\u884C\u5217)\n*/\ntemplate<class T>\nstruct Matrix\
    \ {\n  vector<vector<T>>A;\n  Matrix() {}\n  Matrix(size_t n,size_t m):A(n,vector<T>(m,0)){}\n\
    \  Matrix(size_t n):A(n,vector<T>(n,0)){};\n  size_t height(){\n    return (A.size());\n\
    \  }\n  size_t width(){\n    return (A[0].size());\n  }\n  inline const vector<T>&operator[](int\
    \ k)const{\n    return (A.at(k));\n  }\n  inline vector<T>&operator[](int k){\n\
    \    return (A.at(k));\n  }\n  static Matrix E(size_t n){\n    Matrix mat(n);\n\
    \    for(int i=0;i<n;i++)mat[i][i]=1;\n    return (mat);\n  }\n  Matrix &operator+=(Matrix&B){\n\
    \    size_t n=height(),m=width();\n    for(int i=0;i<n;i++)for(int j=0;j<m;j++)(*this)[i][j]+=B[i][j];\n\
    \    return (*this);\n  }\n  Matrix &operator-=(Matrix&B){\n    size_t n=height(),m=width();\n\
    \    for(int i=0;i<n;i++)for(int j=0;j<m;j++)(*this)[i][j]-=B[i][j];\n    return\
    \ (*this);\n  }\n  Matrix &operator*=(Matrix&B) {\n    size_t n=height(),m=B.width(),p=width();\n\
    \    vector<vector<T>> C(n,vector<T>(m,0));\n    for(int i=0;i<n;i++)for(int j=0;j<m;j++)for(int\
    \ k=0;k<p;k++)C[i][j]+=(*this)[i][k]*B[k][j];\n    A.swap(C);\n    return (*this);\n\
    \  }\n  Matrix &operator^=(long long k){\n    Matrix B=Matrix::E(height());\n\
    \    while(k>0){\n      if(k&1)B*=*this;\n      *this*=*this;\n      k>>=1LL;\n\
    \    }\n    A.swap(B.A);\n    return (*this);\n  }\n  Matrix operator+(Matrix&B){\n\
    \    return (Matrix(*this)+=B);\n  }\n  Matrix operator-(Matrix &B){\n    return\
    \ (Matrix(*this)-=B);\n  }\n  Matrix operator*(Matrix&B){\n    return (Matrix(*this)*=B);\n\
    \  }\n  Matrix operator^(long long k){\n    return (Matrix(*this)^=k);\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: Math/matrix.hpp
  requiredBy: []
  timestamp: '2021-12-23 11:34:36+00:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/matrix_product.test.cpp
documentation_of: Math/matrix.hpp
layout: document
redirect_from:
- /library/Math/matrix.hpp
- /library/Math/matrix.hpp.html
title: "Matrix(\u884C\u5217)"
---
