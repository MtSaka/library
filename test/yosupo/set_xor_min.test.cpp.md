---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_Structure/binary_trie.hpp
    title: Binary Trie
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
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/yosupo/set_xor_min.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\
    \n#line 2 \"template/template.hpp\"\n//#pragma GCC target(\"avx\")\n//#pragma\
    \ GCC optimize(\"O3\")\n//#pragma GCC optimize(\"unroll-loops\")\n#include<bits/stdc++.h>\n\
    #define overload4(a,b,c,d,e,...) e\n#define overload3(a,b,c,d,...) d\n#define\
    \ rep1(a) for(ll i=0;i<(ll)(a);i++)\n#define rep2(i,a) for(ll i=0;i<(ll)(a);i++)\n\
    #define rep3(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)\n#define rep4(i,a,b,c) for(ll\
    \ i=(ll)(a);i<(ll)(b);i+=(ll)(c))\n#define rep(...) overload4(__VA_ARGS__, rep4,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\n#define rrep1(a) for(ll i=(ll)(a)-1;i>=0;i--)\n\
    #define rrep2(i,a) for(ll i=(ll)(a)-1;i>=0;i--)\n#define rrep3(i,a,b) for(ll i=(ll)(b)-1;i>=(ll)(a);i--)\n\
    #define rrep(...) overload3(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)\n#define\
    \ fore(...) for (auto&& __VA_ARGS__)\n#define all1(i) begin(i),end(i)\n#define\
    \ all2(i,a) begin(i),begin(i)+a\n#define all3(i,a,b) begin(i)+a,begin(i)+b\n#define\
    \ all(...) overload3(__VA_ARGS__,all3,all2,all1)(__VA_ARGS__)\n#define rall(n)\
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
    Data_Structure/binary_trie.hpp\"\ntemplate<class S,int B=(sizeof(S)*8-1)>\nstruct\
    \ binary_trie{\n  private:\n  struct node{\n    int ch[2];\n    int count;\n \
    \   node():ch{-1,-1},count(0){}\n  };\n  int sz=1;\n  vector<node>v;\n  S xor_all=0;\n\
    \  int find(S x,S xor_val=0)const{\n    xor_val^=xor_all;\n    int idx=0;\n  \
    \  for(int i=B-1;i>=0;i--){\n      int b=(x>>i)&1;\n      if((xor_val>>i)&1)b^=1;\n\
    \      if(v[idx].ch[b]==-1)return -1;\n      idx=v[idx].ch[b];\n    }\n    return\
    \ idx;\n  }\n  int make(){v.emplace_back(node());return sz++;}\n  public:\n  binary_trie():v(1){}\n\
    \  void reserve(int n){v.reserve(n*4+1);}\n  void insert(S x,S xor_val=0){add(x,1,xor_val);}\n\
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
    };\n/*\ntemplate<class S,int B=(sizeof(S)*8-1)>\nstruct binary_trie{\n  private:\n\
    \  struct node{\n    node*ch[2];\n    int count;\n    node():ch{nullptr,nullptr},count(0){}\n\
    \  };\n  node*root;\n  S xor_all=0;\n  node* find(S x,S xor_val=0)const{\n   \
    \ xor_val^=xor_all;\n    node*u=root;\n    for(int i=B-1;i>=0;i--){\n      int\
    \ b=(x>>i)&1;\n      if((xor_val>>i)&1)b^=1;\n      if(u->ch[b]==nullptr)return\
    \ nullptr;\n      u=u->ch[b];\n    }\n    return u;\n  }\n  public:\n  binary_trie():root(new\
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
    };\n*/\n/**\n * @brief Binary Trie\n*/\n#line 4 \"test/yosupo/set_xor_min.test.cpp\"\
    \nint main(){\n  binary_trie<int>bt;\n  int q;cin>>q;\n  bt.reserve(q);\n  while(q--){\n\
    \    int t,x;cin>>t>>x;\n    if(t==0){\n      if(!bt.count(x))bt.insert(x);\n\
    \    }\n    else if(t==1){\n      if(bt.count(x))bt.erase(x);\n    }\n    else{\n\
    \      print(bt.min_element(x));\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n#include\"\
    ../../template/template.hpp\"\n#include\"../../Data_Structure/binary_trie.hpp\"\
    \nint main(){\n  binary_trie<int>bt;\n  int q;cin>>q;\n  bt.reserve(q);\n  while(q--){\n\
    \    int t,x;cin>>t>>x;\n    if(t==0){\n      if(!bt.count(x))bt.insert(x);\n\
    \    }\n    else if(t==1){\n      if(bt.count(x))bt.erase(x);\n    }\n    else{\n\
    \      print(bt.min_element(x));\n    }\n  }\n}"
  dependsOn:
  - template/template.hpp
  - Data_Structure/binary_trie.hpp
  isVerificationFile: true
  path: test/yosupo/set_xor_min.test.cpp
  requiredBy: []
  timestamp: '2022-07-26 00:54:51+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/set_xor_min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/set_xor_min.test.cpp
- /verify/test/yosupo/set_xor_min.test.cpp.html
title: test/yosupo/set_xor_min.test.cpp
---
