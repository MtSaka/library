---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Math/matrix.hpp
    title: "Matrix(\u884C\u5217)"
  - icon: ':question:'
    path: Math/modint.hpp
    title: modint
  - icon: ':question:'
    path: template/template.hpp
    title: "Template(\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"test/yosupo/matrix_product.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/matrix_product\"\n#line 2 \"template/template.hpp\"\
    \n//#pragma GCC target(\"avx\")\n//#pragma GCC optimize(\"O3\")\n//#pragma GCC\
    \ optimize(\"unroll-loops\")\n#include<bits/stdc++.h>\n#define rep1(a) for(ll\
    \ i=0;i<(ll)(a);i++)\n#define rep2(i,a) for(ll i=0;i<(ll)(a);i++)\n#define rep3(i,a,b)\
    \ for(ll i=(ll)(a);i<(ll)(b);i++)\n#define rep4(i,a,b,c) for(ll i=(ll)(a);i<(ll)(b);i+=(ll)(c))\n\
    #define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n\
    #define rrep1(a) for(ll i=(ll)(a)-1;i>=0;i--)\n#define rrep2(i,a) for(ll i=(ll)(a)-1;i>=0;i--)\n\
    #define rrep3(i,a,b) for(ll i=(ll)(b)-1;i>=(ll)(a);i--)\n#define rrep(...) overload3(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)\n\
    #define all1(i) begin(i),end(i)\n#define all2(i,a) begin(i),begin(i)+a\n#define\
    \ all3(i,a,b) begin(i)+a,begin(i)+b\n#define all(...) overload3(__VA_ARGS__,all3,all2,all1)(__VA_ARGS__)\n\
    #define rall(n) (n).rbegin(),(n).rend()\n#define INT(...) int __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)\n#define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define CHR(...) char __VA_ARGS__;scan(__VA_ARGS__)\n#define DBL(...) double __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define LD(...) ld __VA_ARGS__;scan(__VA_ARGS__)\n#define pb push_back\n#define\
    \ eb emplace_back\n#define END(...) print(__VA_ARGS__);return;\nusing namespace\
    \ std;\nusing ll=long long;\nusing ull=unsigned long long;\nusing ld=long double;\n\
    using vl=vector<ll>;\nusing vi=vector<int>;\nusing vs=vector<string>;\nusing vc=vector<char>;\n\
    using vvl=vector<vl>;\nusing pi=pair<int,int>;\nusing pl=pair<ll,ll>;\nusing vvc=vector<vc>;\n\
    using vd=vector<double>;\nusing vp=vector<pl>;\nusing vb=vector<bool>;\nconst\
    \ int dx[8]={1,0,-1,0,1,-1,-1,1};\nconst int dy[8]={0,1,0,-1,1,1,-1,-1};\nconst\
    \ ll MOD=1000000007;\nconst ll mod=998244353;\nconst ld EPS=1e-8;\nconst ld PI=3.1415926535897932384626;\n\
    template<typename T1,typename T2 >\nostream &operator<<(ostream&os,const pair<T1,T2>&p){os<<p.first<<\"\
    \ \"<<p.second;return os;}\ntemplate<typename T1,typename T2>\nistream &operator>>(istream&is,pair<T1,T2>&p){is>>p.first>>p.second;return\
    \ is;}\ntemplate<typename T>\nostream &operator<<(ostream&os,const vector<T>&v){for(int\
    \ i=0;i<(int)v.size();i++){os<<v[i]<<(i+1!=v.size()?\" \":\"\");}return os;}\n\
    template<typename T>\nistream &operator>>(istream&is,vector<T>&v){for(T &in:v){is>>in;}return\
    \ is;}\nvoid scan(){}\ntemplate<class Head,class... Tail>\nvoid scan(Head&head,Tail&...\
    \ tail){cin>>head;scan(tail...);}\ntemplate<class T>\nvoid print(const T &t){cout<<t<<'\\\
    n';}\ntemplate<class Head, class... Tail>\nvoid print(const Head &head, const\
    \ Tail &... tail){cout<<head<<' ';print(tail...);}\ntemplate<class... T>\nvoid\
    \ fin(const T &... a){print(a...);exit(0);}\ntemplate<typename T1,typename T2>\n\
    inline bool chmax(T1&a,T2 b){return a<b&&(a=b,true);}\ntemplate<typename T1,typename\
    \ T2>\ninline bool chmin(T1&a,T2 b){return a>b&&(a=b,true);}\ntemplate<typename\
    \ T>\nclass infinity{\n  public:\n  static const T MAX=numeric_limits<T>::max();\n\
    \  static const T MIN=numeric_limits<T>::min();\n  static const T value=numeric_limits<T>::max()/2;\n\
    \  static const T mvalue=numeric_limits<T>::min()/2;\n};\ntemplate<typename T>const\
    \ T inf=infinity<T>::value;\ninline int popcnt(ull x){\n#if __cplusplus>=202002L\n\
    \  return popcount(x);\n#endif\n  x=(x&0x5555555555555555)+((x>>1)&0x5555555555555555);\n\
    \  x=(x&0x3333333333333333)+((x>>2)&0x3333333333333333);\n  x=(x&0x0f0f0f0f0f0f0f0f)+((x>>4)&0x0f0f0f0f0f0f0f0f);\n\
    \  x=(x&0x00ff00ff00ff00ff)+((x>>8)&0x00ff00ff00ff00ff);\n  x=(x&0x0000ffff0000ffff)+((x>>16)&0x0000ffff0000ffff);\n\
    \  return (x&0x00000000ffffffff)+((x>>32)&0x00000000ffffffff);\n}\nvoid dump(const\
    \ char&t){cerr<<t;}\nvoid dump(const string&t){cerr<<t;}\nvoid dump(const bool&t){cerr<<(t?\"\
    true\":\"false\");}\ntemplate<typename T>\nvoid dump(const T&t,enable_if_t<is_integral<T>::value>*\
    \ =nullptr){\n  string tmp;\n  if(t==infinity<T>::value||t==infinity<T>::MAX)tmp=\"\
    inf\";\n  if(t==infinity<T>::mvalue||t==infinity<T>::MIN)tmp=\"-inf\";\n  if(tmp.empty())tmp=to_string(t);\n\
    \  cerr<<tmp;\n}\ntemplate <typename T>\nvoid dump(const T&t,enable_if_t<!is_void<typename\
    \ T::iterator>::value>* =nullptr){\n  cerr<<\"{\";\n  for(auto it=t.begin();it!=t.end();){\n\
    \    dump(*it);\n    cerr<<(++it==t.end()?\"\":\", \");\n  }\n  cerr<<\"}\";\n\
    }\ntemplate<typename T,typename U>\nvoid dump(const pair<T,U>&t){\n  cerr<<\"\
    (\";\n  dump(t.first);\n  cerr<<\",\";\n  dump(t.second);\n  cerr<<\")\";\n}\n\
    void trace(){cerr<<endl;}\ntemplate<typename Head,typename... Tail>\nvoid trace(Head&&head,Tail&&...\
    \ tail){\n  dump(head);\n  if(sizeof...(tail))cerr<<\",\";\n  trace(forward<Tail>(tail)...);\n\
    }\n#ifdef ONLINE_JUDGE\n#define debug(...) cerr<<#__VA_ARGS__<<\"=\";trace(__VA_ARGS__);\n\
    #else\n#define debug(...) cerr<<#__VA_ARGS__<<\"=\";trace(__VA_ARGS__);\n#endif\n\
    struct IOSetup{\n  IOSetup(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    cout<<fixed<<setprecision(12);\n    cerr<<fixed<<setprecision(12);\n  }\n\
    };\n/**\n * @brief Template(\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\n#line 1\
    \ \"Math/matrix.hpp\"\n/**\n * @brief Matrix(\u884C\u5217)\n*/\ntemplate<class\
    \ T>\nstruct Matrix {\n  vector<vector<T>>A;\n  Matrix() {}\n  Matrix(size_t n,size_t\
    \ m):A(n,vector<T>(m,0)){}\n  Matrix(size_t n):A(n,vector<T>(n,0)){};\n  size_t\
    \ height(){\n    return (A.size());\n  }\n  size_t width(){\n    return (A[0].size());\n\
    \  }\n  inline const vector<T>&operator[](int k)const{\n    return (A.at(k));\n\
    \  }\n  inline vector<T>&operator[](int k){\n    return (A.at(k));\n  }\n  static\
    \ Matrix E(size_t n){\n    Matrix mat(n);\n    for(int i=0;i<n;i++)mat[i][i]=1;\n\
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
    };\n#line 1 \"Math/modint.hpp\"\n/**\n * @brief modint\n*/\ntemplate<long long\
    \ m>\nstruct modint{\n  long long x;\n  modint():x(0){}\n  modint(long long y):x(y>=0?y%m:(m-(-y)%m)%m){}\n\
    \  modint inv()const{long long a=x,b=m,u=1,v=0,t;\n    while(b){\n      t=a/b;\n\
    \      swap(a-=t*b,b);\n      swap(u-=t*v,v);\n    }\n    return modint(u);\n\
    \  }\n  modint &operator+=(const modint&p) {if((x+=p.x)>=m)x-=m;return *this;}\n\
    \  modint &operator-=(const modint&p){if((x+=m-p.x)>=m)x-=m;return *this;}\n \
    \ modint &operator*=(const modint&p) {x=x*p.x%m;return *this;}\n  modint &operator/=(const\
    \ modint&p){*this*=p.inv();return *this;}\n  modint operator-()const{return modint(-x);\
    \ }\n  modint operator+(const modint&p)const{return modint(*this)+=p; }\n  modint\
    \ operator-(const modint&p)const{return modint(*this)-=p; }\n  modint operator*(const\
    \ modint&p)const{return modint(*this)*=p; }\n  modint operator/(const modint&p)const{return\
    \ modint(*this)/=p; }\n  bool operator==(const modint&p)const{return x==p.x;}\n\
    \  bool operator!=(const modint&p)const{return x!=p.x;}\n  modint pow(long long\
    \ n) const {\n    modint ret(1),mul(x);\n    while(n){\n      if(n&1)ret*=mul;\n\
    \      mul*=mul;\n      n>>=1;\n    }\n    return ret;\n  }\n  friend ostream\
    \ &operator<<(ostream &os,const modint&p) {\n    return os<<p.x;\n  }\n  friend\
    \ istream &operator>>(istream &is, modint &a) {\n    long long t;\n    is>>t;\n\
    \    a=modint<m>(t);\n    return (is);\n  }\n  static long long get_mod(){return\
    \ m;}\n};\n#line 5 \"test/yosupo/matrix_product.test.cpp\"\nint main(){\n  int\
    \ n,m,k;\n  cin>>n>>m>>k;\n  Matrix<modint<mod>>a(n,m),b(m,k);\n  for(int i=0;i<n;i++){\n\
    \    for(int j=0;j<m;j++){\n      cin>>a[i][j];\n    }\n  }\n  for(int i=0;i<m;i++){\n\
    \    for(int j=0;j<k;j++){\n      cin>>b[i][j];\n    }\n  }\n  a*=b;\n  for(int\
    \ i=0;i<n;i++){\n    cout<<a[i]<<endl;\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include\"\
    ../../template/template.hpp\"\n#include\"../../Math/matrix.hpp\"\n#include\"../../Math/modint.hpp\"\
    \nint main(){\n  int n,m,k;\n  cin>>n>>m>>k;\n  Matrix<modint<mod>>a(n,m),b(m,k);\n\
    \  for(int i=0;i<n;i++){\n    for(int j=0;j<m;j++){\n      cin>>a[i][j];\n   \
    \ }\n  }\n  for(int i=0;i<m;i++){\n    for(int j=0;j<k;j++){\n      cin>>b[i][j];\n\
    \    }\n  }\n  a*=b;\n  for(int i=0;i<n;i++){\n    cout<<a[i]<<endl;\n  }\n}"
  dependsOn:
  - template/template.hpp
  - Math/matrix.hpp
  - Math/modint.hpp
  isVerificationFile: true
  path: test/yosupo/matrix_product.test.cpp
  requiredBy: []
  timestamp: '2022-01-02 20:26:45+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/matrix_product.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/matrix_product.test.cpp
- /verify/test/yosupo/matrix_product.test.cpp.html
title: test/yosupo/matrix_product.test.cpp
---
