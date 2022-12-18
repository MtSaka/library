---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Data_Structure/dynamic_segtree.hpp
    title: "Dynamic Segment Tree(\u52D5\u7684\u30BB\u30B0\u6728)"
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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/yosupo/point_add_range_sum3.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#line 2 \"template/template.hpp\"\
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
    \ constexpr T MAX=numeric_limits<T>::max();\n  static constexpr T MIN=numeric_limits<T>::min();\n\
    \  static constexpr T value=numeric_limits<T>::max()/2;\n  static constexpr T\
    \ mvalue=numeric_limits<T>::min()/2;\n};\ntemplate<typename T>constexpr T INF=infinity<T>::value;\n\
    constexpr ll inf=INF<ll>;\nconstexpr ld EPS=1e-8;\nconstexpr ld PI=3.1415926535897932384626;\n\
    constexpr ll mod=998244353;\nconstexpr ll MOD=1000000007;\nconstexpr int dx[8]={1,0,-1,0,1,-1,-1,1};\n\
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
    #line 5 \"template/util.hpp\"\n\nstruct IOSetup{\n  constexpr IOSetup(){\n   \
    \ std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    std::cout.tie(0);\n\
    \    std::cout<<std::fixed<<std::setprecision(12);\n    std::cerr<<std::fixed<<std::setprecision(12);\n\
    \  }\n};\ntemplate<typename F>\nstruct REC{\n  private:\n  F f;\n  public:\n \
    \ explicit constexpr REC(F&&f_):f(std::forward<F>(f_)){}\n  template<typename...Args>\n\
    \  constexpr auto operator()(Args&&...args)const{\n    return f(*this, std::forward<Args>(args)...);\n\
    \  }\n};\ntemplate<typename T,typename Comp=std::less<T>>\nstruct compressor{\n\
    \  private:\n  std::vector<T>data;\n  Comp cmp;\n  bool sorted=false;\n  public:\n\
    \  compressor():compressor(Comp()){}\n  compressor(const Comp&cmp):cmp(cmp){}\n\
    \  compressor(const std::vector<T>&dat,const Comp&cmp=Comp()):data(dat),cmp(cmp){}\n\
    \  compressor(std::vector<T>&&dat,const Comp&cmp=Comp()):data(move(dat)),cmp(cmp){}\n\
    \  compressor(initializer_list<T>li,const Comp&cmp=Comp()):data(li.begin(),li.end()),cmp(cmp){}\n\
    \  void push_back(const T&v){assert(!sorted);data.push_back(v);}\n  void push_back(T&&v){assert(!sorted);data.push_back(move(v));}\n\
    \  template<typename..Args>void emplace_back(Args&&...args){assert(!sorted);data.emplace_back(std::forward<Args>(args)...);}\n\
    \  void push(const vector<T>&v){\n    assert(!sorted);\n    const int n=data.size();\n\
    \    data.resize(v.size()+n);\n    for(int i=0;i<(int)v.size();i++)data[i+n]=v[i];\n\
    \  }\n  void build(){\n    assert(!sorted);sorted=1;\n    std::sort(data.begin(),data.end(),cmp);\n\
    \    data.erase(unique(data.begin(),data.end(),[&](const T&l,const T&r)->bool\
    \ {return !cmp(l,r)&&!cmp(r,l);}),data.end());\n  }\n  const T&operator[](int\
    \ k)const& {\n    assert(sorted);\n    return data[k];\n  }\n  int get_index(const\
    \ T&v)const {\n    assert(sorted);\n    return int(lower_bound(data.begin(),data.end(),v,cmp)-data.begin());\n\
    \  }\n  void press(std::vector<T>&v)const {\n    assert(sorted);\n    for(auto&&i:v)i=get_index(i);\n\
    \  }\n  std::vector<int>pressed(const vector<T>&v)const {\n    assert(sorted);\n\
    \    std::vector<int>ret(v.size());\n    for(int i=0;i<(int)v.size();i++)ret[i]=get_index(v[i]);\n\
    \    return ret;\n  }\n  int size()const {\n    assert(sorted);\n    return data.size();\n\
    \  }\n};\n#line 4 \"template/debug.hpp\"\n\ntemplate<typename T,typename=void>\n\
    struct is_specialize:false_type{};\ntemplate<typename T>\nstruct is_specialize<T,typename\
    \ std::conditional<false,typename T::iterator, void>::type>:true_type{};\ntemplate<typename\
    \ T>\nstruct is_specialize<T,typename std::conditional<false,decltype(T::first),void>::type>:true_type{};\n\
    template<typename T>\nstruct is_specialize<T,std::enable_if_t<std::is_integral<T>::value,void>>:true_type{};\n\
    inline void dump(const char&t){std::cerr<<t;}\ninline void dump(const std::string&t){std::cerr<<t;}\n\
    inline void dump(const bool&t){std::cerr<<(t?\"true\":\"false\");}\ntemplate <typename\
    \ T,std::enable_if_t<!is_specialize<T>::value,nullptr_t> =nullptr>\ninline void\
    \ dump(const T&t){std::cerr<<t;}\ntemplate<typename T>\ninline void dump(const\
    \ T&t,std::enable_if_t<std::is_integral<T>::value>* =nullptr){string tmp;if(t==infinity<T>::value||t==infinity<T>::MAX)tmp=\"\
    inf\";if(is_signed<T>::value&&(t==infinity<T>::mvalue||t==infinity<T>::MIN))tmp=\"\
    -inf\";if(tmp.empty())tmp=to_string(t);std::cerr<<tmp;}\ntemplate<typename T,typename\
    \ U>\ninline void dump(const std::pair<T,U>&);\ntemplate<typename T>\ninline void\
    \ dump(const T&t,std::enable_if_t<!std::is_void<typename T::iterator>::value>*\
    \ =nullptr){std::cerr<<\"{\";for(auto it=std::begin(t);it!=std::end(t);){dump(*it);std::cerr<<(++it==t.end()?\"\
    \":\",\");}std::cerr<<\"}\";}\ntemplate<typename T,typename U>\ninline void dump(const\
    \ std::pair<T,U>&t){std::cerr<<\"(\";dump(t.first);std::cerr<<\",\";dump(t.second);std::cerr<<\"\
    )\";}\ninline void trace(){std::cerr<<std::endl;}\ntemplate<typename Head,typename...\
    \ Tail>\ninline void trace(Head&&head,Tail&&... tail){dump(head);if(sizeof...(tail))std::cerr<<\"\
    ,\";trace(forward<Tail>(tail)...);}\n#ifdef ONLINE_JUDGE\n#define debug(...) (void(0))\n\
    #else\n#define debug(...) do{std::cerr<<#__VA_ARGS__<<\"=\";trace(__VA_ARGS__);}while(0)\n\
    #endif\n#line 8 \"template/template.hpp\"\nusing namespace std;\n#line 2 \"Data_Structure/dynamic_segtree.hpp\"\
    \ntemplate<typename S,S (*op)(S,S),S (*e)()>\nstruct dynamic_segtree{\n  public:\n\
    \  dynamic_segtree():dynamic_segtree(numeric_limits<long long>::max()>>1){}\n\
    \  dynamic_segtree(long long n):n(n),root(nullptr){}\n  void set(int p,const S&x){inner_set(root,0,n,p,x);}\n\
    \  S get(long long p)const{return inner_get(root,0,n,p);}\n  S operator[](long\
    \ long p)const{return inner_get(root,0,n,p);}\n  S query(long long l,long long\
    \ r)const{return inner_query(root,0,n,l,r);}\n  S all_query()const{return root?root->val:e();}\n\
    \  void reset(long long l,long long r){inner_reset(root,0,n,l,r);}\n  private:\n\
    \  struct node;\n  using ptr=unique_ptr<node>;\n  struct node{\n    S val;\n \
    \   ptr l,r;\n    node(const S&val):val(val),l(nullptr),r(nullptr){}\n  };\n \
    \ const long long n;\n  ptr root;\n  void inner_set(ptr&nd,long long l,long long\
    \ r,long long p,const S&x){\n    if(!nd)nd=make_unique<node>(e());\n    if(r-l==1){nd->val=x;return;}\n\
    \    long long m=(l+r)>>1;\n    if(p<m)inner_set(nd->l,l,m,p,x);\n    else inner_set(nd->r,m,r,p,x);\n\
    \    nd->val=op(nd->l?nd->l->val:e(),nd->r?nd->r->val:e());\n  }\n  S inner_get(const\
    \ ptr&nd,long long l,long long r,long long p)const{\n    if(!nd)return e();\n\
    \    if(r-l==1)return nd->val;\n    long long m=(l+r)>>1;\n    if(p<m)return inner_get(nd->l,l,m,p);\n\
    \    return inner_get(nd->r,m,r,p);\n  }\n  S inner_query(const ptr&nd,long long\
    \ nl,long long nr,long long l,long long r)const{\n    if(!nd||nr<=l||r<=nl)return\
    \ e();\n    if(l<=nl&&nr<=r)return nd->val;\n    long long m=(nl+nr)>>1;\n   \
    \ return op(inner_query(nd->l,nl,m,l,r),inner_query(nd->r,m,nr,l,r));\n  }\n \
    \ void inner_reset(ptr&nd,long long nl,long long nr,long long l,long long r){\n\
    \    if(!nd||nr<=l||r<=nl)return;\n    if(l<=nl&&nr<=r){\n      nd.reset();return;\n\
    \    }\n    long long m=(l+r)>>1;\n    inner_reset(nd->l,nl,m,l,r);\n    inner_reset(nd->r,m,nr,l,r);\n\
    \    nd->val=op(nd->l?nd->l->val:e(),nd->r?nd->r->val:e());\n  }\n};\n/**\n *\
    \ @brief Dynamic Segment Tree(\u52D5\u7684\u30BB\u30B0\u6728)\n */\n#line 4 \"\
    test/yosupo/point_add_range_sum3.test.cpp\"\nlong long op(long long a,long long\
    \ b){return a+b;}\nlong long e(){return 0;}\nint main(){\n  int n,q;cin>>n>>q;\n\
    \  dynamic_segtree<long long,op,e>seg(n);\n  vi a(n);cin>>a;\n  for(int i=0;i<n;i++)seg.set(i,a[i]);\n\
    \  while(q--){\n    int t,l,r;cin>>t>>l>>r;\n    if(t)cout<<seg.query(l,r)<<endl;\n\
    \    else seg.set(l,seg[l]+r);\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include\"../../template/template.hpp\"\n#include\"../../Data_Structure/dynamic_segtree.hpp\"\
    \nlong long op(long long a,long long b){return a+b;}\nlong long e(){return 0;}\n\
    int main(){\n  int n,q;cin>>n>>q;\n  dynamic_segtree<long long,op,e>seg(n);\n\
    \  vi a(n);cin>>a;\n  for(int i=0;i<n;i++)seg.set(i,a[i]);\n  while(q--){\n  \
    \  int t,l,r;cin>>t>>l>>r;\n    if(t)cout<<seg.query(l,r)<<endl;\n    else seg.set(l,seg[l]+r);\n\
    \  }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - Data_Structure/dynamic_segtree.hpp
  isVerificationFile: true
  path: test/yosupo/point_add_range_sum3.test.cpp
  requiredBy: []
  timestamp: '2022-12-18 04:50:26+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/point_add_range_sum3.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_add_range_sum3.test.cpp
- /verify/test/yosupo/point_add_range_sum3.test.cpp.html
title: test/yosupo/point_add_range_sum3.test.cpp
---
