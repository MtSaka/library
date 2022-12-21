---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/convolution/lcm-convolution.hpp
    title: LCM Convolution
  - icon: ':question:'
    path: math/modular/modint.hpp
    title: ModInt
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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lcm_convolution
    links:
    - https://judge.yosupo.jp/problem/lcm_convolution
  bundledCode: "#line 1 \"test/yosupo/lcm_convolution.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lcm_convolution\"\n#line 2 \"template/template.hpp\"\
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
    \n\ntemplate<typename T,T mod>\nstruct StaticModInt{\n  static_assert(is_integral<T>::value,\"\
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
    \ int,p>;\n/**\n * @brief ModInt\n*/\n#line 3 \"math/convolution/lcm-convolution.hpp\"\
    \n\ntemplate<typename T>\nvector<T>lcm_convolution(vector<T>a,vector<T>b){\n \
    \ const int n=a.size();\n  vector<bool>sieve(n,true);\n  for(int p=2;p<n;p++)if(sieve[p]){\n\
    \    for(int i=1;i*p<n;i++)a[i*p]+=a[i],sieve[i*p]=false;\n    sieve[p]=true;\n\
    \  }\n  for(int p=2;p<n;p++)if(sieve[p])for(int i=1;i*p<n;i++)b[i*p]+=b[i];\n\
    \  for(int i=0;i<n;i++)a[i]*=b[i];\n  for(int p=2;p<n;p++)if(sieve[p])for(int\
    \ i=(n-1)/p;i>0;i--)a[i*p]-=a[i];\n  return a;\n}\n/**\n * @brief LCM Convolution\n\
    */\n#line 5 \"test/yosupo/lcm_convolution.test.cpp\"\nusing mint=ModInt<998244353>;\n\
    int main(){\n  int n;cin>>n;\n  vector<mint>a(n+1),b(n+1);\n  for(int i=1;i<=n;i++)cin>>a[i];\n\
    \  for(int i=1;i<=n;i++)cin>>b[i];\n  auto ans=lcm_convolution(a,b);\n  for(int\
    \ i=1;i<=n;i++)cout<<ans[i]<<\" \\n\"[i==n];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lcm_convolution\"\n#include\"\
    ../../template/template.hpp\"\n#include\"../../math/modular/modint.hpp\"\n#include\"\
    ../../math/convolution/lcm-convolution.hpp\"\nusing mint=ModInt<998244353>;\n\
    int main(){\n  int n;cin>>n;\n  vector<mint>a(n+1),b(n+1);\n  for(int i=1;i<=n;i++)cin>>a[i];\n\
    \  for(int i=1;i<=n;i++)cin>>b[i];\n  auto ans=lcm_convolution(a,b);\n  for(int\
    \ i=1;i<=n;i++)cout<<ans[i]<<\" \\n\"[i==n];\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - template/type-traits.hpp
  - math/modular/modint.hpp
  - math/convolution/lcm-convolution.hpp
  isVerificationFile: true
  path: test/yosupo/lcm_convolution.test.cpp
  requiredBy: []
  timestamp: '2022-12-22 00:38:16+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/lcm_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/lcm_convolution.test.cpp
- /verify/test/yosupo/lcm_convolution.test.cpp.html
title: test/yosupo/lcm_convolution.test.cpp
---
