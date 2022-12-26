---
data:
  _extendedDependsOn:
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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"test/yosupo/math/factorize.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/factorize\"\n#line 2 \"template/template.hpp\"\
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
    \ constexpr T max=std::numeric_limits<T>::max();\n  static constexpr T min=std::numeric_limits<T>::min();\n\
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
    \  x=((x&0x00ff00ff00ff00ff)<<8)|((x&0xff00ff00ff00ff00)>>8);\n  \n  x=((x&0x0000ffff0000ffff)<<16)|((x&0xffff0000ffff0000)>>16);\n\
    \  return (x<<32)|(x>>32);\n}\ninline constexpr ull reverse(ull x,int len){return\
    \ reverse(x)>>(64-len);}\ninline constexpr int popcnt(ull x){\n#if __cplusplus>=202002L\n\
    \  return std::popcount(x);\n#endif\n  x=(x&0x5555555555555555)+((x>>1)&0x5555555555555555);\n\
    \  x=(x&0x3333333333333333)+((x>>2)&0x3333333333333333);\n  x=(x&0x0f0f0f0f0f0f0f0f)+((x>>4)&0x0f0f0f0f0f0f0f0f);\n\
    \  x=(x&0x00ff00ff00ff00ff)+((x>>8)&0x00ff00ff00ff00ff);\n  x=(x&0x0000ffff0000ffff)+((x>>16)&0x0000ffff0000ffff);\n\
    \  return (x&0x00000000ffffffff)+((x>>32)&0x00000000ffffffff);\n}\ntemplate<typename\
    \ T,typename U>\ninline constexpr bool chmin(T&a,U b){return a>b&&(a=b,true);}\n\
    template<typename T,typename U>\ninline constexpr bool chmax(T&a,U b){return a<b&&(a=b,true);}\n\
    inline constexpr ll gcd(ll a,ll b){\n  if(a<0)a=-a;\n  if(b<0)b=-b;\n  while(b){\n\
    \    const ll c=b;\n    b=a%b;\n    a=c;\n  }\n  return a;\n}\ninline constexpr\
    \ ll lcm(ll a,ll b){return a/gcd(a,b)*b;}\ninline constexpr bool is_prime(ll n){\n\
    \  if(n<=1)return false;\n  for(ll i=2;i*i<=n;i++){\n    if(n%i==0)return false;\n\
    \  }\n  return true;\n}\ninline constexpr ll my_pow(ll a,ll b){\n  ll res=1;\n\
    \  while(b){\n    if(b&1)res*=a;\n    a*=a;\n    b>>=1;\n  }\n  return res;\n\
    }\ninline constexpr ll mod_pow(ll a,ll b,const ll&mod){\n  if(mod==1)return 0;\n\
    \  a%=mod;\n  ll res=1;\n  while(b){\n    if(b&1)(res*=a)%=mod;\n    (a*=a)%=mod;\n\
    \    b>>=1;\n  }\n  return res;\n}\ninline ll mod_inv(ll a,const ll&mod){\n  ll\
    \ b=mod,x=1,u=0,t;\n  while(b){\n    t=a/b;\n    std::swap(a-=t*b,b);\n    std::swap(x-=t*u,u);\n\
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
    \ T&t,std::enable_if_t<std::is_integral<T>::value>* =nullptr){std::string tmp;if(t==infinity<T>::value||t==infinity<T>::max)tmp=\"\
    inf\";if(std::is_signed<T>::value&&(t==infinity<T>::mvalue||t==infinity<T>::min))tmp=\"\
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
    \ 9 \"template/template.hpp\"\nusing namespace std;\n#line 3 \"others/random.hpp\"\
    \n\ntemplate<typename Engine>\nstruct Random{\n  private:\n  Engine rnd;\n  public:\n\
    \  using result_type=typename Engine::result_type;\n  Random():Random(random_device{}()){}\n\
    \  Random(result_type seed):rnd(seed){}\n  result_type operator()(){return rnd();}\n\
    \  template<typename IntType=ll>\n  IntType uniform(IntType l,IntType r){\n  \
    \  static_assert(is_integral<IntType>::value,\"template argument must be an integral\
    \ type\");\n    return uniform_int_distribution<IntType>{l,r}(rnd);\n  }\n  template<typename\
    \ RealType=double>\n  RealType uniform_real(RealType l,RealType r){\n    static_assert(is_floating_point<RealType>::value,\"\
    template argument must be a floating point type\");\n    return uniform_real_distribution<RealType>{l,r}(rnd);\n\
    \  }\n  bool uniform_bool(){return uniform<int>(0,1);}\n  template<typename T=ll>\n\
    \  pair<T,T> uniform_pair(T l,T r){\n    T a,b;\n    do{\n      a=uniform<T>(l,r);\n\
    \      b=uniform<T>(l,r);\n    }while(a==b);\n    if(a>b)swap(a,b);\n    return\
    \ {a,b};\n  }\n  template<typename Iter>\n  void shuffle(const Iter&first,const\
    \ Iter&last){\n    shuffle(first,last,rnd);\n  }\n  template<class T>\n  vector<T>permutalion(T\
    \ n){\n    static_assert(is_integral<T>::value,\"template argument must be an\
    \ integral type\");\n    vector<T>res(n);\n    iota(res.begin(),res.end(),T());\n\
    \    shuffle(all(res));\n    return res;\n  }\n};\nusing Random32=Random<mt19937>;\n\
    using Random64=Random<mt19937_64>;\nRandom32 rand32;\nRandom64 rand64;\n/**\n\
    \ * @brief Random(\u4E71\u6570)\n*/\n#line 3 \"math/modular/montgomery-modint.hpp\"\
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
    )\n*/\n#line 3 \"string/run-length.hpp\"\n\ntemplate<typename Cont,typename Cmp>\n\
    vector<pair<typename Cont::value_type,int>>run_length(const Cont&c,const Cmp&cmp){\n\
    \  vector<pair<typename Cont::value_type,int>> ret;\n  if(c.empty())return ret;\n\
    \  ret.emplace_back(c.front(),1);\n  for(int i=1;i<(int)c.size();i++){\n    if(cmp(c[i],ret.back().first)){\n\
    \      ret.back().second++;\n    }else{\n      ret.emplace_back(c[i],1);\n   \
    \ }\n  }\n  return ret;\n}\ntemplate<typename Cont>vector<pair<typename Cont::value_type,int>>run_length(const\
    \ Cont&c){return run_length(c,equal_to<typename Cont::value_type>());}\n#line\
    \ 7 \"math/number/pollard-rho.hpp\"\n\ntemplate<typename T,typename Rand>\null\
    \ pollard_rho(ull n,Rand&rand){\n  if(~n&1)return 2;\n  if(T::get_mod()!=n)T::set_mod(n);\n\
    \  T c,e=1;\n  auto f=[&](T x)->T {return x*x+c;};\n  constexpr int m=128;\n \
    \ while(1){\n    c=rand.uniform(1ull,n-1);\n    T x=rand.uniform(2ull,n-1),y=x;\n\
    \    ull g=1;\n    while(g==1){\n      T p=e,tx=x,ty=y;\n      rep(i,m){\n   \
    \     x=f(x);\n        y=f(f(y));\n        p*=x-y;\n      }\n      g=gcd(p.get(),n);\n\
    \      if(g==1)continue;\n      rep(i,m){\n        tx=f(tx);\n        ty=f(f(ty));\n\
    \        g=gcd((tx-ty).get(),n);\n        if(g!=1){\n          if(g!=n)return\
    \ g;\n          break;\n        }\n      }\n    }\n  }\n  return -1;\n}\ntemplate<typename\
    \ T=MontgomeryModInt<ull,-3>,typename Rand=Random64>\nvector<ull>factorize(ull\
    \ n,Rand&rand=rand64){\n  if(n==1)return {};\n  vector<ull>res;\n  vector<ull>st={n};\n\
    \  while(!st.empty()){\n    ull t=st.back();\n    st.pop_back();\n    if(t==1)continue;\n\
    \    if(is_prime_fast(t)){\n      res.push_back(t);\n      continue;\n    }\n\
    \    ull p=pollard_rho<T>(t,rand);\n    st.push_back(p);\n    st.push_back(t/p);\n\
    \  }\n  sort(all(res));\n  return res;\n}\ntemplate<typename T=MontgomeryModInt<ull,-3>,typename\
    \ Rand=Random64>\nvector<pair<ull,int>>expfactorize(ull n,Rand&rand=rand64){\n\
    \  auto res=factorize<T>(n,rand);\n  return run_length(res);\n}\n/**\n * @brief\
    \ Pollard's Rho Factorization(\u30DD\u30E9\u30FC\u30C9\u30FB\u30ED\u30FC\u6CD5\
    )\n*/\n#line 4 \"test/yosupo/math/factorize.test.cpp\"\nint main(){\n  int q;\n\
    \  cin>>q;\n  while(q--){\n    long long x;\n    cin>>x;\n    auto ret=factorize(x);\n\
    \    print(ret.size(),ret);\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n#include\"\
    ../../../template/template.hpp\"\n#include\"../../../math/number/pollard-rho.hpp\"\
    \nint main(){\n  int q;\n  cin>>q;\n  while(q--){\n    long long x;\n    cin>>x;\n\
    \    auto ret=factorize(x);\n    print(ret.size(),ret);\n  }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - template/type-traits.hpp
  - math/number/pollard-rho.hpp
  - others/random.hpp
  - math/modular/montgomery-modint.hpp
  - math/number/miller-rabin.hpp
  - string/run-length.hpp
  isVerificationFile: true
  path: test/yosupo/math/factorize.test.cpp
  requiredBy: []
  timestamp: '2022-12-25 17:16:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/math/factorize.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/math/factorize.test.cpp
- /verify/test/yosupo/math/factorize.test.cpp.html
title: test/yosupo/math/factorize.test.cpp
---
