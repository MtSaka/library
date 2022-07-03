---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_Structure/hash_map.hpp
    title: "HashMap(\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7)"
  - icon: ':heavy_check_mark:'
    path: Math/modular/mod_log.hpp
    title: "Mod Log(\u96E2\u6563\u5BFE\u6570)"
  - icon: ':heavy_check_mark:'
    path: Math/modular/modpow.hpp
    title: "Mod Pow(\u3079\u304D\u4E57)"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "Template(\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"test/yosupo/discrete-logarithm-mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\" \n#line 2 \"template/template.hpp\"\
    \n//#pragma GCC target(\"avx\")\n//#pragma GCC optimize(\"O3\")\n//#pragma GCC\
    \ optimize(\"unroll-loops\")\n#include<bits/stdc++.h>\n#define overload4(a,b,c,d,e,...)\
    \ e\n#define overload3(a,b,c,d,...) d\n#define rep1(a) for(ll i=0;i<(ll)(a);i++)\n\
    #define rep2(i,a) for(ll i=0;i<(ll)(a);i++)\n#define rep3(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)\n\
    #define rep4(i,a,b,c) for(ll i=(ll)(a);i<(ll)(b);i+=(ll)(c))\n#define rep(...)\
    \ overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n#define rrep1(a)\
    \ for(ll i=(ll)(a)-1;i>=0;i--)\n#define rrep2(i,a) for(ll i=(ll)(a)-1;i>=0;i--)\n\
    #define rrep3(i,a,b) for(ll i=(ll)(b)-1;i>=(ll)(a);i--)\n#define rrep(...) overload3(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)\n\
    #define fore(...) for (auto&& __VA_ARGS__)\n#define all1(i) begin(i),end(i)\n\
    #define all2(i,a) begin(i),begin(i)+a\n#define all3(i,a,b) begin(i)+a,begin(i)+b\n\
    #define all(...) overload3(__VA_ARGS__,all3,all2,all1)(__VA_ARGS__)\n#define rall(n)\
    \ (n).rbegin(),(n).rend()\n#define INT(...) int __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)\n#define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define CHR(...) char __VA_ARGS__;scan(__VA_ARGS__)\n#define DBL(...) double __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define LD(...) ld __VA_ARGS__;scan(__VA_ARGS__)\n#define pb push_back\n#define\
    \ eb emplace_back\n#define END(...) {print(__VA_ARGS__);return;}\nusing namespace\
    \ std;\nusing ll=long long;\nusing ull=unsigned long long;\nusing ld=long double;\n\
    using vl=vector<ll>;\nusing vi=vector<int>;\nusing vs=vector<string>;\nusing vc=vector<char>;\n\
    using vvl=vector<vl>;\nusing pi=pair<int,int>;\nusing pl=pair<ll,ll>;\nusing vvc=vector<vc>;\n\
    using vd=vector<double>;\nusing vp=vector<pl>;\nusing vb=vector<bool>;\nconstexpr\
    \ int dx[8]={1,0,-1,0,1,-1,-1,1};\nconstexpr int dy[8]={0,1,0,-1,1,1,-1,-1};\n\
    constexpr ll MOD=1000000007;\nconstexpr ll mod=998244353;\nconstexpr ld EPS=1e-8;\n\
    constexpr ld PI=3.1415926535897932384626;\ntemplate<typename T,typename U>\nostream\
    \ &operator<<(ostream&os,const pair<T,U>&p){os<<p.first<<\" \"<<p.second;return\
    \ os;}\ntemplate<typename T,typename U>\nistream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return\
    \ is;}\ntemplate<typename T>\nostream &operator<<(ostream&os,const vector<T>&v){for(auto\
    \ it=v.begin();it!=v.end();){os<<*it<<((++it)!=v.end()?\" \":\"\");}return os;}\n\
    template<typename T>\nistream &operator>>(istream&is,vector<T>&v){for(T &in:v){is>>in;}return\
    \ is;}\nvoid scan(){}\ntemplate<class Head,class... Tail>\nvoid scan(Head&head,Tail&...\
    \ tail){cin>>head;scan(tail...);}\ntemplate<class T>\nvoid print(const T &t){cout<<t<<'\\\
    n';}\ntemplate<class Head, class... Tail>\nvoid print(const Head &head, const\
    \ Tail &... tail){cout<<head<<' ';print(tail...);}\ntemplate<class... T>\nvoid\
    \ fin(const T &... a){print(a...);exit(0);}\ntemplate<typename T,typename U>\n\
    inline bool chmax(T&a,U b){return a<b&&(a=b,true);}\ntemplate<typename T,typename\
    \ U>\ninline bool chmin(T&a,U b){return a>b&&(a=b,true);}\ntemplate<typename T>\n\
    class infinity{\n  public:\n  static constexpr T MAX=numeric_limits<T>::max();\n\
    \  static constexpr T MIN=numeric_limits<T>::min();\n  static constexpr T value=numeric_limits<T>::max()/2;\n\
    \  static constexpr T mvalue=numeric_limits<T>::min()/2;\n};\n#if __cplusplus\
    \ <= 201402L\ntemplate<class T>constexpr T infinity<T>::value;\ntemplate<class\
    \ T>constexpr T infinity<T>::mvalue;\ntemplate<class T>constexpr T infinity<T>::MAX;\n\
    template<class T>constexpr T infinity<T>::MIN;\n#endif\ntemplate<typename T>constexpr\
    \ T INF=infinity<T>::value;\nconstexpr long long inf=INF<ll>;\ninline int popcnt(ull\
    \ x){\n#if __cplusplus>=202002L\nreturn popcount(x);\n#endif\nx=(x&0x5555555555555555)+((x>>1)&0x5555555555555555);x=(x&0x3333333333333333)+((x>>2)&0x3333333333333333);x=(x&0x0f0f0f0f0f0f0f0f)+((x>>4)&0x0f0f0f0f0f0f0f0f);x=(x&0x00ff00ff00ff00ff)+((x>>8)&0x00ff00ff00ff00ff);x=(x&0x0000ffff0000ffff)+((x>>16)&0x0000ffff0000ffff);return\
    \ (x&0x00000000ffffffff)+((x>>32)&0x00000000ffffffff);\n}\ntemplate<typename T,typename=void>\n\
    struct is_specialize:false_type{};\ntemplate<typename T>\nstruct is_specialize<T,typename\
    \ conditional<false,typename T::iterator, void>::type>:true_type{};\ntemplate<typename\
    \ T>\nstruct is_specialize<T,typename conditional<false,decltype(T::first),void>::type>:true_type{};\n\
    template<typename T>\nstruct is_specialize<T,enable_if_t<is_integral<T>::value,void>>:true_type{};\n\
    void dump(const char&t){cerr<<t;}\nvoid dump(const string&t){cerr<<t;}\nvoid dump(const\
    \ bool&t){cerr<<(t?\"true\":\"false\");}\ntemplate <typename T,enable_if_t<!is_specialize<T>::value,nullptr_t>\
    \ =nullptr>\nvoid dump(const T&t){cerr<<t;}\ntemplate<typename T>\nvoid dump(const\
    \ T&t,enable_if_t<is_integral<T>::value>* =nullptr){string tmp;if(t==infinity<T>::value||t==infinity<T>::MAX)tmp=\"\
    inf\";if(is_signed<T>::value&&(t==infinity<T>::mvalue||t==infinity<T>::MIN))tmp=\"\
    -inf\";if(tmp.empty())tmp=to_string(t);cerr<<tmp;}\ntemplate<typename T,typename\
    \ U>\nvoid dump(const pair<T,U>&);\ntemplate<typename T>\nvoid dump(const T&t,enable_if_t<!is_void<typename\
    \ T::iterator>::value>* =nullptr){cerr<<\"{\";for(auto it=t.begin();it!=t.end();){dump(*it);cerr<<(++it==t.end()?\"\
    \":\",\");}cerr<<\"}\";}\ntemplate<typename T,typename U>\nvoid dump(const pair<T,U>&t){cerr<<\"\
    (\";dump(t.first);cerr<<\",\";dump(t.second);cerr<<\")\";}\nvoid trace(){cerr<<endl;}\n\
    template<typename Head,typename... Tail>\nvoid trace(Head&&head,Tail&&... tail){dump(head);if(sizeof...(tail))cerr<<\"\
    ,\";trace(forward<Tail>(tail)...);}\n#ifdef ONLINE_JUDGE\n#define debug(...) (void(0))\n\
    #else\n#define debug(...) do{cerr<<#__VA_ARGS__<<\"=\";trace(__VA_ARGS__);}while(0)\n\
    #endif\nstruct IOSetup{IOSetup(){cin.tie(nullptr);ios::sync_with_stdio(false);cout.tie(0);cout<<fixed<<setprecision(12);cerr<<fixed<<setprecision(12);}};\n\
    template<class F>struct REC{F f;REC(F&&f_):f(std::forward<F>(f_)){}template<class...Args>auto\
    \ operator()(Args&&...args)const{return f(*this, std::forward<Args>(args)...);}};\n\
    /**\n * @brief Template(\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\n#line 2 \"\
    Math/modular/modpow.hpp\"\ntemplate<typename T,typename S>\nT modpow(T a,S b,T\
    \ m){\n  T ret=1;\n  while(b){\n    if(b&1)ret=ret*a%m;\n    a=a*a%m;\n    b>>=1;\n\
    \  }\n  return ret;\n}\n/**\n * @brief Mod Pow(\u3079\u304D\u4E57)\n*/\n#line\
    \ 1 \"Data_Structure/hash_map.hpp\"\ntemplate<typename Key,typename Val>\nstruct\
    \ hash_map{\n  using u32=uint32_t;\n  using u64=uint64_t;\n  using Data=pair<Key,Val>;\n\
    \  protected:\n  template <typename K>\n  inline u64 randomized(const K&key)const{\n\
    \    return u64(key)^r;\n  }\n  template<typename K,enable_if_t<is_integral<K>::value,nullptr_t>\
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
    \ uint32_t DEFAULT_SIZE=4;\n  struct iterator{\n    u32 i;\n    hash_map<Key,Val>*p;\n\
    \    explicit constexpr iterator():i(0),p(nullptr){}\n    explicit constexpr iterator(u32\
    \ i,hash_map<Key,Val>*p):i(i),p(p){}\n    explicit constexpr iterator(u32 i,const\
    \ hash_map<Key,Val>*p):i(i),p(const_cast<hash_map<Key,Val>*>(p)){}\n    const\
    \ Data& operator*()const{\n      return const_cast<hash_map<Key,Val>*>(p)->data[i];\n\
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
    \ hash_map():cap(DEFAULT_SIZE),s(0),data(cap),flag(cap),dflag(cap),shift(62){}\n\
    \  itr begin()const{\n    u32 h=0;\n    while(h!=cap){\n      if(flag[h]&&!dflag[h])break;\n\
    \      h++;\n    }\n    return itr(h,this);\n  }\n  itr end()const{return itr(this->cap,this);}\
    \    \n  friend itr begin(hash_map<Key,Val>&a){return a.begin();}\n  friend itr\
    \ end(hash_map<Key,Val>&a){return a.end();}\n  itr find(const Key&key)const{\n\
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
    \  }\n};\ntemplate<typename Key,typename Val>uint64_t hash_map<Key,Val>::r=chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count();\n\
    /**\n * @brief HashMap(\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7)\n*/\n#line\
    \ 3 \"Math/modular/mod_log.hpp\"\ntemplate<typename T>\nT discrete_logarithm(T\
    \ x,T y,T m){\n  x%=m,y%=m;\n  if(y==1||m==1)return 0;\n  if(x==0)return y==0?1:-1;\n\
    \  T add=0,g,k=1%m;\n  while((g=gcd(x,m))>1){\n    if(y==k)return add;\n    if(y%g)return\
    \ -1;\n    y/=g,m/=g,add++;\n    k=(k*(x/g))%m;\n  }\n  T n=sqrt(m)+1;\n  T tmp=modpow(x,n,m);\n\
    \  hash_map<T,T>mp;\n  for(T i=0,now=y;i<=n;i++){\n    mp[now]=i;\n    now=(now*x)%m;\n\
    \  }\n  for(T i=1,now=k;i<=n;i++){\n    now=(now*tmp)%m;\n    if(mp.contain(now))return\
    \ n*i-mp[now]+add;\n  }\n  return -1;\n}\n/**\n * @brief Mod Log(\u96E2\u6563\u5BFE\
    \u6570)\n*/\n#line 4 \"test/yosupo/discrete-logarithm-mod.test.cpp\"\nint main(){\n\
    \  int t;\n  cin>>t;\n  while(t--){\n    ll x,y,m;\n    cin>>x>>y>>m;\n    print(discrete_logarithm(x,y,m));\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \ \n#include\"../../template/template.hpp\"\n#include\"../../Math/modular/mod_log.hpp\"\
    \nint main(){\n  int t;\n  cin>>t;\n  while(t--){\n    ll x,y,m;\n    cin>>x>>y>>m;\n\
    \    print(discrete_logarithm(x,y,m));\n  }\n}"
  dependsOn:
  - template/template.hpp
  - Math/modular/mod_log.hpp
  - Math/modular/modpow.hpp
  - Data_Structure/hash_map.hpp
  isVerificationFile: true
  path: test/yosupo/discrete-logarithm-mod.test.cpp
  requiredBy: []
  timestamp: '2022-07-03 21:11:59+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/discrete-logarithm-mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/discrete-logarithm-mod.test.cpp
- /verify/test/yosupo/discrete-logarithm-mod.test.cpp.html
title: test/yosupo/discrete-logarithm-mod.test.cpp
---
