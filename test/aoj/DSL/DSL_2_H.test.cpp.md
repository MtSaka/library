---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/dual-segment-tree.hpp
    title: "Dual Segment Tree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':question:'
    path: data-structure/lazy-segment-tree.hpp
    title: "Lazy Segment Tree(\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree-monoids.hpp
    title: "Monoids(\u30E2\u30CE\u30A4\u30C9)"
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree.hpp
    title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_H
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_H
  bundledCode: "#line 1 \"test/aoj/DSL/DSL_2_H.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_H\"\
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
    #endif\n#line 8 \"template/template.hpp\"\nusing namespace std;\n#line 3 \"data-structure/segment-tree.hpp\"\
    \n\ntemplate<class S,S (*op)(S,S),S (*e)()>\nstruct SegmentTree{\n  private:\n\
    \  int _n,size=1,idx=0;\n  vector<S>seq;\n  void update(int k){seq[k]=op(seq[k<<1],seq[k<<1^1]);}\n\
    \  public:\n  SegmentTree():SegmentTree(0){};\n  SegmentTree(int n):SegmentTree(vector<S>(n,e())){}\n\
    \  SegmentTree(const vector<S>&v):_n(int(v.size())){\n    while(size<_n)size<<=1,idx++;\n\
    \    seq=vector<S>(size<<1,e());\n    for(int i=0;i<_n;i++)seq[size+i]=v[i];\n\
    \    for(int i=size-1;i>=1;i--)update(i);\n  }\n  void set(int p,S x){\n    p+=size;\n\
    \    seq[p]=x;\n    for(int i=1;i<=idx;i++)update(p>>i);\n  }\n  S operator[](int\
    \ p)const{return seq[p+size];}\n  S query(int l,int r)const{\n    S sml=e(),smr=e();\n\
    \    l+=size,r+=size;\n    while(l<r){\n      if(l&1)sml=op(sml,seq[l++]);\n \
    \     if(r&1)smr=op(seq[--r],smr);\n      l>>=1,r>>=1;\n    }\n    return op(sml,smr);\n\
    \  }\n  S all_query()const{return seq[1];}\n  template<typename F>\n  int find_right(int\
    \ l,const F&f)const{\n    if(l==_n)return _n;\n    l+=size;\n    S sum=e();\n\
    \    do{\n      while(!(l&1))l>>=1;\n      if(!f(op(sum,seq[l]))){\n        while(l<size){\n\
    \          l<<=1;\n          if(f(op(sum,seq[l])))sum=op(sum,seq[l++]);\n    \
    \    }\n        return l-size;\n      }\n      sum=op(sum,seq[l++]);\n    }while((l&-l)!=l);\n\
    \    return _n;\n  }\n  template<typename F>\n  int find_left(int r,const F&f)const{\n\
    \    if(!r)return 0;\n    r+=size;\n    S sum=e();\n    do{\n      r--;\n    \
    \  while(r>1&&(r&1))r>>=1;\n      if(!f(op(seq[r],sum))){\n        while(r<size){\n\
    \          (r<<=1)++;\n          if(f(op(seq[r],sum)))sum=op(seq[r--],sum);\n\
    \        }\n        return r+1-size;\n      }\n      sum=op(seq[r],sum);\n   \
    \ }while((r&-r)!=r);\n    return 0;\n  }\n};\n/**\n * @brief Segment Tree(\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728)\n*/\n#line 3 \"data-structure/lazy-segment-tree.hpp\"\
    \n\ntemplate<class S,S (*op)(S,S),S (*e)(),class F,S (*mapping)(F,S),F (*composition)(F,F),F\
    \ (*id)()>\nstruct LazySegmentTree{\n  private:\n  int _n,size=1,idx=0;\n  vector<S>seq;\n\
    \  vector<F>lazy;\n  void update(int k){seq[k]=op(seq[k<<1],seq[k<<1^1]);}\n \
    \ void all_apply(int k,F f){\n    seq[k]=mapping(f,seq[k]);\n    if(k<size)lazy[k]=composition(f,lazy[k]);\n\
    \  }\n  void eval(int k){\n    all_apply(k<<1,lazy[k]);\n    all_apply(k<<1^1,lazy[k]);\n\
    \    lazy[k]=id();\n  }\n  public:\n  LazySegmentTree():LazySegmentTree(0){}\n\
    \  LazySegmentTree(int n):LazySegmentTree(vector<S>(n,e())){}\n  LazySegmentTree(const\
    \ vector<S>&v):_n(int(v.size())){\n    while(size<_n)size<<=1,idx++;\n    seq=vector<S>(size<<1,e());\n\
    \    lazy=vector<F>(size,id());\n    for(int i=0;i<_n;i++)seq[size+i]=v[i];\n\
    \    for(int i=size-1;i>=1;i--)update(i);\n  }\n  void set(int p,S x){\n    p+=size;\n\
    \    for(int i=idx;i>=1;i--)eval(p>>i);\n    seq[p]=x;\n    for(int i=1;i<=idx;i++)update(p>>i);\n\
    \  }\n  S operator[](int p){\n    p+=size;\n    for(int i=idx;i>=1;i--)eval(p>>i);\n\
    \    return seq[p];\n  }\n  S query(int l,int r){\n    if(l==r)return e();\n \
    \   S sml=e(),smr=e();\n    l+=size,r+=size;\n    for(int i=idx;i>=1;i--){\n \
    \     if(((l>>i)<<i)!=l)eval(l>>i);\n      if(((r>>i)<<i)!=r)eval(r>>i);\n   \
    \ }\n    while(l<r){\n      if(l&1)sml=op(sml,seq[l++]);\n      if(r&1)smr=op(seq[--r],smr);\n\
    \      l>>=1,r>>=1;\n    }\n    return op(sml,smr);\n  }\n  S all_query()const{return\
    \ seq[1];}\n  void apply(int p,F f){\n    p+=size;\n    for(int i=idx;i>=1;i--)eval(p>>i);\n\
    \    seq[p]=mapping(f,seq[p]);\n    for(int i=1;i<=idx;i++)update(p>>i);\n  }\n\
    \  void apply(int l,int r,F f){\n    if(l==r)return ;\n    l+=size;\n    r+=size;\n\
    \    for(int i=idx;i>=1;i--){\n      if(((l>>i)<<i)!=l)eval(l>>i);\n      if(((r>>i)<<i)!=r)eval(r>>i);\n\
    \    }\n    int l2=l,r2=r;\n    while(l<r){\n      if(l&1)all_apply(l++,f);\n\
    \      if(r&1)all_apply(--r,f);\n      l>>=1;\n      r>>=1;\n    }\n    l=l2,r=r2;\n\
    \    for(int i=1;i<=idx;i++){\n      if(((l>>i)<<i)!=l)update(l>>i);\n      if(((r>>i)<<i)!=r)update(r>>i);\n\
    \    }\n  }\n};\n/**\n * @brief Lazy Segment Tree(\u9045\u5EF6\u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728)\n*/\n#line 3 \"data-structure/dual-segment-tree.hpp\"\n\n\
    template<class S,class F,S (*mapping)(F,S),F (*composition)(F,F),F (*id)()>\n\
    struct DualSegmentTree{\n  private:\n  int _n,size=1,idx=0;\n  vector<S>seq;\n\
    \  vector<F>lazy;\n  void all_apply(int k,F f){\n    if(k<size)lazy[k]=composition(f,lazy[k]);\n\
    \    else if(k<size+_n)seq[k-size]=mapping(f,seq[k-size]);\n  }\n  void eval(int\
    \ k){\n    all_apply(k<<1,lazy[k]);\n    all_apply(k<<1^1,lazy[k]);\n    lazy[k]=id();\n\
    \  }\n  public:\n  DualSegmentTree():DualSegmentTree(0){}\n  DualSegmentTree(int\
    \ n,S e=S()):DualSegmentTree(vector<S>(n,e)){};\n  DualSegmentTree(const vector<S>&v):_n(v.size()){\n\
    \    while(size<_n)size<<=1,idx++;\n    seq=v;lazy=vector<F>(size,id());\n  }\n\
    \  void set(int p,S x){\n    p+=size;\n    for(int i=idx;i>=1;i--)eval(p>>i);\n\
    \    seq[p-size]=x;\n  }\n  S operator[](int p){\n    p+=size;\n    for(int i=idx;i>=1;i--)eval(p>>i);\n\
    \    return seq[p-size];\n  }\n  void apply(int p,F f){\n    p+=size;\n    for(int\
    \ i=idx;i>=1;i--)eval(p>>i);\n    seq[p-size]=mapping(f,seq[p-size]);\n  }\n \
    \ void apply(int l,int r,F f){\n    if(l==r)return;\n    l+=size;r+=size;\n  \
    \  for(int i=idx;i>=1;i--){\n      if(((l>>i)<<i)!=l)eval(l>>i);\n      if(((r>>i)<<i)!=r)eval(r>>i);\n\
    \    }\n    while(l<r){\n      if(l&1)all_apply(l++,f);\n      if(r&1)all_apply(--r,f);\n\
    \      l>>=1,r>>=1;\n    }\n  }\n};\n/**\n *@brief Dual Segment Tree(\u53CC\u5BFE\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n*/\n#line 6 \"data-structure/segment-tree-monoids.hpp\"\
    \n\nnamespace MonoidSegmentTree{\n  template<class T>static constexpr T op1(T\
    \ a,T b){return min<T>(a,b);}\n  template<class T>static constexpr T op2(T a,T\
    \ b){return max<T>(a,b);}\n  template<class T>static constexpr T op3(T a,T b){return\
    \ a+b;}\n  template<class T>static constexpr T e1(){return infinity<T>::MAX;}\n\
    \  template<class T>static constexpr T e2(){return infinity<T>::MIN;}\n  template<class\
    \ T>static constexpr T e3(){return T(0);}\n  template<class T>using RmQ=SegmentTree<T,op1<T>,e1<T>>;\n\
    \  template<class T>using RMQ=SegmentTree<T,op2<T>,e2<T>>;\n  template<class T>using\
    \ RSQ=SegmentTree<T,op3<T>,e3<T>>;\n}\nusing MonoidSegmentTree::RmQ;\nusing MonoidSegmentTree::RMQ;\n\
    using MonoidSegmentTree::RSQ;\nnamespace MonoidLazySegmentTree{\n  template<class\
    \ T>struct S{T value;int size;S(const T&a):value(a),size(1){}S(const T&a,const\
    \ int&size):value(a),size(size){}operator T()const{return value;}};\n  template<class\
    \ T>static constexpr T op1(T a,T b){return min<T>(a,b);}\n  template<class T>static\
    \ constexpr T op2(T a,T b){return max<T>(a,b);}\n  template<class T>static constexpr\
    \ S<T> op3(S<T>a,S<T>b){return {a.value+b.value,a.size+b.size};}\n  template<class\
    \ T>static constexpr T e1(){return infinity<T>::MAX;}\n  template<class T>static\
    \ constexpr T e2(){return infinity<T>::MIN;}\n  template<class T>static constexpr\
    \ S<T> e3(){return {T(0),1};}\n  template<class T>static constexpr T mapping1(T\
    \ a,T b){return a==infinity<T>::MAX?b:a;}\n  template<class T>static constexpr\
    \ S<T> mapping2(T a,S<T>b){if(a!=infinity<T>::MAX)b.value=a*b.size;return b;}\n\
    \  template<class T>static constexpr S<T> mapping3(T a,S<T>b){return {b.value+a*b.size,b.size};}\n\
    \  template<class T>static constexpr T mapping4(T a,T b){return a+b;}\n  template<class\
    \ T>static constexpr T mapping5(T a,T b){return min<T>(a,b);}\n  template<class\
    \ T>static constexpr T mapping6(T a,T b){return max<T>(a,b);}\n  template<class\
    \ T>static constexpr T composition1(T a,T b){return a==infinity<T>::MAX?b:a;}\n\
    \  template<class T>static constexpr T composition2(T a,T b){return a+b;}\n  template<class\
    \ T>static constexpr T composition3(T a,T b){return min<T>(a,b);}\n  template<class\
    \ T>static constexpr T composition4(T a,T b){return max<T>(a,b);}\n  template<class\
    \ T>static constexpr T id1(){return infinity<T>::MAX;}\n  template<class T>static\
    \ constexpr T id2(){return T(0);}\n  template<class T>static constexpr T id3(){return\
    \ infinity<T>::MIN;}\n  template<class T>using RUQRmQ=LazySegmentTree<T,op1<T>,e1<T>,T,mapping1<T>,composition1<T>,id1<T>>;\n\
    \  template<class T>using RUQRMQ=LazySegmentTree<T,op2<T>,e2<T>,T,mapping1<T>,composition1<T>,id1<T>>;\n\
    \  template<class T>using RUQRSQ=LazySegmentTree<S<T>,op3<T>,e3<T>,T,mapping2<T>,composition1<T>,id1<T>>;\n\
    \  template<class T>using RAQRSQ=LazySegmentTree<S<T>,op3<T>,e3<T>,T,mapping3<T>,composition2<T>,id2<T>>;\n\
    \  template<class T>using RAQRmQ=LazySegmentTree<T,op1<T>,e1<T>,T,mapping4<T>,composition2<T>,id2<T>>;\n\
    \  template<class T>using RAQRMQ=LazySegmentTree<T,op2<T>,e2<T>,T,mapping4<T>,composition2<T>,id2<T>>;\n\
    \  template<class T>using RChminRmQ=LazySegmentTree<T,op1<T>,e1<T>,T,mapping5<T>,composition3<T>,id1<T>>;\n\
    \  template<class T>using RChminRMQ=LazySegmentTree<T,op2<T>,e2<T>,T,mapping5<T>,composition3<T>,id1<T>>;\n\
    \  template<class T>using RChmaxRmQ=LazySegmentTree<T,op1<T>,e1<T>,T,mapping6<T>,composition4<T>,id3<T>>;\n\
    \  template<class T>using RChmaxRMQ=LazySegmentTree<T,op2<T>,e2<T>,T,mapping6<T>,composition4<T>,id3<T>>;\n\
    }\nusing MonoidLazySegmentTree::RUQRmQ;\nusing MonoidLazySegmentTree::RUQRMQ;\n\
    using MonoidLazySegmentTree::RUQRSQ;\nusing MonoidLazySegmentTree::RAQRSQ;\nusing\
    \ MonoidLazySegmentTree::RAQRmQ;\nusing MonoidLazySegmentTree::RAQRMQ;\nusing\
    \ MonoidLazySegmentTree::RChminRmQ;\nusing MonoidLazySegmentTree::RChminRMQ;\n\
    using MonoidLazySegmentTree::RChmaxRmQ;\nusing MonoidLazySegmentTree::RChmaxRMQ;\n\
    namespace MonoidDualSegmentTree{\n  template<class T>static constexpr T mapping1(T\
    \ a,T b){return a==infinity<T>::MAX?b:a;}\n  template<class T>static constexpr\
    \ T mapping2(T a,T b){return min<T>(a,b);}\n  template<class T>static constexpr\
    \ T mapping3(T a,T b){return max<T>(a,b);}\n  template<class T>static constexpr\
    \ T mapping4(T a,T b){return a+b;}\n  template<class T>static constexpr T composition1(T\
    \ a,T b){return a==infinity<T>::MAX?b:a;}\n  template<class T>static constexpr\
    \ T composition2(T a,T b){return min<T>(a,b);}\n  template<class T>static constexpr\
    \ T composition3(T a,T b){return max<T>(a,b);}\n  template<class T>static constexpr\
    \ T composition4(T a,T b){return a+b;}\n  template<class T>static constexpr T\
    \ id1(){return infinity<T>::MAX;}\n  template<class T>static constexpr T id2(){return\
    \ infinity<T>::MIN;}\n  template<class T>static constexpr T id3(){return T(0);}\n\
    \  template<class T>using RUQ=DualSegmentTree<T,T,mapping1<T>,composition1<T>,id1<T>>;\n\
    \  template<class T>using RChminQ=DualSegmentTree<T,T,mapping2<T>,composition2<T>,id1<T>>;\n\
    \  template<class T>using RChmaxQ=DualSegmentTree<T,T,mapping3<T>,composition3<T>,id2<T>>;\n\
    \  template<class T>using RAQ=DualSegmentTree<T,T,mapping4<T>,composition4<T>,id3<T>>;\n\
    }\nusing MonoidDualSegmentTree::RUQ;\nusing MonoidDualSegmentTree::RChminQ;\n\
    using MonoidDualSegmentTree::RChmaxQ;\nusing MonoidDualSegmentTree::RAQ;\n/**\n\
    \ * @brief Monoids(\u30E2\u30CE\u30A4\u30C9)\n */\n#line 4 \"test/aoj/DSL/DSL_2_H.test.cpp\"\
    \nint main(){\n  int n,q;cin>>n>>q;\n  RAQRmQ<int>seg(vector<int>(n,0));\n  while(q--){\n\
    \    int t;cin>>t;\n    if(t==0){\n      int l,r,x;cin>>l>>r>>x;\n      seg.apply(l,r+1,x);\n\
    \    }\n    else{\n      int l,r;cin>>l>>r;\n      cout<<seg.query(l,r+1)<<endl;\n\
    \    }\n  }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_H\"\n#include\"\
    ../../../template/template.hpp\"\n#include\"../../../data-structure/segment-tree-monoids.hpp\"\
    \nint main(){\n  int n,q;cin>>n>>q;\n  RAQRmQ<int>seg(vector<int>(n,0));\n  while(q--){\n\
    \    int t;cin>>t;\n    if(t==0){\n      int l,r,x;cin>>l>>r>>x;\n      seg.apply(l,r+1,x);\n\
    \    }\n    else{\n      int l,r;cin>>l>>r;\n      cout<<seg.query(l,r+1)<<endl;\n\
    \    }\n  }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - data-structure/segment-tree-monoids.hpp
  - data-structure/segment-tree.hpp
  - data-structure/lazy-segment-tree.hpp
  - data-structure/dual-segment-tree.hpp
  isVerificationFile: true
  path: test/aoj/DSL/DSL_2_H.test.cpp
  requiredBy: []
  timestamp: '2022-12-18 23:26:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL/DSL_2_H.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL/DSL_2_H.test.cpp
- /verify/test/aoj/DSL/DSL_2_H.test.cpp.html
title: test/aoj/DSL/DSL_2_H.test.cpp
---
