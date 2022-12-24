---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/convolution/convolution.hpp
    title: "Number Theoretic Transform(\u6570\u8AD6\u5909\u63DB)"
  - icon: ':question:'
    path: math/modular/modint.hpp
    title: ModInt
  - icon: ':question:'
    path: math/modular/montgomery-modint.hpp
    title: "MontgomeryModInt(\u30E2\u30F3\u30B4\u30E1\u30EA\u4E57\u7B97)"
  - icon: ':question:'
    path: math/number/miller-rabin.hpp
    title: "Miller-Rabin Primality Test(\u30DF\u30E9\u30FC\u30E9\u30D3\u30F3\u7D20\
      \u6570\u5224\u5B9A)"
  - icon: ':question:'
    path: math/number/pollard-rho.hpp
    title: "Pollard's Rho Factorization(\u30DD\u30E9\u30FC\u30C9\u30FB\u30ED\u30FC\
      \u6CD5)"
  - icon: ':question:'
    path: math/number/primitive-root.hpp
    title: "Primitive Root(\u539F\u59CB\u6839)"
  - icon: ':question:'
    path: others/random.hpp
    title: "Random(\u4E71\u6570)"
  - icon: ':question:'
    path: string/run-length.hpp
    title: string/run-length.hpp
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
    path: template/type-traits.hpp
    title: template/type-traits.hpp
  - icon: ':question:'
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
    path: test/yosupo/math/sharp_p_subset_sum.test.cpp
    title: test/yosupo/math/sharp_p_subset_sum.test.cpp
  - icon: ':x:'
    path: test/yosupo/polynomial/division_of_polynomials.test.cpp
    title: test/yosupo/polynomial/division_of_polynomials.test.cpp
  - icon: ':x:'
    path: test/yosupo/polynomial/exp_of_formal_power_series.test.cpp
    title: test/yosupo/polynomial/exp_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/polynomial/inv_of_formal_power_series.test.cpp
    title: test/yosupo/polynomial/inv_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/polynomial/log_of_formal_power_series.test.cpp
    title: test/yosupo/polynomial/log_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/polynomial/multipoint_evaluation.test.cpp
    title: test/yosupo/polynomial/multipoint_evaluation.test.cpp
  - icon: ':x:'
    path: test/yosupo/polynomial/polynomial_interpolation.test.cpp
    title: test/yosupo/polynomial/polynomial_interpolation.test.cpp
  - icon: ':x:'
    path: test/yosupo/polynomial/polynomial_taylor_shift.test.cpp
    title: test/yosupo/polynomial/polynomial_taylor_shift.test.cpp
  - icon: ':x:'
    path: test/yosupo/polynomial/pow_of_formal_power_series.test.cpp
    title: test/yosupo/polynomial/pow_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/polynomial/sqrt_of_formal_power_series.test.cpp
    title: test/yosupo/polynomial/sqrt_of_formal_power_series.test.cpp
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
    \ x){return x?msb(x-1)+1:0;}\ninline constexpr ull reverse(ull x){\n  x=((x&0x5555555555555555)<<1)|((x&0xaaaaaaaaaaaaaaaa)>>1);\n\
    \  x=((x&0x3333333333333333)<<2)|((x&0xcccccccccccccccc)>>2);\n  x=((x&0x0f0f0f0f0f0f0f0f)<<4)|((x&0xf0f0f0f0f0f0f0f0)>>4);\n\
    \  x=((x&0xff00ff00ff00ff00)>>8)|((x&0x00ff00ff00ff00ff)<<8);\n  x=((x&0x0000ffff0000ffff)<<16)|((x&0xffff0000ffff0000)>>16);\n\
    \  return (x<<32)|(x>>32);\n}\ninline constexpr ull reverse(ull x,int len){return\
    \ reverse(x)>>(64-len);}\ninline constexpr int popcnt(ull x){\n#if __cplusplus>=202002L\n\
    \  return std::popcount(x);\n#endif\n  x=(x&0x5555555555555555)+((x>>1)&0x5555555555555555);\n\
    \  x=(x&0x3333333333333333)+((x>>2)&0x3333333333333333);\n  x=(x&0x0f0f0f0f0f0f0f0f)+((x>>4)&0x0f0f0f0f0f0f0f0f);\n\
    \  x=(x&0x00ff00ff00ff00ff)+((x>>8)&0x00ff00ff00ff00ff);\n  x=(x&0x0000ffff0000ffff)+((x>>16)&0x0000ffff0000ffff);\n\
    \  return (x&0x00000000ffffffff)+((x>>32)&0x00000000ffffffff);\n}\ntemplate<typename\
    \ T,typename U>\ninline constexpr bool chmin(T&a,U b){return a>b&&(a=b,true);}\n\
    template<typename T,typename U>\ninline constexpr bool chmax(T&a,U b){return a<b&&(a=b,true);}\n\
    inline constexpr ll gcd(ll a,ll b){\n  if(a<0)a=-a;\n  if(b<0)b=-b;\n  while(b){\n\
    \    std::swap(a%=b,b);\n  }\n  return a;\n}\ninline constexpr ll lcm(ll a,ll\
    \ b){return a/gcd(a,b)*b;}\ninline constexpr bool is_prime(ll n){\n  if(n<=1)return\
    \ false;\n  for(ll i=2;i*i<=n;i++){\n    if(n%i==0)return false;\n  }\n  return\
    \ true;\n}\ninline constexpr ll my_pow(ll a,ll b){\n  ll res=1;\n  while(b){\n\
    \    if(b&1)res*=a;\n    a*=a;\n    b>>=1;\n  }\n  return res;\n}\ninline constexpr\
    \ ll mod_pow(ll a,ll b,const ll&mod){\n  if(mod==1)return 0;\n  a%=mod;\n  ll\
    \ res=1;\n  while(b){\n    if(b&1)(res*=a)%=mod;\n    (a*=a)%=mod;\n    b>>=1;\n\
    \  }\n  return res;\n}\ninline ll mod_inv(ll a,const ll&mod){\n  ll b=mod,x=1,u=0,t;\n\
    \  while(b){\n    t=a/b;\n    std::swap(a-=t*b,b);\n    std::swap(x-=t*u,u);\n\
    \  }\n  if(x<0)x+=mod;\n  return x;\n}\ntemplate<typename T,typename U>\nstd::ostream\
    \ &operator<<(std::ostream&os,const std::pair<T,U>&p){os<<p.first<<\" \"<<p.second;return\
    \ os;}\ntemplate<typename T,typename U>\nstd::istream &operator>>(std::istream&is,std::pair<T,U>&p){is>>p.first>>p.second;return\
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
    #endif\n#line 4 \"template/type-traits.hpp\"\n\ntemplate<std::size_t size>\nstruct\
    \ int_least{\n  static_assert(size<=128,\"size must be less than or equal to 128\"\
    );\n  using type=typename std::conditional<\n    size<=8,std::int_least8_t,\n\
    \    typename std::conditional<\n      size<=16,std::int_least16_t,\n      typename\
    \ std::conditional<\n        size<=32,std::int_least32_t,\n        typename std::conditional<size<=64,std::int_least64_t,__int128_t>::type>::type>::type>::type;\n\
    };\ntemplate<std::size_t size>using int_least_t=typename int_least<size>::type;\n\
    template<std::size_t size>\nstruct uint_least{\n  static_assert(size<=128,\"size\
    \ must be less than or equal to 128\");\n  using type=typename std::conditional<\n\
    \    size<=8,std::uint_least8_t,\n    typename std::conditional<\n      size<=16,std::uint_least16_t,\n\
    \      typename std::conditional<\n        size<=32,std::uint_least32_t,\n   \
    \     typename std::conditional<size<=64,std::uint_least64_t,__uint128_t>::type>::type>::type>::type;\n\
    };\ntemplate<std::size_t size>using uint_least_t=typename uint_least<size>::type;\n\
    template<typename T>\nusing double_size_int=int_least<std::numeric_limits<T>::digits*2+1>;\n\
    template<typename T>using double_size_int_t=typename double_size_int<T>::type;\n\
    template<typename T>\nusing double_size_uint=uint_least<std::numeric_limits<T>::digits*2>;\n\
    template<typename T>using double_size_uint_t=typename double_size_uint<T>::type;\n\
    template<typename T>\nusing double_size=typename std::conditional<std::is_signed<T>::value,double_size_int<T>,double_size_uint<T>>::type;\n\
    template<typename T>using double_size_t=typename double_size<T>::type;\n#line\
    \ 9 \"template/template.hpp\"\nusing namespace std;\n#line 3 \"math/modular/modint.hpp\"\
    \n\nnamespace internal{\n  struct modint_base{};\n}//naespace internal\ntemplate<typename\
    \ T>using is_modint=is_base_of<internal::modint_base,T>;\ntemplate<typename T,T\
    \ mod>\nstruct StaticModInt:internal::modint_base{\n  static_assert(is_integral<T>::value,\"\
    T must be integral\");\n  static_assert(is_unsigned<T>::value,\"T must be unsgined\"\
    );\n  static_assert(mod>0,\"mod must be positive\");\n  static_assert(mod<=INF<T>,\"\
    mod*2 must be less than or equal to T::max()\");\n  private:\n  using large_t=typename\
    \ double_size_uint<T>::type;\n  using signed_t=typename make_signed<T>::type;\n\
    \  T val;\n  public:\n  constexpr StaticModInt():val(0){}\n  template<typename\
    \ U,typename enable_if<is_integral<U>::value&&is_unsigned<U>::value>::type* =nullptr>\n\
    \  constexpr StaticModInt(U x):val(x%mod){}\n  template<typename U,typename enable_if<is_integral<U>::value&&is_signed<U>::value>::type*\
    \ =nullptr>\n  constexpr StaticModInt(U x):val{}{\n    x%=static_cast<signed_t>(mod);\n\
    \    if(x<0)x+=static_cast<signed_t>(mod);\n    val=static_cast<T>(x);\n  }\n\
    \  T get()const{return val;}\n  static constexpr T get_mod(){return mod;}\n  static\
    \ StaticModInt raw(T v){\n    StaticModInt res;\n    res.val=v;\n    return res;\n\
    \  }\n  StaticModInt inv()const{\n    return mod_inv(val,mod);\n  }\n  StaticModInt&\
    \ operator++(){\n    ++val;\n    if(val==mod)val=0;\n    return *this;\n  }\n\
    \  StaticModInt operator++(int){\n    StaticModInt res=*this;\n    ++*this;\n\
    \    return res;\n  }\n  StaticModInt& operator--(){\n    if(val==0)val=mod;\n\
    \    --val;\n    return *this;\n  }\n  StaticModInt operator--(int){\n    StaticModInt\
    \ res=*this;\n    --*this;\n    return res;\n  }\n  StaticModInt& operator+=(const\
    \ StaticModInt&x){\n    val+=x.val;\n    if(val>=mod)val-=mod;\n    return *this;\n\
    \  }\n  StaticModInt& operator-=(const StaticModInt&x){\n    if(val<x.val)val+=mod;\n\
    \    val-=x.val;\n    return *this;\n  }\n  StaticModInt& operator*=(const StaticModInt&x){\n\
    \    val=static_cast<T>((static_cast<large_t>(val)*x.val)%mod);\n    return *this;\n\
    \  }\n  StaticModInt& operator/=(const StaticModInt&x){\n    return *this*=x.inv();\n\
    \  }\n  friend StaticModInt operator+(const StaticModInt&l,const StaticModInt&r){return\
    \ StaticModInt(l)+=r;}\n  friend StaticModInt operator-(const StaticModInt&l,const\
    \ StaticModInt&r){return StaticModInt(l)-=r;}\n  friend StaticModInt operator*(const\
    \ StaticModInt&l,const StaticModInt&r){return StaticModInt(l)*=r;}\n  friend StaticModInt\
    \ operator/(const StaticModInt&l,const StaticModInt&r){return StaticModInt(l)/=r;}\n\
    \  StaticModInt operator+()const{return StaticModInt(*this);}\n  StaticModInt\
    \ operator-()const{return StaticModInt()-*this;}\n  friend bool operator==(const\
    \ StaticModInt&l,const StaticModInt&r){return l.val==r.val;}\n  friend bool operator!=(const\
    \ StaticModInt&l,const StaticModInt&r){return l.val!=r.val;}\n  StaticModInt pow(ll\
    \ a)const{\n    StaticModInt v=*this,res=1;\n    while(a){\n      if(a&1)res*=v;\n\
    \      v*=v;\n      a>>=1;\n    }\n    return res;\n  }\n  friend ostream &operator<<(ostream\
    \ &os,const StaticModInt&x){\n    return os<<x.val;\n  }\n  friend istream &operator>>(istream\
    \ &is,StaticModInt&x){\n    ll tmp;\n    is>>tmp;\n    x=StaticModInt(tmp);\n\
    \    return is;\n  }\n};\ntemplate<unsigned int p>using ModInt=StaticModInt<unsigned\
    \ int,p>;\n/**\n * @brief ModInt\n*/\n#line 3 \"math/modular/montgomery-modint.hpp\"\
    \n\ntemplate<typename T>\nstruct MontgomeryReduction{\n  static_assert(is_integral<T>::value,\"\
    template argument must be integral\");\n  static_assert(is_unsigned<T>::value,\"\
    template argument must be unsigned\");\n  private:\n  using large_t=typename double_size_uint<T>::type;\n\
    \  static constexpr int lg=numeric_limits<T>::digits;\n  T mod;\n  T r;\n  T r2;\n\
    \  T minv;\n  T calc_inv()const{\n    T t=0,res=0;\n    rep(i,lg){\n      if(~t&1){\n\
    \        t+=mod;\n        res+=static_cast<T>(1)<<i;\n      }\n      t>>=1;\n\
    \    }\n    return res;\n  }\n  public:\n  MontgomeryReduction(T x){set_mod(x);}\n\
    \  static constexpr int get_lg(){return lg;}\n  void set_mod(T x){\n    assert(x>0);\n\
    \    assert(x&1);\n    assert(x<=INF<T>);\n    mod=x;\n    r=(-static_cast<T>(mod))%mod;\n\
    \    r2=(-static_cast<large_t>(mod))%mod;\n    minv=calc_inv();\n  }\n  inline\
    \ T get_r()const{return r;}\n  inline T get_mod()const{return mod;}\n  T reduce(large_t\
    \ x)const{\n    large_t tmp=(x+static_cast<large_t>(static_cast<T>(x)*minv)*mod)>>lg;\n\
    \    return tmp>=mod?tmp-mod:tmp;\n  }\n  T transform(large_t x)const{return reduce(x*r2);}\n\
    };\ntemplate<typename T,int id>\nstruct MontgomeryModInt{\n  static_assert(is_integral<T>::value,\"\
    template argument must be integral\");\n  static_assert(is_unsigned<T>::value,\"\
    template argument must be unsigned\");\n  private:\n  using large_t=typename double_size_uint<T>::type;\n\
    \  T val;\n  static MontgomeryReduction<T>reduction;\n  public:\n  MontgomeryModInt():val(0){}\n\
    \  template<typename U,typename enable_if<is_integral<U>::value&&is_unsigned<U>::value>::type*\
    \ =nullptr>\n  MontgomeryModInt(U x):val(reduction.transform(x<(static_cast<large_t>(reduction.get_mod())<<reduction.get_lg())?static_cast<large_t>(x):static_cast<large_t>(x%reduction.get_mod()))){}\n\
    \  template<typename U,typename enable_if<is_integral<U>::value&&is_signed<U>::value>::type*\
    \ =nullptr>\n  MontgomeryModInt(U x):MontgomeryModInt(static_cast<typename std::make_unsigned<U>::type>(x<0?-x:x)){\n\
    \    if(x<0&&val)val=reduction.get_mod()-val;\n  }\n  T get()const{return reduction.reduce(val);}\n\
    \  static T get_mod(){return reduction.get_mod();}\n  static void set_mod(T x){reduction.set_mod(x);}\n\
    \  MontgomeryModInt& operator++(){\n    val+=reduction.get_r();\n    if(val>=reduction.get_mod())val-=reduction.get_mod();\n\
    \    return *this;\n  }\n  MontgomeryModInt operator++(int){\n    MontgomeryModInt\
    \ res=*this;\n    ++*this;\n    return res;\n  }\n  MontgomeryModInt& operator--(){\n\
    \    if(val<reduction.get_r())val+=reduction.get_mod();\n    val-=reduction.get_r();\n\
    \    return *this;\n  }\n  MontgomeryModInt operator--(int){\n    MontgomeryModInt\
    \ res=*this;\n    --*this;\n    return res;\n  }\n  MontgomeryModInt& operator+=(const\
    \ MontgomeryModInt&r){\n    val+=r.val;\n    if(val>=reduction.get_mod())val-=reduction.get_mod();\n\
    \    return *this;\n  }\n  MontgomeryModInt& operator-=(const MontgomeryModInt&r){\n\
    \    if(val<r.val)val+=reduction.get_mod();\n    val-=r.val;\n    return *this;\n\
    \  }\n  MontgomeryModInt& operator*=(const MontgomeryModInt&r){\n    val=reduction.reduce(static_cast<large_t>(val)*r.val);\n\
    \    return *this;\n  }\n  MontgomeryModInt pow(ull n)const{\n    MontgomeryModInt\
    \ res=1,tmp=*this;\n    while(n){\n      if(n&1)res*=tmp;\n      tmp*=tmp;\n \
    \     n>>=1;\n    }\n    return res;\n  }\n  MontgomeryModInt inv()const{return\
    \ pow(reduction.get_mod()-2);}\n  MontgomeryModInt& operator/=(const MontgomeryModInt&r){return\
    \ *this*=r.inv();}\n  friend MontgomeryModInt operator+(const MontgomeryModInt&l,const\
    \ MontgomeryModInt&r){return MontgomeryModInt(l)+=r;}\n  friend MontgomeryModInt\
    \ operator-(const MontgomeryModInt&l,const MontgomeryModInt&r){return MontgomeryModInt(l)-=r;}\n\
    \  friend MontgomeryModInt operator*(const MontgomeryModInt&l,const MontgomeryModInt&r){return\
    \ MontgomeryModInt(l)*=r;}\n  friend MontgomeryModInt operator/(const MontgomeryModInt&l,const\
    \ MontgomeryModInt&r){return MontgomeryModInt(l)/=r;}\n  friend bool operator==(const\
    \ MontgomeryModInt&l,const MontgomeryModInt&r){return l.val==r.val;}\n  friend\
    \ bool operator!=(const MontgomeryModInt&l,const MontgomeryModInt&r){return l.val!=r.val;}\n\
    \  friend ostream &operator<<(ostream &os,const MontgomeryModInt&x){\n    return\
    \ os<<x.get();\n  }\n  friend istream &operator>>(istream &is,MontgomeryModInt&x){\n\
    \    ll tmp;\n    is>>tmp;\n    x=MontgomeryModInt(tmp);\n    return is;\n  }\n\
    };\ntemplate<typename T,int id>\nMontgomeryReduction<T>\n  MontgomeryModInt<T,id>::reduction=MontgomeryReduction<T>(998244353);\n\
    using ArbitraryModInt=MontgomeryModInt<unsigned int,-1>;\n/**\n * @brief MontgomeryModInt(\u30E2\
    \u30F3\u30B4\u30E1\u30EA\u4E57\u7B97)\n*/\n#line 4 \"math/number/miller-rabin.hpp\"\
    \n\ntemplate<typename T>\nconstexpr bool miller_rabin(ull n,const ull base[],int\
    \ sz){\n  if(T::get_mod()!=n)T::set_mod(n);\n  ull d=n-1;\n  while(~d&1)d>>=1;\n\
    \  const T e1=1,e2=n-1;\n  rep(i,sz){\n    ull a=base[i];\n    if(n<=a)return\
    \ true;\n    ull t=d;\n    T y=T(a).pow(t);\n    while(t!=n-1&&y!=e1&&y!=e2){\n\
    \      y*=y;\n      t<<=1;\n    }\n    if(y!=e2&&(~t&1))return false;\n  }\n \
    \ return true;\n}\nconstexpr bool is_prime_fast(ull n){\n  constexpr ull base_int[3]={2,7,61},base_ll[7]={2,325,9375,28178,450775,9780504,1795265022};\n\
    \  if(n==2)return true;\n  if(n<2||n%2==0)return false;\n  if(n<(1u<<31))return\
    \ miller_rabin<MontgomeryModInt<unsigned int,-2>>(n,base_int,3);\n  return miller_rabin<MontgomeryModInt<ull,-2>>(n,base_ll,7);\n\
    }\ntemplate<ull n>constexpr bool is_prime_v=is_prime(n);\n/**\n * @brief Miller-Rabin\
    \ Primality Test(\u30DF\u30E9\u30FC\u30E9\u30D3\u30F3\u7D20\u6570\u5224\u5B9A\
    )\n*/\n#line 3 \"others/random.hpp\"\n\ntemplate<typename Engine>\nstruct Random{\n\
    \  private:\n  Engine rnd;\n  public:\n  using result_type=typename Engine::result_type;\n\
    \  Random():Random(random_device{}()){}\n  Random(result_type seed):rnd(seed){}\n\
    \  result_type operator()(){return rnd();}\n  template<typename IntType=ll>\n\
    \  IntType uniform(IntType l,IntType r){\n    static_assert(is_integral<IntType>::value,\"\
    template argument must be an integral type\");\n    return uniform_int_distribution<IntType>{l,r}(rnd);\n\
    \  }\n  template<typename RealType=double>\n  RealType uniform_real(RealType l,RealType\
    \ r){\n    static_assert(is_floating_point<RealType>::value,\"template argument\
    \ must be a floating point type\");\n    return uniform_real_distribution<RealType>{l,r}(rnd);\n\
    \  }\n  bool uniform_bool(){return uniform<int>(0,1);}\n  template<typename T=ll>\n\
    \  pair<T,T> uniform_pair(T l,T r){\n    T a,b;\n    do{\n      a=uniform<T>(l,r);\n\
    \      b=uniform<T>(l,r);\n    }while(a==b);\n    if(a>b)swap(a,b);\n    return\
    \ {a,b};\n  }\n  template<typename Iter>\n  void shuffle(const Iter&first,const\
    \ Iter&last){\n    shuffle(first,last,rnd);\n  }\n  template<class T>\n  vector<T>permutalion(T\
    \ n){\n    static_assert(is_integral<T>::value,\"template argument must be an\
    \ integral type\");\n    vector<T>res(n);\n    iota(res.begin(),res.end(),T());\n\
    \    shuffle(all(res));\n    return res;\n  }\n};\nusing Random32=Random<mt19937>;\n\
    using Random64=Random<mt19937_64>;\nRandom32 rand32;\nRandom64 rand64;\n/**\n\
    \ * @brief Random(\u4E71\u6570)\n*/\n#line 3 \"string/run-length.hpp\"\n\ntemplate<typename\
    \ Cont,typename Cmp>\nvector<pair<typename Cont::value_type,int>>run_length(const\
    \ Cont&c,const Cmp&cmp){\n  vector<pair<typename Cont::value_type,int>> ret;\n\
    \  if(c.empty())return ret;\n  ret.emplace_back(c.front(),1);\n  for(int i=1;i<(int)c.size();i++){\n\
    \    if(cmp(c[i],ret.back().first)){\n      ret.back().second++;\n    }else{\n\
    \      ret.emplace_back(c[i],1);\n    }\n  }\n  return ret;\n}\ntemplate<typename\
    \ Cont>vector<pair<typename Cont::value_type,int>>run_length(const Cont&c){return\
    \ run_length(c,equal_to<typename Cont::value_type>());}\n#line 7 \"math/number/pollard-rho.hpp\"\
    \n\ntemplate<typename T,typename Rand>\null pollard_rho(ull n,Rand&rand){\n  if(~n&1)return\
    \ 2;\n  if(T::get_mod()!=n)T::set_mod(n);\n  T c,e=1;\n  auto f=[&](T x)->T {return\
    \ x*x+c;};\n  constexpr int m=128;\n  while(1){\n    c=rand.uniform(1ull,n-1);\n\
    \    T x=rand.uniform(2ull,n-1),y=x;\n    ull g=1;\n    while(g==1){\n      T\
    \ p=e,tx=x,ty=y;\n      rep(i,m){\n        x=f(x);\n        y=f(f(y));\n     \
    \   p*=x-y;\n      }\n      g=gcd(p.get(),n);\n      if(g==1)continue;\n     \
    \ rep(i,m){\n        tx=f(tx);\n        ty=f(f(ty));\n        g=gcd((tx-ty).get(),n);\n\
    \        if(g!=1){\n          if(g!=n)return g;\n          break;\n        }\n\
    \      }\n    }\n  }\n  return -1;\n}\ntemplate<typename T=MontgomeryModInt<ull,-3>,typename\
    \ Rand=Random64>\nvector<ull>factorize(ull n,Rand&rand=rand64){\n  if(n==1)return\
    \ {};\n  vector<ull>res;\n  vector<ull>st={n};\n  while(!st.empty()){\n    ull\
    \ t=st.back();\n    st.pop_back();\n    if(t==1)continue;\n    if(is_prime_fast(t)){\n\
    \      res.push_back(t);\n      continue;\n    }\n    ull p=pollard_rho<T>(t,rand);\n\
    \    st.push_back(p);\n    st.push_back(t/p);\n  }\n  sort(all(res));\n  return\
    \ res;\n}\ntemplate<typename T=MontgomeryModInt<ull,-3>,typename Rand=Random64>\n\
    vector<pair<ull,int>>expfactorize(ull n,Rand&rand=rand64){\n  auto res=factorize<T>(n,rand);\n\
    \  return run_length(res);\n}\n/**\n * @brief Pollard's Rho Factorization(\u30DD\
    \u30E9\u30FC\u30C9\u30FB\u30ED\u30FC\u6CD5)\n*/\n#line 6 \"math/number/primitive-root.hpp\"\
    \n\ntemplate<typename T=MontgomeryModInt<ull,-4>,typename Rand=Random64>\null\
    \ primitive_root(ull n,Rand rand=rand64){\n  assert(is_prime_fast(n));\n  if(n==2)return\
    \ 1;\n  if(T::get_mod()!=n)T::set_mod(n);\n  auto divs=factorize(n-1);\n  divs.erase(unique(divs.begin(),divs.end()),divs.end());\n\
    \  for(auto&x:divs)x=(n-1)/x;\n  const T e=1;\n  while(1){\n    ull g=rand.uniform(2ull,n-1);\n\
    \    bool ok=1;\n    for(auto x:divs){\n      if(T(g).pow(x)==e){\n        ok=false;\n\
    \        break;\n      }\n    }\n    if(ok)return g;\n  }\n}\ntemplate<ull p,enable_if_t<is_prime_v<p>>*\
    \ =nullptr>\nconstexpr ull constexpr_primitive_root(){\n  if(p==2)return 1;\n\
    \  if(p==167772161)return 3;\n  if(p==469762049)return 3;\n  if(p==754974721)return\
    \ 11;\n  if(p==998244353)return 3;\n  if(p==1224736769)return 3;\n  if(p==1811939329)return\
    \ 11;\n  if(p==2013265921)return 11;\n  rep(g,2,p){\n    if(mod_pow(g,(p-1)>>1,p)!=1)return\
    \ g;\n  }\n  return -1;\n}\n/**\n * @brief Primitive Root(\u539F\u59CB\u6839)\n\
    */\n#line 6 \"math/convolution/convolution.hpp\"\n\ntemplate<unsigned int p>\n\
    struct NthRoot{\n  private:\n  static constexpr unsigned int lg=msb((p-1)&(1-p));\n\
    \  array<unsigned int,lg+1>root,inv_root;\n  public:\n  constexpr NthRoot():root{},inv_root{}{\n\
    \    root[lg]=mod_pow(constexpr_primitive_root<p>(),(p-1)>>lg,p);\n    inv_root[lg]=mod_pow(root[lg],p-2,p);\n\
    \    rrep(i,lg){\n      root[i]=(ull)root[i+1]*root[i+1]%p;\n      inv_root[i]=(ull)inv_root[i+1]*inv_root[i+1]%p;\n\
    \    }\n  }\n  static constexpr unsigned int get_lg(){return lg;}\n  constexpr\
    \ unsigned int get(int n)const{return root[n];}\n  constexpr unsigned int inv(int\
    \ n)const{return inv_root[n];}\n};\ntemplate<unsigned int p>constexpr NthRoot<p>\
    \ nth_root;\ntemplate<typename T,enable_if_t<is_modint<T>::value>* =nullptr>\n\
    void ntt(vector<T>&a){\n  constexpr unsigned int p=T::get_mod();\n  const int\
    \ sz=a.size();\n  assert((unsigned int)sz<=((1-p)&(p-1)));\n  assert((sz&(sz-1))==0);\n\
    \  const int lg=msb(sz);\n  rep(i,sz){\n    const int j=reverse(i,lg);\n    if(i<j)swap(a[i],a[j]);\n\
    \  }\n  rep(i,lg){\n    const T w=nth_root<p>.get(i+1);\n    rep(j,0,sz,1<<(i+1)){\n\
    \      T z=1;\n      rep(k,1<<i){\n        T x=a[j+k],y=a[j+k+(1<<i)]*z;\n   \
    \     a[j+k]=x+y,a[j+k+(1<<i)]=x-y;\n        z*=w;\n      }\n    }\n  }\n}\ntemplate<typename\
    \ T,enable_if_t<is_modint<T>::value>* =nullptr>\nvoid intt(vector<T>&a,const bool&f=true){\n\
    \  constexpr unsigned int p=T::get_mod();\n  const int sz=a.size();\n  assert((unsigned\
    \ int)sz<=((1-p)&(p-1)));\n  assert((sz&(sz-1))==0);\n  const int lg=msb(sz);\n\
    \  rep(i,sz){\n    const int j=reverse(i,lg);\n    if(i<j)swap(a[i],a[j]);\n \
    \ }\n  rep(i,lg){\n    const T w=nth_root<p>.inv(i+1);\n    rep(j,0,sz,1<<(i+1)){\n\
    \      T z=1;\n      rep(k,1<<i){\n        T x=a[j+k],y=a[j+k+(1<<i)]*z;\n   \
    \     a[j+k]=x+y,a[j+k+(1<<i)]=x-y;\n        z*=w;\n      }\n    }\n  }\n  if(f){\n\
    \    const T inv_sz=T(1)/sz;\n    for(auto&x:a)x*=inv_sz;\n  }\n}\ntemplate<typename\
    \ T>\nvector<T>convolution_naive(const vector<T>&a,const vector<T>&b){\n  const\
    \ int sz1=a.size(),sz2=b.size();\n  vector<T>c(sz1+sz2-1);\n  rep(i,sz1)rep(j,sz2)c[i+j]+=a[i]*b[j];\n\
    \  return c;\n}\ntemplate<unsigned int p>\nvector<ModInt<p>>convolution_for_any_mod(const\
    \ vector<ModInt<p>>&a,const vector<ModInt<p>>&b);\ntemplate<typename T,enable_if_t<is_modint<T>::value>*\
    \ =nullptr>\nvector<T>convole(vector<T>a,vector<T>b){\n  constexpr unsigned int\
    \ p=T::get_mod();\n  const int n=a.size()+b.size()-1;\n  const int lg=ceil_log2(n);\n\
    \  const int sz=1<<lg;\n  a.resize(sz),b.resize(sz);\n  rep(i,sz){\n    const\
    \ int j=reverse(i,lg);\n    if(i<j){\n      swap(a[i],a[j]);\n      swap(b[i],b[j]);\n\
    \    }\n  }\n  rep(i,lg){\n    const T w=nth_root<p>.get(i+1);\n    rep(j,0,sz,1<<(i+1)){\n\
    \      T z=1;\n      rep(k,1<<i){\n        T x=a[j+k],y=a[j+k+(1<<i)]*z;\n   \
    \     a[j+k]=x+y,a[j+k+(1<<i)]=x-y;\n        x=b[j+k],y=b[j+k+(1<<i)]*z;\n   \
    \     b[j+k]=x+y,b[j+k+(1<<i)]=x-y;\n        z*=w;\n      }\n    }\n  }\n  rep(i,sz)a[i]*=b[i];\n\
    \  rep(i,sz){\n    const int j=reverse(i,lg);\n    if(i<j)swap(a[i],a[j]);\n \
    \ }\n  rep(i,lg){\n    const T w=nth_root<p>.inv(i+1);\n    rep(j,0,sz,1<<(i+1)){\n\
    \      T z=1;\n      rep(k,1<<i){\n        T x=a[j+k],y=a[j+k+(1<<i)]*z;\n   \
    \     a[j+k]=x+y,a[j+k+(1<<i)]=x-y;\n        z*=w;\n      }\n    }\n  }\n  a.resize(n);\n\
    \  const T inv_sz=T(1)/sz;\n  for(auto&x:a)x*=inv_sz;\n  return a;\n}\ntemplate<typename\
    \ T,enable_if_t<is_modint<T>::value>* =nullptr>\nvector<T>convolution(const vector<T>&a,const\
    \ vector<T>&b){\n  constexpr unsigned int p=T::get_mod();\n  const unsigned int\
    \ sz1=a.size(),sz2=b.size();\n  if(sz1==0||sz2==0)return {};\n  if(sz1<=64||sz2<=64)return\
    \ convolution_naive(a,b);\n  if(sz1+sz2-1>((p-1)&(1-p)))return convolution_for_any_mod(a,b);\n\
    \  return convole(a,b);\n}\n\ntemplate<unsigned int p=99824435>\nvector<ll>convolution(const\
    \ vector<ll>&a,const vector<ll>&b){\n  const int sz1=a.size(),sz2=b.size();\n\
    \  vector<ModInt<p>>a1(sz1),b1(sz2);\n  rep(i,sz1)a1[i]=a[i];\n  rep(i,sz2)b1[i]=b[i];\n\
    \  auto c1=convolution(a1,b1);\n  vector<ll>c(sz1+sz2-1);\n  rep(i,sz1+sz2-1)c[i]=c1[i].get();\n\
    \  return c;\n}\ntemplate<unsigned int p>\nvector<ModInt<p>>convolution_for_any_mod(const\
    \ vector<ModInt<p>>&a,const vector<ModInt<p>>&b){\n  const int sz1=a.size(),sz2=b.size();\n\
    \  assert(sz1+sz2-1<=(1<<26));\n  vector<ll>a1(sz1),b1(sz2);\n  rep(i,sz1)a1[i]=a[i].get();\n\
    \  rep(i,sz2)b1[i]=b[i].get();\n  static constexpr ull MOD1=469762049;\n  static\
    \ constexpr ull MOD2=1811939329;\n  static constexpr ull MOD3=2013265921;\n  static\
    \ constexpr ull INV1_2=mod_pow(MOD1,MOD2-2,MOD2);\n  static constexpr ull INV1_3=mod_pow(MOD1,MOD3-2,MOD3);\n\
    \  static constexpr ull INV2_3=mod_pow(MOD2,MOD3-2,MOD3);\n  auto c1=convolution<MOD1>(a1,b1);\n\
    \  auto c2=convolution<MOD2>(a1,b1);\n  auto c3=convolution<MOD3>(a1,b1);\n  vector<ModInt<p>>c(sz1+sz2-1);\n\
    \  rep(i,sz1+sz2-1){\n    ll x1=c1[i];\n    ll x2=(c2[i]-x1+MOD2)*INV1_2%MOD2;\n\
    \    if(x2<0)x2+=MOD2;\n    ll x3=((c3[i]-x1+MOD3)*INV1_3%MOD3-x2+MOD3)*INV2_3%MOD3;\n\
    \    if(x3<0)x3+=MOD3;\n    c[i]=ModInt<p>(x1+(x2+x3*MOD2)*MOD1);\n  }\n  return\
    \ c;\n}\ntemplate<int m>\nstruct NTT{\n  using mint=ModInt<m>;\n  private:\n \
    \ static ModInt<m> g;\n  static int limit;\n  static vector<ModInt<m>>root,inv_root;\n\
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
    \    print(a);\n    dft(a,-1);\n    a.resize(mxsiz);\n    mint iz=mint(sz).inv();\n\
    \    for(int i=0;i<mxsiz;i++)a[i]*=iz;\n    return a;\n  }\n  template<typename\
    \ T,std::enable_if_t<is_integral<T>::value>* = nullptr>\n  static vector<T>multiply(const\
    \ vector<T>&a,const vector<T>&b){\n    vector<mint>a1(a.size()),b1(b.size());\n\
    \    for(int i=0;i<(int)a.size();i++)a1[i]=a[i];\n    for(int i=0;i<(int)b.size();i++)b1[i]=b[i];\n\
    \    auto c2=multiply(a1,b1);\n    vector<T>c(c2.size());\n    for(int i=0;i<(int)c.size();i++)c[i]=c2[i].get();\n\
    \    return c;\n  }\n};\ntemplate<int m>\nint NTT<m>::limit=0;\ntemplate<int m>\n\
    vector<ModInt<m>>NTT<m>::root=vector<ModInt<m>>();\ntemplate<int m>\nvector<ModInt<m>>NTT<m>::inv_root=vector<ModInt<m>>();\n\
    template<int m>\nModInt<m>NTT<m>::g=ModInt<m>();\n/**\n * @brief Number Theoretic\
    \ Transform(\u6570\u8AD6\u5909\u63DB)\n*/\n#line 4 \"math/fps/fps.hpp\"\n\ntemplate<typename\
    \ mint=ModInt<998244353>>\nstruct FormalPowerSeries:vector<mint>{\n  using vector<mint>::vector;\n\
    \  using FPS=FormalPowerSeries<mint>;\n  private:\n  static constexpr unsigned\
    \ int p=mint::get_mod();\n  public:\n  inline void shrink(){while(!(*this).empty()&&(*this).back()==mint())(*this).pop_back();}\n\
    \  FPS& dot(const FPS&r){\n    rep(i,min((*this).size(),r.size()))(*this)[i]*=r[i];\n\
    \    return *this;\n  }\n  FPS inv(int d=-1)const{\n    const int n=(*this).size();\n\
    \    if(d==-1)d=n;\n    FPS res(d);\n    res[0]=(*this)[0].inv();\n    for(int\
    \ sz=1;sz<d;sz<<=1){\n      FPS f((*this).begin(),(*this).begin()+min(n,2*sz));\n\
    \      FPS g(res.begin(),res.begin()+sz);\n      f.resize(2*sz),g.resize(2*sz);\n\
    \      ntt(f),ntt(g);\n      f.dot(g);\n      intt(f);\n      rep(i,sz)f[i]=0;\n\
    \      ntt(f);\n      f.dot(g);\n      intt(f);\n      rep(j,sz,min(2*sz,d))res[j]=-f[j];\n\
    \    }\n    return res;\n  }\n  FPS operator+()const{return *this;}\n  FPS operator-()const{\n\
    \    FPS res(*this);\n    for(auto &x:res)x=-x;\n    return res;\n  }\n  FPS&\
    \ operator+=(const mint&r){\n    shrink();\n    if((*this).empty())(*this).resize(1);\n\
    \    (*this)[0]+=r;\n    return *this;\n  }\n  FPS& operator-=(const mint&r){\n\
    \    shrink();\n    if((*this).empty())(*this).resize(1);\n    (*this)[0]-=r;\n\
    \    return *this;\n  }\n  FPS& operator*=(const mint&r){\n    shrink();\n   \
    \ for(auto &x:*this)x*=r;\n    return *this;\n  }\n  FPS& operator/=(const mint&r){\n\
    \    shrink()\n    (*this)*=r.inv();\n    return *this;\n  }\n  FPS& operator+=(const\
    \ FPS&r){\n    shrink();\n    if((*this).size()<r.size())(*this).resize(r.size());\n\
    \    rep(i,r.size())(*this)[i]+=r[i];\n    return *this;\n  }\n  FPS& operator-=(const\
    \ FPS&r){\n    shrink();\n    if((*this).size()<r.size())(*this).resize(r.size());\n\
    \    rep(i,r.size())(*this)[i]-=r[i];\n    return *this;\n  }\n  FPS& operator*=(const\
    \ FPS&r){\n    shrink();\n    auto ret=convolution(*this,r);\n    (*this)={ret.begin(),ret.end()};\n\
    \    return *this;\n  }\n  FPS& operator/=(const FPS&r){\n    shrink();\n    const\
    \ int n=(*this).size(),m=r.size();\n    if(n<m){\n      (*this).clear();\n   \
    \   return *this;\n    }\n    const int d=n-m+1;\n    reverse((*this).begin(),(*this).end());\n\
    \    reverse(r.begin(),r.end());\n    (*this).resize(d);\n    (*this)*=r.inv(d);\n\
    \    (*this).resize(d);\n    reverse((*this).begin(),(*this).end());\n    return\
    \ *this;\n  }\n  FPS& operator%=(const FPS&r){\n    shrink();\n    const int n=(*this).size(),m=r.size();\n\
    \    if(n<m)return *this;\n    (*this)-=(*this)/r*r;\n    shrink();\n    return\
    \ *this;\n  }\n  FPS& operator<<=(ll k){\n    shrink();\n    (*this).insert((*this).begin(),k,mint(0));\n\
    \    return *this;\n  }\n  FPS& operator>>=(ll k){\n    shrink();\n    if(k>(*this).size())(*this).clear();\n\
    \    else (*this).erase((*this).begin(),(*this).begin()+k);\n    return *this;\n\
    \  }\n  FPS operator<<(ll k)const{return FPS(*this)<<=k;}\n  FPS operator>>(ll\
    \ k)const{return FPS(*this)>>=k;}\n  friend FPS operator+(const FPS&l,const mint&r){return\
    \ FPS(l)+=r;}\n  friend FPS operator-(const FPS&l,const mint&r){return FPS(l)-=r;}\n\
    \  friend FPS operator*(const FPS&l,const mint&r){return FPS(l)*=r;}\n  friend\
    \ FPS operator/(const FPS&l,const mint&r){return FPS(l)/=r;}\n  friend FPS operator+(const\
    \ mint&l,const FPS&r){return FPS(r)+=l;}\n  friend FPS operator-(const mint&l,const\
    \ FPS&r){return FPS(-r)+=l;}\n  friend FPS operator*(const mint&l,const FPS&r){return\
    \ FPS(r)*=l;}\n  friend FPS operator+(const FPS&l,const FPS&r){return FPS(l)+=r;}\n\
    \  friend FPS operator-(const FPS&l,const FPS&r){return FPS(l)-=r;}\n  friend\
    \ FPS operator*(const FPS&l,const FPS&r){return FPS(l)*=r;}\n  friend FPS operator/(const\
    \ FPS&l,const FPS&r){return FPS(l)/=r;}\n  friend FPS operator%(const FPS&l,const\
    \ FPS&r){return FPS(l)%=r;}\n  pair<FPS,FPS>div_mod(const FPS&r)const{\n    FPS\
    \ q=(*this)/r;\n    FPS m;\n    if((*this).size()>=r.size())m=(*this)-q*r;\n \
    \   else m=*this;\n    q.shrink(),m.shrink();\n    return {q,m};\n  }\n  mint\
    \ operator()(const mint&x)const{\n    mint res=0,w=1;\n    for(auto &v:*this)res+=v*w,w*=x;\n\
    \    return res;\n  }\n  FPS diff()const{\n    const int n=(*this).size();\n \
    \   FPS res(n-1);\n    rep(i,1,n)res[i-1]=(*this)[i]*i;\n    return res;\n  }\n\
    \  FPS& inplace_diff(){\n    shrink();\n    (*this).erase((*this).begin());\n\
    \    mint coeff=1;\n    for(int i=0;i<(int)(*this).size();i++){\n      (*this)[i]*=coeff;\n\
    \      coeff++;\n    }\n    return *this;\n  }\n  FPS integral()const{\n    const\
    \ int n=(*this).size();\n    vector<mint>iv(n+1,1);\n    rep(i,2,n+1)iv[i]=-iv[p%i]*(p/i);\n\
    \    FPS res(n+1);\n    rep(i,n)res[i+1]=(*this)[i]*iv[i+1];\n    return res;\n\
    \  }\n  FPS& inplace_integral(){\n    shrink();\n    const int n=(*this).size();\n\
    \    vector<mint>iv(n+1,1);\n    rep(i,2,n+1)iv[i]=-iv[p%i]*(p/i);\n    (*this).insert((*this).begin(),mint(0));\n\
    \    rep(i,1,n+1)(*this)[i]*=iv[i];\n    return *this;\n  }\n  FPS log(int d=-1)const{\n\
    \    const int n=(*this).size();\n    if(d==-1)d=n;\n    FPS res=diff()*inv(d);\n\
    \    res.resize(d-1);\n    return res.integral();\n  }\n  FPS& inplace_log(int\
    \ d=-1){\n    shrink();\n    const int n=(*this).size();\n    if(d==-1)d=n;\n\
    \    FPS tmp=inv(d);\n    (*this).inplace_diff()*=tmp;\n    (*this).resize(d-1);\n\
    \    return (*this).inplace_integral();\n  }\n  FPS exp(int d=-1)const{\n    const\
    \ int n=(*this).size();\n    if(d==-1)d=n;\n    if(n==1){\n      FPS res(d,mint());\n\
    \      res[0]=1;\n      return res;\n    }\n    FPS f={mint(1)+(*this)[0],(*this)[1]},res{1,(*this)[1]};\n\
    \    for(int sz=2;sz<d;sz<<=1){\n      f.insert(f.end(),(*this).begin()+min(sz,n),(*this).begin()+min(n,sz<<1));\n\
    \      f.resize(sz<<1);\n      res=res*(f-res.log(sz<<1));\n      res.resize(sz<<1);\n\
    \    }\n    res.resize(d);\n    return res;\n  }\n  FPS pow(ll k,int d=-1)const{\n\
    \    const int n=(*this).size();\n    if(d==-1)d=n;\n    if(k==0){\n      FPS\
    \ ans(d,mint());\n      ans[0]=1;\n      return ans;\n    }\n    for(int i=0;i<n;i++){\n\
    \      if((*this)[i]!=mint()){\n        if(i>d/k)return FPS(d,mint());\n     \
    \   mint rev=(*this)[i].inv();\n        FPS res=(((*this*rev)>>i).log(d)*k).exp(d)*((*this)[i].pow(k));\n\
    \        res=(res<<(i*k));\n        res.resize(d);\n        return res;\n    \
    \  }\n    }\n    return FPS(d,mint());\n  }\n  FPS sqrt(const function<mint(mint)>&get_sqrt=[](mint){return\
    \ mint(1);},int d=-1)const{\n    const int n=(*this).size();\n    if(d==-1)d=n;\n\
    \    if((*this)[0]==mint(0)){\n      rep(i,1,n){\n        if((*this)[i]!=mint(0)){\n\
    \          if(i&1)return {};\n          if(d-i/2<=0)break;\n          auto res=(*this>>i).sqrt(get_sqrt,d-i/2);\n\
    \          if(res.empty())return {};\n          res=res<<(i/2);\n          res.resize(d);\n\
    \          return res;\n        }\n      }\n      return FPS(d);\n    }\n    auto\
    \ sqr=get_sqrt((*this)[0]);\n    if(sqr*sqr!=(*this)[0])return {};\n    FPS res{sqr};\n\
    \    const mint inv2=mint(2).inv();\n    FPS f={(*this)[0]};\n    for(int i=1;i<d;i<<=1){\n\
    \      if(i<n)f.insert(f.end(),(*this).begin()+i,(*this).begin()+min(n,i<<1));\n\
    \      if((int)f.size()<(i<<1))f.resize(i<<1);\n      res=(res+f*res.inv(i<<1))*inv2;\n\
    \    }\n    res.resize(d);\n    return res;\n  }\n};\n/**\n * @brief Formal Power\
    \ Series(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)\n*/\n"
  code: "#pragma once\n#include\"../../template/template.hpp\"\n#include\"../convolution/convolution.hpp\"\
    \n\ntemplate<typename mint=ModInt<998244353>>\nstruct FormalPowerSeries:vector<mint>{\n\
    \  using vector<mint>::vector;\n  using FPS=FormalPowerSeries<mint>;\n  private:\n\
    \  static constexpr unsigned int p=mint::get_mod();\n  public:\n  inline void\
    \ shrink(){while(!(*this).empty()&&(*this).back()==mint())(*this).pop_back();}\n\
    \  FPS& dot(const FPS&r){\n    rep(i,min((*this).size(),r.size()))(*this)[i]*=r[i];\n\
    \    return *this;\n  }\n  FPS inv(int d=-1)const{\n    const int n=(*this).size();\n\
    \    if(d==-1)d=n;\n    FPS res(d);\n    res[0]=(*this)[0].inv();\n    for(int\
    \ sz=1;sz<d;sz<<=1){\n      FPS f((*this).begin(),(*this).begin()+min(n,2*sz));\n\
    \      FPS g(res.begin(),res.begin()+sz);\n      f.resize(2*sz),g.resize(2*sz);\n\
    \      ntt(f),ntt(g);\n      f.dot(g);\n      intt(f);\n      rep(i,sz)f[i]=0;\n\
    \      ntt(f);\n      f.dot(g);\n      intt(f);\n      rep(j,sz,min(2*sz,d))res[j]=-f[j];\n\
    \    }\n    return res;\n  }\n  FPS operator+()const{return *this;}\n  FPS operator-()const{\n\
    \    FPS res(*this);\n    for(auto &x:res)x=-x;\n    return res;\n  }\n  FPS&\
    \ operator+=(const mint&r){\n    shrink();\n    if((*this).empty())(*this).resize(1);\n\
    \    (*this)[0]+=r;\n    return *this;\n  }\n  FPS& operator-=(const mint&r){\n\
    \    shrink();\n    if((*this).empty())(*this).resize(1);\n    (*this)[0]-=r;\n\
    \    return *this;\n  }\n  FPS& operator*=(const mint&r){\n    shrink();\n   \
    \ for(auto &x:*this)x*=r;\n    return *this;\n  }\n  FPS& operator/=(const mint&r){\n\
    \    shrink()\n    (*this)*=r.inv();\n    return *this;\n  }\n  FPS& operator+=(const\
    \ FPS&r){\n    shrink();\n    if((*this).size()<r.size())(*this).resize(r.size());\n\
    \    rep(i,r.size())(*this)[i]+=r[i];\n    return *this;\n  }\n  FPS& operator-=(const\
    \ FPS&r){\n    shrink();\n    if((*this).size()<r.size())(*this).resize(r.size());\n\
    \    rep(i,r.size())(*this)[i]-=r[i];\n    return *this;\n  }\n  FPS& operator*=(const\
    \ FPS&r){\n    shrink();\n    auto ret=convolution(*this,r);\n    (*this)={ret.begin(),ret.end()};\n\
    \    return *this;\n  }\n  FPS& operator/=(const FPS&r){\n    shrink();\n    const\
    \ int n=(*this).size(),m=r.size();\n    if(n<m){\n      (*this).clear();\n   \
    \   return *this;\n    }\n    const int d=n-m+1;\n    reverse((*this).begin(),(*this).end());\n\
    \    reverse(r.begin(),r.end());\n    (*this).resize(d);\n    (*this)*=r.inv(d);\n\
    \    (*this).resize(d);\n    reverse((*this).begin(),(*this).end());\n    return\
    \ *this;\n  }\n  FPS& operator%=(const FPS&r){\n    shrink();\n    const int n=(*this).size(),m=r.size();\n\
    \    if(n<m)return *this;\n    (*this)-=(*this)/r*r;\n    shrink();\n    return\
    \ *this;\n  }\n  FPS& operator<<=(ll k){\n    shrink();\n    (*this).insert((*this).begin(),k,mint(0));\n\
    \    return *this;\n  }\n  FPS& operator>>=(ll k){\n    shrink();\n    if(k>(*this).size())(*this).clear();\n\
    \    else (*this).erase((*this).begin(),(*this).begin()+k);\n    return *this;\n\
    \  }\n  FPS operator<<(ll k)const{return FPS(*this)<<=k;}\n  FPS operator>>(ll\
    \ k)const{return FPS(*this)>>=k;}\n  friend FPS operator+(const FPS&l,const mint&r){return\
    \ FPS(l)+=r;}\n  friend FPS operator-(const FPS&l,const mint&r){return FPS(l)-=r;}\n\
    \  friend FPS operator*(const FPS&l,const mint&r){return FPS(l)*=r;}\n  friend\
    \ FPS operator/(const FPS&l,const mint&r){return FPS(l)/=r;}\n  friend FPS operator+(const\
    \ mint&l,const FPS&r){return FPS(r)+=l;}\n  friend FPS operator-(const mint&l,const\
    \ FPS&r){return FPS(-r)+=l;}\n  friend FPS operator*(const mint&l,const FPS&r){return\
    \ FPS(r)*=l;}\n  friend FPS operator+(const FPS&l,const FPS&r){return FPS(l)+=r;}\n\
    \  friend FPS operator-(const FPS&l,const FPS&r){return FPS(l)-=r;}\n  friend\
    \ FPS operator*(const FPS&l,const FPS&r){return FPS(l)*=r;}\n  friend FPS operator/(const\
    \ FPS&l,const FPS&r){return FPS(l)/=r;}\n  friend FPS operator%(const FPS&l,const\
    \ FPS&r){return FPS(l)%=r;}\n  pair<FPS,FPS>div_mod(const FPS&r)const{\n    FPS\
    \ q=(*this)/r;\n    FPS m;\n    if((*this).size()>=r.size())m=(*this)-q*r;\n \
    \   else m=*this;\n    q.shrink(),m.shrink();\n    return {q,m};\n  }\n  mint\
    \ operator()(const mint&x)const{\n    mint res=0,w=1;\n    for(auto &v:*this)res+=v*w,w*=x;\n\
    \    return res;\n  }\n  FPS diff()const{\n    const int n=(*this).size();\n \
    \   FPS res(n-1);\n    rep(i,1,n)res[i-1]=(*this)[i]*i;\n    return res;\n  }\n\
    \  FPS& inplace_diff(){\n    shrink();\n    (*this).erase((*this).begin());\n\
    \    mint coeff=1;\n    for(int i=0;i<(int)(*this).size();i++){\n      (*this)[i]*=coeff;\n\
    \      coeff++;\n    }\n    return *this;\n  }\n  FPS integral()const{\n    const\
    \ int n=(*this).size();\n    vector<mint>iv(n+1,1);\n    rep(i,2,n+1)iv[i]=-iv[p%i]*(p/i);\n\
    \    FPS res(n+1);\n    rep(i,n)res[i+1]=(*this)[i]*iv[i+1];\n    return res;\n\
    \  }\n  FPS& inplace_integral(){\n    shrink();\n    const int n=(*this).size();\n\
    \    vector<mint>iv(n+1,1);\n    rep(i,2,n+1)iv[i]=-iv[p%i]*(p/i);\n    (*this).insert((*this).begin(),mint(0));\n\
    \    rep(i,1,n+1)(*this)[i]*=iv[i];\n    return *this;\n  }\n  FPS log(int d=-1)const{\n\
    \    const int n=(*this).size();\n    if(d==-1)d=n;\n    FPS res=diff()*inv(d);\n\
    \    res.resize(d-1);\n    return res.integral();\n  }\n  FPS& inplace_log(int\
    \ d=-1){\n    shrink();\n    const int n=(*this).size();\n    if(d==-1)d=n;\n\
    \    FPS tmp=inv(d);\n    (*this).inplace_diff()*=tmp;\n    (*this).resize(d-1);\n\
    \    return (*this).inplace_integral();\n  }\n  FPS exp(int d=-1)const{\n    const\
    \ int n=(*this).size();\n    if(d==-1)d=n;\n    if(n==1){\n      FPS res(d,mint());\n\
    \      res[0]=1;\n      return res;\n    }\n    FPS f={mint(1)+(*this)[0],(*this)[1]},res{1,(*this)[1]};\n\
    \    for(int sz=2;sz<d;sz<<=1){\n      f.insert(f.end(),(*this).begin()+min(sz,n),(*this).begin()+min(n,sz<<1));\n\
    \      f.resize(sz<<1);\n      res=res*(f-res.log(sz<<1));\n      res.resize(sz<<1);\n\
    \    }\n    res.resize(d);\n    return res;\n  }\n  FPS pow(ll k,int d=-1)const{\n\
    \    const int n=(*this).size();\n    if(d==-1)d=n;\n    if(k==0){\n      FPS\
    \ ans(d,mint());\n      ans[0]=1;\n      return ans;\n    }\n    for(int i=0;i<n;i++){\n\
    \      if((*this)[i]!=mint()){\n        if(i>d/k)return FPS(d,mint());\n     \
    \   mint rev=(*this)[i].inv();\n        FPS res=(((*this*rev)>>i).log(d)*k).exp(d)*((*this)[i].pow(k));\n\
    \        res=(res<<(i*k));\n        res.resize(d);\n        return res;\n    \
    \  }\n    }\n    return FPS(d,mint());\n  }\n  FPS sqrt(const function<mint(mint)>&get_sqrt=[](mint){return\
    \ mint(1);},int d=-1)const{\n    const int n=(*this).size();\n    if(d==-1)d=n;\n\
    \    if((*this)[0]==mint(0)){\n      rep(i,1,n){\n        if((*this)[i]!=mint(0)){\n\
    \          if(i&1)return {};\n          if(d-i/2<=0)break;\n          auto res=(*this>>i).sqrt(get_sqrt,d-i/2);\n\
    \          if(res.empty())return {};\n          res=res<<(i/2);\n          res.resize(d);\n\
    \          return res;\n        }\n      }\n      return FPS(d);\n    }\n    auto\
    \ sqr=get_sqrt((*this)[0]);\n    if(sqr*sqr!=(*this)[0])return {};\n    FPS res{sqr};\n\
    \    const mint inv2=mint(2).inv();\n    FPS f={(*this)[0]};\n    for(int i=1;i<d;i<<=1){\n\
    \      if(i<n)f.insert(f.end(),(*this).begin()+i,(*this).begin()+min(n,i<<1));\n\
    \      if((int)f.size()<(i<<1))f.resize(i<<1);\n      res=(res+f*res.inv(i<<1))*inv2;\n\
    \    }\n    res.resize(d);\n    return res;\n  }\n};\n/**\n * @brief Formal Power\
    \ Series(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)\n*/"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - template/type-traits.hpp
  - math/convolution/convolution.hpp
  - math/modular/modint.hpp
  - math/number/miller-rabin.hpp
  - math/modular/montgomery-modint.hpp
  - math/number/primitive-root.hpp
  - math/number/pollard-rho.hpp
  - others/random.hpp
  - string/run-length.hpp
  isVerificationFile: false
  path: math/fps/fps.hpp
  requiredBy:
  - math/fps/subset-sum.hpp
  - math/fps/polynomial-interpolation.hpp
  - math/fps/taylor-shift.hpp
  - math/fps/multipoint-evaluation.hpp
  timestamp: '2022-12-24 11:09:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/polynomial/log_of_formal_power_series.test.cpp
  - test/yosupo/polynomial/division_of_polynomials.test.cpp
  - test/yosupo/polynomial/polynomial_taylor_shift.test.cpp
  - test/yosupo/polynomial/pow_of_formal_power_series.test.cpp
  - test/yosupo/polynomial/sqrt_of_formal_power_series.test.cpp
  - test/yosupo/polynomial/exp_of_formal_power_series.test.cpp
  - test/yosupo/polynomial/polynomial_interpolation.test.cpp
  - test/yosupo/polynomial/multipoint_evaluation.test.cpp
  - test/yosupo/polynomial/inv_of_formal_power_series.test.cpp
  - test/yosupo/math/sharp_p_subset_sum.test.cpp
documentation_of: math/fps/fps.hpp
layout: document
redirect_from:
- /library/math/fps/fps.hpp
- /library/math/fps/fps.hpp.html
title: "Formal Power Series(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)"
---
