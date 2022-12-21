---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/convolution/ntt.hpp
    title: "Number Theoretic Transform(\u6570\u8AD6\u5909\u63DB)"
  - icon: ':x:'
    path: math/modular/modint.hpp
    title: ModInt
  - icon: ':x:'
    path: math/number/fast-prime.hpp
    title: "Fast Prime Factorization(\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3)"
  - icon: ':x:'
    path: math/number/primitive-root.hpp
    title: "Primitive Root(\u539F\u59CB\u6839)"
  - icon: ':x:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':x:'
    path: template/debug.hpp
    title: template/debug.hpp
  - icon: ':x:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':x:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':x:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':x:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/fps/multipoint-evaluation.hpp
    title: "Multipoint Evaluation(\u591A\u70B9\u8A55\u4FA1)"
  - icon: ':x:'
    path: math/fps/polynomial-interpolation.hpp
    title: "Polynomial Interpolation(\u591A\u9805\u5F0F\u88DC\u9593)"
  - icon: ':x:'
    path: math/fps/subset-sum.hpp
    title: Count Subset Sum
  - icon: ':x:'
    path: math/fps/taylor-shift.hpp
    title: "Taylor Shift(\u591A\u9805\u5F0F\u306E\u5E73\u884C\u79FB\u52D5)"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/division_of_polynomials.test.cpp
    title: test/yosupo/division_of_polynomials.test.cpp
  - icon: ':x:'
    path: test/yosupo/exp_of_formal_power_series.test.cpp
    title: test/yosupo/exp_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/log_of_formal_power_series.test.cpp
    title: test/yosupo/log_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/multipoint_evaluation.test.cpp
    title: test/yosupo/multipoint_evaluation.test.cpp
  - icon: ':x:'
    path: test/yosupo/polynomial_interpolation.test.cpp
    title: test/yosupo/polynomial_interpolation.test.cpp
  - icon: ':x:'
    path: test/yosupo/polynomial_taylor_shift.test.cpp
    title: test/yosupo/polynomial_taylor_shift.test.cpp
  - icon: ':x:'
    path: test/yosupo/pow_of_formal_power_series.test.cpp
    title: test/yosupo/pow_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/sharp_p_subset_sum.test.cpp
    title: test/yosupo/sharp_p_subset_sum.test.cpp
  - icon: ':x:'
    path: test/yosupo/sqrt_of_formal_power_series.test.cpp
    title: test/yosupo/sqrt_of_formal_power_series.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Formal Power Series(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)"
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n#include<bits/stdc++.h>\n#line\
    \ 3 \"template/macro.hpp\"\n\n#define SELECT4(a,b,c,d,e,...) e\n#define SELECT3(a,b,c,d,...)\
    \ d\n#define REP1(a) for(ll i=0;i<(ll)(a);++i)\n#define REP2(i,a) for(ll i=0;i<(ll)(a);++i)\n\
    #define REP3(i,a,b) for(ll i=(ll)(a);i<(ll)(b);++i)\n#define REP4(i,a,b,c) for(ll\
    \ i=(ll)(a);i<(ll)(b);i+=(ll)(c))\n#define rep(...) SELECT4(__VA_ARGS__,REP4,REP3,REP2,REP1)(__VA_ARGS__)\n\
    #define RREP1(a) for(ll i=(ll)(a)-1;i>=0;--i)\n#define RREP2(i,a) for(ll i=(ll)(a)-1;i>=0;--i)\n\
    #define RREP3(i,a,b) for(ll i=(ll)(b)-1;i>=(ll)(a);--i)\n#define rrep(...) SELECT3(__VA_ARGS__,RREP3,RREP2,RREP1)(__VA_ARGS__)\n\
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
    inline constexpr ll gcd(ll a,ll b){\n  if(a<0)a=-a;\n  if(b<0)b=-b;\n  while(b){\n\
    \    tie(a,b)={b,a%b};\n  }\n  return a;\n}\ninline constepxr ll lcm(ll a,ll b){return\
    \ a/gcd(a,b)*b;}\ninline constexpr bool is_prime(ll n){\n  if(n<=1)return false;\n\
    \  for(ll i=2;i*i<=n;i++){\n    if(n%i==0)return false;\n  }\n  return true;\n\
    }\ninline constexpr ll my_pow(ll a,ll b){\n  ll res=1;\n  while(b){\n    if(b&1)res*=a;\n\
    \    a*=a;\n    b>>=1;\n  }\n  return res;\n}\ninline constexpr ll mod_pow(ll\
    \ a,ll b,const ll&mod){\n  if(mod==1)return 0;\n  a%=mod;\n  ll res=1;\n  while(b){\n\
    \    if(b&1)(res*=a)%=mod;\n    (a*=a)%=mod;\n    b>>=1;\n  }\n  return res;\n\
    }\ninline ll mod_inv(ll a,const ll&mod){\n  ll b=mod,x=1,u=0,t;\n  while(b){\n\
    \    t=a/b;\n    std::swap(a-=t*b,b);\n    std::swap(x-=t*u,u);\n  }\n  if(x<0)x+=mod;\n\
    \  return x;\n}\ntemplate<typename T,typename U>\nstd::ostream &operator<<(std::ostream&os,const\
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
    -inf\";if(tmp.empty())tmp=std::to_string(t);std::cerr<<tmp;}\ntemplate<typename\
    \ T,typename U>\ninline void dump(const std::pair<T,U>&);\ntemplate<typename T>\n\
    inline void dump(const T&t,std::enable_if_t<!std::is_void<typename T::iterator>::value>*\
    \ =nullptr){std::cerr<<\"{\";for(auto it=std::begin(t);it!=std::end(t);){dump(*it);std::cerr<<(++it==t.end()?\"\
    \":\",\");}std::cerr<<\"}\";}\ntemplate<typename T,typename U>\ninline void dump(const\
    \ std::pair<T,U>&t){std::cerr<<\"(\";dump(t.first);std::cerr<<\",\";dump(t.second);std::cerr<<\"\
    )\";}\ninline void trace(){std::cerr<<std::endl;}\ntemplate<typename Head,typename...\
    \ Tail>\ninline void trace(Head&&head,Tail&&... tail){dump(head);if(sizeof...(tail))std::cerr<<\"\
    ,\";trace(std::forward<Tail>(tail)...);}\n#ifdef ONLINE_JUDGE\n#define debug(...)\
    \ (void(0))\n#else\n#define debug(...) do{std::cerr<<#__VA_ARGS__<<\"=\";trace(__VA_ARGS__);}while(0)\n\
    #endif\n#line 8 \"template/template.hpp\"\nusing namespace std;\n#line 3 \"math/modular/modint.hpp\"\
    \n\ntemplate<int m>\nstruct ModInt{\n  private:\n  unsigned int x;\n  static constexpr\
    \ unsigned int umod(){return m;}\n  public:\n  static ModInt raw(int v){\n   \
    \ ModInt ret;\n    ret.x=v;\n    return ret;\n  }\n  constexpr ModInt():x(0){}\n\
    \  constexpr ModInt(int y){\n    int v=y%m;\n    if(v<0)v+=m;\n    x=(unsigned\
    \ int)v;\n  }\n  constexpr ModInt(long long y){\n    long long v=y%(long long)m;\n\
    \    if(v<0)v+=m;\n    x=(unsigned int)v;\n  }\n  constexpr ModInt(unsigned int\
    \ y){\n    x=(unsigned int)(y%umod());\n  }\n  ModInt& operator++(){x++;if(x==umod())x=0;return\
    \ *this;}\n  ModInt& operator--(){if(x==0)x=umod();x--;return *this;}\n  ModInt\
    \ operator++(int){\n    ModInt ret=*this;\n    ++*this;\n    return ret;\n  }\n\
    \  ModInt operator--(int){\n    ModInt ret=*this;\n    --*this;\n    return ret;\n\
    \  }\n  ModInt& operator+=(const ModInt&p){if((x+=p.x)>=umod())x-=umod();return\
    \ *this;}\n  ModInt& operator-=(const ModInt&p){if((x-=p.x)>=umod())x+=umod();return\
    \ *this;}\n  ModInt& operator*=(const ModInt&p){\n    unsigned long long y=x;\n\
    \    y*=p.x;\n    x=(unsigned int)(y%umod());\n    return *this;\n  }\n  ModInt&\
    \ operator/=(const ModInt&p){return *this*=p.inv();}\n  ModInt operator+()const{return\
    \ *this;}\n  ModInt operator-()const{return ModInt()-*this;}\n  ModInt pow(long\
    \ long n)const{\n    ModInt ret(1),mul=*this;\n    while(n){\n      if(n&1)ret*=mul;\n\
    \      mul*=mul;\n      n>>=1;\n    }\n    return ret;\n  }\n  ModInt inv()const{\n\
    \    long long a=x,b=m,u=1,v=0;\n    while(b){\n      long long t=a/b;\n     \
    \ swap(a-=t*b,b);\n      swap(u-=t*v,v);\n    }\n    return ModInt(u);\n  }\n\
    \  friend ModInt operator+(const ModInt&l,const ModInt&r){return ModInt(l)+=r;}\n\
    \  friend ModInt operator-(const ModInt&l,const ModInt&r){return ModInt(l)-=r;}\n\
    \  friend ModInt operator*(const ModInt&l,const ModInt&r){return ModInt(l)*=r;}\n\
    \  friend ModInt operator/(const ModInt&l,const ModInt&r){return ModInt(l)/=r;}\n\
    \  friend bool operator==(const ModInt&l,const ModInt&r){return l.x==r.x;}\n \
    \ friend bool operator!=(const ModInt&l,const ModInt&r){return l.x!=r.x;}\n  friend\
    \ ostream &operator<<(ostream &os,const ModInt&p) {\n    return os<<p.val();\n\
    \  }\n  friend istream &operator>>(istream &is, ModInt &a) {\n    long long t;\n\
    \    is>>t;\n    a=ModInt(t);\n    return (is);\n  }\n  static constexpr int get_mod(){return\
    \ m;}\n  int val()const{return (int)x;}\n};\n/**\n * @brief ModInt\n*/\n#line\
    \ 3 \"math/number/fast-prime.hpp\"\n\nnamespace fastprime{\n  using i128=__uint128_t;\n\
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
    \u901F\u7D20\u56E0\u6570\u5206\u89E3)\n*/\n#line 4 \"math/number/primitive-root.hpp\"\
    \n\nint primitive_root(int n){\n  if(n==2)return 1;\n  if(n==167772161)return\
    \ 3;\n  if(n==469762049)return 3;\n  if(n==754974721)return 11;\n  if(n==998244353)return\
    \ 3;\n  if(n==1224736769)return 3;\n  auto divs=fastprime::factorize(n-1);\n \
    \ divs.erase(unique(divs.begin(),divs.end()),divs.end());\n  for(int g=2;;g++){\n\
    \    bool ok=true;\n    for(int d:divs){\n      if(mod_pow(g,(n-1)/d,n)==1){\n\
    \        ok=false;\n        break;\n      }\n    }\n    if(ok)return g;\n  }\n\
    }\n/**\n * @brief Primitive Root(\u539F\u59CB\u6839)\n*/\n#line 5 \"math/convolution/ntt.hpp\"\
    \n\ntemplate<int m>\nstruct NTT{\n  using mint=ModInt<m>;\n  private:\n  static\
    \ ModInt<m> g;\n  static int limit;\n  static vector<ModInt<m>>root,inv_root;\n\
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
    vector<ModInt<m>>NTT<m>::root=vector<ModInt<m>>();\ntemplate<int m>\nvector<ModInt<m>>NTT<m>::inv_root=vector<ModInt<m>>();\n\
    template<int m>\nModInt<m>NTT<m>::g=ModInt<m>();\n/**\n * @brief Number Theoretic\
    \ Transform(\u6570\u8AD6\u5909\u63DB)\n*/\n#line 4 \"math/fps/fps.hpp\"\n\ntemplate<int\
    \ m>\nstruct FormalPowerSeries:vector<ModInt<m>>{\n  using mint=ModInt<m>;\n \
    \ using vector<mint>::vector;\n  using vector<mint>::operator=;\n  void shrink(){while(!(*this).empty()&&(*this).back()==mint())(*this).pop_back();}\n\
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
    \ Series(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)\n*/\n"
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
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - math/convolution/ntt.hpp
  - math/modular/modint.hpp
  - math/number/primitive-root.hpp
  - math/number/fast-prime.hpp
  isVerificationFile: false
  path: math/fps/fps.hpp
  requiredBy:
  - math/fps/subset-sum.hpp
  - math/fps/polynomial-interpolation.hpp
  - math/fps/taylor-shift.hpp
  - math/fps/multipoint-evaluation.hpp
  timestamp: '2022-12-21 08:33:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/yosupo/division_of_polynomials.test.cpp
  - test/yosupo/polynomial_taylor_shift.test.cpp
  - test/yosupo/pow_of_formal_power_series.test.cpp
  - test/yosupo/sharp_p_subset_sum.test.cpp
  - test/yosupo/sqrt_of_formal_power_series.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
  - test/yosupo/polynomial_interpolation.test.cpp
  - test/yosupo/multipoint_evaluation.test.cpp
  - test/yosupo/inv_of_formal_power_series.test.cpp
documentation_of: math/fps/fps.hpp
layout: document
redirect_from:
- /library/math/fps/fps.hpp
- /library/math/fps/fps.hpp.html
title: "Formal Power Series(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)"
---
