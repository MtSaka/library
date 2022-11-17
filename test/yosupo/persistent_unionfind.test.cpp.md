---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_Structure/persistent_array.hpp
    title: "\u6C38\u7D9A\u914D\u5217(Persistent Array)"
  - icon: ':heavy_check_mark:'
    path: Data_Structure/persistent_dsu.hpp
    title: "Persistent Disjoint Set Union(\u6C38\u7D9AUnion-Find)"
  - icon: ':question:'
    path: template/template.hpp
    title: "Template(\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"test/yosupo/persistent_unionfind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n#line 2 \"template/template.hpp\"\
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
    Data_Structure/persistent_array.hpp\"\ntemplate<typename T,int N=1>\nstruct persistent_array{\n\
    \  struct node{\n    T val;\n    node*ch[1<<N]={};\n  };\n  node*root=nullptr;\n\
    \  static constexpr int bit=(1<<N)-1;\n  persistent_array(){}\n  persistent_array(const\
    \ vector<T>&a){\n    build(a);\n  }\n  void build(const vector<T>&a){\n    for(int\
    \ i=0;i<(int)a.size();i++){\n      destructive_set(i,a[i],root);\n    }\n  }\n\
    \  node*get_root(){return root;}\n  void destructive_set(int idx,T val,node*&t){\n\
    \    if(!t)t=new node();\n    if(idx==0)t->val=val;\n    else destructive_set(idx>>N,val,t->ch[idx&bit]);\n\
    \  }\n  node*set(int idx,T val,node*const& t){\n    node*ret=new node();\n   \
    \ if(t){\n      memcpy(ret->ch,t->ch,sizeof(t->ch));\n      ret->val=t->val;\n\
    \    }\n    if(idx==0){\n      ret->val=val;\n    }\n    else{\n      ret->ch[idx&bit]=set(idx>>N,val,ret->ch[idx&bit]);\n\
    \    }\n    return ret;\n  }\n  T get(int idx, node*t){\n    if(!t)return 0;\n\
    \    if(idx==0)return t->val;\n    return get(idx>>N,t->ch[idx&bit]);\n  }\n};\n\
    /**\n * @brief \u6C38\u7D9A\u914D\u5217(Persistent Array)\n*/\n#line 3 \"Data_Structure/persistent_dsu.hpp\"\
    \nstruct persistent_dsu{\n  private:\n  using pa=persistent_array<int,2>;\n  pa\
    \ p;\n  public:\n  using node=pa::node;\n  persistent_dsu(){}\n  persistent_dsu(int\
    \ n){\n    p.build(vector<int>(n,-1));\n  }\n  int root(int x,node*t){\n    if(p.get(x,t)<0)return\
    \ x;\n    return root(p.get(x,t),t);\n  }\n  bool same(int x,int y,node*t){\n\
    \    return root(x,t)==root(y,t);\n  }\n  int size(int x,node*t){\n    return\
    \ -p.get(root(x,t),t);\n  }\n  pair<int,node*>merge(int x,int y,node*t){\n   \
    \ x=root(x,t),y=root(y,t);\n    if(x==y)return {x,t};\n    if(p.get(x,t)>p.get(y,t))swap(x,y);\n\
    \    node*ret=p.set(y,x,p.set(x,p.get(x,t)+p.get(y,t),t));\n    return {x,ret};\n\
    \  }\n  node*get_root(){return p.get_root();}\n};\n/**\n * @brief Persistent Disjoint\
    \ Set Union(\u6C38\u7D9AUnion-Find)\n*/\n#line 4 \"test/yosupo/persistent_unionfind.test.cpp\"\
    \nint main(){\n  int n,q;\n  cin>>n>>q;\n  using node=persistent_dsu::node;\n\
    \  persistent_dsu d(n);\n  vector<node*>g(q+1);\n  g[0]=d.get_root();\n  for(int\
    \ i=1;i<=q;i++){\n    int t,k,u,v;\n    cin>>t>>k>>u>>v;\n    k++;\n    if(t==0){\n\
    \      g[i]=d.merge(u,v,g[k]).second;\n    }\n    else{\n      cout<<d.same(u,v,g[k])<<endl;\n\
    \    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    #include\"../../template/template.hpp\"\n#include\"../../Data_Structure/persistent_dsu.hpp\"\
    \nint main(){\n  int n,q;\n  cin>>n>>q;\n  using node=persistent_dsu::node;\n\
    \  persistent_dsu d(n);\n  vector<node*>g(q+1);\n  g[0]=d.get_root();\n  for(int\
    \ i=1;i<=q;i++){\n    int t,k,u,v;\n    cin>>t>>k>>u>>v;\n    k++;\n    if(t==0){\n\
    \      g[i]=d.merge(u,v,g[k]).second;\n    }\n    else{\n      cout<<d.same(u,v,g[k])<<endl;\n\
    \    }\n  }\n}"
  dependsOn:
  - template/template.hpp
  - Data_Structure/persistent_dsu.hpp
  - Data_Structure/persistent_array.hpp
  isVerificationFile: true
  path: test/yosupo/persistent_unionfind.test.cpp
  requiredBy: []
  timestamp: '2022-08-23 09:51:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/persistent_unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/persistent_unionfind.test.cpp
- /verify/test/yosupo/persistent_unionfind.test.cpp.html
title: test/yosupo/persistent_unionfind.test.cpp
---
