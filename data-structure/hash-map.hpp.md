---
data:
  _extendedDependsOn:
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
  - icon: ':heavy_check_mark:'
    path: math/modular/mod-log.hpp
    title: "Mod Log(\u96E2\u6563\u5BFE\u6570)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/data_strucuture/associative_array.test.cpp
    title: test/yosupo/data_strucuture/associative_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/math/discrete-logarithm-mod.test.cpp
    title: test/yosupo/math/discrete-logarithm-mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "HashMap(\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7)"
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
    \ Comp&cmp=Comp()):data(std::move(dat)),cmp(cmp){}\n  compressor(std::initializer_list<T>li,const\
    \ Comp&cmp=Comp()):data(li.begin(),li.end()),cmp(cmp){}\n  void push_back(const\
    \ T&v){assert(!sorted);data.push_back(v);}\n  void push_back(T&&v){assert(!sorted);data.push_back(std::move(v));}\n\
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
    \ 9 \"template/template.hpp\"\nusing namespace std;\n#line 3 \"data-structure/hash-map.hpp\"\
    \n\ntemplate<typename Key,typename Val>\nstruct HashMap{\n  using u32=uint32_t;\n\
    \  using u64=uint64_t;\n  using Data=pair<Key,Val>;\n  protected:\n  template\
    \ <typename K>\n  inline u64 randomized(const K&key)const{\n    return u64(key)^r;\n\
    \  }\n  template<typename K,enable_if_t<is_integral<K>::value,nullptr_t> = nullptr>\n\
    \  inline u64 inner_hash(const K&key)const{\n    return (randomized(key)*11995408973635179863ULL);\n\
    \  }\n  template<typename K,enable_if_t<is_integral<decltype(K::first)>::value,nullptr_t>\
    \ = nullptr,enable_if_t<is_integral<decltype(K::second)>::value,nullptr_t> = nullptr>\n\
    \  inline u64 inner_hash(const K&key)const{\n    u64 a=randomized(key.first),b=randomized(key.second);\n\
    \    a*=11995408973635179863ULL;\n    b*=10150724397891781847ULL;\n    return\
    \ (a+b);\n  }\n  template <typename K,enable_if_t<is_integral<typename K::value_type>::value,nullptr_t>\
    \ = nullptr>\n  inline u64 inner_hash(const K&key)const{\n    static constexpr\
    \ u64 mod=(1LL << 61)-1;\n    static constexpr u64 base=950699498548472943ULL;\n\
    \    u64 res=0;\n    for(auto&elem:key) {\n      __uint128_t x=__uint128_t(res)*base+(randomized(elem)&mod);\n\
    \      res=(x&mod)+(x>>61);\n    }\n    __uint128_t x=__uint128_t(res)*base;\n\
    \    res=(x&mod)+(x >> 61);\n    if(res>=mod)res-=mod;\n    return (res<<3);\n\
    \  }\n  inline u32 hash(const Key&key)const{\n    return inner_hash(key)>>shift;\n\
    \  }\n  void reallocate(u32 new_cap){\n    vector<Data>new_data(new_cap);\n  \
    \  vector<bool>new_flag(new_cap,false);\n    shift=64-__lg(new_cap);\n    for(u32\
    \ i=0;i<cap;i++){\n      if(flag[i]&&!dflag[i]){\n        u32 h=hash(data[i].first);\n\
    \        while(new_flag[h])h=(h+1)&(new_cap-1);\n        new_data[h]=move(data[i]);\n\
    \        new_flag[h]=true;\n      }\n    }\n    data.swap(new_data);\n    flag.swap(new_flag);\n\
    \    cap=new_cap;\n    dflag.resize(cap);\n    fill(dflag.begin(),dflag.end(),false);\n\
    \  }\n  inline bool should_extend(u32 x)const{return x*2>=cap;}\n  inline bool\
    \ should_shrink(u32 x)const{return 4<cap&&x*10<=cap;}\n  inline void extend(){reallocate(cap<<1);}\n\
    \  inline void shrink(){reallocate(cap>>1);}\n  public:\n  u32 cap,s;\n  vector<Data>data;\n\
    \  vector<bool>flag,dflag;\n  u32 shift;\n  static u64 r;\n  static constexpr\
    \ uint32_t DEFAULT_SIZE=4;\n  struct iterator{\n    u32 i;\n    HashMap<Key,Val>*p;\n\
    \    explicit constexpr iterator():i(0),p(nullptr){}\n    explicit constexpr iterator(u32\
    \ i,HashMap<Key,Val>*p):i(i),p(p){}\n    explicit constexpr iterator(u32 i,const\
    \ HashMap<Key,Val>*p):i(i),p(const_cast<HashMap<Key,Val>*>(p)){}\n    const Data&\
    \ operator*()const{\n      return const_cast<HashMap<Key,Val>*>(p)->data[i];\n\
    \    }\n    Data& operator*(){return p->data[i];}\n    Data* operator->(){return\
    \ &(p->data[i]);}\n    friend void swap(iterator&a,iterator&b){swap(a.i,b.i);swap(a.p,b.p);}\n\
    \    friend bool operator==(const iterator&a,const iterator&b){return a.i==b.i;}\n\
    \    friend bool operator!=(const iterator&a,const iterator&b){return a.i!=b.i;}\n\
    \    iterator& operator++(){\n      assert(i!=p->cap&&\"iterator overflow\");\n\
    \      do{\n        i++;\n        if(i==p->cap)break;\n        if(p->flag[i]&&!(p->dflag[i]))break;\n\
    \      }while(true);\n      return *this;\n    } \n    iterator operator++(int){\n\
    \      iterator tmp(*this);\n      ++(*this);\n      return tmp;\n    }\n    iterator&\
    \ operator--(){\n      do{\n        i--;\n        if(p->flag[i]&&!(p->dflag[i]))break;\n\
    \        assert(i!=0&&\"iterator underflow\");\n      }while(true);\n      return\
    \ *this;\n    }\n    iterator operator--(int){\n      iterator tmp(*this);\n \
    \     --(*this);\n      return tmp;\n    }\n  };\n  using itr=iterator;\n  explicit\
    \ HashMap():cap(DEFAULT_SIZE),s(0),data(cap),flag(cap),dflag(cap),shift(62){}\n\
    \  itr begin()const{\n    u32 h=0;\n    while(h!=cap){\n      if(flag[h]&&!dflag[h])break;\n\
    \      h++;\n    }\n    return itr(h,this);\n  }\n  itr end()const{return itr(this->cap,this);}\
    \    \n  friend itr begin(HashMap<Key,Val>&a){return a.begin();}\n  friend itr\
    \ end(HashMap<Key,Val>&a){return a.end();}\n  itr find(const Key&key)const{\n\
    \    u32 h=hash(key);\n    while(true){\n      if(!flag[h])return this->end();\n\
    \      if(data[h].first==key){\n        if(dflag[h])return this->end();\n    \
    \    return itr(h,this);\n      }\n      h=(h+1)&(cap-1);\n    }\n  }\n  bool\
    \ contain(const Key&key)const{return find(key)!=this->end();}\n  int count(const\
    \ Key&key)const{return int(find(key)!=this->end());}\n  itr insert(const Data&d){\n\
    \    u32 h=hash(d.first);\n    while(true){\n      if(!flag[h]){\n        if(should_extend(s+1)){\n\
    \          extend();\n          h=hash(d.first);\n          continue;\n      \
    \  }\n        data[h]=d;\n        flag[h]=true;\n        s++;\n        return\
    \ itr(h,this);\n      }\n      if(data[h].first==d.first){\n        if(dflag[h]){\n\
    \          data[h]=d;\n          dflag[h]=false;\n          s++;\n        }\n\
    \        return itr(h,this);\n      }\n      h=(h+1)&(cap-1);\n    }\n  }\n  bool\
    \ erase(itr it){\n    if(it==this->end())return false;\n    s--;\n    if(should_shrink(s)){\n\
    \      Data d=data[it.i];\n      shrink();\n      it=find(d.first);\n    }\n \
    \   int ni=(it.i+1)&(cap-1);\n    if(flag[ni]){\n      dflag[it.i]=true;\n   \
    \ }\n    else{\n      flag[it.i]=false;\n    }\n    return true;\n  }\n  bool\
    \ erase(const Key&key){return erase(find(key));}\n  bool empty()const{return s==0;}\n\
    \  u32 size()const{return s;}\n  void clear(){\n    s=0;\n    fill(flag.begin(),flag.end(),false);\n\
    \    fill(dflag.begin(),dflag.end(),false);\n  }\n  void reserve(int n){\n   \
    \ if(n<=0)return;\n    n=1<<(__lg(n)+2);\n    if(cap<u32(n))reallocate(n);\n \
    \ }\n  Val& operator[](const Key&key){\n    u32 h=hash(key);\n    while(true){\n\
    \      if(!flag[h]){\n        if(should_extend(s+1)){\n          extend();\n \
    \         h=hash(key);\n          continue;\n        }\n        data[h]=Data(key,Val());\n\
    \        flag[h]=true;\n        s++;\n        return data[h].second;\n      }\n\
    \      if(data[h].first==key){\n        if(dflag[h])data[h].second=Val();\n  \
    \      return data[h].second;\n      }\n      h=(h+1)&(cap-1);\n    }\n  }\n \
    \ bool emplace(const Key&key,const Val&val){\n    return insert(Data(key,val));\n\
    \  }\n};\ntemplate<typename Key,typename Val>uint64_t HashMap<Key,Val>::r=chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count();\n\
    /**\n * @brief HashMap(\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7)\n*/\n"
  code: "#pragma once\n#include\"../template/template.hpp\"\n\ntemplate<typename Key,typename\
    \ Val>\nstruct HashMap{\n  using u32=uint32_t;\n  using u64=uint64_t;\n  using\
    \ Data=pair<Key,Val>;\n  protected:\n  template <typename K>\n  inline u64 randomized(const\
    \ K&key)const{\n    return u64(key)^r;\n  }\n  template<typename K,enable_if_t<is_integral<K>::value,nullptr_t>\
    \ = nullptr>\n  inline u64 inner_hash(const K&key)const{\n    return (randomized(key)*11995408973635179863ULL);\n\
    \  }\n  template<typename K,enable_if_t<is_integral<decltype(K::first)>::value,nullptr_t>\
    \ = nullptr,enable_if_t<is_integral<decltype(K::second)>::value,nullptr_t> = nullptr>\n\
    \  inline u64 inner_hash(const K&key)const{\n    u64 a=randomized(key.first),b=randomized(key.second);\n\
    \    a*=11995408973635179863ULL;\n    b*=10150724397891781847ULL;\n    return\
    \ (a+b);\n  }\n  template <typename K,enable_if_t<is_integral<typename K::value_type>::value,nullptr_t>\
    \ = nullptr>\n  inline u64 inner_hash(const K&key)const{\n    static constexpr\
    \ u64 mod=(1LL << 61)-1;\n    static constexpr u64 base=950699498548472943ULL;\n\
    \    u64 res=0;\n    for(auto&elem:key) {\n      __uint128_t x=__uint128_t(res)*base+(randomized(elem)&mod);\n\
    \      res=(x&mod)+(x>>61);\n    }\n    __uint128_t x=__uint128_t(res)*base;\n\
    \    res=(x&mod)+(x >> 61);\n    if(res>=mod)res-=mod;\n    return (res<<3);\n\
    \  }\n  inline u32 hash(const Key&key)const{\n    return inner_hash(key)>>shift;\n\
    \  }\n  void reallocate(u32 new_cap){\n    vector<Data>new_data(new_cap);\n  \
    \  vector<bool>new_flag(new_cap,false);\n    shift=64-__lg(new_cap);\n    for(u32\
    \ i=0;i<cap;i++){\n      if(flag[i]&&!dflag[i]){\n        u32 h=hash(data[i].first);\n\
    \        while(new_flag[h])h=(h+1)&(new_cap-1);\n        new_data[h]=move(data[i]);\n\
    \        new_flag[h]=true;\n      }\n    }\n    data.swap(new_data);\n    flag.swap(new_flag);\n\
    \    cap=new_cap;\n    dflag.resize(cap);\n    fill(dflag.begin(),dflag.end(),false);\n\
    \  }\n  inline bool should_extend(u32 x)const{return x*2>=cap;}\n  inline bool\
    \ should_shrink(u32 x)const{return 4<cap&&x*10<=cap;}\n  inline void extend(){reallocate(cap<<1);}\n\
    \  inline void shrink(){reallocate(cap>>1);}\n  public:\n  u32 cap,s;\n  vector<Data>data;\n\
    \  vector<bool>flag,dflag;\n  u32 shift;\n  static u64 r;\n  static constexpr\
    \ uint32_t DEFAULT_SIZE=4;\n  struct iterator{\n    u32 i;\n    HashMap<Key,Val>*p;\n\
    \    explicit constexpr iterator():i(0),p(nullptr){}\n    explicit constexpr iterator(u32\
    \ i,HashMap<Key,Val>*p):i(i),p(p){}\n    explicit constexpr iterator(u32 i,const\
    \ HashMap<Key,Val>*p):i(i),p(const_cast<HashMap<Key,Val>*>(p)){}\n    const Data&\
    \ operator*()const{\n      return const_cast<HashMap<Key,Val>*>(p)->data[i];\n\
    \    }\n    Data& operator*(){return p->data[i];}\n    Data* operator->(){return\
    \ &(p->data[i]);}\n    friend void swap(iterator&a,iterator&b){swap(a.i,b.i);swap(a.p,b.p);}\n\
    \    friend bool operator==(const iterator&a,const iterator&b){return a.i==b.i;}\n\
    \    friend bool operator!=(const iterator&a,const iterator&b){return a.i!=b.i;}\n\
    \    iterator& operator++(){\n      assert(i!=p->cap&&\"iterator overflow\");\n\
    \      do{\n        i++;\n        if(i==p->cap)break;\n        if(p->flag[i]&&!(p->dflag[i]))break;\n\
    \      }while(true);\n      return *this;\n    } \n    iterator operator++(int){\n\
    \      iterator tmp(*this);\n      ++(*this);\n      return tmp;\n    }\n    iterator&\
    \ operator--(){\n      do{\n        i--;\n        if(p->flag[i]&&!(p->dflag[i]))break;\n\
    \        assert(i!=0&&\"iterator underflow\");\n      }while(true);\n      return\
    \ *this;\n    }\n    iterator operator--(int){\n      iterator tmp(*this);\n \
    \     --(*this);\n      return tmp;\n    }\n  };\n  using itr=iterator;\n  explicit\
    \ HashMap():cap(DEFAULT_SIZE),s(0),data(cap),flag(cap),dflag(cap),shift(62){}\n\
    \  itr begin()const{\n    u32 h=0;\n    while(h!=cap){\n      if(flag[h]&&!dflag[h])break;\n\
    \      h++;\n    }\n    return itr(h,this);\n  }\n  itr end()const{return itr(this->cap,this);}\
    \    \n  friend itr begin(HashMap<Key,Val>&a){return a.begin();}\n  friend itr\
    \ end(HashMap<Key,Val>&a){return a.end();}\n  itr find(const Key&key)const{\n\
    \    u32 h=hash(key);\n    while(true){\n      if(!flag[h])return this->end();\n\
    \      if(data[h].first==key){\n        if(dflag[h])return this->end();\n    \
    \    return itr(h,this);\n      }\n      h=(h+1)&(cap-1);\n    }\n  }\n  bool\
    \ contain(const Key&key)const{return find(key)!=this->end();}\n  int count(const\
    \ Key&key)const{return int(find(key)!=this->end());}\n  itr insert(const Data&d){\n\
    \    u32 h=hash(d.first);\n    while(true){\n      if(!flag[h]){\n        if(should_extend(s+1)){\n\
    \          extend();\n          h=hash(d.first);\n          continue;\n      \
    \  }\n        data[h]=d;\n        flag[h]=true;\n        s++;\n        return\
    \ itr(h,this);\n      }\n      if(data[h].first==d.first){\n        if(dflag[h]){\n\
    \          data[h]=d;\n          dflag[h]=false;\n          s++;\n        }\n\
    \        return itr(h,this);\n      }\n      h=(h+1)&(cap-1);\n    }\n  }\n  bool\
    \ erase(itr it){\n    if(it==this->end())return false;\n    s--;\n    if(should_shrink(s)){\n\
    \      Data d=data[it.i];\n      shrink();\n      it=find(d.first);\n    }\n \
    \   int ni=(it.i+1)&(cap-1);\n    if(flag[ni]){\n      dflag[it.i]=true;\n   \
    \ }\n    else{\n      flag[it.i]=false;\n    }\n    return true;\n  }\n  bool\
    \ erase(const Key&key){return erase(find(key));}\n  bool empty()const{return s==0;}\n\
    \  u32 size()const{return s;}\n  void clear(){\n    s=0;\n    fill(flag.begin(),flag.end(),false);\n\
    \    fill(dflag.begin(),dflag.end(),false);\n  }\n  void reserve(int n){\n   \
    \ if(n<=0)return;\n    n=1<<(__lg(n)+2);\n    if(cap<u32(n))reallocate(n);\n \
    \ }\n  Val& operator[](const Key&key){\n    u32 h=hash(key);\n    while(true){\n\
    \      if(!flag[h]){\n        if(should_extend(s+1)){\n          extend();\n \
    \         h=hash(key);\n          continue;\n        }\n        data[h]=Data(key,Val());\n\
    \        flag[h]=true;\n        s++;\n        return data[h].second;\n      }\n\
    \      if(data[h].first==key){\n        if(dflag[h])data[h].second=Val();\n  \
    \      return data[h].second;\n      }\n      h=(h+1)&(cap-1);\n    }\n  }\n \
    \ bool emplace(const Key&key,const Val&val){\n    return insert(Data(key,val));\n\
    \  }\n};\ntemplate<typename Key,typename Val>uint64_t HashMap<Key,Val>::r=chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count();\n\
    /**\n * @brief HashMap(\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7)\n*/"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - template/type-traits.hpp
  isVerificationFile: false
  path: data-structure/hash-map.hpp
  requiredBy:
  - math/modular/mod-log.hpp
  timestamp: '2023-01-18 00:28:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/math/discrete-logarithm-mod.test.cpp
  - test/yosupo/data_strucuture/associative_array.test.cpp
documentation_of: data-structure/hash-map.hpp
layout: document
redirect_from:
- /library/data-structure/hash-map.hpp
- /library/data-structure/hash-map.hpp.html
title: "HashMap(\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7)"
---
