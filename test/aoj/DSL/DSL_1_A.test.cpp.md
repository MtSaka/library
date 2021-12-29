---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Data_Structure/dsu.hpp
    title: Disjoint Set Union(Union Find)
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
  bundledCode: "#line 1 \"test/aoj/DSL/DSL_1_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n#line 2 \"template/template.hpp\"\n//#pragma GCC target(\"avx\")\n//#pragma\
    \ GCC optimize(\"O3\")\n//#pragma GCC optimize(\"unroll-loops\")\n#include<bits/stdc++.h>\n\
    using namespace std;\nusing ll=long long;\nusing ld=long double;\nusing vl=vector<ll>;\n\
    using vi=vector<int>;\nusing vs=vector<string>;\nusing vc=vector<char>;\nusing\
    \ vvl=vector<vl>;\nusing P=pair<ll,ll>;\nusing vvc=vector<vc>;\nusing vd=vector<double>;\n\
    using vp=vector<P>;\nusing vb=vector<bool>;\n#define overload4(_1,_2,_3,_4,name,...)\
    \ name\n#define overload3(_1,_2,_3,name,...) name\n#define rep1(a) for(__typeof(a)\
    \ i=0;i<a;i++)\n#define rep2(i,a) for(__typeof(a) i=0;i<a;i++)\n#define rep3(i,a,b)\
    \ for(__typeof(a) i=a;i<b;i++)\n#define rep4(i,a,b,c) for(__typeof(a) i=a;i<b;i+=c)\n\
    #define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n\
    #define rrep1(a) for(__typeof(a) i=(a)-1;i>=0;i--)\n#define rrep2(i,a) for(__typeof(a)\
    \ i=(a)-1;i>=0;i--)\n#define rrep3(i,a,b) for(__typeof(a) i=(b)-1;i>=(a);i--)\n\
    #define rrep(...) overload3(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)\n#define\
    \ all1(i) begin(i),end(i)\n#define all2(i,a) begin(i),begin(i)+a\n#define all3(i,a,b)\
    \ begin(i)+a,begin(i)+b\n#define all(...) overload3(__VA_ARGS__,all3,all2,all1)(__VA_ARGS__)\n\
    #define rall(n) (n).rbegin(),(n).rend()\n#define pb push_back\n#define eb emplace_back\n\
    #define MtSaka ios::sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(12)\n\
    #define max_(a) *max_element(all(a))\n#define min_(a) *min_element(all(a))\n#define\
    \ INT(...) int __VA_ARGS__;scan(__VA_ARGS__)\n#define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)\n#define CHR(...) char __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define DBL(...) double __VA_ARGS__;scan(__VA_ARGS__)\n#define LD(...) ld __VA_ARGS__;scan(__VA_ARGS__)\n\
    const int dx[8]={1,0,-1,0,1,-1,-1,1};\nconst int dy[8]={0,1,0,-1,1,1,-1,-1};\n\
    const ll inf=2e18;\nconst ll MOD=1000000007;\nconst ll mod=998244353;\nconst double\
    \ pi=acos(-1);\ntemplate<typename T1,typename T2 >\nostream &operator<<(ostream&os,const\
    \ pair<T1,T2>&p){os<<p.first<<\" \"<<p.second;return os;}\ntemplate<typename T1,typename\
    \ T2>\nistream &operator>>(istream&is,pair<T1,T2>&p){is>>p.first>>p.second;return\
    \ is;}\ntemplate<typename T>\nostream &operator<<(ostream&os,const vector<T>&v){for(int\
    \ i=0;i<(int)v.size();i++){os<<v[i]<<(i+1!=v.size()?\" \":\"\");}return os;}\n\
    template<typename T>\nistream &operator>>(istream&is,vector<T>&v){for(T &in:v){is>>in;}return\
    \ is;}\nvoid scan(){}\ntemplate<class Head,class... Tail>\nvoid scan(Head&head,Tail&...\
    \ tail){cin>>head;scan(tail...);}\ntemplate<class T>\nvoid print(const T &t){cout<<t<<'\\\
    n';}\ntemplate<class Head, class... Tail>\nvoid print(const Head &head, const\
    \ Tail &... tail){cout<<head<<' ';print(tail...);}\ntemplate<class... T>\nvoid\
    \ fin(const T &... a){print(a...);exit(0);}\ntemplate<typename T>\nT sum_(vector<T>a){return\
    \ accumulate(all(a),T(0));}\ntemplate<typename T1,typename T2>\ninline bool chmax(T1&a,T2\
    \ b){return a<b&&(a=b,true);}\ntemplate<typename T1,typename T2>\ninline bool\
    \ chmin(T1&a,T2 b){return a>b&&(a=b,true);}\n/**\n * @brief Template(\u30C6\u30F3\
    \u30D7\u30EC\u30FC\u30C8)\n*/\n#line 1 \"Data_Structure/dsu.hpp\"\n/**\n * @brief\
    \ Disjoint Set Union(Union Find)\n*/\nstruct dsu{\n  vector<int>sz,par;\n  dsu(){}\n\
    \  dsu(int n){\n    sz.resize(n,1);\n    par.resize(n,0);\n    for(int i=0;i<n;i++)par[i]=i;\n\
    \  }\n  int root(int x){\n    if(x==par[x])return x;\n    return par[x]=root(par[x]);\n\
    \  }\n  bool same(int x,int y){return root(x)==root(y);}\n  int size(int x){return\
    \ sz[root(x)];}\n  void merge(int x,int y){\n    x=root(x),y=root(y);\n    if(x==y)return\
    \ ;\n    if(sz[x]>sz[y]){\n      par[y]=x;\n      sz[x]+=sz[y];\n    }\n    else{\n\
    \      par[x]=y;\n      sz[y]+=sz[x];\n    }\n  }\n};\n#line 4 \"test/aoj/DSL/DSL_1_A.test.cpp\"\
    \nint main(){\n  int n,q;\n  cin>>n>>q;\n  dsu d(n);\n  while(q--){\n    int t,x,y;\n\
    \    cin>>t>>x>>y;\n    if(t==0)d.merge(x,y);\n    else print(d.same(x,y));\n\
    \  }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n#include\"../../../template/template.hpp\"\n#include\"../../../Data_Structure/dsu.hpp\"\
    \nint main(){\n  int n,q;\n  cin>>n>>q;\n  dsu d(n);\n  while(q--){\n    int t,x,y;\n\
    \    cin>>t>>x>>y;\n    if(t==0)d.merge(x,y);\n    else print(d.same(x,y));\n\
    \  }\n}"
  dependsOn:
  - template/template.hpp
  - Data_Structure/dsu.hpp
  isVerificationFile: true
  path: test/aoj/DSL/DSL_1_A.test.cpp
  requiredBy: []
  timestamp: '2021-12-29 21:42:40+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL/DSL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL/DSL_1_A.test.cpp
- /verify/test/aoj/DSL/DSL_1_A.test.cpp.html
title: test/aoj/DSL/DSL_1_A.test.cpp
---
