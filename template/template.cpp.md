---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-dpl-1-d.test.cpp
    title: test/verify/aoj-dpl-1-d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-grl-1-a.test.cpp
    title: test/verify/aoj-grl-1-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-grl-1-c.test.cpp
    title: test/verify/aoj-grl-1-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-grl-2-a.test.cpp
    title: test/verify/aoj-grl-2-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-grl-5-c.test.cpp
    title: test/verify/aoj-grl-5-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-convolution-mod.test.cpp
    title: test/verify/yosupo-convolution-mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-lca-3.test.cpp
    title: test/verify/yosupo-lca-3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-shortest-path.test.cpp
    title: test/verify/yosupo-shortest-path.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 1 "template/template.cpp"

    //GIVE ME AC!!!!!!!!!!!!!!!!!

    //#pragma GCC target("avx")

    //#pragma GCC optimize("O3")

    //#pragma GCC optimize("unroll-loops")

    #include<bits/stdc++.h>

    using namespace std;

    using ll=long long;

    using ld=long double;

    using vl=vector<ll>;

    using vi=vector<int>;

    using vs=vector<string>;

    using vc=vector<char>;

    using vvl=vector<vl>;

    using P=pair<ll,ll>;

    using vvc=vector<vc>;

    using vd=vector<double>;

    using vp=vector<P>;

    using vb=vector<bool>;

    #define overload4(_1,_2,_3,_4,name,...) name

    #define overload3(_1,_2,_3,name,...) name

    #define rep1(a) for(__typeof(a) i=0;i<a;i++)

    #define rep2(i,a) for(__typeof(a) i=0;i<a;i++)

    #define rep3(i,a,b) for(__typeof(a) i=a;i<b;i++)

    #define rep4(i,a,b,c) for(__typeof(a) i=a;i<b;i+=c)

    #define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

    #define rrep1(a) for(__typeof(a) i=(a)-1;i>=0;i--)

    #define rrep2(i,a) for(__typeof(a) i=(a)-1;i>=0;i--)

    #define rrep3(i,a,b) for(__typeof(a) i=(b)-1;i>=(a);i--)

    #define rrep(...) overload3(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)

    #define all1(i) begin(i),end(i)

    #define all2(i,a) begin(i),begin(i)+a

    #define all3(i,a,b) begin(i)+a,begin(i)+b

    #define all(...) overload3(__VA_ARGS__,all3,all2,all1)(__VA_ARGS__)

    #define rall(n) (n).rbegin(),(n).rend()

    #define pb push_back

    #define eb emplace_back

    #define MtSaka ios::sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(12)

    #define max_(a) *max_element(all(a))

    #define min_(a) *min_element(all(a))

    #define INT(...) int __VA_ARGS__;scan(__VA_ARGS__)

    #define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)

    #define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)

    #define CHR(...) char __VA_ARGS__;scan(__VA_ARGS__)

    #define DBL(...) double __VA_ARGS__;scan(__VA_ARGS__)

    #define LD(...) ld __VA_ARGS__;scan(__VA_ARGS__)

    const int dx[8]={1,0,-1,0,1,-1,-1,1};

    const int dy[8]={0,1,0,-1,1,1,-1,-1};

    const ll inf=2e18;

    const ll MOD=1000000007;

    const ll mod=998244353;

    const double pi=acos(-1);

    template<typename T1,typename T2 >

    ostream &operator<<(ostream&os,const pair<T1,T2>&p){os<<p.first<<" "<<p.second;return
    os;}

    template<typename T1,typename T2>

    istream &operator>>(istream&is,pair<T1,T2>&p){is>>p.first>>p.second;return is;}

    template<typename T>

    ostream &operator<<(ostream&os,const vector<T>&v){for(int i=0;i<(int)v.size();i++){os<<v[i]<<(i+1!=v.size()?"
    ":"");}return os;}

    template<typename T>

    istream &operator>>(istream&is,vector<T>&v){for(T &in:v){is>>in;}return is;}

    void scan(){}

    template<class Head,class... Tail>

    void scan(Head&head,Tail&... tail){cin>>head;scan(tail...);}

    template<class T>

    void print(const T &t){cout<<t<<''\n'';}

    template<class Head, class... Tail>

    void print(const Head &head, const Tail &... tail){cout<<head<<'' '';print(tail...);}

    template<class... T>

    void fin(const T &... a){print(a...);exit(0);}

    template<typename T>

    T sum_(vector<T>a){return accumulate(all(a),T(0));}

    template<typename T1,typename T2>

    inline bool chmax(T1&a,T2 b){return a<b&&(a=b,true);}

    template<typename T1,typename T2>

    inline bool chmin(T1&a,T2 b){return a>b&&(a=b,true);}

    '
  code: '//GIVE ME AC!!!!!!!!!!!!!!!!!

    //#pragma GCC target("avx")

    //#pragma GCC optimize("O3")

    //#pragma GCC optimize("unroll-loops")

    #include<bits/stdc++.h>

    using namespace std;

    using ll=long long;

    using ld=long double;

    using vl=vector<ll>;

    using vi=vector<int>;

    using vs=vector<string>;

    using vc=vector<char>;

    using vvl=vector<vl>;

    using P=pair<ll,ll>;

    using vvc=vector<vc>;

    using vd=vector<double>;

    using vp=vector<P>;

    using vb=vector<bool>;

    #define overload4(_1,_2,_3,_4,name,...) name

    #define overload3(_1,_2,_3,name,...) name

    #define rep1(a) for(__typeof(a) i=0;i<a;i++)

    #define rep2(i,a) for(__typeof(a) i=0;i<a;i++)

    #define rep3(i,a,b) for(__typeof(a) i=a;i<b;i++)

    #define rep4(i,a,b,c) for(__typeof(a) i=a;i<b;i+=c)

    #define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

    #define rrep1(a) for(__typeof(a) i=(a)-1;i>=0;i--)

    #define rrep2(i,a) for(__typeof(a) i=(a)-1;i>=0;i--)

    #define rrep3(i,a,b) for(__typeof(a) i=(b)-1;i>=(a);i--)

    #define rrep(...) overload3(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)

    #define all1(i) begin(i),end(i)

    #define all2(i,a) begin(i),begin(i)+a

    #define all3(i,a,b) begin(i)+a,begin(i)+b

    #define all(...) overload3(__VA_ARGS__,all3,all2,all1)(__VA_ARGS__)

    #define rall(n) (n).rbegin(),(n).rend()

    #define pb push_back

    #define eb emplace_back

    #define MtSaka ios::sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(12)

    #define max_(a) *max_element(all(a))

    #define min_(a) *min_element(all(a))

    #define INT(...) int __VA_ARGS__;scan(__VA_ARGS__)

    #define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)

    #define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)

    #define CHR(...) char __VA_ARGS__;scan(__VA_ARGS__)

    #define DBL(...) double __VA_ARGS__;scan(__VA_ARGS__)

    #define LD(...) ld __VA_ARGS__;scan(__VA_ARGS__)

    const int dx[8]={1,0,-1,0,1,-1,-1,1};

    const int dy[8]={0,1,0,-1,1,1,-1,-1};

    const ll inf=2e18;

    const ll MOD=1000000007;

    const ll mod=998244353;

    const double pi=acos(-1);

    template<typename T1,typename T2 >

    ostream &operator<<(ostream&os,const pair<T1,T2>&p){os<<p.first<<" "<<p.second;return
    os;}

    template<typename T1,typename T2>

    istream &operator>>(istream&is,pair<T1,T2>&p){is>>p.first>>p.second;return is;}

    template<typename T>

    ostream &operator<<(ostream&os,const vector<T>&v){for(int i=0;i<(int)v.size();i++){os<<v[i]<<(i+1!=v.size()?"
    ":"");}return os;}

    template<typename T>

    istream &operator>>(istream&is,vector<T>&v){for(T &in:v){is>>in;}return is;}

    void scan(){}

    template<class Head,class... Tail>

    void scan(Head&head,Tail&... tail){cin>>head;scan(tail...);}

    template<class T>

    void print(const T &t){cout<<t<<''\n'';}

    template<class Head, class... Tail>

    void print(const Head &head, const Tail &... tail){cout<<head<<'' '';print(tail...);}

    template<class... T>

    void fin(const T &... a){print(a...);exit(0);}

    template<typename T>

    T sum_(vector<T>a){return accumulate(all(a),T(0));}

    template<typename T1,typename T2>

    inline bool chmax(T1&a,T2 b){return a<b&&(a=b,true);}

    template<typename T1,typename T2>

    inline bool chmin(T1&a,T2 b){return a>b&&(a=b,true);}'
  dependsOn: []
  isVerificationFile: false
  path: template/template.cpp
  requiredBy: []
  timestamp: '2021-11-17 20:52:48+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/aoj-dpl-1-d.test.cpp
  - test/verify/aoj-grl-2-a.test.cpp
  - test/verify/yosupo-convolution-mod.test.cpp
  - test/verify/aoj-grl-1-c.test.cpp
  - test/verify/yosupo-lca-3.test.cpp
  - test/verify/aoj-grl-5-c.test.cpp
  - test/verify/yosupo-shortest-path.test.cpp
  - test/verify/aoj-grl-1-a.test.cpp
documentation_of: template/template.cpp
layout: document
redirect_from:
- /library/template/template.cpp
- /library/template/template.cpp.html
title: template/template.cpp
---