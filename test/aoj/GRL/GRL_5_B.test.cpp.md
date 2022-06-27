---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/tree/rerooting.hpp
    title: "ReRooting(\u5168\u65B9\u4F4D\u6728DP)"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B
  bundledCode: "#line 1 \"test/aoj/GRL/GRL_5_B.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B\"\
    \n#line 1 \"template/template.hpp\"\n//#pragma GCC target(\"avx\")\n//#pragma\
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
    class infinity{\n  public:\n  static const T MAX=numeric_limits<T>::max();\n \
    \ static const T MIN=numeric_limits<T>::min();\n  static const T value=numeric_limits<T>::max()/2;\n\
    \  static const T mvalue=numeric_limits<T>::min()/2;\n};\n#if __cplusplus <= 201402L\n\
    template<class T>const T infinity<T>::value;\ntemplate<class T>const T infinity<T>::mvalue;\n\
    template<class T>const T infinity<T>::MAX;\ntemplate<class T>const T infinity<T>::MIN;\n\
    #endif\ntemplate<typename T>const T INF=infinity<T>::value;\nconst long long inf=INF<ll>;\n\
    inline int popcnt(ull x){\n#if __cplusplus>=202002L\nreturn popcount(x);\n#endif\n\
    x=(x&0x5555555555555555)+((x>>1)&0x5555555555555555);x=(x&0x3333333333333333)+((x>>2)&0x3333333333333333);x=(x&0x0f0f0f0f0f0f0f0f)+((x>>4)&0x0f0f0f0f0f0f0f0f);x=(x&0x00ff00ff00ff00ff)+((x>>8)&0x00ff00ff00ff00ff);x=(x&0x0000ffff0000ffff)+((x>>16)&0x0000ffff0000ffff);return\
    \ (x&0x00000000ffffffff)+((x>>32)&0x00000000ffffffff);\n}\ntemplate<typename T,typename=void>\n\
    struct is_specialize:false_type{};\ntemplate<typename T>\nstruct is_specialize<T,typename\
    \ conditional<false,typename T::iterator, void>::type>:true_type{};\ntemplate<typename\
    \ T>\nstruct is_specialize<T,typename conditional<false,decltype(T::first),void>::type>:true_type{};\n\
    template<typename T>\nstruct is_specialize<T,enable_if_t<is_integral<T>::value,void>>:true_type{};\n\
    void dump(const char&t){cerr<<t;}\nvoid dump(const string&t){cerr<<t;}\nvoid dump(const\
    \ bool&t){cerr<<(t?\"true\":\"false\");}\ntemplate <typename T,enable_if_t<!is_specialize<T>::value,nullptr_t>\
    \ =nullptr>\nvoid dump(const T&t){cerr<<t;}\ntemplate<typename T>\nvoid dump(const\
    \ T&t,enable_if_t<is_integral<T>::value>* =nullptr){string tmp;if(t==infinity<T>::value||t==infinity<T>::MAX)tmp=\"\
    inf\";if(t==infinity<T>::mvalue||t==infinity<T>::MIN)tmp=\"-inf\";if(tmp.empty())tmp=to_string(t);cerr<<tmp;}\n\
    template <typename T>\nvoid dump(const T&t,enable_if_t<!is_void<typename T::iterator>::value>*\
    \ =nullptr){cerr<<\"{\";for(auto it=t.begin();it!=t.end();){dump(*it);cerr<<(++it==t.end()?\"\
    \":\",\");}cerr<<\"}\";}\ntemplate<typename T,typename U>\nvoid dump(const pair<T,U>&t){cerr<<\"\
    (\";dump(t.first);cerr<<\",\";dump(t.second);cerr<<\")\";}\nvoid trace(){cerr<<endl;}\n\
    template<typename Head,typename... Tail>\nvoid trace(Head&&head,Tail&&... tail){dump(head);if(sizeof...(tail))cerr<<\"\
    ,\";trace(forward<Tail>(tail)...);}\n#ifdef ONLINE_JUDGE\n#define debug(...) (void(0))\n\
    #else\n#define debug(...) do{cerr<<#__VA_ARGS__<<\"=\";trace(__VA_ARGS__);}while(0)\n\
    #endif\nstruct IOSetup{IOSetup(){cin.tie(nullptr);ios::sync_with_stdio(false);cout.tie(0);cout<<fixed<<setprecision(12);cerr<<fixed<<setprecision(12);}};\n\
    /**\n * @brief Template(\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\n#line 1 \"\
    Graph/tree/rerooting.hpp\"\ntemplate<typename S,typename T=S>\nstruct ReRooting{\n\
    \  struct Edge{\n    int from,to;\n    S cost;\n    T dp,ndp;\n  };\n  using F=function<T(T,T)>;\n\
    \  using G=function<T(T,Edge)>;\n  vector<vector<Edge>>graph;\n  const F f;\n\
    \  const G g;\n  const T id;\n  vector<T>subdp,dp;\n  void add_edge(int u,int\
    \ v,const S&d) {\n    graph[u].emplace_back(Edge{u,v,d,id,id});\n    graph[v].emplace_back(Edge{v,u,d,id,id});\n\
    \  }\n  void add_directed_edge(int u,int v,const S&d) {\n    graph[u].emplace_back(Edge{u,v,d,id,id});\n\
    \  }\n  ReRooting(int n,const F&f,const G&g,const T&id=T{}):graph(n),f(f),g(g),id(id),subdp(n,id),dp(n,id){}\n\
    \  void dfs_sub(int x,int p){\n    for(auto&e:graph[x])if(e.to!=p){\n      dfs_sub(e.to,x);\n\
    \      e.dp=g(subdp[e.to],e);\n      subdp[x]=f(subdp[x],e.dp);\n    }\n  }\n\
    \  void dfs_all(int x,int p,T top) {\n    T now=id;\n    for(auto&e:graph[x]){\n\
    \      e.ndp=now;\n      if(e.to==p)e.dp=g(top,e);\n      now=f(now,e.dp);\n \
    \   }\n    dp[x]=now;\n    now=id;\n    for(int i=(int)graph[x].size()-1;i>=0;i--){\n\
    \      auto&e=graph[x][i];\n      if(e.to!=p)dfs_all(e.to,x,f(e.ndp,now));\n \
    \     now=f(e.dp,now);\n    }\n  }\n  vector<T>solve(){\n    dfs_sub(0,-1);\n\
    \    dfs_all(0,-1,id);\n    return dp;\n  }\n};\n/**\n * @brief ReRooting(\u5168\
    \u65B9\u4F4D\u6728DP)\n*/\n#line 4 \"test/aoj/GRL/GRL_5_B.test.cpp\"\nlong long\
    \ f(long long a,long long b){\n  return max(a,b);\n}\nlong long g(long long a,ReRooting<long\
    \ long>::Edge b){\n  return a+b.cost;\n}\nint main(){\n  int n;\n  cin>>n;\n \
    \ ReRooting<long long>r(n,f,g);\n  for(int i=0;i<n-1;i++){\n    int s,t;\n   \
    \ long long w;\n    cin>>s>>t>>w;\n    r.add_edge(s,t,w);\n  }\n  auto ans=r.solve();\n\
    \  for(auto i:ans)cout<<i<<endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B\"\
    \n#include\"../../../template/template.hpp\"\n#include\"../../../Graph/tree/rerooting.hpp\"\
    \nlong long f(long long a,long long b){\n  return max(a,b);\n}\nlong long g(long\
    \ long a,ReRooting<long long>::Edge b){\n  return a+b.cost;\n}\nint main(){\n\
    \  int n;\n  cin>>n;\n  ReRooting<long long>r(n,f,g);\n  for(int i=0;i<n-1;i++){\n\
    \    int s,t;\n    long long w;\n    cin>>s>>t>>w;\n    r.add_edge(s,t,w);\n \
    \ }\n  auto ans=r.solve();\n  for(auto i:ans)cout<<i<<endl;\n}"
  dependsOn:
  - template/template.hpp
  - Graph/tree/rerooting.hpp
  isVerificationFile: true
  path: test/aoj/GRL/GRL_5_B.test.cpp
  requiredBy: []
  timestamp: '2022-06-28 00:39:17+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL/GRL_5_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL/GRL_5_B.test.cpp
- /verify/test/aoj/GRL/GRL_5_B.test.cpp.html
title: test/aoj/GRL/GRL_5_B.test.cpp
---
