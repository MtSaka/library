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
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/set_xor_min.test.cpp
    title: test/yosupo/set_xor_min.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Binary Trie
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
    constexpr ld PI=3.1415926535897932384626;\nconstexpr ll mod=998244353;\nconstexpr\
    \ ll MOD=1000000007;\nconstexpr int dx[8]={1,0,-1,0,1,-1,-1,1};\nconstexpr int\
    \ dy[8]={0,1,0,-1,1,1,-1,-1};\n#line 5 \"template/func.hpp\"\n\ninline constexpr\
    \ int msb(ull x){\n  int res=x?0:-1;\n  if(x&0xffffffff00000000)x&=0xffffffff00000000,res+=32;\n\
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
    #endif\n#line 8 \"template/template.hpp\"\nusing namespace std;\n#line 3 \"data-structure/binary-trie.hpp\"\
    \n\ntemplate<class S,int B=(sizeof(S)*8-1)>\nstruct BinaryTrie{\n  private:\n\
    \  struct node{\n    int ch[2];\n    int count;\n    node():ch{-1,-1},count(0){}\n\
    \  };\n  int sz=1;\n  vector<node>v;\n  S xor_all=0;\n  int find(S x,S xor_val=0)const{\n\
    \    xor_val^=xor_all;\n    int idx=0;\n    for(int i=B-1;i>=0;i--){\n      int\
    \ b=(x>>i)&1;\n      if((xor_val>>i)&1)b^=1;\n      if(v[idx].ch[b]==-1)return\
    \ -1;\n      idx=v[idx].ch[b];\n    }\n    return idx;\n  }\n  int make(){v.emplace_back(node());return\
    \ sz++;}\n  public:\n  BinaryTrie():v(1){}\n  void insert(S x,S xor_val=0){add(x,1,xor_val);}\n\
    \  void erase(S x,S xor_val=0){add(x,-1,xor_val);}\n  void add(S x,int a,S xor_val=0){\n\
    \    xor_val^=xor_all;\n    int idx=0;\n    v[idx].count+=a;\n    for(int i=B-1;i>=0;i--){\n\
    \      int b=(x>>i)&1;\n      if((xor_val>>i)&1)b^=1;\n      if(v[idx].ch[b]==-1)v[idx].ch[b]=make();\n\
    \      idx=v[idx].ch[b];\n      v[idx].count+=a;\n    }\n  }\n  S min_element(S\
    \ xor_val=0)const{return kth_element(0,xor_val);}\n  S max_element(S xor_val=0)const{return\
    \ kth_element(size()-1,xor_val);}\n  S kth_element(int k,S xor_val=0)const{\n\
    \    xor_val^=xor_all;\n    int idx=0;\n    S ret=0;\n    for(int i=B-1;i>=0;i--){\n\
    \      bool f=(xor_val>>i)&1;\n      int u0=(f?v[idx].ch[1]:v[idx].ch[0]);\n \
    \     int u1=(f?v[idx].ch[0]:v[idx].ch[1]);\n      if(u0==-1||v[u0].count<=k){\n\
    \        if(u0!=-1)k-=v[u0].count;\n        idx=u1;\n        ret|=(S(1)<<i);\n\
    \      }\n      else idx=u0;\n    }\n    return ret;\n  }\n  int order(S k,S xor_val=0)const{\n\
    \    xor_val^=xor_all;\n    int idx=0;\n    int order=0;\n    for(int i=B-1;i>=0;i--){\n\
    \      bool b=(k>>i)&1;\n      bool f=(xor_val>>i)&1;\n      int u0=(f?v[idx].ch[1]:v[idx].ch[0]);\n\
    \      int u1=(f?v[idx].ch[0]:v[idx].ch[1]);\n      if(b){\n        if(u0!=-1)order+=v[u0].count;\n\
    \        idx=u1;\n      }\n      else idx=u0;\n      if(idx==-1)break;\n    }\n\
    \    return order;\n  }\n  S lower_bound(S k,S xor_val=0)const{\n    return kth_element(order(k,xor_val));\n\
    \  }\n  S upper_bound(S k,S xor_val=0)const{\n    return kth_element(order(k+1,xor_val));\n\
    \  }\n  void all_xor(S x){xor_all^=x;}\n  int count(S x)const{\n    int tmp=find(x);\n\
    \    return (tmp==-1?0:v[tmp].count);\n  }\n  int size()const{return v[0].count;}\n\
    };\n/*\ntemplate<class S,int B=(sizeof(S)*8-1)>\nstruct BinaryTrie{\n  private:\n\
    \  struct node{\n    node*ch[2];\n    int count;\n    node():ch{nullptr,nullptr},count(0){}\n\
    \  };\n  node*root;\n  S xor_all=0;\n  node* find(S x,S xor_val=0)const{\n   \
    \ xor_val^=xor_all;\n    node*u=root;\n    for(int i=B-1;i>=0;i--){\n      int\
    \ b=(x>>i)&1;\n      if((xor_val>>i)&1)b^=1;\n      if(u->ch[b]==nullptr)return\
    \ nullptr;\n      u=u->ch[b];\n    }\n    return u;\n  }\n  public:\n  BinaryTrie():root(new\
    \ node()){}\n  void insert(S x,S xor_val=0){add(x,1,xor_val);}\n  void erase(S\
    \ x,S xor_val=0){add(x,-1,xor_val);}\n  void add(S x,int a,S xor_val=0){\n   \
    \ xor_val^=xor_all;\n    node*u=root;\n    u->count+=a;\n    for(int i=B-1;i>=0;i--){\n\
    \      int b=(x>>i)&1;\n      if((xor_val>>i)&1)b^=1;\n      if(u->ch[b]==nullptr)u->ch[b]=new\
    \ node();\n      u=u->ch[b];\n      u->count+=a;\n    }\n  }\n  S min_element(S\
    \ xor_val=0)const{return kth_element(0,xor_val);}\n  S max_element(S xor_val=0)const{return\
    \ kth_element(size()-1,xor_val);}\n  S kth_element(int k,S xor_val=0)const{\n\
    \    xor_val^=xor_all;\n    node*u=root;\n    S ret=0;\n    for(int i=B-1;i>=0;i--){\n\
    \      bool f=(xor_val>>i)&1;\n      node*u0=(f?u->ch[1]:u->ch[0]);\n      node*u1=(f?u->ch[0]:u->ch[1]);\n\
    \      if(u0==nullptr||u0->count<=k){\n        if(u0!=nullptr)k-=u0->count;\n\
    \        u=u1;\n        ret|=(S(1)<<i);\n      }\n      else u=u0;\n    }\n  \
    \  return ret;\n  }\n  int order(S k,S xor_val=0)const{\n    xor_val^=xor_all;\n\
    \    node*u=root;\n    int order=0;\n    for(int i=B-1;i>=0;i--){\n      bool\
    \ b=(k>>i)&1;\n      bool f=(xor_val>>i)&1;\n      node*u0=(f?u->ch[1]:u->ch[0]);\n\
    \      node*u1=(f?u->ch[0]:u->ch[1]);\n      if(b){\n        if(u0!=nullptr)order+=u0->count;\n\
    \        u=u1;\n      }\n      else u=u0;\n      if(u==nullptr)break;\n    }\n\
    \    return order;\n  }\n  S lower_bound(S k,S xor_val=0)const{\n    return kth_element(order(k,xor_val));\n\
    \  }\n  S upper_bound(S k,S xor_val=0)const{\n    return kth_element(order(k+1,xor_val));\n\
    \  }\n  void all_xor(S x){xor_all^=x;}\n  int count(S x)const{\n    node*tmp=find(x);\n\
    \    return (tmp==nullptr?0:tmp->count);\n  }\n  int size()const{return root->count;}\n\
    };\n*/\n/**\n * @brief Binary Trie\n*/\n"
  code: "#pragma once\n#include\"../template/template.hpp\"\n\ntemplate<class S,int\
    \ B=(sizeof(S)*8-1)>\nstruct BinaryTrie{\n  private:\n  struct node{\n    int\
    \ ch[2];\n    int count;\n    node():ch{-1,-1},count(0){}\n  };\n  int sz=1;\n\
    \  vector<node>v;\n  S xor_all=0;\n  int find(S x,S xor_val=0)const{\n    xor_val^=xor_all;\n\
    \    int idx=0;\n    for(int i=B-1;i>=0;i--){\n      int b=(x>>i)&1;\n      if((xor_val>>i)&1)b^=1;\n\
    \      if(v[idx].ch[b]==-1)return -1;\n      idx=v[idx].ch[b];\n    }\n    return\
    \ idx;\n  }\n  int make(){v.emplace_back(node());return sz++;}\n  public:\n  BinaryTrie():v(1){}\n\
    \  void insert(S x,S xor_val=0){add(x,1,xor_val);}\n  void erase(S x,S xor_val=0){add(x,-1,xor_val);}\n\
    \  void add(S x,int a,S xor_val=0){\n    xor_val^=xor_all;\n    int idx=0;\n \
    \   v[idx].count+=a;\n    for(int i=B-1;i>=0;i--){\n      int b=(x>>i)&1;\n  \
    \    if((xor_val>>i)&1)b^=1;\n      if(v[idx].ch[b]==-1)v[idx].ch[b]=make();\n\
    \      idx=v[idx].ch[b];\n      v[idx].count+=a;\n    }\n  }\n  S min_element(S\
    \ xor_val=0)const{return kth_element(0,xor_val);}\n  S max_element(S xor_val=0)const{return\
    \ kth_element(size()-1,xor_val);}\n  S kth_element(int k,S xor_val=0)const{\n\
    \    xor_val^=xor_all;\n    int idx=0;\n    S ret=0;\n    for(int i=B-1;i>=0;i--){\n\
    \      bool f=(xor_val>>i)&1;\n      int u0=(f?v[idx].ch[1]:v[idx].ch[0]);\n \
    \     int u1=(f?v[idx].ch[0]:v[idx].ch[1]);\n      if(u0==-1||v[u0].count<=k){\n\
    \        if(u0!=-1)k-=v[u0].count;\n        idx=u1;\n        ret|=(S(1)<<i);\n\
    \      }\n      else idx=u0;\n    }\n    return ret;\n  }\n  int order(S k,S xor_val=0)const{\n\
    \    xor_val^=xor_all;\n    int idx=0;\n    int order=0;\n    for(int i=B-1;i>=0;i--){\n\
    \      bool b=(k>>i)&1;\n      bool f=(xor_val>>i)&1;\n      int u0=(f?v[idx].ch[1]:v[idx].ch[0]);\n\
    \      int u1=(f?v[idx].ch[0]:v[idx].ch[1]);\n      if(b){\n        if(u0!=-1)order+=v[u0].count;\n\
    \        idx=u1;\n      }\n      else idx=u0;\n      if(idx==-1)break;\n    }\n\
    \    return order;\n  }\n  S lower_bound(S k,S xor_val=0)const{\n    return kth_element(order(k,xor_val));\n\
    \  }\n  S upper_bound(S k,S xor_val=0)const{\n    return kth_element(order(k+1,xor_val));\n\
    \  }\n  void all_xor(S x){xor_all^=x;}\n  int count(S x)const{\n    int tmp=find(x);\n\
    \    return (tmp==-1?0:v[tmp].count);\n  }\n  int size()const{return v[0].count;}\n\
    };\n/*\ntemplate<class S,int B=(sizeof(S)*8-1)>\nstruct BinaryTrie{\n  private:\n\
    \  struct node{\n    node*ch[2];\n    int count;\n    node():ch{nullptr,nullptr},count(0){}\n\
    \  };\n  node*root;\n  S xor_all=0;\n  node* find(S x,S xor_val=0)const{\n   \
    \ xor_val^=xor_all;\n    node*u=root;\n    for(int i=B-1;i>=0;i--){\n      int\
    \ b=(x>>i)&1;\n      if((xor_val>>i)&1)b^=1;\n      if(u->ch[b]==nullptr)return\
    \ nullptr;\n      u=u->ch[b];\n    }\n    return u;\n  }\n  public:\n  BinaryTrie():root(new\
    \ node()){}\n  void insert(S x,S xor_val=0){add(x,1,xor_val);}\n  void erase(S\
    \ x,S xor_val=0){add(x,-1,xor_val);}\n  void add(S x,int a,S xor_val=0){\n   \
    \ xor_val^=xor_all;\n    node*u=root;\n    u->count+=a;\n    for(int i=B-1;i>=0;i--){\n\
    \      int b=(x>>i)&1;\n      if((xor_val>>i)&1)b^=1;\n      if(u->ch[b]==nullptr)u->ch[b]=new\
    \ node();\n      u=u->ch[b];\n      u->count+=a;\n    }\n  }\n  S min_element(S\
    \ xor_val=0)const{return kth_element(0,xor_val);}\n  S max_element(S xor_val=0)const{return\
    \ kth_element(size()-1,xor_val);}\n  S kth_element(int k,S xor_val=0)const{\n\
    \    xor_val^=xor_all;\n    node*u=root;\n    S ret=0;\n    for(int i=B-1;i>=0;i--){\n\
    \      bool f=(xor_val>>i)&1;\n      node*u0=(f?u->ch[1]:u->ch[0]);\n      node*u1=(f?u->ch[0]:u->ch[1]);\n\
    \      if(u0==nullptr||u0->count<=k){\n        if(u0!=nullptr)k-=u0->count;\n\
    \        u=u1;\n        ret|=(S(1)<<i);\n      }\n      else u=u0;\n    }\n  \
    \  return ret;\n  }\n  int order(S k,S xor_val=0)const{\n    xor_val^=xor_all;\n\
    \    node*u=root;\n    int order=0;\n    for(int i=B-1;i>=0;i--){\n      bool\
    \ b=(k>>i)&1;\n      bool f=(xor_val>>i)&1;\n      node*u0=(f?u->ch[1]:u->ch[0]);\n\
    \      node*u1=(f?u->ch[0]:u->ch[1]);\n      if(b){\n        if(u0!=nullptr)order+=u0->count;\n\
    \        u=u1;\n      }\n      else u=u0;\n      if(u==nullptr)break;\n    }\n\
    \    return order;\n  }\n  S lower_bound(S k,S xor_val=0)const{\n    return kth_element(order(k,xor_val));\n\
    \  }\n  S upper_bound(S k,S xor_val=0)const{\n    return kth_element(order(k+1,xor_val));\n\
    \  }\n  void all_xor(S x){xor_all^=x;}\n  int count(S x)const{\n    node*tmp=find(x);\n\
    \    return (tmp==nullptr?0:tmp->count);\n  }\n  int size()const{return root->count;}\n\
    };\n*/\n/**\n * @brief Binary Trie\n*/"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: data-structure/binary-trie.hpp
  requiredBy: []
  timestamp: '2022-12-18 17:08:11+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/set_xor_min.test.cpp
documentation_of: data-structure/binary-trie.hpp
layout: document
redirect_from:
- /library/data-structure/binary-trie.hpp
- /library/data-structure/binary-trie.hpp.html
title: Binary Trie
---
