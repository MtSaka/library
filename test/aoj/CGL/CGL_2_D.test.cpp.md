---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/geometry.hpp
    title: geometry/geometry.hpp
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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-6
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_D
  bundledCode: "#line 1 \"test/aoj/CGL/CGL_2_D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_D\"\
    \n#define ERROR 1e-6\n#line 2 \"template/template.hpp\"\n#include<bits/stdc++.h>\n\
    #line 3 \"template/macro.hpp\"\n\n#define SELECT4(a,b,c,d,e,...) e\n#define SELECT3(a,b,c,d,...)\
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
    #endif\n#line 8 \"template/template.hpp\"\nusing namespace std;\n#line 3 \"geometry/geometry.hpp\"\
    \n\nnamespace geometry{\n  const long double eps=1e-9;\n  const long double pi=acos(-1.0);\n\
    \  bool equals(long double a,long double b){return fabs(a-b)<eps;}\n  long double\
    \ torad(long double deg){return deg*pi/180.0;}\n  long double todeg(long double\
    \ rad){return rad*180.0/pi;}\n  int sign(long double a){return (a>eps?1:(a<-eps?-1:0));}\n\
    \  struct point{\n    long double x,y;\n    point(long double x=0.0,long double\
    \ y=0.0):x(x),y(y){}\n    point operator-()const{return point(-x,-y);}\n    point\
    \ operator+(const point&p)const{return point(x+p.x,y+p.y);}\n    point operator-(const\
    \ point&p)const{return point(x-p.x,y-p.y);}\n    point operator*(const long double&k)const{return\
    \ point(x*k,y*k);}\n    point operator/(const long double&k)const{return point(x/k,y/k);}\n\
    \    point operator*(const point&p)const{return point(x*p.x-y*p.y,x*p.y+y*p.x);}\n\
    \    point operator/(const point&p)const{return point((x*p.x+y*p.y)/p.norm(),(x*p.y-y*p.x)/p.norm());}\n\
    \    point& operator*=(const long double&k){x*=k;y*=k;return *this;}\n    point&\
    \ operator/=(const long double&k){x/=k;y/=k;return *this;}\n    point& operator+=(const\
    \ point&p){x+=p.x;y+=p.y;return *this;}\n    point& operator-=(const point&p){x-=p.x;y-=p.y;return\
    \ *this;}\n    bool operator==(const point&p){return equals(x,p.x)&&equals(y,p.y);}\n\
    \    long double abs()const{return sqrt(norm());}\n    long double norm()const{return\
    \ x*x+y*y;}\n    static point polar(long double r,long double theta){return point(r*cos(theta),r*sin(theta));}\n\
    \  };\n  struct segment{point s,t;segment(point s=0,point t=0):s(s),t(t){}};\n\
    \  struct line{point s,t;line(point s=0,point t=0):s(s),t(t){}};\n  struct circle{point\
    \ c;long double r;circle(point c=0,long double r=0):c(c),r(r){}};\n  struct polygon{\n\
    \    int n;\n    vector<point>ps;\n    polygon(int n=0):n(n),ps(n){}\n    polygon(vector<point>ps):n(ps.size()),ps(ps){}\n\
    \    point &operator[](int i){return ps[i];}\n  };\n  ostream &operator<<(ostream&os,const\
    \ point&p){return os<<p.x<<\" \"<<p.y;}\n  istream &operator>>(istream&is,point&p){return\
    \ is>>p.x>>p.y;}\n  long double cross(point a,point b){return a.x*b.y-a.y*b.x;}\n\
    \  long double dot(point a,point b){return a.x*b.x+a.y*b.y;}\n  point rotate(point\
    \ p,long double theta,point o=point(0,0)){\n    point pp=p-o;\n    point res(pp.x*cos(theta)-pp.y*sin(theta),pp.x*sin(theta)+pp.y*cos(theta));\n\
    \    return res+o;\n  }\n  int ccw(point a,point b,point c){\n    b-=a,c-=a;\n\
    \    if(cross(b,c)>eps)return 1;\n    if(cross(b,c)<-eps)return -1;\n    if(dot(b,c)<0)return\
    \ 2;\n    if(b.norm()<c.norm())return -2;\n    return 0;\n  }\n  bool intersect(point\
    \ a,line l){return abs(ccw(l.s,a,l.t))!=1;}\n  int line_place(line l,line m){\n\
    \    if(intersect(m.s,l)&&intersect(m.t,l))return 1;\n    else if(intersect(0,line(l.t-l.s,m.t-m.s)))return\
    \ 2;\n    else if(sign(dot(l.t-l.s,m.t-m.s))==0)return 3;\n    return 0;\n  }\n\
    \  bool intersect(line l,line m){return line_place(l,m)!=1&&line_place(l,m)!=2;}\n\
    \  bool intersect(line l,segment s){s.s-=l.s,s.t-=l.s;l.t-=l.s,l.s-=l.s;return\
    \ sign(cross(l.t,s.s)*cross(l.t,s.t))!=1;}\n  bool intersect(segment s,segment\
    \ t){return (ccw(s.s,s.t,t.s)*ccw(s.s,s.t,t.t)<=0&&ccw(t.s,t.t,s.s)*ccw(t.s,t.t,s.t)<=0);}\n\
    \  bool intersect(point a,segment s){return ccw(s.s,s.t,a)==0;}\n  bool intersect(line\
    \ l,point a){return intersect(a,l);}\n  bool intersect(segment s,point a){return\
    \ intersect(a,s);}\n  bool intersect(segment s,line l){return intersect(l,s);}\n\
    \  point project(line l,point p){point a=l.t-l.s,b=p-l.s;return l.s+a*(dot(a,b)/a.norm());}\n\
    \  point project(point p,line l){return project(l,p);}\n  point reflect(line l,point\
    \ p){return project(l,p)*2-p;}\n  point reflect(point p,line l){return reflect(l,p);}\n\
    \  long double dist(point p,point q){return (p-q).abs();}\n  long double dist(line\
    \ l,point p){return dist(p,project(l,p));}\n  long double dist(point p,line l){return\
    \ dist(p,project(l,p));}\n  long double dist(line l,line m){\n    if(line_place(l,m)!=2)return\
    \ 0;\n    return dist(l,m.s);\n  }\n  long double dist(line l,segment s){\n  \
    \  if(intersect(l,s))return 0;\n    return min(dist(l,s.s),dist(l,s.t));\n  }\n\
    \  long double dist(segment s,line l){return dist(l,s);}\n  long double dist(segment\
    \ s,point p){\n    point q=project(line(s.s,s.t),p);\n    if(intersect(s,q))return\
    \ (p-q).abs();\n    else return min((s.s-p).abs(),(s.t-p).abs());\n  }\n  long\
    \ double dist(point p,segment s){return dist(s,p);}\n  long double dist(segment\
    \ s,segment t){\n    if(intersect(s,t))return 0;\n    return min(min(dist(s,t.s),dist(s,t.t)),min(dist(t,s.s),dist(t,s.t)));\n\
    \  }\n  point crosspoint(line l,line m){\n    long double a=cross(m.t-m.s,m.s-l.s);\n\
    \    long double b=cross(m.t-m.s,l.t-l.s);\n    if(sign(a)==0&&sign(b)==0)return\
    \ l.s;\n    else if(sign(b)==0)throw \"no crosspoint\";\n    return l.s+(l.t-l.s)*(a/b);\n\
    \  }\n  long double dist(circle c,point p,bool inside_zero=0){\n    if(inside_zero)return\
    \ max(dist(c.c,p)-c.r,(long double)0.0);\n    return max(abs(dist(c.c,p)-c.r),(long\
    \ double)0.0); \n  }\n  long double dist(circle c,line l){return max(dist(l,c.c)-c.r,(long\
    \ double)0.0);}\n  long double dist(circle c,segment s,bool inside_zero=0){\n\
    \    long double sqr1=(s.s-c.c).norm(),sqr2=(s.t-c.c).norm();\n    if(inside_zero==0){\n\
    \      if((sqr1<c.r*c.r)^(sqr2<c.r*c.r))return 0;\n      else if(sqr1<c.r&&sqr2<c.r)return\
    \ c.r-sqrt(max(sqr1,sqr2));\n      return max(dist(s,c.c)-c.r,(long double)0.0);\n\
    \    }\n    else{\n      if(sqr1<c.r*c.r||sqr2<c.r*c.r)return 0;\n      return\
    \ max(dist(s,c.c)-c.r,(long double)0.0);\n    }\n  }\n  long double dist(circle\
    \ c,circle d){\n    long double dir=(c.c-d.c).abs();\n    return sign(dir-abs(c.r-d.r))==1?max(dir-c.r-d.r,(long\
    \ double)0.0):abs(c.r-d.r)-dir;\n  }\n  long double dist(point p,circle c,bool\
    \ inside_zero=0){return dist(c,p,inside_zero);}\n  long double dist(line l,circle\
    \ c){return dist(c,l);}\n  long double dist(segment s,circle c,bool inside_zero=0){return\
    \ dist(c,s,inside_zero);}\n  bool intersect(circle c,point p){return sign(dist(c,p))==0;}\n\
    \  bool intersect(circle c,line l){return sign(dist(c,l))==0;}\n  bool intersect(circle\
    \ c,segment s){return sign(dist(c,s))==0;}\n  bool intersect(circle c,circle d){return\
    \ sign(dist(c,d))==0;}\n  bool intersect(point p,circle c){return intersect(c,p);}\n\
    \  bool intersect(line l,circle c){return intersect(c,l);}\n  bool intersect(segment\
    \ s,circle c){return intersect(c,s);}\n  vector<point>crosspoint(circle c,circle\
    \ d){\n    vector<point>ret;\n    if(sign(dist(c,d))!=0)return ret;\n    point\
    \ cd=d.c-c.c;\n    long double di=cd.abs();\n    long double x=(cd.norm()-d.r*d.r+c.r*c.r)/((long\
    \ double)2.0*di);\n    point inter=c.c+cd*(x/di);\n    point rev=cd*point(0,sqrt(c.r*c.r-x*x)/di);\n\
    \    ret.push_back(inter+rev);\n    if(sign(rev.norm())==0)ret.push_back(inter-rev);\n\
    \    return ret;\n  }\n  vector<point>tangentpoint(circle c,point p){\n    vector<point>ret;\n\
    \    long double sin=c.r/(p-c.c).abs();\n    if(sign(sin-1.0)==0)return ret;\n\
    \    long double theta=pi/2.0-asin(min(sin,(long double)1.0));\n    ret.push_back(c.c+(p-c.c)*point::polar(sin,theta));\n\
    \    if(sign(sin-(long double)1.0)!=0)ret.push_back(c.c+(p-c.c)*point::polar(sin,-theta));\n\
    \    return ret;\n  }\n  point circumcenter(polygon pol){\n    assert(pol.n==3);\n\
    \    pol[0]=(pol[0]-pol[2])/2.0;\n    pol[1]=(pol[1]-pol[2])/2.0;\n    return\
    \ pol[2]+crosspoint(line(pol[0],pol[0]*point(1,1)),line(pol[1],pol[1]*point(1,1)));\n\
    \  }\n  point circumcenter(point a,point b,point c){\n    return circumcenter(polygon(vector<point>{a,b,c}));\n\
    \  }\n  point center_of_gravity(polygon pol){\n    assert(pol.n==3);\n    return\
    \ (pol[0]+pol[1]+pol[2])/3.0;\n  }\n  point center_of_gravity(point p1,point p2,point\
    \ p3){\n    return center_of_gravity(polygon(vector<point>{p1,p2,p3}));\n  }\n\
    \  point innercenter(polygon pol){\n    assert(pol.n==3);\n    long double a=dist(pol[0],pol[1]),b=dist(pol[1],pol[2]),c=dist(pol[2],pol[0]);\n\
    \    return (pol[0]*a+pol[1]*b+pol[2]*c)/(a+b+c);\n  }\n  point innercenter(point\
    \ p1,point p2,point p3){\n    return innercenter(polygon(vector<point>{p1,p2,p3}));\n\
    \  }\n  point orthocenter(polygon pol){\n    assert(pol.n==3);\n    return pol[0]+pol[2]+pol[3]-center_of_gravity(pol)*2.0;\n\
    \  }\n  point orthocenter(point p1,point p2,point p3){\n    return orthocenter(polygon(vector<point>{p1,p2,p3}));\n\
    \  }\n  long double area(polygon&pol){\n    long double ret=0;\n    for(int i=0;i<pol.n;i++)ret+=cross(pol[i],pol[(i+1)%pol.n]);\n\
    \    return ret/2.0;\n  }\n  long double isconvex(polygon&pol){\n    int neg=0,pos=0;\n\
    \    for(int i=0;i<pol.n;i++){\n      int dir=ccw(pol[i],pol[(i+1)%pol.n],pol[(i+2)%pol.n]);\n\
    \      if(dir==1)pos++;\n      else if(dir==-1)neg++;\n    }\n    if(pos&&neg)return\
    \ 0;\n    return 1;\n  }\n  int in_polygon(point p,polygon&pol){\n    int n=pol.n;\n\
    \    bool in=false;\n    for(int i=0;i<n;i++){\n      point a=pol[i],b=pol[(i+1)%n];\n\
    \      if(intersect(p,segment(a,b)))return 2;\n      if(intersect(segment(p,point(p.x+1.0,INT_MAX)),segment(a,b)))in=!in;\
    \ \n    }\n    return in;\n  }\n}//namespace geometry\n#line 5 \"test/aoj/CGL/CGL_2_D.test.cpp\"\
    \nint main(){\n  cout<<fixed<<setprecision(15);\n  int q;\n  cin>>q;\n  while(q--){\n\
    \    geometry::point p1,p2,q1,q2;\n    cin>>p1>>p2>>q1>>q2;\n    geometry::segment\
    \ a(p1,p2),b(q1,q2);\n    auto ans=dist(a,b);\n    cout<<ans<<endl;\n  }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_D\"\
    \n#define ERROR 1e-6\n#include\"../../../template/template.hpp\"\n#include\"../../../geometry/geometry.hpp\"\
    \nint main(){\n  cout<<fixed<<setprecision(15);\n  int q;\n  cin>>q;\n  while(q--){\n\
    \    geometry::point p1,p2,q1,q2;\n    cin>>p1>>p2>>q1>>q2;\n    geometry::segment\
    \ a(p1,p2),b(q1,q2);\n    auto ans=dist(a,b);\n    cout<<ans<<endl;\n  }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - geometry/geometry.hpp
  isVerificationFile: true
  path: test/aoj/CGL/CGL_2_D.test.cpp
  requiredBy: []
  timestamp: '2022-12-18 21:52:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL/CGL_2_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL/CGL_2_D.test.cpp
- /verify/test/aoj/CGL/CGL_2_D.test.cpp.html
title: test/aoj/CGL/CGL_2_D.test.cpp
---
