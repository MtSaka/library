---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/convolution/ntt.hpp
    title: "Number Theoretic Transform(\u6570\u8AD6\u5909\u63DB)"
  - icon: ':question:'
    path: Math/modular/modint.hpp
    title: modint
  - icon: ':question:'
    path: Math/modular/modpow.hpp
    title: "Mod Pow(\u3079\u304D\u4E57)"
  - icon: ':question:'
    path: Math/number/fast_prime.hpp
    title: "Fast Prime Factorization(\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3)"
  - icon: ':question:'
    path: Math/number/primitive_root.hpp
    title: Math/number/primitive_root.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod_1000000007.test.cpp
    title: test/yosupo/convolution_mod_1000000007.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Arbitrary Mod Convolution(\u4EFB\u610Fmod\u7573\u307F\u8FBC\u307F\
      )"
    links: []
  bundledCode: "#line 2 \"Math/modular/modint.hpp\"\ntemplate<int m>\nstruct modint{\n\
    \  private:\n  unsigned int x;\n  static constexpr unsigned int umod(){return\
    \ m;}\n  public:\n  static modint raw(int v){\n    modint ret;\n    ret.x=v;\n\
    \    return ret;\n  }\n  constexpr modint():x(0){}\n  constexpr modint(int y){\n\
    \    int v=y%m;\n    if(v<0)v+=m;\n    x=(unsigned int)v;\n  }\n  constexpr modint(long\
    \ long y){\n    long long v=y%(long long)m;\n    if(v<0)v+=m;\n    x=(unsigned\
    \ int)v;\n  }\n  constexpr modint(unsigned int y){\n    x=(unsigned int)(y%umod());\n\
    \  }\n  modint& operator++(){x++;if(x==umod())x=0;return *this;}\n  modint& operator--(){if(x==0)x=umod();x--;return\
    \ *this;}\n  modint operator++(int){\n    modint ret=*this;\n    ++*this;\n  \
    \  return ret;\n  }\n  modint operator--(int){\n    modint ret=*this;\n    --*this;\n\
    \    return ret;\n  }\n  modint& operator+=(const modint&p){if((x+=p.x)>=umod())x-=umod();return\
    \ *this;}\n  modint& operator-=(const modint&p){if((x-=p.x)>=umod())x+=umod();return\
    \ *this;}\n  modint& operator*=(const modint&p){\n    unsigned long long y=x;\n\
    \    y*=p.x;\n    x=(unsigned int)(y%umod());\n    return *this;\n  }\n  modint&\
    \ operator/=(const modint&p){return *this*=p.inv();}\n  modint operator+()const{return\
    \ *this;}\n  modint operator-()const{return modint()-*this;}\n  modint pow(long\
    \ long n)const{\n    modint ret(1),mul=*this;\n    while(n){\n      if(n&1)ret*=mul;\n\
    \      mul*=mul;\n      n>>=1;\n    }\n    return ret;\n  }\n  modint inv()const{\n\
    \    long long a=x,b=m,u=1,v=0;\n    while(b){\n      long long t=a/b;\n     \
    \ swap(a-=t*b,b);\n      swap(u-=t*v,v);\n    }\n    return modint(u);\n  }\n\
    \  friend modint operator+(const modint&l,const modint&r){return modint(l)+=r;}\n\
    \  friend modint operator-(const modint&l,const modint&r){return modint(l)-=r;}\n\
    \  friend modint operator*(const modint&l,const modint&r){return modint(l)*=r;}\n\
    \  friend modint operator/(const modint&l,const modint&r){return modint(l)/=r;}\n\
    \  friend bool operator==(const modint&l,const modint&r){return l.x==r.x;}\n \
    \ friend bool operator!=(const modint&l,const modint&r){return l.x!=r.x;}\n  friend\
    \ ostream &operator<<(ostream &os,const modint&p) {\n    return os<<p.val();\n\
    \  }\n  friend istream &operator>>(istream &is, modint &a) {\n    long long t;\n\
    \    is>>t;\n    a=modint(t);\n    return (is);\n  }\n  static constexpr int get_mod(){return\
    \ m;}\n  int val()const{return (int)x;}\n};\n/**\n * @brief modint\n*/\n#line\
    \ 1 \"Math/number/fast_prime.hpp\"\nnamespace fastprime{\n  using i128=__uint128_t;\n\
    \  long long inner_modmul(const long long&x,const long long&y,const long long&p){\n\
    \    return i128(x)*y%p;\n  }\n  long long inner_modpow(long long n,long long\
    \ m,const long long&p){\n    long long res=1;\n    while(m){\n      if(m&1)res=inner_modmul(res,n,p);\n\
    \      n=inner_modmul(n,n,p);\n      m>>=1;\n    }\n    return res;\n  }\n  bool\
    \ miller_rabin(const long long&n,const vector<long long>&p){\n    long long s=__builtin_ctzll(n-1),d=n>>s;\n\
    \    for(long long a:p){\n      if(n<=a)break;\n      long long t=d,y=inner_modpow(a,t,n);\n\
    \      while(t!=n-1&&y!=1&&y!=n-1){\n        y=inner_modmul(y,y,n);\n        t=inner_modmul(t,2,n);\n\
    \      }\n      if(y!=n-1&&!(t&1))return false;\n    }\n    return true;\n  }\n\
    \  bool is_prime(const long long&n){\n    if(n<=2)return n==2;\n    if(!(n&1))return\
    \ false;\n    if(n<=4759123141)return miller_rabin(n,{2,7,61});\n    return miller_rabin(n,{2,325,9375,28178,450775,9780504,1795265022});\n\
    \  }\n  long long factor(const long long&n){\n    if(!(n&1))return 2;\n    else\
    \ if(is_prime(n))return n;\n    int c=2;\n    while(true){\n      auto f=[&](long\
    \ long x){\n        x=inner_modmul(x,x,n)+c;\n        if(x>=n)x-=n;\n        return\
    \ x;\n      };\n      long long x=c,g=1,q=1,xs,y;\n      int m=128;\n      int\
    \ l=1;\n      while(g==1){\n        y=x;\n        for(int i=1;i<l;i++)x=f(x);\n\
    \        int k=0;\n        while(k<l&&g==1){\n          xs=x;\n          for(int\
    \ i=0;i<m&&i<l-k;i++){\n            x=f(x);\n            q=inner_modmul(q,llabs(y-x),n);\n\
    \          }\n          g=__gcd(q,n);\n          k+=m;\n        }\n        l*=2;\n\
    \      }\n      if(g==n){\n        do{\n          xs=f(xs);\n          g=__gcd(llabs(xs-y),n);\n\
    \        }while(g==1);\n      }\n      if(g!=n)return g;\n      c++;\n    }\n\
    \  }\n  vector<long long>factorize_sub(const long long&n){\n    if(n==1)return\
    \ {};\n    long long p=factor(n);\n    if(p==n)return {p};\n    vector<long long>l=factorize_sub(n/p);\n\
    \    vector<long long>r=factorize_sub(p);\n    l.insert(l.end(),r.begin(),r.end());\n\
    \    return l;\n  }\n  vector<long long>factorize(const long long&n,const bool&sorted=true){\n\
    \    vector<long long>res=factorize_sub(n);\n    if(sorted)sort(res.begin(),res.end());\n\
    \    return res;\n  }\n} // namespace fastprime\n/**\n * @brief Fast Prime Factorization(\u9AD8\
    \u901F\u7D20\u56E0\u6570\u5206\u89E3)\n*/\n#line 2 \"Math/modular/modpow.hpp\"\
    \ntemplate<typename T,typename S>\nT modpow(T a,S b,T m){\n  T ret=1;\n  while(b){\n\
    \    if(b&1)ret=ret*a%m;\n    a=a*a%m;\n    b>>=1;\n  }\n  return ret;\n}\n/**\n\
    \ * @brief Mod Pow(\u3079\u304D\u4E57)\n*/\n#line 3 \"Math/number/primitive_root.hpp\"\
    \nint primitive_root(int n){\n  if(n==2)return 1;\n  if(n==167772161)return 3;\n\
    \  if(n==469762049)return 3;\n  if(n==754974721)return 11;\n  if(n==998244353)return\
    \ 3;\n  if(n==1224736769)return 3;\n  auto divs=fastprime::factorize(n-1);\n \
    \ divs.erase(unique(divs.begin(),divs.end()),divs.end());\n  for(int g=2;;g++){\n\
    \    bool ok=true;\n    for(int d:divs){\n      if(modpow(g,(n-1)/d,n)==1){\n\
    \        ok=false;\n        break;\n      }\n    }\n    if(ok)return g;\n  }\n\
    }\n#line 4 \"Math/convolution/ntt.hpp\"\ntemplate<int m>\nstruct NTT{\n  using\
    \ mint=modint<m>;\n  private:\n  static modint<m> g;\n  static int limit;\n  static\
    \ vector<modint<m>>root,inv_root;\n  static void init(){\n    if(!root.empty())return;\n\
    \    g=primitive_root(m);\n    long long now=m-1;\n    while(!(now&1))now>>=1,limit++;\n\
    \    root.resize(limit+1,1),inv_root.resize(limit+1,1);\n    root[limit]=g.pow(now);\n\
    \    inv_root[limit]/=root[limit];\n    for(int i=limit-1;i>=0;i--){\n      root[i]=root[i+1]*root[i+1];\n\
    \      inv_root[i]=inv_root[i+1]*inv_root[i+1];\n    }\n  }\n  public:\n  NTT(){init();};\n\
    \  static void dft(vector<mint>&a,int inv){\n    init();\n    const int sz=a.size();\n\
    \    if(sz==1)return;\n    const int mask=sz-1;\n    vector<mint>b(sz);\n    for(int\
    \ i=sz>>1;i>=1;i>>=1){\n      int e=__builtin_ffsll(sz/i)-1;\n      mint w=1,z=(inv==1?root[e]:inv_root[e]);\n\
    \      for(int j=0;j<sz;j+=i){\n        for(int k=0;k<i;k++)b[j+k]=a[((j<<1)&mask)+k]+w*a[(((j<<1)+i)&mask)+k];\n\
    \        w*=z;\n      }\n      swap(a,b);\n    }\n  }\n  static vector<mint>multiply(vector<mint>a,vector<mint>b){\n\
    \    int sz=1;\n    const int mxsiz=a.size()+b.size()-1;\n    while(sz<mxsiz)sz<<=1;\n\
    \    a.resize(sz),b.resize(sz);\n    dft(a,1),dft(b,1);\n    for(int i=0;i<sz;i++)a[i]*=b[i];\n\
    \    dft(a,-1);\n    a.resize(mxsiz);\n    mint iz=mint(sz).inv();\n    for(int\
    \ i=0;i<mxsiz;i++)a[i]*=iz;\n    return a;\n  }\n  template<typename T,std::enable_if_t<is_integral<T>::value>*\
    \ = nullptr>\n  static vector<T>multiply(const vector<T>&a,const vector<T>&b){\n\
    \    vector<mint>a2(a.size()),b2(b.size());\n    for(int i=0;i<(int)a.size();i++)a2[i]=a[i];\n\
    \    for(int i=0;i<(int)b.size();i++)b2[i]=b[i];\n    auto c2=multiply(a2,b2);\n\
    \    vector<T>c(c2.size());\n    for(int i=0;i<(int)c.size();i++)c[i]=c2[i].val();\n\
    \    return c;\n  }\n};\ntemplate<int m>\nint NTT<m>::limit=0;\ntemplate<int m>\n\
    vector<modint<m>>NTT<m>::root=vector<modint<m>>();\ntemplate<int m>\nvector<modint<m>>NTT<m>::inv_root=vector<modint<m>>();\n\
    template<int m>\nmodint<m>NTT<m>::g=modint<m>();\n/**\n * @brief Number Theoretic\
    \ Transform(\u6570\u8AD6\u5909\u63DB)\n*/\n#line 2 \"Math/convolution/mod_ntt.hpp\"\
    \nvector<long long>mod_convolution(const vector<long long>&a,const vector<long\
    \ long>&b,const long long&m){\n  static constexpr long long m1=167772161,m2=469762049,m3=1224736769,m1_inv_m2=104391568,m12_inv_m3=721017874;\n\
    \  const long long m12_mod=78812994116517889%m;\n  auto x=NTT<m1>::multiply(a,b);\n\
    \  auto y=NTT<m2>::multiply(a,b);\n  auto z=NTT<m3>::multiply(a,b);\n  vector<long\
    \ long>res(x.size());\n  for(int i=0;i<(int)x.size();i++){\n    long long v1=(y[i]-x[i])*m1_inv_m2%m2;\n\
    \    if(v1<0)v1+=m2;\n    long long v2=(z[i]-(x[i]+m1*v1)%m3)*m12_inv_m3%m3;\n\
    \    if(v2<0)v2+=m3;\n    long long c=(x[i]+m1*v1+m12_mod*v2)%m;\n    if(c<0)c+=m;\n\
    \    res[i]=c;\n  }\n  return res;\n}\n/**\n * @brief Arbitrary Mod Convolution(\u4EFB\
    \u610Fmod\u7573\u307F\u8FBC\u307F)\n*/\n"
  code: "#include\"ntt.hpp\"\nvector<long long>mod_convolution(const vector<long long>&a,const\
    \ vector<long long>&b,const long long&m){\n  static constexpr long long m1=167772161,m2=469762049,m3=1224736769,m1_inv_m2=104391568,m12_inv_m3=721017874;\n\
    \  const long long m12_mod=78812994116517889%m;\n  auto x=NTT<m1>::multiply(a,b);\n\
    \  auto y=NTT<m2>::multiply(a,b);\n  auto z=NTT<m3>::multiply(a,b);\n  vector<long\
    \ long>res(x.size());\n  for(int i=0;i<(int)x.size();i++){\n    long long v1=(y[i]-x[i])*m1_inv_m2%m2;\n\
    \    if(v1<0)v1+=m2;\n    long long v2=(z[i]-(x[i]+m1*v1)%m3)*m12_inv_m3%m3;\n\
    \    if(v2<0)v2+=m3;\n    long long c=(x[i]+m1*v1+m12_mod*v2)%m;\n    if(c<0)c+=m;\n\
    \    res[i]=c;\n  }\n  return res;\n}\n/**\n * @brief Arbitrary Mod Convolution(\u4EFB\
    \u610Fmod\u7573\u307F\u8FBC\u307F)\n*/"
  dependsOn:
  - Math/convolution/ntt.hpp
  - Math/modular/modint.hpp
  - Math/number/primitive_root.hpp
  - Math/number/fast_prime.hpp
  - Math/modular/modpow.hpp
  isVerificationFile: false
  path: Math/convolution/mod_ntt.hpp
  requiredBy: []
  timestamp: '2022-11-14 23:10:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/convolution_mod_1000000007.test.cpp
documentation_of: Math/convolution/mod_ntt.hpp
layout: document
redirect_from:
- /library/Math/convolution/mod_ntt.hpp
- /library/Math/convolution/mod_ntt.hpp.html
title: "Arbitrary Mod Convolution(\u4EFB\u610Fmod\u7573\u307F\u8FBC\u307F)"
---
