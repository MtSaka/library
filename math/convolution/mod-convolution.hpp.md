---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/convolution/ntt.hpp
    title: "Number Theoretic Transform(\u6570\u8AD6\u5909\u63DB)"
  - icon: ':x:'
    path: math/modular/modint.hpp
    title: modint
  - icon: ':x:'
    path: math/modular/modpow.hpp
    title: "Mod Pow(\u3079\u304D\u4E57)"
  - icon: ':x:'
    path: math/number/fast-prime.hpp
    title: "Fast Prime Factorization(\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3)"
  - icon: ':x:'
    path: math/number/primitive-root.hpp
    title: "Primitive Root(\u539F\u59CB\u6839)"
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
    path: test/yosupo/convolution_mod_1000000007.test.cpp
    title: test/yosupo/convolution_mod_1000000007.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Arbitrary Mod Convolution(\u4EFB\u610Fmod\u7573\u307F\u8FBC\u307F\
      )"
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
    #endif\n#line 8 \"template/template.hpp\"\nusing namespace std;\n#line 3 \"math/modular/modint.hpp\"\
    \n\ntemplate<int m>\nstruct modint{\n  private:\n  unsigned int x;\n  static constexpr\
    \ unsigned int umod(){return m;}\n  public:\n  static modint raw(int v){\n   \
    \ modint ret;\n    ret.x=v;\n    return ret;\n  }\n  constexpr modint():x(0){}\n\
    \  constexpr modint(int y){\n    int v=y%m;\n    if(v<0)v+=m;\n    x=(unsigned\
    \ int)v;\n  }\n  constexpr modint(long long y){\n    long long v=y%(long long)m;\n\
    \    if(v<0)v+=m;\n    x=(unsigned int)v;\n  }\n  constexpr modint(unsigned int\
    \ y){\n    x=(unsigned int)(y%umod());\n  }\n  modint& operator++(){x++;if(x==umod())x=0;return\
    \ *this;}\n  modint& operator--(){if(x==0)x=umod();x--;return *this;}\n  modint\
    \ operator++(int){\n    modint ret=*this;\n    ++*this;\n    return ret;\n  }\n\
    \  modint operator--(int){\n    modint ret=*this;\n    --*this;\n    return ret;\n\
    \  }\n  modint& operator+=(const modint&p){if((x+=p.x)>=umod())x-=umod();return\
    \ *this;}\n  modint& operator-=(const modint&p){if((x-=p.x)>=umod())x+=umod();return\
    \ *this;}\n  modint& operator*=(const modint&p){\n    unsigned long long y=x;\n\
    \    y*=p.x;\n    x=(unsigned int)(y%umod());\n    return *this;\n  }\n  modint&\
    \ operator/=(const modint&p){return *this*=p.inv();}\n  modint operator+()const{return\
    \ *this;}\n  modint operator-()const{return modint()-*this;}\n  modint pow(long\
    \ long n)const{\n    modint ret(1),mul=*this;\n    while(n){\n      if(n&1)ret*=mul;\n\
    \      mul*=mul;\n      n>>=1;\n    }\n    return ret;\n  }\n  modint inv()const{\n\
    \    long long a=x,b=m,u=1,v=0;\n    while(b){\n      long long t=a/b;\n     \
    \ swap(a-=t*b,b);\n      swap(u-=t*v,v);\n    }\n    return modint(u);\n  }\n\
    \  friend modint operator+(const modint&l,const modint&r){return modint(l)+=r;}\n\
    \  friend modint operator-(const modint&l,const modint&r){return modint(l)-=r;}\n\
    \  friend modint operator*(const modint&l,const modint&r){return modint(l)*=r;}\n\
    \  friend modint operator/(const modint&l,const modint&r){return modint(l)/=r;}\n\
    \  friend bool operator==(const modint&l,const modint&r){return l.x==r.x;}\n \
    \ friend bool operator!=(const modint&l,const modint&r){return l.x!=r.x;}\n  friend\
    \ ostream &operator<<(ostream &os,const modint&p) {\n    return os<<p.val();\n\
    \  }\n  friend istream &operator>>(istream &is, modint &a) {\n    long long t;\n\
    \    is>>t;\n    a=modint(t);\n    return (is);\n  }\n  static constexpr int get_mod(){return\
    \ m;}\n  int val()const{return (int)x;}\n};\n/**\n * @brief modint\n*/\n#line\
    \ 3 \"math/number/fast-prime.hpp\"\n\nnamespace fastprime{\n  using i128=__uint128_t;\n\
    \  long long inner_modmul(const long long&x,const long long&y,const long long&p){\n\
    \    return i128(x)*y%p;\n  }\n  long long inner_modpow(long long n,long long\
    \ m,const long long&p){\n    long long res=1;\n    while(m){\n      if(m&1)res=inner_modmul(res,n,p);\n\
    \      n=inner_modmul(n,n,p);\n      m>>=1;\n    }\n    return res;\n  }\n  bool\
    \ miller_rabin(const long long&n,const vector<long long>&p){\n    long long s=__builtin_ctzll(n-1),d=n>>s;\n\
    \    for(long long a:p){\n      if(n<=a)break;\n      long long t=d,y=inner_modpow(a,t,n);\n\
    \      while(t!=n-1&&y!=1&&y!=n-1){\n        y=inner_modmul(y,y,n);\n        t=inner_modmul(t,2,n);\n\
    \      }\n      if(y!=n-1&&!(t&1))return false;\n    }\n    return true;\n  }\n\
    \  bool is_prime(const long long&n){\n    if(n<=2)return n==2;\n    if(!(n&1))return\
    \ false;\n    if(n<=4759123141)return miller_rabin(n,{2,7,61});\n    return miller_rabin(n,{2,325,9375,28178,450775,9780504,1795265022});\n\
    \  }\n  long long factor(const long long&n){\n    if(!(n&1))return 2;\n    else\
    \ if(is_prime(n))return n;\n    int c=2;\n    while(true){\n      auto f=[&](long\
    \ long x){\n        x=inner_modmul(x,x,n)+c;\n        if(x>=n)x-=n;\n        return\
    \ x;\n      };\n      long long x=c,g=1,q=1,xs,y;\n      int m=128;\n      int\
    \ l=1;\n      while(g==1){\n        y=x;\n        for(int i=1;i<l;i++)x=f(x);\n\
    \        int k=0;\n        while(k<l&&g==1){\n          xs=x;\n          for(int\
    \ i=0;i<m&&i<l-k;i++){\n            x=f(x);\n            q=inner_modmul(q,llabs(y-x),n);\n\
    \          }\n          g=__gcd(q,n);\n          k+=m;\n        }\n        l*=2;\n\
    \      }\n      if(g==n){\n        do{\n          xs=f(xs);\n          g=__gcd(llabs(xs-y),n);\n\
    \        }while(g==1);\n      }\n      if(g!=n)return g;\n      c++;\n    }\n\
    \  }\n  vector<long long>factorize_sub(const long long&n){\n    if(n==1)return\
    \ {};\n    long long p=factor(n);\n    if(p==n)return {p};\n    vector<long long>l=factorize_sub(n/p);\n\
    \    vector<long long>r=factorize_sub(p);\n    l.insert(l.end(),r.begin(),r.end());\n\
    \    return l;\n  }\n  vector<long long>factorize(const long long&n,const bool&sorted=true){\n\
    \    vector<long long>res=factorize_sub(n);\n    if(sorted)sort(res.begin(),res.end());\n\
    \    return res;\n  }\n} // namespace fastprime\n/**\n * @brief Fast Prime Factorization(\u9AD8\
    \u901F\u7D20\u56E0\u6570\u5206\u89E3)\n*/\n#line 3 \"math/modular/modpow.hpp\"\
    \n\ntemplate<typename T,typename S>\nT modpow(T a,S b,T m){\n  T ret=1;\n  while(b){\n\
    \    if(b&1)ret=ret*a%m;\n    a=a*a%m;\n    b>>=1;\n  }\n  return ret;\n}\n/**\n\
    \ * @brief Mod Pow(\u3079\u304D\u4E57)\n*/\n#line 5 \"math/number/primitive-root.hpp\"\
    \n\nint primitive_root(int n){\n  if(n==2)return 1;\n  if(n==167772161)return\
    \ 3;\n  if(n==469762049)return 3;\n  if(n==754974721)return 11;\n  if(n==998244353)return\
    \ 3;\n  if(n==1224736769)return 3;\n  auto divs=fastprime::factorize(n-1);\n \
    \ divs.erase(unique(divs.begin(),divs.end()),divs.end());\n  for(int g=2;;g++){\n\
    \    bool ok=true;\n    for(int d:divs){\n      if(modpow(g,(n-1)/d,n)==1){\n\
    \        ok=false;\n        break;\n      }\n    }\n    if(ok)return g;\n  }\n\
    }\n/**\n * @brief Primitive Root(\u539F\u59CB\u6839)\n*/\n#line 5 \"math/convolution/ntt.hpp\"\
    \n\ntemplate<int m>\nstruct NTT{\n  using mint=modint<m>;\n  private:\n  static\
    \ modint<m> g;\n  static int limit;\n  static vector<modint<m>>root,inv_root;\n\
    \  static void init(){\n    if(!root.empty())return;\n    g=primitive_root(m);\n\
    \    long long now=m-1;\n    while(!(now&1))now>>=1,limit++;\n    root.resize(limit+1,1),inv_root.resize(limit+1,1);\n\
    \    root[limit]=g.pow(now);\n    inv_root[limit]/=root[limit];\n    for(int i=limit-1;i>=0;i--){\n\
    \      root[i]=root[i+1]*root[i+1];\n      inv_root[i]=inv_root[i+1]*inv_root[i+1];\n\
    \    }\n  }\n  public:\n  NTT(){init();};\n  static void dft(vector<mint>&a,int\
    \ inv){\n    init();\n    const int sz=a.size();\n    if(sz==1)return;\n    const\
    \ int mask=sz-1;\n    vector<mint>b(sz);\n    for(int i=sz>>1;i>=1;i>>=1){\n \
    \     int e=__builtin_ffsll(sz/i)-1;\n      mint w=1,z=(inv==1?root[e]:inv_root[e]);\n\
    \      for(int j=0;j<sz;j+=i){\n        for(int k=0;k<i;k++)b[j+k]=a[((j<<1)&mask)+k]+w*a[(((j<<1)+i)&mask)+k];\n\
    \        w*=z;\n      }\n      swap(a,b);\n    }\n  }\n  static vector<mint>multiply(vector<mint>a,vector<mint>b){\n\
    \    int sz=1;\n    const int mxsiz=a.size()+b.size()-1;\n    while(sz<mxsiz)sz<<=1;\n\
    \    a.resize(sz),b.resize(sz);\n    dft(a,1),dft(b,1);\n    for(int i=0;i<sz;i++)a[i]*=b[i];\n\
    \    dft(a,-1);\n    a.resize(mxsiz);\n    mint iz=mint(sz).inv();\n    for(int\
    \ i=0;i<mxsiz;i++)a[i]*=iz;\n    return a;\n  }\n  template<typename T,std::enable_if_t<is_integral<T>::value>*\
    \ = nullptr>\n  static vector<T>multiply(const vector<T>&a,const vector<T>&b){\n\
    \    vector<mint>a2(a.size()),b2(b.size());\n    for(int i=0;i<(int)a.size();i++)a2[i]=a[i];\n\
    \    for(int i=0;i<(int)b.size();i++)b2[i]=b[i];\n    auto c2=multiply(a2,b2);\n\
    \    vector<T>c(c2.size());\n    for(int i=0;i<(int)c.size();i++)c[i]=c2[i].val();\n\
    \    return c;\n  }\n};\ntemplate<int m>\nint NTT<m>::limit=0;\ntemplate<int m>\n\
    vector<modint<m>>NTT<m>::root=vector<modint<m>>();\ntemplate<int m>\nvector<modint<m>>NTT<m>::inv_root=vector<modint<m>>();\n\
    template<int m>\nmodint<m>NTT<m>::g=modint<m>();\n/**\n * @brief Number Theoretic\
    \ Transform(\u6570\u8AD6\u5909\u63DB)\n*/\n#line 4 \"math/convolution/mod-convolution.hpp\"\
    \n\nvector<long long>mod_convolution(const vector<long long>&a,const vector<long\
    \ long>&b,const long long&m){\n  static constexpr long long m1=167772161,m2=469762049,m3=1224736769,m1_inv_m2=104391568,m12_inv_m3=721017874;\n\
    \  const long long m12_mod=78812994116517889%m;\n  auto x=NTT<m1>::multiply(a,b);\n\
    \  auto y=NTT<m2>::multiply(a,b);\n  auto z=NTT<m3>::multiply(a,b);\n  vector<long\
    \ long>res(x.size());\n  for(int i=0;i<(int)x.size();i++){\n    long long v1=(y[i]-x[i])*m1_inv_m2%m2;\n\
    \    if(v1<0)v1+=m2;\n    long long v2=(z[i]-(x[i]+m1*v1)%m3)*m12_inv_m3%m3;\n\
    \    if(v2<0)v2+=m3;\n    long long c=(x[i]+m1*v1+m12_mod*v2)%m;\n    if(c<0)c+=m;\n\
    \    res[i]=c;\n  }\n  return res;\n}\n/**\n * @brief Arbitrary Mod Convolution(\u4EFB\
    \u610Fmod\u7573\u307F\u8FBC\u307F)\n*/\n"
  code: "#pragma once\n#include\"../../template/template.hpp\"\n#include\"ntt.hpp\"\
    \n\nvector<long long>mod_convolution(const vector<long long>&a,const vector<long\
    \ long>&b,const long long&m){\n  static constexpr long long m1=167772161,m2=469762049,m3=1224736769,m1_inv_m2=104391568,m12_inv_m3=721017874;\n\
    \  const long long m12_mod=78812994116517889%m;\n  auto x=NTT<m1>::multiply(a,b);\n\
    \  auto y=NTT<m2>::multiply(a,b);\n  auto z=NTT<m3>::multiply(a,b);\n  vector<long\
    \ long>res(x.size());\n  for(int i=0;i<(int)x.size();i++){\n    long long v1=(y[i]-x[i])*m1_inv_m2%m2;\n\
    \    if(v1<0)v1+=m2;\n    long long v2=(z[i]-(x[i]+m1*v1)%m3)*m12_inv_m3%m3;\n\
    \    if(v2<0)v2+=m3;\n    long long c=(x[i]+m1*v1+m12_mod*v2)%m;\n    if(c<0)c+=m;\n\
    \    res[i]=c;\n  }\n  return res;\n}\n/**\n * @brief Arbitrary Mod Convolution(\u4EFB\
    \u610Fmod\u7573\u307F\u8FBC\u307F)\n*/"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - math/convolution/ntt.hpp
  - math/modular/modint.hpp
  - math/number/primitive-root.hpp
  - math/number/fast-prime.hpp
  - math/modular/modpow.hpp
  isVerificationFile: false
  path: math/convolution/mod-convolution.hpp
  requiredBy: []
  timestamp: '2022-12-19 04:31:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/convolution_mod_1000000007.test.cpp
documentation_of: math/convolution/mod-convolution.hpp
layout: document
redirect_from:
- /library/math/convolution/mod-convolution.hpp
- /library/math/convolution/mod-convolution.hpp.html
title: "Arbitrary Mod Convolution(\u4EFB\u610Fmod\u7573\u307F\u8FBC\u307F)"
---
