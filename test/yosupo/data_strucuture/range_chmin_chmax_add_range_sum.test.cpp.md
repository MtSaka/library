---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree-beats.hpp
    title: Segment Tree Beats!(Rnage Chmin Chmax Add Update Range Sum Min Max)
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
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"test/yosupo/data_strucuture/range_chmin_chmax_add_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#line 2 \"template/template.hpp\"\n#include<bits/stdc++.h>\n#line 3 \"template/macro.hpp\"\
    \n\n#define SELECT4(a,b,c,d,e,...) e\n#define SELECT3(a,b,c,d,...) d\n#define\
    \ REP1(a) for(ll i=0;i<(ll)(a);++i)\n#define REP2(i,a) for(ll i=0;i<(ll)(a);++i)\n\
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
    \ 9 \"template/template.hpp\"\nusing namespace std;\n#line 3 \"data-structure/segment-tree-beats.hpp\"\
    \n\ntemplate<class T>\nstruct SegmentTreeBeats{\n  private:\n  static constexpr\
    \ T INF=numeric_limits<T>::max();\n  struct S{\n    T sum=0,b1=0,s1=0,b2=-INF,s2=INF,b_cnt=1,s_cnt=1,add=0;\n\
    \    S(){}\n    S(const T&a):sum(a),b1(a),s1(a){}\n  };\n  vector<S>seq;\n  int\
    \ size=1,idx=0;\n  void update(int k){\n    S&s=seq[k];\n    S&l=seq[2*k];\n \
    \   S&r=seq[2*k+1];\n    s.sum=l.sum+r.sum;\n    if(l.b1==r.b1){\n      s.b1=l.b1;\n\
    \      s.b2=max(l.b2,r.b2);\n      s.b_cnt=l.b_cnt+r.b_cnt;\n    }\n    else{\n\
    \      s.b1=max(l.b1,r.b1);\n      s.b2=max(l.b1>r.b1?l.b2:l.b1,l.b1>r.b1?r.b1:r.b2);\n\
    \      s.b_cnt=l.b1>r.b1?l.b_cnt:r.b_cnt;\n    }\n    if(l.s1==r.s1){\n      s.s1=l.s1;\n\
    \      s.s2=min(l.s2,r.s2);\n      s.s_cnt=l.s_cnt+r.s_cnt;\n    }\n    else{\n\
    \      s.s1=min(l.s1,r.s1);\n      s.s2=min(l.s1>r.s1?l.s1:l.s2,l.s1>r.s1?r.s2:r.s1);\n\
    \      s.s_cnt=l.s1>r.s1?r.s_cnt:l.s_cnt;\n    }\n  }\n  void eval_add(int k,T\
    \ x){\n    S&s=seq[k];\n    s.sum+=x<<(idx+__builtin_clz(k)-31);\n    s.b1+=x,s.s1+=x;\n\
    \    if(s.b2!=-INF)s.b2+=x;\n    if(s.s2!=INF)s.s2+=x;\n    s.add+=x;\n  }\n \
    \ void eval_min(int k,T x){\n    S&s=seq[k];\n    s.sum+=(x-s.b1)*s.b_cnt;\n \
    \   if(s.s1==s.b1)s.s1=x;\n    if(s.s2==s.b1)s.s2=x;\n    s.b1=x;\n  }\n  void\
    \ eval_max(int k,T x){\n    S&s=seq[k];\n    s.sum+=(x-s.s1)*s.s_cnt;\n    if(s.b1==s.s1)s.b1=x;\n\
    \    if(s.b2==s.s1)s.b2=x;\n    s.s1=x;\n  }\n  void eval(int k){\n    S&s=seq[k];\n\
    \    if(s.add!=0){\n      eval_add(k*2,s.add);\n      eval_add(k*2+1,s.add);\n\
    \      s.add=0;\n    }\n    if(s.b1<seq[2*k].b1)eval_min(2*k,s.b1);\n    if(s.s1>seq[2*k].s1)eval_max(2*k,s.s1);\n\
    \    if(s.b1<seq[2*k+1].b1)eval_min(2*k+1,s.b1);\n    if(s.s1>seq[2*k+1].s1)eval_max(2*k+1,s.s1);\n\
    \  }\n  void apply_min(int k,T x){\n    if(seq[k].b1<=x)return;\n    if(seq[k].b2<x){\n\
    \      eval_min(k,x);\n      return;\n    }\n    eval(k);\n    apply_min(2*k,x);\n\
    \    apply_min(2*k+1,x);\n    update(k);\n  }\n  void apply_max(int k,T x){\n\
    \    if(seq[k].s1>=x)return;\n    if(seq[k].s2>x){\n      eval_max(k,x);\n   \
    \   return;\n    }\n    eval(k);\n    apply_max(2*k,x);\n    apply_max(2*k+1,x);\n\
    \    update(k);\n  }\n  void inner_chmin(int l,int r,T x){\n    if(l==r)return;\n\
    \    l+=size,r+=size;\n    for(int i=idx;i>=1;i--){\n      if(((l>>i)<<i)!=l)eval(l>>i);\n\
    \      if(((r>>i)<<i)!=r)eval(r>>i);\n    }\n    int l2=l,r2=r;\n    while(l<r){\n\
    \      if(l&1)apply_min(l++,x);\n      if(r&1)apply_min(--r,x);\n      l>>=1;\n\
    \      r>>=1;\n    }\n    l=l2,r=r2;\n    for(int i=1;i<=idx;i++){\n      if(((l>>i)<<i)!=l)update(l>>i);\n\
    \      if(((r>>i)<<i)!=r)update(r>>i);\n    }\n  }\n  void inner_chmax(int l,int\
    \ r,T x){\n    if(l==r)return;\n    l+=size,r+=size;\n    for(int i=idx;i>=1;i--){\n\
    \      if(((l>>i)<<i)!=l)eval(l>>i);\n      if(((r>>i)<<i)!=r)eval(r>>i);\n  \
    \  }\n    int l2=l,r2=r;\n    while(l<r){\n      if(l&1)apply_max(l++,x);\n  \
    \    if(r&1)apply_max(--r,x);\n      l>>=1;\n      r>>=1;\n    }\n    l=l2,r=r2;\n\
    \    for(int i=1;i<=idx;i++){\n      if(((l>>i)<<i)!=l)update(l>>i);\n      if(((r>>i)<<i)!=r)update(r>>i);\n\
    \    }\n  }\n  void inner_add(int l,int r,T x){\n    if(l==r)return;\n    l+=size,r+=size;\n\
    \    for(int i=idx;i>=1;i--){\n      if(((l>>i)<<i)!=l)eval(l>>i);\n      if(((r>>i)<<i)!=r)eval(r>>i);\n\
    \    }\n    int l2=l,r2=r;\n    while(l<r){\n      if(l&1)eval_add(l++,x);\n \
    \     if(r&1)eval_add(--r,x);\n      l>>=1;\n      r>>=1;\n    }\n    l=l2,r=r2;\n\
    \    for(int i=1;i<=idx;i++){\n      if(((l>>i)<<i)!=l)update(l>>i);\n      if(((r>>i)<<i)!=r)update(r>>i);\n\
    \    }\n  }\n  void inner_update(int l,int r,T x){\n    if(l==r)return;\n    l+=size,r+=size;\n\
    \    for(int i=idx;i>=1;i--){\n      if(((l>>i)<<i)!=l)eval(l>>i);\n      if(((r>>i)<<i)!=r)eval(r>>i);\n\
    \    }\n    int l2=l,r2=r;\n    while(l<r){\n      if(l&1)apply_min(l++,x),apply_max(l,x);\n\
    \      if(r&1)apply_min(--r,x),apply_max(r,x);\n      l>>=1;\n      r>>=1;\n \
    \   }\n    l=l2,r=r2;\n    for(int i=1;i<=idx;i++){\n      if(((l>>i)<<i)!=l)update(l>>i);\n\
    \      if(((r>>i)<<i)!=r)update(r>>i);\n    }\n  }\n  T inner_min(int l,int r){\n\
    \    if(l==r)return INF;\n    T sml=INF,smr=INF;\n    l+=size,r+=size;\n    for(int\
    \ i=idx;i>=1;i--){\n      if(((l>>i)<<i)!=l)eval(l>>i);\n      if(((r>>i)<<i)!=r)eval(r>>i);\n\
    \    }\n    while(l<r){\n      if(l&1)sml=min(sml,seq[l++].s1);\n      if(r&1)smr=min(seq[--r].s1,smr);\n\
    \      l>>=1,r>>=1;\n    }\n    return min(sml,smr);\n  }\n  T inner_max(int l,int\
    \ r){\n    if(l==r)return -INF;\n    T sml=-INF,smr=-INF;\n    l+=size,r+=size;\n\
    \    for(int i=idx;i>=1;i--){\n      if(((l>>i)<<i)!=l)eval(l>>i);\n      if(((r>>i)<<i)!=r)eval(r>>i);\n\
    \    }\n    while(l<r){\n      if(l&1)sml=max(sml,seq[l++].b1);\n      if(r&1)smr=max(seq[--r].b1,smr);\n\
    \      l>>=1,r>>=1;\n    }\n    return max(sml,smr);\n  }\n  T inner_sum(int l,int\
    \ r){\n    if(l==r)return 0;\n    T sml=0,smr=0;\n    l+=size,r+=size;\n    for(int\
    \ i=idx;i>=1;i--){\n      if(((l>>i)<<i)!=l)eval(l>>i);\n      if(((r>>i)<<i)!=r)eval(r>>i);\n\
    \    }\n    while(l<r){\n      if(l&1)sml+=seq[l++].sum;\n      if(r&1)smr+=seq[--r].sum;\n\
    \      l>>=1,r>>=1;\n    }\n    return sml+smr;\n  }\n  public:\n  SegmentTreeBeats(){}\n\
    \  SegmentTreeBeats(int n):SegmentTreeBeats(vector<T>(n)){}\n  SegmentTreeBeats(const\
    \ vector<T>&v){\n    const int n=v.size();\n    while(size<n)size<<=1,idx++;\n\
    \    seq.resize(2*size);\n    for(int i=0;i<n;i++)seq[i+size]=v[i];\n    for(int\
    \ i=size-1;i;i--)update(i);\n  }\n  void range_chmin(int l,int r,T x){inner_chmin(l,r,x);}\n\
    \  void range_chmax(int l,int r,T x){inner_chmax(l,r,x);}\n  void range_add(int\
    \ l,int r,T x){inner_add(l,r,x);}\n  void range_update(int l,int r,T x){inner_update(l,r,x);}\n\
    \  T range_min(int l,int r){return inner_min(l,r);}\n  T range_max(int l,int r){return\
    \ inner_max(l,r);}\n  T range_sum(int l,int r){return inner_sum(l,r);}\n};\n/**\n\
    \ * @brief Segment Tree Beats!(Rnage Chmin Chmax Add Update Range Sum Min Max)\n\
    */\n#line 4 \"test/yosupo/data_strucuture/range_chmin_chmax_add_range_sum.test.cpp\"\
    \nint main(){\n  int n,q;cin>>n>>q;\n  vl a(n);cin>>a;\n  SegmentTreeBeats<ll>seg(a);\n\
    \  while(q--){\n    int t;cin>>t;\n    if(t==0){\n      int l,r;ll x;\n      cin>>l>>r>>x;\n\
    \      seg.range_chmin(l,r,x);\n    }\n    else if(t==1){\n      int l,r;ll x;\n\
    \      cin>>l>>r>>x;\n      seg.range_chmax(l,r,x);\n    }\n    else if(t==2){\n\
    \      int l,r;ll x;\n      cin>>l>>r>>x;\n      seg.range_add(l,r,x);\n    }\n\
    \    else{\n      int l,r;cin>>l>>r;\n      print(seg.range_sum(l,r));\n    }\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#include\"../../../template/template.hpp\"\n#include\"../../../data-structure/segment-tree-beats.hpp\"\
    \nint main(){\n  int n,q;cin>>n>>q;\n  vl a(n);cin>>a;\n  SegmentTreeBeats<ll>seg(a);\n\
    \  while(q--){\n    int t;cin>>t;\n    if(t==0){\n      int l,r;ll x;\n      cin>>l>>r>>x;\n\
    \      seg.range_chmin(l,r,x);\n    }\n    else if(t==1){\n      int l,r;ll x;\n\
    \      cin>>l>>r>>x;\n      seg.range_chmax(l,r,x);\n    }\n    else if(t==2){\n\
    \      int l,r;ll x;\n      cin>>l>>r>>x;\n      seg.range_add(l,r,x);\n    }\n\
    \    else{\n      int l,r;cin>>l>>r;\n      print(seg.range_sum(l,r));\n    }\n\
    \  }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - template/type-traits.hpp
  - data-structure/segment-tree-beats.hpp
  isVerificationFile: true
  path: test/yosupo/data_strucuture/range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2023-01-18 00:28:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/data_strucuture/range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/data_strucuture/range_chmin_chmax_add_range_sum.test.cpp
- /verify/test/yosupo/data_strucuture/range_chmin_chmax_add_range_sum.test.cpp.html
title: test/yosupo/data_strucuture/range_chmin_chmax_add_range_sum.test.cpp
---
