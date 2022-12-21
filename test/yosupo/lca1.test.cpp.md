---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph-template.hpp
    title: "Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  - icon: ':heavy_check_mark:'
    path: graph/tree/doubling-lowest-common-ancestor.hpp
    title: "Doubling Lowest Common Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148)"
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
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/yosupo/lca1.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
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
    \u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\n#line 4 \"graph/tree/doubling-lowest-common-ancestor.hpp\"\
    \n\ntemplate<typename T=UnweightedEdge>\nstruct DoublingLCA:Graph<T>{\n  using\
    \ Graph<T>::g;\n  const int lg;\n  vector<int>dep;\n  vector<T>sum;\n  vector<vector<int>>table;\n\
    \  DoublingLCA(int n):Graph<T>(n),lg(32-__builtin_clz(n)){}\n  DoublingLCA(const\
    \ Graph<T>&g):Graph<T>(g),lg(32-__builtin_clz(g.size())){}\n  void build(int root=0){\n\
    \    dep.assign(g.size(),0);\n    sum.assign(g.size(),0);\n    table.assign(lg,vector<int>(g.size(),-1));\n\
    \    dfs(root,-1,0);\n    for(int k=0;k+1<lg;k++){\n      for(int i=0;i<(int)table[k].size();i++){\n\
    \        if(table[k][i]==-1)table[k+1][i]=-1;\n        else table[k+1][i]=table[k][table[k][i]];\n\
    \      }\n    }\n  }\n  int lca(int u,int v){\n    if(dep[u]>dep[v])swap(u,v);\n\
    \    int k=dep[v]-dep[u];\n    if(dep[v]<k)return -1;\n    for(int i=lg-1;i>=0;i--){\n\
    \      if((k>>i)&1)v=table[i][v];\n    }\n    if(u==v)return u;\n    for(int i=lg-1;i>=0;i--){\n\
    \      if(table[i][u]!=table[i][v]){\n        u=table[i][u];\n        v=table[i][v];\n\
    \      }\n    }\n    return table[0][u];\n  }\n  T dist(int u,int v){return sum[u]+sum[v]-2*sum[lca(u,v)];}\n\
    \  private:\n  void dfs(int idx,int par,int d){\n    table[0][idx]=par;\n    dep[idx]=d;\n\
    \    for(auto &e:g[idx])if(e!=par){\n      sum[e]=sum[idx]+e.cost;\n      dfs(e,idx,d+1);\n\
    \    }\n  }\n};\n/**\n * @brief Doubling Lowest Common Ancestor(\u6700\u5C0F\u5171\
    \u901A\u7956\u5148)\n*/\n#line 4 \"test/yosupo/lca1.test.cpp\"\nint main(){\n\
    \  int n,q;\n  cin>>n>>q;\n  DoublingLCA g(n);\n  for(int i=1;i<n;i++){\n    int\
    \ u;\n    cin>>u;\n    g.add_edge(u,i,false);\n  }\n  g.build();\n  while(q--){\n\
    \    int u,v;\n    cin>>u>>v;\n    cout<<g.lca(u,v)<<endl;\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include\"../../template/template.hpp\"\
    \n#include\"../../graph/tree/doubling-lowest-common-ancestor.hpp\"\nint main(){\n\
    \  int n,q;\n  cin>>n>>q;\n  DoublingLCA g(n);\n  for(int i=1;i<n;i++){\n    int\
    \ u;\n    cin>>u;\n    g.add_edge(u,i,false);\n  }\n  g.build();\n  while(q--){\n\
    \    int u,v;\n    cin>>u>>v;\n    cout<<g.lca(u,v)<<endl;\n  }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - template/type-traits.hpp
  - graph/tree/doubling-lowest-common-ancestor.hpp
  - graph/graph-template.hpp
  isVerificationFile: true
  path: test/yosupo/lca1.test.cpp
  requiredBy: []
  timestamp: '2022-12-21 20:26:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/lca1.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/lca1.test.cpp
- /verify/test/yosupo/lca1.test.cpp.html
title: test/yosupo/lca1.test.cpp
---
