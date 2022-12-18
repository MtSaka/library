---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/bit-vector.hpp
    title: Bit Vector
  - icon: ':x:'
    path: data-structure/wavelet-matrix.hpp
    title: Wavelet Matrix
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
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"test/yosupo/range_kth_smallest.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n#line 2 \"template/template.hpp\"\
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
    #endif\n#line 8 \"template/template.hpp\"\nusing namespace std;\n#line 3 \"data-structure/bit-vector.hpp\"\
    \n\nstruct BitVector{\n  private:\n  size_t size,block;\n  vector<unsigned int>bit,sum;\n\
    \  public:\n  BitVector(){}\n  BitVector(size_t size):size(size),block((size+31)>>5),bit(block,0u),sum(block,0u){}\n\
    \  void set(int i){bit[i>>5]|=1u<<(i&31);}\n  bool operator[](int i)const{return\
    \ (bit[i>>5]>>(i&31))&1;}\n  void build(){\n    sum[0]=0u;\n    for(size_t i=1;i<block;i++)sum[i]=sum[i-1]+__builtin_popcount(bit[i-1]);\n\
    \  }\n  int rank(int i)const{return sum[i>>5]+__builtin_popcount(bit[i>>5]&((1<<(i&31))-1));}\n\
    \  int rank(bool v,int i)const{return (v?rank(i):i-rank(i));}\n};\n/**\n * @brief\
    \ Bit Vector\n*/\n#line 4 \"data-structure/wavelet-matrix.hpp\"\n\ntemplate<typename\
    \ T,int LOG>\nstruct WaveletMatrix{\n  private:\n  size_t size;\n  BitVector matrix[LOG];\n\
    \  int mid[LOG];\n  public:\n  WaveletMatrix(){}\n  WaveletMatrix(vector<T>v):size(v.size()){\n\
    \    vector<T>left(size),right(size);\n    for(int level=LOG-1;level>=0;level--){\n\
    \      matrix[level]=BitVector(size+1);\n      int l=0,r=0;\n      for(size_t\
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
    \  }\n};\n\ntemplate<typename T,int LOG>\nstruct CompressedWaveletMatrix{\n  private:\n\
    \  WaveletMatrix<int,LOG>w;\n  vector<T>v;\n  int get(const T&x)const{return lower_bound(v.begin(),v.end(),x)-v.begin();}\n\
    \  public:\n  CompressedWaveletMatrix(){}\n  CompressedWaveletMatrix(const vector<T>&x):v(x){\n\
    \    sort(v.begin(),v.end());\n    v.erase(unique(v.begin(),v.end()),v.end());\n\
    \    vector<int>t(x.size());\n    for(int i=0;i<(int)x.size();i++)t[i]=get(x[i]);\n\
    \    w=WaveletMatrix<int,LOG>(t);\n  }\n  T access(int i)const{return v[w.access(i)];}\n\
    \  T operator[](int i)const{return access(i);}\n  int rank(int r,const T&x)const{\n\
    \    auto idx=get(x);\n    if(idx==(int)v.size()||v[idx]!=x)return 0;\n    return\
    \ w.rank(r,idx);\n  }\n  T kth_smallest(int l,int r,int k)const{\n    return v[w.kth_smallest(l,r,k)];\n\
    \  }\n  T kth_largest(int l,int r,int k)const{\n    return v[w.kth_largest(l,r,k)];\n\
    \  }\n  int range_freq(int l,int r,T high)const{\n    return w.range_freq(l,r,get(high));\n\
    \  }\n  int range_freq(int l,int r,T low,T high)const{\n    return w.range_freq(l,r,get(low),get(high));\n\
    \  }\n  T prev_val(int l,int r,T high)const{\n    auto ret=w.prev_val(l,r,get(high));\n\
    \    return ret==-1?T(-1):v[ret];\n  }\n  T next_val(int l,int r,T low)const{\n\
    \    auto ret=w.next_val(l,r,get(low));\n    return ret==-1?T(-1):v[ret];\n  }\n\
    };\n/**\n * @brief Wavelet Matrix\n*/\n#line 4 \"test/yosupo/range_kth_smallest.test.cpp\"\
    \nint main(){\n  int n,q;\n  cin>>n>>q;\n  vi a(n);cin>>a;\n  CompressedWaveletMatrix<int,18>w(a);\n\
    \  while(q--){\n    int l,r,k;\n    cin>>l>>r>>k;\n    print(w.kth_smallest(l,r,k));\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\
    #include\"../../template/template.hpp\"\n#include\"../../data-structure/wavelet-matrix.hpp\"\
    \nint main(){\n  int n,q;\n  cin>>n>>q;\n  vi a(n);cin>>a;\n  CompressedWaveletMatrix<int,18>w(a);\n\
    \  while(q--){\n    int l,r,k;\n    cin>>l>>r>>k;\n    print(w.kth_smallest(l,r,k));\n\
    \  }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - data-structure/wavelet-matrix.hpp
  - data-structure/bit-vector.hpp
  isVerificationFile: true
  path: test/yosupo/range_kth_smallest.test.cpp
  requiredBy: []
  timestamp: '2022-12-18 23:26:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/range_kth_smallest.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_kth_smallest.test.cpp
- /verify/test/yosupo/range_kth_smallest.test.cpp.html
title: test/yosupo/range_kth_smallest.test.cpp
---
