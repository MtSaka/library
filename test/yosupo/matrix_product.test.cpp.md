---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/modular/modint.hpp
    title: modint
  - icon: ':heavy_check_mark:'
    path: math/others/matrix.hpp
    title: "Matrix(\u884C\u5217)"
  - icon: ':question:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':question:'
    path: template/debug.hpp
    title: template/debug.hpp
  - icon: ':question:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':question:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"test/yosupo/matrix_product.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/matrix_product\"\n#line 2 \"template/template.hpp\"\
    \n#include<bits/stdc++.h>\n#line 3 \"template/macro.hpp\"\n\n#define SELECT4(a,b,c,d,e,...)\
    \ e\n#define SELECT3(a,b,c,d,...) d\n#define REP1(a) for(ll i=0;i<(ll)(a);++i)\n\
    #define REP2(i,a) for(ll i=0;i<(ll)(a);++i)\n#define REP3(i,a,b) for(ll i=(ll)(a);i<(ll)(b);++i)\n\
    #define REP4(i,a,b,c) for(ll i=(ll)(a);i<(ll)(b);i+=(ll)(c))\n#define rep(...)\
    \ SELECT4(__VA_ARGS__,REP4,REP3,REP2,REP1)(__VA_ARGS__)\n#define RREP1(a) for(ll\
    \ i=(ll)(a)-1;i>=0;--i)\n#define RREP2(i,a) for(ll i=(ll)(a)-1;i>=0;--i)\n#define\
    \ RREP3(i,a,b) for(ll i=(ll)(b)-1;i>=(ll)(a);--i)\n#define rrep(...) SELECT3(__VA_ARGS__,RREP3,RREP2,RREP1)(__VA_ARGS__)\n\
    #define all(v) std::begin(v),std::end(v)\n#define rall(v) std::rbegin(v),std::rend(v)\n\
    #define INT(...) int __VA_ARGS__;scan(__VA_ARGS__)\n#define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)\n#define CHR(...) char __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define DBL(...) double __VA_ARGS__;scan(__VA_ARGS__)\n#define LD(...) ld __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define pb push_back\n#define eb emplace_back\n#line 3 \"template/alias.hpp\"\n\
    \nusing ll=long long;\nusing ull=unsigned long long;\nusing ld=long double;\n\
    using pi=std::pair<int,int>;\nusing pl=std::pair<ll,ll>;\nusing vi=std::vector<int>;\n\
    using vl=std::vector<ll>;\nusing vs=std::vector<std::string>;\nusing vc=std::vector<char>;\n\
    using vvl=std::vector<vl>;\nusing vd=std::vector<double>;\nusing vp=std::vector<pl>;\n\
    using vb=std::vector<bool>;\ntemplate<typename T>\nstruct infinity{\n  static\
    \ constexpr T MAX=std::numeric_limits<T>::max();\n  static constexpr T MIN=std::numeric_limits<T>::min();\n\
    \  static constexpr T value=std::numeric_limits<T>::max()/2;\n  static constexpr\
    \ T mvalue=std::numeric_limits<T>::min()/2;\n};\ntemplate<typename T>constexpr\
    \ T INF=infinity<T>::value;\nconstexpr ll inf=INF<ll>;\nconstexpr ld EPS=1e-8;\n\
    constexpr ld PI=3.1415926535897932384626;\nconstexpr int dx[8]={1,0,-1,0,1,-1,-1,1};\n\
    constexpr int dy[8]={0,1,0,-1,1,1,-1,-1};\n#line 5 \"template/func.hpp\"\n\ninline\
    \ constexpr int msb(ull x){\n  int res=x?0:-1;\n  if(x&0xffffffff00000000)x&=0xffffffff00000000,res+=32;\n\
    \  if(x&0xffff0000ffff0000)x&=0xffff0000ffff0000,res+=16;\n  if(x&0xff00ff00ff00ff00)x&=0xff00ff00ff00ff00,res+=8;\n\
    \  if(x&0xf0f0f0f0f0f0f0f0)x&=0xf0f0f0f0f0f0f0f0,res+=4;\n  if(x&0xcccccccccccccccc)x&=0xcccccccccccccccc,res+=2;\n\
    \  return res+(x&0xaaaaaaaaaaaaaaaa?1:0);\n}\ninline constexpr int ceil_log2(ull\
    \ x){return x?msb(x-1)+1:0;}\ninline constexpr int popcnt(ull x){\n#if __cplusplus>=202002L\n\
    \  return popcount(x);\n#endif\n  x=(x&0x5555555555555555)+((x>>1)&0x5555555555555555);\n\
    \  x=(x&0x3333333333333333)+((x>>2)&0x3333333333333333);\n  x=(x&0x0f0f0f0f0f0f0f0f)+((x>>4)&0x0f0f0f0f0f0f0f0f);\n\
    \  x=(x&0x00ff00ff00ff00ff)+((x>>8)&0x00ff00ff00ff00ff);\n  x=(x&0x0000ffff0000ffff)+((x>>16)&0x0000ffff0000ffff);\n\
    \  return (x&0x00000000ffffffff)+((x>>32)&0x00000000ffffffff);\n}\ntemplate<typename\
    \ T,typename U>\ninline constexpr bool chmin(T&a,U b){return a>b&&(a=b,true);}\n\
    template<typename T,typename U>\ninline constexpr bool chmax(T&a,U b){return a<b&&(a=b,true);}\n\
    template<typename T,typename U>\nstd::ostream &operator<<(std::ostream&os,const\
    \ std::pair<T,U>&p){os<<p.first<<\" \"<<p.second;return os;}\ntemplate<typename\
    \ T,typename U>\nstd::istream &operator>>(std::istream&is,std::pair<T,U>&p){is>>p.first>>p.second;return\
    \ is;}\ntemplate<typename T>\nstd::ostream &operator<<(std::ostream&os,const std::vector<T>&v){for(auto\
    \ it=std::begin(v);it!=std::end(v);){os<<*it<<((++it)!=std::end(v)?\" \":\"\"\
    );}return os;}\ntemplate<typename T>\nstd::istream &operator>>(std::istream&is,std::vector<T>&v){for(T\
    \ &in:v){is>>in;}return is;}\ninline void scan(){}\ntemplate<class Head,class...\
    \ Tail>\ninline void scan(Head&head,Tail&... tail){std::cin>>head;scan(tail...);}\n\
    template<class T>\ninline void print(const T &t){std::cout<<t<<'\\n';}\ntemplate<class\
    \ Head, class... Tail>\ninline void print(const Head &head, const Tail &... tail){std::cout<<head<<'\
    \ ';print(tail...);}\ntemplate<class... T>\ninline void fin(const T &... a){print(a...);exit(0);}\n\
    #line 5 \"template/util.hpp\"\n\nstruct IOSetup{\n  IOSetup(){\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    std::cout.tie(0);\n    std::cout<<std::fixed<<std::setprecision(12);\n\
    \    std::cerr<<std::fixed<<std::setprecision(12);\n  }\n};\ntemplate<typename\
    \ F>\nstruct REC{\n  private:\n  F f;\n  public:\n  explicit constexpr REC(F&&f_):f(std::forward<F>(f_)){}\n\
    \  template<typename... Args>\n  constexpr auto operator()(Args&&...args)const{\n\
    \    return f(*this, std::forward<Args>(args)...);\n  }\n};\ntemplate<typename\
    \ T,typename Comp=std::less<T>>\nstruct compressor{\n  private:\n  std::vector<T>data;\n\
    \  Comp cmp;\n  bool sorted=false;\n  public:\n  compressor():compressor(Comp()){}\n\
    \  compressor(const Comp&cmp):cmp(cmp){}\n  compressor(const std::vector<T>&dat,const\
    \ Comp&cmp=Comp()):data(dat),cmp(cmp){}\n  compressor(std::vector<T>&&dat,const\
    \ Comp&cmp=Comp()):data(move(dat)),cmp(cmp){}\n  compressor(std::initializer_list<T>li,const\
    \ Comp&cmp=Comp()):data(li.begin(),li.end()),cmp(cmp){}\n  void push_back(const\
    \ T&v){assert(!sorted);data.push_back(v);}\n  void push_back(T&&v){assert(!sorted);data.push_back(move(v));}\n\
    \  template<typename... Args>void emplace_back(Args&&...args){assert(!sorted);data.emplace_back(std::forward<Args>(args)...);}\n\
    \  void push(const std::vector<T>&v){\n    assert(!sorted);\n    const int n=data.size();\n\
    \    data.resize(v.size()+n);\n    for(int i=0;i<(int)v.size();i++)data[i+n]=v[i];\n\
    \  }\n  void build(){\n    assert(!sorted);sorted=1;\n    std::sort(data.begin(),data.end(),cmp);\n\
    \    data.erase(unique(data.begin(),data.end(),[&](const T&l,const T&r)->bool\
    \ {return !cmp(l,r)&&!cmp(r,l);}),data.end());\n  }\n  const T&operator[](int\
    \ k)const& {\n    assert(sorted);\n    return data[k];\n  }\n  int get_index(const\
    \ T&v)const {\n    assert(sorted);\n    return int(lower_bound(data.begin(),data.end(),v,cmp)-data.begin());\n\
    \  }\n  void press(std::vector<T>&v)const {\n    assert(sorted);\n    for(auto&&i:v)i=get_index(i);\n\
    \  }\n  std::vector<int>pressed(const std::vector<T>&v)const {\n    assert(sorted);\n\
    \    std::vector<int>ret(v.size());\n    for(int i=0;i<(int)v.size();i++)ret[i]=get_index(v[i]);\n\
    \    return ret;\n  }\n  int size()const {\n    assert(sorted);\n    return data.size();\n\
    \  }\n};\n#line 4 \"template/debug.hpp\"\n\ntemplate<typename T,typename=void>\n\
    struct is_specialize:std::false_type{};\ntemplate<typename T>\nstruct is_specialize<T,typename\
    \ std::conditional<false,typename T::iterator, void>::type>:std::true_type{};\n\
    template<typename T>\nstruct is_specialize<T,typename std::conditional<false,decltype(T::first),void>::type>:std::true_type{};\n\
    template<typename T>\nstruct is_specialize<T,std::enable_if_t<std::is_integral<T>::value,void>>:std::true_type{};\n\
    inline void dump(const char&t){std::cerr<<t;}\ninline void dump(const std::string&t){std::cerr<<t;}\n\
    inline void dump(const bool&t){std::cerr<<(t?\"true\":\"false\");}\ntemplate <typename\
    \ T,std::enable_if_t<!is_specialize<T>::value,std::nullptr_t> =nullptr>\ninline\
    \ void dump(const T&t){std::cerr<<t;}\ntemplate<typename T>\ninline void dump(const\
    \ T&t,std::enable_if_t<std::is_integral<T>::value>* =nullptr){std::string tmp;if(t==infinity<T>::value||t==infinity<T>::MAX)tmp=\"\
    inf\";if(std::is_signed<T>::value&&(t==infinity<T>::mvalue||t==infinity<T>::MIN))tmp=\"\
    -inf\";if(tmp.empty())tmp=to_string(t);std::cerr<<tmp;}\ntemplate<typename T,typename\
    \ U>\ninline void dump(const std::pair<T,U>&);\ntemplate<typename T>\ninline void\
    \ dump(const T&t,std::enable_if_t<!std::is_void<typename T::iterator>::value>*\
    \ =nullptr){std::cerr<<\"{\";for(auto it=std::begin(t);it!=std::end(t);){dump(*it);std::cerr<<(++it==t.end()?\"\
    \":\",\");}std::cerr<<\"}\";}\ntemplate<typename T,typename U>\ninline void dump(const\
    \ std::pair<T,U>&t){std::cerr<<\"(\";dump(t.first);std::cerr<<\",\";dump(t.second);std::cerr<<\"\
    )\";}\ninline void trace(){std::cerr<<std::endl;}\ntemplate<typename Head,typename...\
    \ Tail>\ninline void trace(Head&&head,Tail&&... tail){dump(head);if(sizeof...(tail))std::cerr<<\"\
    ,\";trace(std::forward<Tail>(tail)...);}\n#ifdef ONLINE_JUDGE\n#define debug(...)\
    \ (void(0))\n#else\n#define debug(...) do{std::cerr<<#__VA_ARGS__<<\"=\";trace(__VA_ARGS__);}while(0)\n\
    #endif\n#line 8 \"template/template.hpp\"\nusing namespace std;\n#line 3 \"math/others/matrix.hpp\"\
    \n\ntemplate<typename T>\nstruct Matrix{\n  private:\n  vector<vector<T>>A;\n\
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
    )\n*/\n#line 3 \"math/modular/modint.hpp\"\n\ntemplate<int m>\nstruct modint{\n\
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
    \ 5 \"test/yosupo/matrix_product.test.cpp\"\nint main(){\n  int n,m,k;\n  cin>>n>>m>>k;\n\
    \  Matrix<modint<998244353>>a(n,m),b(m,k);\n  for(int i=0;i<n;i++){\n    for(int\
    \ j=0;j<m;j++){\n      cin>>a[i][j];\n    }\n  }\n  for(int i=0;i<m;i++){\n  \
    \  for(int j=0;j<k;j++){\n      cin>>b[i][j];\n    }\n  }\n  a*=b;\n  for(int\
    \ i=0;i<n;i++){\n    cout<<a[i]<<endl;\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include\"\
    ../../template/template.hpp\"\n#include\"../../math/others/matrix.hpp\"\n#include\"\
    ../../math/modular/modint.hpp\"\nint main(){\n  int n,m,k;\n  cin>>n>>m>>k;\n\
    \  Matrix<modint<998244353>>a(n,m),b(m,k);\n  for(int i=0;i<n;i++){\n    for(int\
    \ j=0;j<m;j++){\n      cin>>a[i][j];\n    }\n  }\n  for(int i=0;i<m;i++){\n  \
    \  for(int j=0;j<k;j++){\n      cin>>b[i][j];\n    }\n  }\n  a*=b;\n  for(int\
    \ i=0;i<n;i++){\n    cout<<a[i]<<endl;\n  }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - math/others/matrix.hpp
  - math/modular/modint.hpp
  isVerificationFile: true
  path: test/yosupo/matrix_product.test.cpp
  requiredBy: []
  timestamp: '2022-12-18 23:26:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/matrix_product.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/matrix_product.test.cpp
- /verify/test/yosupo/matrix_product.test.cpp.html
title: test/yosupo/matrix_product.test.cpp
---
