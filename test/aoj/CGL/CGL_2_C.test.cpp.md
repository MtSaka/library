---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Geometry/geometry.hpp
    title: Geometry/geometry.hpp
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
    ERROR: 1e-6
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_C
  bundledCode: "#line 1 \"test/aoj/CGL/CGL_2_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_C\"\
    \n#define ERROR 1e-6\n#line 1 \"template/template.hpp\"\n//#pragma GCC target(\"\
    avx\")\n//#pragma GCC optimize(\"O3\")\n//#pragma GCC optimize(\"unroll-loops\"\
    )\n#include<bits/stdc++.h>\n#define overload4(a,b,c,d,e,...) e\n#define overload3(a,b,c,d,...)\
    \ d\n#define rep1(a) for(ll i=0;i<(ll)(a);i++)\n#define rep2(i,a) for(ll i=0;i<(ll)(a);i++)\n\
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
    /**\n * @brief Template(\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\n#line 2 \"\
    Geometry/geometry.hpp\"\nnamespace geometry{\n  const long double eps=1e-9;\n\
    \  const long double pi=acos(-1.0);\n  bool equals(long double a,long double b){return\
    \ fabs(a-b)<eps;}\n  long double torad(long double deg){return deg*pi/180.0;}\n\
    \  long double todeg(long double rad){return rad*180.0/pi;}\n  int sign(long double\
    \ a){return (a>eps?1:(a<-eps?-1:0));}\n  struct point{\n    long double x,y;\n\
    \    point(long double x=0.0,long double y=0.0):x(x),y(y){}\n    point operator-()const{return\
    \ point(-x,-y);}\n    point operator+(const point&p)const{return point(x+p.x,y+p.y);}\n\
    \    point operator-(const point&p)const{return point(x-p.x,y-p.y);}\n    point\
    \ operator*(const long double&k)const{return point(x*k,y*k);}\n    point operator/(const\
    \ long double&k)const{return point(x/k,y/k);}\n    point operator*(const point&p)const{return\
    \ point(x*p.x-y*p.y,x*p.y+y*p.x);}\n    point operator/(const point&p)const{return\
    \ point((x*p.x+y*p.y)/p.norm(),(x*p.y-y*p.x)/p.norm());}\n    point& operator*=(const\
    \ long double&k){x*=k;y*=k;return *this;}\n    point& operator/=(const long double&k){x/=k;y/=k;return\
    \ *this;}\n    point& operator+=(const point&p){x+=p.x;y+=p.y;return *this;}\n\
    \    point& operator-=(const point&p){x-=p.x;y-=p.y;return *this;}\n    bool operator==(const\
    \ point&p){return equals(x,p.x)&&equals(y,p.y);}\n    long double abs()const{return\
    \ sqrt(norm());}\n    long double norm()const{return x*x+y*y;}\n    static point\
    \ polar(long double r,long double theta){return point(r*cos(theta),r*sin(theta));}\n\
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
    \ \n    }\n    return in;\n  }\n};\n#line 5 \"test/aoj/CGL/CGL_2_C.test.cpp\"\n\
    int main(){\n  cout<<fixed<<setprecision(15);\n  int q;\n  cin>>q;\n  while(q--){\n\
    \    geometry::point p1,p2,q1,q2;\n    cin>>p1>>p2>>q1>>q2;\n    geometry::line\
    \ a(p1,p2),b(q1,q2);\n    auto ans=geometry::crosspoint(a,b);\n    cout<<ans.x<<\"\
    \ \"<<ans.y<<endl;\n  }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_C\"\
    \n#define ERROR 1e-6\n#include\"../../../template/template.hpp\"\n#include\"../../../Geometry/geometry.hpp\"\
    \nint main(){\n  cout<<fixed<<setprecision(15);\n  int q;\n  cin>>q;\n  while(q--){\n\
    \    geometry::point p1,p2,q1,q2;\n    cin>>p1>>p2>>q1>>q2;\n    geometry::line\
    \ a(p1,p2),b(q1,q2);\n    auto ans=geometry::crosspoint(a,b);\n    cout<<ans.x<<\"\
    \ \"<<ans.y<<endl;\n  }\n}"
  dependsOn:
  - template/template.hpp
  - Geometry/geometry.hpp
  isVerificationFile: true
  path: test/aoj/CGL/CGL_2_C.test.cpp
  requiredBy: []
  timestamp: '2022-06-28 01:57:16+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL/CGL_2_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL/CGL_2_C.test.cpp
- /verify/test/aoj/CGL/CGL_2_C.test.cpp.html
title: test/aoj/CGL/CGL_2_C.test.cpp
---
