---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/sparse-table.hpp
    title: Sparse Table
  - icon: ':question:'
    path: graph/graph-template.hpp
    title: "Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  - icon: ':x:'
    path: graph/tree/RMQ_lowest_common_ancestor.hpp
    title: "RMQ Lowest Common Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148)"
  - icon: ':question:'
    path: others/monoid.hpp
    title: others/monoid.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/yosupo/tree/lca2.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
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
    constexpr ld PI=3.1415926535897932384626;\nconstexpr int dx[8]={-1,0,1,0,1,-1,-1,1};\n\
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
    \ 9 \"template/template.hpp\"\nusing namespace std;\n#line 3 \"graph/graph-template.hpp\"\
    \n\ntemplate<typename T=int>\nstruct Edge{\n  int from,to;\n  T cost;\n  int idx;\n\
    \  Edge(){}\n  Edge(int from,int to,T cost=1,int idx=-1):from(from),to(to),cost(cost),idx(idx){}\n\
    \  operator int()const{return to;}\n  bool operator<(const Edge&e)const{return\
    \ cost<e.cost;}\n};\ntemplate<typename T=int>\nusing Edges=vector<Edge<T>>;\n\
    template<typename T=int>\nstruct Graph{\n  vector<vector<Edge<T>>>g;\n  int es;\n\
    \  Graph(){}\n  explicit Graph(int n):g(n),es(0){}\n  size_t size()const{return\
    \ g.size();}\n  size_t edge_size()const{return es;}\n  void add_edge(int from,int\
    \ to,T cost=1,bool direct=false){\n    g[from].emplace_back(from,to,cost,es);\n\
    \    if(!direct)g[to].emplace_back(to,from,cost,es);\n    es++;\n  }\n  void add_edge(int\
    \ from,int to,bool direct=false){\n    g[from].emplace_back(from,to,1,es);\n \
    \   if(!direct)g[to].emplace_back(to,from,1,es);\n  }\n  inline vector<Edge<T>>&operator[](int\
    \ idx){return g[idx];}\n  inline const vector<Edge<T>>&operator[](int idx)const{return\
    \ g[idx];}\n  void read(int m,int padding=-1,bool weighted=false,bool direct=false){\n\
    \    int a,b;\n    T c=T(1);\n    for(int i=0;i<m;i++){\n      cin>>a>>b;\n  \
    \    a+=padding;\n      b+=padding;\n      if(weighted)cin>>c;\n      add_edge(a,b,c,direct);\n\
    \    }\n  }\n};\nstruct UnweightedEdge{\n  template<class... Args>UnweightedEdge(const\
    \ Args&...){}\n  operator int()const{return 1;}\n};\nistream &operator>>(istream&is,UnweightedEdge&c){c=UnweightedEdge();return\
    \ is;}\nusing UnweightedGraph=Graph<UnweightedEdge>;\n/**\n * @brief Graph Template(\u30B0\
    \u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\n#line 3 \"others/monoid.hpp\"\
    \n\nnamespace Monoid{\n  template<typename M,typename=void>struct has_op:false_type{};\n\
    \  template<typename M>struct has_op<M,decltype((void)M::op)>:true_type{};\n \
    \ template<typename M,typename=void>struct has_id:false_type{};\n  template<typename\
    \ M>struct has_id<M,decltype((void)M::id)>:true_type{};\n  template<typename M,typename=void>struct\
    \ has_inv:false_type{};\n  template<typename M>struct has_inv<M,decltype((void)M::inv)>:true_type{};\n\
    \  template<typename M,typename=void>struct has_get_inv:false_type{};\n  template<typename\
    \ M>struct has_get_inv<M,decltype((void)M::get_inv)>:true_type{};\n  template<typename\
    \ A,typename=void>struct has_mul_op:false_type{};\n  template<typename A>struct\
    \ has_mul_op<A,decltype((void)A::mul_op)>:true_type{};\n  template<typename T,typename=void>struct\
    \ is_semigroup:false_type{};\n  template<typename T>struct is_semigroup<T,decltype(declval<typename\
    \ T::value_type>(),(void)T::op)>:true_type{};\n  template<typename T,typename=void>struct\
    \ is_monoid:false_type{};\n  template<typename T>struct is_monoid<T,decltype(declval<typename\
    \ T::value_type>(),(void)T::op,(void)T::id)>:true_type{};\n  template<typename\
    \ T,typename=void>struct is_group:false_type{};\n  template<typename T>struct\
    \ is_group<T,decltype(declval<typename T::value_type>(),(void)T::op,(void)T::id,(void)T::get_inv)>:true_type{};\n\
    \  template<typename T,typename=void>struct is_action:false_type{};\n  template<typename\
    \ T>struct is_action<T,typename enable_if<is_monoid<typename T::M>::value&&is_semigroup<typename\
    \ T::E>::value&&(has_op<T>::value||has_mul_op<T>::value)>::type>:true_type{};\n\
    \  template<typename T,typename=void>struct is_distributable_action:false_type{};\n\
    \  template<typename T>struct is_distributable_action<T,typename enable_if<is_action<T>::value&&!has_mul_op<T>::value>::type>:true_type{};\n\
    \  template<typename T>\n  struct Sum{\n    using value_type=T;\n    static constexpr\
    \ T op(const T&x,const T&y){return x+y;}\n    static constexpr T id(){return T(0);}\n\
    \    static constexpr T inv(const T&x,const T&y){return x-y;}\n    static constexpr\
    \ T get_inv(const T&x){return -x;}\n  };\n  template<typename T,T max_value=infinity<T>::value>\n\
    \  struct Min{\n    using value_type=T;\n    static constexpr T op(const T&x,const\
    \ T&y){return x<y?x:y;}\n    static constexpr T id(){return max_value;}\n  };\n\
    \  template<typename T,T min_value=infinity<T>::mvalue>\n  struct Max{\n    using\
    \ value_type=T;\n    static constexpr T op(const T&x,const T&y){return x<y?y:x;}\n\
    \    static constexpr T id(){return min_value;}\n  };\n  template<typename T>\n\
    \  struct Assign{\n    using value_type=T;\n    static constexpr T op(const T&,const\
    \ T&x){return x;}\n  };\n  template<typename T,T max_value=infinity<T>::value>\n\
    \  struct AssignMin{\n    using M=Min<T,max_value>;\n    using E=Assign<T>;\n\
    \    static constexpr T op(const T&x,const T&){return x;}\n  };\n  template<typename\
    \ T,T min_value=infinity<T>::mvalue>\n  struct AssignMax{\n    using M=Max<T,min_value>;\n\
    \    using E=Assign<T>;\n    static constexpr T op(const T&x,const T&){return\
    \ x;}\n  };\n  template<typename T>\n  struct AssignSum{\n    using M=Sum<T>;\n\
    \    using E=Assign<T>;\n    static constexpr T mul_op(const T&x,int sz,const\
    \ T&){return x*sz;}\n  };\n  template<typename T,T max_value=infinity<T>::value>\n\
    \  struct AddMin{\n    using M=Min<T,max_value>;\n    using E=Sum<T>;\n    static\
    \ constexpr T op(const T&a,const T&b){return b+a;}\n  };\n  template<typename\
    \ T,T min_value=infinity<T>::mvalue>\n  struct AddMax{\n    using M=Max<T,min_value>;\n\
    \    using E=Sum<T>;\n    static constexpr T op(const T&a,const T&b){return b+a;}\n\
    \  };\n  template<typename T>\n  struct AddSum{\n    using M=Sum<T>;\n    using\
    \ E=Sum<T>;\n    static constexpr T mul_op(const T&x,int sz,const T&y){return\
    \ y+x*sz;}\n  };\n  template<typename T,T max_value=infinity<T>::value>\n  struct\
    \ ChminMin{\n    using M=Min<T,max_value>;\n    using E=Min<T>;\n    static constexpr\
    \ T op(const T&x,const T&y){return y<x?y:x;}\n  };\n  template<typename T,T min_value=infinity<T>::mvalue>\n\
    \  struct ChminMax{\n    using M=Max<T,min_value>;\n    using E=Min<T>;\n    static\
    \ constexpr T op(const T&x,const T&y){return y<x?y:x;}\n  };\n  template<typename\
    \ T,T max_value=infinity<T>::value>\n  struct ChmaxMin{\n    using M=Min<T,max_value>;\n\
    \    using E=Max<T>;\n    static constexpr T op(const T&x,const T&y){return x<y?y:x;}\n\
    \  };\n  template<typename T,T min_value=infinity<T>::mvalue>\n  struct ChmaxMax{\n\
    \    using M=Max<T,min_value>;\n    using E=Max<T>;\n    static constexpr T op(const\
    \ T&x,const T&y){return x<y?y:x;}\n  };\n  template<typename E_>\n  struct AttachMonoid{\n\
    \    using M=E_;\n    using E=E_;\n    using T=typename E_::value_type;\n    static\
    \ T op(const T&x,const T&y){return E_::op(y,x);}\n  };\n}// namespace Monoid\n\
    #line 4 \"data-structure/sparse-table.hpp\"\n\ntemplate<typename M>\nstruct SparseTable{\n\
    \  private:\n  using T=typename M::value_type;\n  int lg,n;\n  vector<vector<T>>table;\n\
    \  vector<int>log_table;\n  T internal_prod(int l,int r)const{\n    int d=log_table[r-l];\n\
    \    return M::op(table[d][l],table[d][r-(1<<d)]);\n  }\n  public:\n  SparseTable()=default;\n\
    \  SparseTable(const vector<T>&v){init(v);}\n  void init(const vector<T>&v){\n\
    \    n=v.size();\n    lg=ceil_log2(n)+1;\n    table.assign(lg,vector<T>(n));\n\
    \    table[0]=v;\n    rep(i,1,lg)rep(j,n-(1<<i)+1)table[i][j]=M::op(table[i-1][j],table[i-1][j+(1<<(i-1))]);\n\
    \    log_table.assign(n+1,0);\n    log_table[1]=0;\n    rep(i,2,n+1)log_table[i]=log_table[i>>1]+1;\n\
    \  }\n  template<bool dummy=true,typename enable_if<Monoid::has_id<M>::value&&dummy>::type*\
    \ = nullptr>\n  T prod(int l,int r)const{\n    if(l==r)return M::id();\n    return\
    \ internal_prod(l,r);\n  }\n  template<bool dummy=true,typename enable_if<!Monoid::has_id<M>::value&&dummy>::type*\
    \ = nullptr>\n  T prod(int l,int r)const{\n    if(l==r)return T{};\n    return\
    \ internal_prod(l,r);\n  }\n};\n/**\n * @brief Sparse Table\n*/\n#line 4 \"graph/tree/RMQ_lowest_common_ancestor.hpp\"\
    \n\nnamespace Monoid{\n  struct PairMinForLCA{\n    using value_type=pair<int,int>;\n\
    \    static value_type op(const value_type&a,const value_type&b){\n      return\
    \ a.first<b.first?a:b;\n    }\n    static value_type id(){return {infinity<int>::value,-1};}\n\
    \  };\n}//namespace Monoid\ntemplate<typename T=UnweightedEdge>\nstruct RMQ_LCA:Graph<T>{\n\
    \  using Graph<T>::g;\n  vector<int>in;\n  RMQ_LCA(int n):Graph<T>(n){}\n  RMQ_LCA(const\
    \ Graph<T>&g):Graph<T>(g){}\n  void build(int root=0){\n    in.resize(g.size());\n\
    \    dfs(root,-1,0);\n    RMQ.init(rmqvec);\n  }\n  int lca(int u,int v)const{\n\
    \    if(in[u]>in[v])swap(u,v);\n    return u==v?u:RMQ.prod(in[u],in[v]).second;\n\
    \  }\n  private:\n  vector<pair<int,int>>rmqvec;\n  SparseTable<Monoid::PairMinForLCA>RMQ;\n\
    \  void dfs(int idx,int par,int d){\n    in[idx]=(int)rmqvec.size();\n    rmqvec.emplace_back(d,idx);\n\
    \    for(auto &e:g[idx])if(e!=par){\n      dfs(e,idx,d+1);\n      rmqvec.emplace_back(d,idx);\
    \  \n    }\n  }\n};\n/**\n * @brief RMQ Lowest Common Ancestor(\u6700\u5C0F\u5171\
    \u901A\u7956\u5148)\n*/\n#line 4 \"test/yosupo/tree/lca2.test.cpp\"\nint main(){\n\
    \  INT(n,q);\n  RMQ_LCA g(n);\n  for(int i=1;i<n;i++){\n    INT(u);\n    g.add_edge(u,i,false);\n\
    \  }\n  g.build();\n  while(q--){\n    INT(u,v);\n    print(g.lca(u,v));\n  }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include\"../../../template/template.hpp\"\
    \n#include\"../../../graph/tree/RMQ_lowest_common_ancestor.hpp\"\nint main(){\n\
    \  INT(n,q);\n  RMQ_LCA g(n);\n  for(int i=1;i<n;i++){\n    INT(u);\n    g.add_edge(u,i,false);\n\
    \  }\n  g.build();\n  while(q--){\n    INT(u,v);\n    print(g.lca(u,v));\n  }\n\
    }"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - template/type-traits.hpp
  - graph/tree/RMQ_lowest_common_ancestor.hpp
  - graph/graph-template.hpp
  - data-structure/sparse-table.hpp
  - others/monoid.hpp
  isVerificationFile: true
  path: test/yosupo/tree/lca2.test.cpp
  requiredBy: []
  timestamp: '2024-02-04 11:21:20+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/tree/lca2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/tree/lca2.test.cpp
- /verify/test/yosupo/tree/lca2.test.cpp.html
title: test/yosupo/tree/lca2.test.cpp
---
