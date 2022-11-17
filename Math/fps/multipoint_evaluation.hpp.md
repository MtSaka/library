---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/convolution/ntt.hpp
    title: "Number Theoretic Transform(\u6570\u8AD6\u5909\u63DB)"
  - icon: ':heavy_check_mark:'
    path: Math/fps/fps.hpp
    title: "Formal Power Series(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)"
  - icon: ':heavy_check_mark:'
    path: Math/modular/modint.hpp
    title: modint
  - icon: ':heavy_check_mark:'
    path: Math/modular/modpow.hpp
    title: "Mod Pow(\u3079\u304D\u4E57)"
  - icon: ':heavy_check_mark:'
    path: Math/number/fast_prime.hpp
    title: "Fast Prime Factorization(\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3)"
  - icon: ':heavy_check_mark:'
    path: Math/number/primitive_root.hpp
    title: "Primitive Root(\u539F\u59CB\u6839)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/multipoint_evaluation.test.cpp
    title: test/yosupo/multipoint_evaluation.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Multipoint Evaluation(\u591A\u70B9\u8A55\u4FA1)"
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
    }\n/**\n * @brief Primitive Root(\u539F\u59CB\u6839)\n*/\n#line 4 \"Math/convolution/ntt.hpp\"\
    \ntemplate<int m>\nstruct NTT{\n  using mint=modint<m>;\n  private:\n  static\
    \ modint<m> g;\n  static int limit;\n  static vector<modint<m>>root,inv_root;\n\
    \  static void init(){\n    if(!root.empty())return;\n    g=primitive_root(m);\n\
    \    long long now=m-1;\n    while(!(now&1))now>>=1,limit++;\n    root.resize(limit+1,1),inv_root.resize(limit+1,1);\n\
    \    root[limit]=g.pow(now);\n    inv_root[limit]/=root[limit];\n    for(int i=limit-1;i>=0;i--){\n\
    \      root[i]=root[i+1]*root[i+1];\n      inv_root[i]=inv_root[i+1]*inv_root[i+1];\n\
    \    }\n  }\n  public:\n  NTT(){init();};\n  static void dft(vector<mint>&a,int\
    \ inv){\n    init();\n    const int sz=a.size();\n    if(sz==1)return;\n    const\
    \ int mask=sz-1;\n    vector<mint>b(sz);\n    for(int i=sz>>1;i>=1;i>>=1){\n \
    \     int e=__builtin_ffsll(sz/i)-1;\n      mint w=1,z=(inv==1?root[e]:inv_root[e]);\n\
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
    \ Transform(\u6570\u8AD6\u5909\u63DB)\n*/\n#line 3 \"Math/fps/fps.hpp\"\ntemplate<int\
    \ m>\nstruct FPS:vector<modint<m>>{\n  using mint=modint<m>;\n  using vector<mint>::vector;\n\
    \  using vector<mint>::operator=;\n  void shrink(){while(!(*this).empty()&&(*this).back()==mint())(*this).pop_back();}\n\
    \  FPS inv(int d=-1)const{\n    NTT<m>ntt;\n    const int n=(*this).size();\n\
    \    if(d==-1)d=n;\n    FPS res{(*this)[0].inv()};\n    for(int sz=1;sz<d;sz<<=1){\n\
    \      FPS f((*this).begin(),(*this).begin()+min(n,2*sz));\n      FPS g(res);\n\
    \      f.resize(2*sz),g.resize(2*sz);\n      ntt.dft(f,1),ntt.dft(g,1);\n    \
    \  for(int i=0;i<2*sz;i++)f[i]*=g[i];\n      ntt.dft(f,-1);\n      f.erase(f.begin(),f.begin()+sz);\n\
    \      f.resize(2*sz);ntt.dft(f,1);\n      for(int i=0;i<2*sz;i++)f[i]*=g[i];\n\
    \      ntt.dft(f,-1);\n      mint iz=mint(2*sz).inv();iz*=-iz;\n      for(int\
    \ i=0;i<sz;i++)f[i]*=iz;\n      res.insert(res.end(),f.begin(),f.begin()+sz);\n\
    \    }\n    res.resize(d);\n    return res;\n  }\n  FPS operator+(const mint&r)const{return\
    \ FPS(*this)+=r;}\n  FPS operator-(const mint&r)const{return FPS(*this)-=r;}\n\
    \  FPS operator*(const mint&r)const{return FPS(*this)*=r;}\n  FPS operator/(const\
    \ mint&r)const{return FPS(*this)/=r;}\n  FPS operator+(const FPS&r)const{return\
    \ FPS(*this)+=r;}\n  FPS operator-(const FPS&r)const{return FPS(*this)-=r;}\n\
    \  FPS operator<<(const int&d)const{return FPS(*this)<<=d;}\n  FPS operator>>(const\
    \ int&d)const{return FPS(*this)>>=d;}\n  FPS operator*(const FPS&r)const{return\
    \ FPS(*this)*=r;}\n  FPS operator/(const FPS&r)const{return FPS(*this)/=r;}\n\
    \  FPS operator%(const FPS&r)const{return FPS(*this)%=r;}\n  FPS operator-()const{\n\
    \    FPS ret(*this);\n    for(auto &i:ret)i=-i;\n    return ret;\n  }\n  FPS &operator+=(const\
    \ mint&r){\n    if((*this).empty())(*this).resize(1);\n    (*this)[0]+=r;\n  \
    \  return *this;\n  }\n  FPS &operator-=(const mint&r){\n    if((*this).empty())(*this).resize(1);\n\
    \    (*this)[0]-=r;\n    return *this;\n  }\n  FPS &operator*=(const mint&r){\n\
    \    for(auto &i:*this)i*=r;\n    return *this;\n  }\n  FPS &operator/=(const\
    \ mint&r){\n    (*this)*=r.inv();\n    return *this;\n  }\n  FPS &operator+=(const\
    \ FPS&r){\n    const int n=(*this).size(),sz=r.size();\n    (*this).resize(max(n,sz));\n\
    \    for(int i=0;i<sz;i++)(*this)[i]+=r[i];\n    return *this;\n  }\n  FPS &operator-=(const\
    \ FPS&r){\n    const int n=(*this).size(),sz=r.size();\n    (*this).resize(max(n,sz));\n\
    \    for(int i=0;i<sz;i++)(*this)[i]-=r[i];\n    return *this;\n  }\n  FPS &operator<<=(const\
    \ long long&d){\n    (*this).insert((*this).begin(),d,mint(0));\n    return *this;\n\
    \  }\n  FPS &operator>>=(const long long&d){\n    (*this).erase((*this).begin(),(*this).begin()+d);\n\
    \    return *this;\n  }\n  FPS &operator*=(const FPS&r){\n    (*this)=NTT<m>::multiply((*this),r);\n\
    \    return *this;\n  }\n  FPS &operator/=(FPS r){\n    const int n=(*this).size(),n1=r.size();\n\
    \    if(n<n1){\n      (*this).clear();\n      return *this;\n    }\n    const\
    \ int sz=n-n1+1;\n    reverse((*this).begin(),(*this).end());\n    reverse(r.begin(),r.end());\n\
    \    (*this).resize(sz);\n    (*this)*=r.inv(sz);\n    (*this).resize(sz);\n \
    \   reverse((*this).begin(),(*this).end());\n    return (*this);\n  }\n  FPS &operator%=(const\
    \ FPS&r){\n    const int n=(*this).size(),sz=r.size();\n    if(n<sz)return (*this);\n\
    \    (*this)-=(*this)/r*r;\n    (*this).resize(sz-1);\n    shrink();\n    return\
    \ (*this);\n  }\n  pair<FPS,FPS>div_mod(const FPS&r){\n    FPS p=*this/r,q=*this-p*r;\n\
    \    q.shrink();\n    return {p,q};\n  }\n  mint operator()(const mint&x)const{\n\
    \    mint ret(0),w(1);\n    for(auto &e:*this){\n      ret+=e*w;\n      w*=x;\n\
    \    }\n    return ret;\n  }\n  FPS diff()const{\n    const int n=(*this).size();\n\
    \    FPS ret(max(0,n-1));\n    for(int i=1;i<n;i++)ret[i-1]=(*this)[i]*mint(i);\n\
    \    return ret;\n  }\n  FPS integral()const{\n    const int n=(*this).size();\n\
    \    vector<mint>inv(n+1);\n    inv[1]=mint(1);\n    for(int i=2;i<=n;i++)inv[i]=-inv[m%i]*mint(m/i);\n\
    \    FPS ret(n+1);\n    for(int i=0;i<n;i++)ret[i+1]=(*this)[i]*inv[i+1];\n  \
    \  return ret;\n  }\n  FPS log(int d=-1)const{\n    const int n=(*this).size();\n\
    \    if(d==-1)d=n;\n    FPS res=diff()*inv(d);\n    res.resize(d-1);\n    return\
    \ res.integral();\n  }\n  FPS exp(int d=-1)const{\n    const int n=(*this).size();\n\
    \    if(d==-1)d=n;\n    FPS f={mint(1)+(*this)[0],(*this)[1]},res{1,1<n?(*this)[1]:0};\n\
    \    for(int sz=2;sz<d;sz<<=1){\n      f.insert(f.end(),(*this).begin()+min(sz,n),(*this).begin()+min(n,2*sz));\n\
    \      if((int)f.size()<2*sz)f.resize(2*sz);\n      res=res*(f-res.log(2*sz));\n\
    \      res.resize(2*sz);\n    }\n    res.resize(d);\n    return res;\n  }\n  FPS\
    \ pow(long long k,int d=-1)const{\n    const int n=(*this).size();\n    if(d==-1)d=n;\n\
    \    if(k==0){\n      FPS ans(d,mint(0));\n      ans[0]=1;\n      return ans;\n\
    \    }\n    for(int i=0;i<n;i++){\n      if((*this)[i]!=mint()){\n        if(i>d/k)return\
    \ FPS(d,mint(0));\n        mint rev=(*this)[i].inv();\n        FPS ret=(((*this*rev)>>i).log(d)*k).exp(d)*((*this)[i].pow(k));\n\
    \        ret=(ret<<(i*k));\n        ret.resize(d);\n        return ret;\n    \
    \  }\n    }\n    return FPS(d,mint(0));\n  }\n  FPS sqrt(int d=-1,const function<mint(mint)>&get_sqrt=[](mint){return\
    \ mint(1);})const{\n    const int n=(*this).size();\n    if(d==-1)d=n;\n    if((*this)[0]==mint(0)){\n\
    \      for(int i=1;i<n;i++){\n        if((*this)[i]!=mint(0)){\n          if(i&1)return\
    \ {};\n          if(d-i/2<=0)break;\n          auto ret=(*this>>i).sqrt(d-i/2,get_sqrt);\n\
    \          if(ret.empty())return {};\n          ret=ret<<(i/2);\n          if((int)ret.size()<d)ret.resize(d);\n\
    \          return ret;\n        }\n      }\n      return FPS(d);\n    }\n    auto\
    \ sqr=get_sqrt((*this)[0]);\n    if(sqr*sqr!=(*this)[0])return {};\n    FPS ret{sqr};\n\
    \    mint inv2=mint(2).inv();\n    FPS f={(*this)[0]};\n    for(int i=1;i<d;i<<=1){\n\
    \      if(i<n)f.insert(f.end(),(*this).begin()+i,(*this).begin()+min(n,i<<1));\n\
    \      if((int)f.size()<(i<<1))f.resize(i<<1);\n      ret=(ret+f*ret.inv(i<<1))*inv2;\n\
    \    }\n    ret.resize(d);\n    return ret;\n  }\n};\n/**\n * @brief Formal Power\
    \ Series(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)\n*/\n#line 3 \"Math/fps/multipoint_evaluation.hpp\"\
    \ntemplate<int m>\nvector<modint<m>>multipoint_evaluation(const FPS<m>&f,const\
    \ vector<modint<m>>&xs){\n  const int n=xs.size();\n  int sz=1;\n  while(sz<n)sz<<=1;\n\
    \  vector<FPS<m>>g(sz+sz,{1});\n  for(int i=0;i<n;i++)g[i+sz]={-xs[i],1};\n  for(int\
    \ i=sz;i-->1;)g[i]=g[i<<1]*g[i<<1|1];\n  g[1]=f%g[1];\n  for(int i=2;i<sz+n;i++)g[i]=g[i>>1]%g[i];\n\
    \  vector<modint<m>>res(n);\n  for(int i=0;i<n;i++)res[i]=(g[i+sz].empty()?modint<m>():g[i+sz][0]);\n\
    \  return res;\n}\n/**\n * @brief Multipoint Evaluation(\u591A\u70B9\u8A55\u4FA1\
    )\n*/\n"
  code: "#pragma once\n#include\"fps.hpp\"\ntemplate<int m>\nvector<modint<m>>multipoint_evaluation(const\
    \ FPS<m>&f,const vector<modint<m>>&xs){\n  const int n=xs.size();\n  int sz=1;\n\
    \  while(sz<n)sz<<=1;\n  vector<FPS<m>>g(sz+sz,{1});\n  for(int i=0;i<n;i++)g[i+sz]={-xs[i],1};\n\
    \  for(int i=sz;i-->1;)g[i]=g[i<<1]*g[i<<1|1];\n  g[1]=f%g[1];\n  for(int i=2;i<sz+n;i++)g[i]=g[i>>1]%g[i];\n\
    \  vector<modint<m>>res(n);\n  for(int i=0;i<n;i++)res[i]=(g[i+sz].empty()?modint<m>():g[i+sz][0]);\n\
    \  return res;\n}\n/**\n * @brief Multipoint Evaluation(\u591A\u70B9\u8A55\u4FA1\
    )\n*/"
  dependsOn:
  - Math/fps/fps.hpp
  - Math/convolution/ntt.hpp
  - Math/modular/modint.hpp
  - Math/number/primitive_root.hpp
  - Math/number/fast_prime.hpp
  - Math/modular/modpow.hpp
  isVerificationFile: false
  path: Math/fps/multipoint_evaluation.hpp
  requiredBy: []
  timestamp: '2022-11-17 18:07:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/multipoint_evaluation.test.cpp
documentation_of: Math/fps/multipoint_evaluation.hpp
layout: document
redirect_from:
- /library/Math/fps/multipoint_evaluation.hpp
- /library/Math/fps/multipoint_evaluation.hpp.html
title: "Multipoint Evaluation(\u591A\u70B9\u8A55\u4FA1)"
---
