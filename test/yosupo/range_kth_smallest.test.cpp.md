---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_Structure/bit_vector.hpp
    title: Bit Vector
  - icon: ':heavy_check_mark:'
    path: Data_Structure/wavelet_matrix.hpp
    title: Wavelet Matrix
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
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"test/yosupo/range_kth_smallest.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n#line 1 \"template/template.hpp\"\
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
    Data_Structure/bit_vector.hpp\"\nstruct bit_vector{\n  private:\n  size_t size,block;\n\
    \  vector<unsigned int>bit,sum;\n  public:\n  bit_vector(){}\n  bit_vector(size_t\
    \ size):size(size),block((size+31)>>5),bit(block,0u),sum(block,0u){}\n  void set(int\
    \ i){bit[i>>5]|=1u<<(i&31);}\n  bool operator[](int i)const{return (bit[i>>5]>>(i&31))&1;}\n\
    \  void build(){\n    sum[0]=0u;\n    for(size_t i=1;i<block;i++)sum[i]=sum[i-1]+__builtin_popcount(bit[i-1]);\n\
    \  }\n  int rank(int i)const{return sum[i>>5]+__builtin_popcount(bit[i>>5]&((1<<(i&31))-1));}\n\
    \  int rank(bool v,int i)const{return (v?rank(i):i-rank(i));}\n};\n/**\n * @brief\
    \ Bit Vector\n*/\n#line 3 \"Data_Structure/wavelet_matrix.hpp\"\ntemplate<typename\
    \ T,int LOG>\nstruct wavelet_matrix{\n  private:\n  size_t size;\n  bit_vector\
    \ matrix[LOG];\n  int mid[LOG];\n  public:\n  wavelet_matrix(){}\n  wavelet_matrix(vector<T>v):size(v.size()){\n\
    \    vector<T>left(size),right(size);\n    for(int level=LOG-1;level>=0;level--){\n\
    \      matrix[level]=bit_vector(size+1);\n      int l=0,r=0;\n      for(size_t\
    \ i=0;i<size;i++){\n        if((v[i]>>level)&1)right[r++]=v[i],matrix[level].set(i);\n\
    \        else left[l++]=v[i];\n      }\n      mid[level]=l;\n      matrix[level].build();\n\
    \      swap(v,left);\n      for(int i=0;i<r;i++)v[l+i]=right[i];\n    }\n  }\n\
    \  T access(int i)const{\n    T ret=0;\n    for(int level=LOG-1;level>=0;level--){\n\
    \      bool f=matrix[level][i];\n      if(f)ret|=T(1)<<level;\n      i=mid[level]*f+matrix[level].rank(f,i);\n\
    \    }\n    return ret;\n  }\n  T operator[](int i)const{return access(i);}\n\
    \  pair<int,int>succ(bool f,int l,int r,int level)const{\n    return {matrix[level].rank(f,l)+mid[level]*f,matrix[level].rank(f,r)+mid[level]*f};\n\
    \  }\n  int rank(int r,const T&x)const{\n    int l=0;\n    for(int level=LOG-1;level>=0;level--){\n\
    \      tie(l,r)=succ((x>>level)&1,l,r,level);\n    }\n    return r-l;\n  }\n \
    \ T kth_smallest(int l,int r,int k)const{\n    T ret=0;\n    for(int level=LOG-1;level>=0;level--){\n\
    \      int cnt=matrix[level].rank(false,r)-matrix[level].rank(false,l);\n    \
    \  bool f=(cnt<=k);\n      if(f){\n        ret|=T(1)<<level;\n        k-=cnt;\n\
    \      }\n      tie(l,r)=succ(f,l,r,level);\n    }\n    return ret;\n  }\n  T\
    \ kth_largest(int l,int r,int k)const{return kth_smallest(l,r,r-l-1-k);}\n  int\
    \ range_freq(int l,int r,T high)const{\n    int ret=0;\n    for(int level=LOG-1;level>=0;level--){\n\
    \      bool f=(high>>level)&1;\n      if(f)ret+=matrix[level].rank(false,r)-matrix[level].rank(false,l);\n\
    \      tie(l,r)=succ(f,l,r,level);\n    }\n    return ret;\n  }\n  int range_freq(int\
    \ l,int r,T low,T high)const{return range_freq(l,r,high)-range_freq(l,r,low);}\n\
    \  int prev_val(int l,int r,T x)const{\n    int cnt=range_freq(l,r,x);\n    return\
    \ (cnt==0?T(-1):kth_smallest(l,r,cnt-1));\n  }\n  int next_val(int l,int r,T x)const{\n\
    \    int cnt=range_freq(l,r,x);\n    return (cnt==r-l?T(-1):kth_largest(l,r,cnt));\n\
    \  }\n};\n\ntemplate<typename T,int LOG>\nstruct compressed_wavelet_matrix{\n\
    \  private:\n  wavelet_matrix<int,LOG>w;\n  vector<T>v;\n  int get(const T&x)const{return\
    \ lower_bound(v.begin(),v.end(),x)-v.begin();}\n  public:\n  compressed_wavelet_matrix(){}\n\
    \  compressed_wavelet_matrix(const vector<T>&x):v(x){\n    sort(v.begin(),v.end());\n\
    \    v.erase(unique(v.begin(),v.end()),v.end());\n    vector<int>t(x.size());\n\
    \    for(int i=0;i<(int)x.size();i++)t[i]=get(x[i]);\n    w=wavelet_matrix<int,LOG>(t);\n\
    \  }\n  T access(int i)const{return v[w.access(i)];}\n  T operator[](int i)const{return\
    \ access(i);}\n  int rank(int r,const T&x)const{\n    auto idx=get(x);\n    if(idx==(int)v.size()||v[idx]!=x)return\
    \ 0;\n    return w.rank(r,idx);\n  }\n  T kth_smallest(int l,int r,int k)const{\n\
    \    return v[w.kth_smallest(l,r,k)];\n  }\n  T kth_largest(int l,int r,int k)const{\n\
    \    return v[w.kth_largest(l,r,k)];\n  }\n  int range_freq(int l,int r,T high)const{\n\
    \    return w.range_freq(l,r,get(high));\n  }\n  int range_freq(int l,int r,T\
    \ low,T high)const{\n    return w.range_freq(l,r,get(low),get(high));\n  }\n \
    \ T prev_val(int l,int r,T high)const{\n    auto ret=w.prev_val(l,r,get(high));\n\
    \    return ret==-1?T(-1):v[ret];\n  }\n  T next_val(int l,int r,T low)const{\n\
    \    auto ret=w.next_val(l,r,get(low));\n    return ret==-1?T(-1):v[ret];\n  }\n\
    };\n/**\n * @brief Wavelet Matrix\n*/\n#line 4 \"test/yosupo/range_kth_smallest.test.cpp\"\
    \nint main(){\n  int n,q;\n  cin>>n>>q;\n  vi a(n);cin>>a;\n  compressed_wavelet_matrix<int,18>w(a);\n\
    \  while(q--){\n    int l,r,k;\n    cin>>l>>r>>k;\n    print(w.kth_smallest(l,r,k));\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\
    #include\"../../template/template.hpp\"\n#include\"../../Data_Structure/wavelet_matrix.hpp\"\
    \nint main(){\n  int n,q;\n  cin>>n>>q;\n  vi a(n);cin>>a;\n  compressed_wavelet_matrix<int,18>w(a);\n\
    \  while(q--){\n    int l,r,k;\n    cin>>l>>r>>k;\n    print(w.kth_smallest(l,r,k));\n\
    \  }\n}"
  dependsOn:
  - template/template.hpp
  - Data_Structure/wavelet_matrix.hpp
  - Data_Structure/bit_vector.hpp
  isVerificationFile: true
  path: test/yosupo/range_kth_smallest.test.cpp
  requiredBy: []
  timestamp: '2022-07-02 00:42:50+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/range_kth_smallest.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_kth_smallest.test.cpp
- /verify/test/yosupo/range_kth_smallest.test.cpp.html
title: test/yosupo/range_kth_smallest.test.cpp
---
