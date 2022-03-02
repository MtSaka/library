---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Geometry/geometry.hpp\"\nnamespace geometry{\n  const double\
    \ eps=1e-8;\n  const double pi=acos(-1.0);\n  bool equals(double a,double b){return\
    \ fabs(a-b)<eps;}\n  double torad(double deg){return deg*pi/180.0;}\n  double\
    \ todeg(double rad){return rad*180.0/pi;}\n  int sign(double a){return (a>eps?1:(a<-eps?-1:0));}\n\
    \  struct point{\n    double x,y;\n    point(double x=0.0,double y=0.0):x(x),y(y){}\n\
    \    point operator-()const{return point(-x,-y);}\n    point operator+(const point&p)const{return\
    \ point(x+p.x,y+p.y);}\n    point operator-(const point&p)const{return point(x-p.x,y-p.y);}\n\
    \    point operator*(const double&k)const{return point(x*k,y*k);}\n    point operator/(const\
    \ double&k)const{return point(x/k,y/k);}\n    point operator*(const point&p)const{return\
    \ point(x*p.x-y*p.y,x*p.y+y*p.x);}\n    point operator/(const point&p)const{return\
    \ point((x*p.x+y*p.y)/p.norm(),(x*p.y-y*p.x)/p.norm());}\n    point& operator*=(const\
    \ double&k){x*=k;y*=k;return *this;}\n    point& operator/=(const double&k){x/=k;y/=k;return\
    \ *this;}\n    point& operator+=(const point&p){x+=p.x;y+=p.y;return *this;}\n\
    \    point& operator-=(const point&p){x-=p.x;y-=p.y;return *this;}\n    bool operator==(const\
    \ point&p){return equals(x,p.x)&&equals(y,p.y);}\n    double abs()const{return\
    \ sqrt(norm());}\n    double norm()const{return x*x+y*y;}\n    static point polar(double\
    \ r,double theta){return point(r*cos(theta),r*sin(theta));}\n  };\n  struct segment{point\
    \ s,t;segment(point s=0,point t=0):s(s),t(t){}};\n  struct line{point s,t;line(point\
    \ s=0,point t=0):s(s),t(t){}};\n  struct circle{point c;double r;circle(point\
    \ c=0,double r=0):c(c),r(r){}};\n  struct polygon{\n    int n;\n    vector<point>ps;\n\
    \    polygon(int n=0):n(n),ps(n){}\n    polygon(vector<point>ps):n(ps.size()),ps(ps){}\n\
    \    point &operator[](int i){return ps[i];}\n  };\n  ostream &operator<<(ostream&os,const\
    \ point&p){return os<<p.x<<\" \"<<p.y;}\n  istream &operator>>(istream&is,point&p){return\
    \ is>>p.x>>p.y;}\n  double cross(point a,point b){return a.x*b.y-a.y*b.x;}\n \
    \ double dot(point a,point b){return a.x*b.x+a.y*b.y;}\n  point rotate(point o=point(0,0),point\
    \ p,double theta){\n    point pp=p-o;\n    point res(pp.x*cos(theta)-pp.y*sin(theta),pp.x*sin(theta)+pp.y*cos(theta));\n\
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
    \  double dist(point p,point q){return (p-q).abs();}\n  double dist(line l,point\
    \ p){return dist(p,project(l,p));}\n  double dist(point p,line l){return dist(p,project(l,p));}\n\
    \  double dist(line l,line m){\n    if(line_place(l,m)!=2)return 0;\n    return\
    \ dist(l,m.s);\n  }\n  double dist(line l,segment s){\n    if(intersect(l,s))return\
    \ 0;\n    return min(dist(l,s.s),dist(l,s.t));\n  }\n  double dist(segment s,line\
    \ l){return dist(l,s);}\n  double dist(segment s,point p){\n    point q=project(line(s.s,s.t),p);\n\
    \    if(intersect(s,q))return (p-q).abs();\n    else return min((s.s-p).abs(),(s.t-p).abs());\n\
    \  }\n  double dist(point p,segment s){return dist(p,s);}\n  double dist(segment\
    \ s,segment t){\n    if(intersect(s,t))return 0;\n    return min(min(dist(s,t.s),dist(s,t.t)),min(dist(t,s.s),dist(t,s.t)));\n\
    \  }\n  point crosspoint(line l,line m){\n    double a=cross(m.t-m.s,m.s-l.s);\n\
    \    double b=cross(m.t-m.s,l.t-l.s);\n    if(sign(a)==0&&sign(b)==0)return l.s;\n\
    \    else if(sign(b)==0)throw \"no crosspoint\";\n    return l.s+(l.t-l.s)*(a/b);\n\
    \  }\n  double dist(circle c,point p,bool inside_zero=0){\n    if(inside_zero)return\
    \ max(dist(c.c,p)-c.r,0.0);\n    return max(abs(dist(c.c,p)-c.r),0.0); \n  }\n\
    \  double dist(circle c,line l){return max(dist(l,c.c)-c.r,0.0);}\n  double dist(circle\
    \ c,segment s,bool inside_zero=0){\n    double sqr1=(s.s-c.c).norm(),sqr2=(s.t-c.c).norm();\n\
    \    if(inside_zero==0){\n      if((sqr1<c.r*c.r)^(sqr2<c.r*c.r))return 0;\n \
    \     else if(sqr1<c.r&&sqr2<c.r)return c.r-sqrt(max(sqr1,sqr2));\n      return\
    \ max(dist(s,c.c)-c.r,0.0);\n    }\n    else{\n      if(sqr1<c.r*c.r||sqr2<c.r*c.r)return\
    \ 0;\n      return max(dist(s,c.c)-c.r,0.0);\n    }\n  }\n  double dist(circle\
    \ c,circle d){\n    double dir=(c.c-d.c).abs();\n    return sign(dir-abs(c.r-d.r))==1?max(dir-c.r-d.r,0.0):abs(c.r-d.r)-dir;\n\
    \  }\n  double dist(point p,circle c,bool inside_zero=0){return dist(c,p,inside_zero);}\n\
    \  double dist(line l,circle c){return dist(c,l);}\n  double dist(segment s,circle\
    \ c,bool inside_zero=0){return dist(c,s,inside_zero);}\n  bool intersect(circle\
    \ c,point p){return sign(dist(c,p))==0;}\n  bool intersect(circle c,line l){return\
    \ sign(dist(c,l))==0;}\n  bool intersect(circle c,segment s){return sign(dist(c,s))==0;}\n\
    \  bool intersect(circle c,circle d){return sign(dist(c,d))==0;}\n  bool intersect(point\
    \ p,circle c){return intersect(c,p);}\n  bool intersect(line l,circle c){return\
    \ intersect(c,l);}\n  bool intersect(segment s,circle c){return intersect(c,s);}\n\
    \  vector<point>crosspoint(circle c,circle d){\n    vector<point>ret;\n    if(sign(dist(c,d))!=0)return\
    \ ret;\n    point cd=d.c-c.c;\n    double di=cd.abs();\n    double x=(cd.norm()-d.r*d.r+c.r*c.r)/((double)2.0*di);\n\
    \    point inter=c.c+cd*(x/di);\n    point rev=cd*point(0,sqrt(c.r*c.r-x*x)/di);\n\
    \    ret.push_back(inter+rev);\n    if(sign(rev.norm())==0)ret.push_back(inter-rev);\n\
    \    return ret;\n  }\n  vector<point>tangentpoint(circle c,point p){\n    vector<point>ret;\n\
    \    double sin=c.r/(p-c.c).abs();\n    if(sign(sin-1.0)==0)return ret;\n    double\
    \ theta=pi/2.0-asin(min(sin,double(1.0)));\n    ret.push_back(c.c+(p-c.c)*point::polar(sin,theta));\n\
    \    if(sign(sin-double(1.0))!=0)ret.push_back(c.c+(p-c.c)*point::polar(sin,-theta));\n\
    \    return ret;\n  }\n};\n"
  code: "#pragma once\nnamespace geometry{\n  const double eps=1e-8;\n  const double\
    \ pi=acos(-1.0);\n  bool equals(double a,double b){return fabs(a-b)<eps;}\n  double\
    \ torad(double deg){return deg*pi/180.0;}\n  double todeg(double rad){return rad*180.0/pi;}\n\
    \  int sign(double a){return (a>eps?1:(a<-eps?-1:0));}\n  struct point{\n    double\
    \ x,y;\n    point(double x=0.0,double y=0.0):x(x),y(y){}\n    point operator-()const{return\
    \ point(-x,-y);}\n    point operator+(const point&p)const{return point(x+p.x,y+p.y);}\n\
    \    point operator-(const point&p)const{return point(x-p.x,y-p.y);}\n    point\
    \ operator*(const double&k)const{return point(x*k,y*k);}\n    point operator/(const\
    \ double&k)const{return point(x/k,y/k);}\n    point operator*(const point&p)const{return\
    \ point(x*p.x-y*p.y,x*p.y+y*p.x);}\n    point operator/(const point&p)const{return\
    \ point((x*p.x+y*p.y)/p.norm(),(x*p.y-y*p.x)/p.norm());}\n    point& operator*=(const\
    \ double&k){x*=k;y*=k;return *this;}\n    point& operator/=(const double&k){x/=k;y/=k;return\
    \ *this;}\n    point& operator+=(const point&p){x+=p.x;y+=p.y;return *this;}\n\
    \    point& operator-=(const point&p){x-=p.x;y-=p.y;return *this;}\n    bool operator==(const\
    \ point&p){return equals(x,p.x)&&equals(y,p.y);}\n    double abs()const{return\
    \ sqrt(norm());}\n    double norm()const{return x*x+y*y;}\n    static point polar(double\
    \ r,double theta){return point(r*cos(theta),r*sin(theta));}\n  };\n  struct segment{point\
    \ s,t;segment(point s=0,point t=0):s(s),t(t){}};\n  struct line{point s,t;line(point\
    \ s=0,point t=0):s(s),t(t){}};\n  struct circle{point c;double r;circle(point\
    \ c=0,double r=0):c(c),r(r){}};\n  struct polygon{\n    int n;\n    vector<point>ps;\n\
    \    polygon(int n=0):n(n),ps(n){}\n    polygon(vector<point>ps):n(ps.size()),ps(ps){}\n\
    \    point &operator[](int i){return ps[i];}\n  };\n  ostream &operator<<(ostream&os,const\
    \ point&p){return os<<p.x<<\" \"<<p.y;}\n  istream &operator>>(istream&is,point&p){return\
    \ is>>p.x>>p.y;}\n  double cross(point a,point b){return a.x*b.y-a.y*b.x;}\n \
    \ double dot(point a,point b){return a.x*b.x+a.y*b.y;}\n  point rotate(point o=point(0,0),point\
    \ p,double theta){\n    point pp=p-o;\n    point res(pp.x*cos(theta)-pp.y*sin(theta),pp.x*sin(theta)+pp.y*cos(theta));\n\
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
    \  double dist(point p,point q){return (p-q).abs();}\n  double dist(line l,point\
    \ p){return dist(p,project(l,p));}\n  double dist(point p,line l){return dist(p,project(l,p));}\n\
    \  double dist(line l,line m){\n    if(line_place(l,m)!=2)return 0;\n    return\
    \ dist(l,m.s);\n  }\n  double dist(line l,segment s){\n    if(intersect(l,s))return\
    \ 0;\n    return min(dist(l,s.s),dist(l,s.t));\n  }\n  double dist(segment s,line\
    \ l){return dist(l,s);}\n  double dist(segment s,point p){\n    point q=project(line(s.s,s.t),p);\n\
    \    if(intersect(s,q))return (p-q).abs();\n    else return min((s.s-p).abs(),(s.t-p).abs());\n\
    \  }\n  double dist(point p,segment s){return dist(p,s);}\n  double dist(segment\
    \ s,segment t){\n    if(intersect(s,t))return 0;\n    return min(min(dist(s,t.s),dist(s,t.t)),min(dist(t,s.s),dist(t,s.t)));\n\
    \  }\n  point crosspoint(line l,line m){\n    double a=cross(m.t-m.s,m.s-l.s);\n\
    \    double b=cross(m.t-m.s,l.t-l.s);\n    if(sign(a)==0&&sign(b)==0)return l.s;\n\
    \    else if(sign(b)==0)throw \"no crosspoint\";\n    return l.s+(l.t-l.s)*(a/b);\n\
    \  }\n  double dist(circle c,point p,bool inside_zero=0){\n    if(inside_zero)return\
    \ max(dist(c.c,p)-c.r,0.0);\n    return max(abs(dist(c.c,p)-c.r),0.0); \n  }\n\
    \  double dist(circle c,line l){return max(dist(l,c.c)-c.r,0.0);}\n  double dist(circle\
    \ c,segment s,bool inside_zero=0){\n    double sqr1=(s.s-c.c).norm(),sqr2=(s.t-c.c).norm();\n\
    \    if(inside_zero==0){\n      if((sqr1<c.r*c.r)^(sqr2<c.r*c.r))return 0;\n \
    \     else if(sqr1<c.r&&sqr2<c.r)return c.r-sqrt(max(sqr1,sqr2));\n      return\
    \ max(dist(s,c.c)-c.r,0.0);\n    }\n    else{\n      if(sqr1<c.r*c.r||sqr2<c.r*c.r)return\
    \ 0;\n      return max(dist(s,c.c)-c.r,0.0);\n    }\n  }\n  double dist(circle\
    \ c,circle d){\n    double dir=(c.c-d.c).abs();\n    return sign(dir-abs(c.r-d.r))==1?max(dir-c.r-d.r,0.0):abs(c.r-d.r)-dir;\n\
    \  }\n  double dist(point p,circle c,bool inside_zero=0){return dist(c,p,inside_zero);}\n\
    \  double dist(line l,circle c){return dist(c,l);}\n  double dist(segment s,circle\
    \ c,bool inside_zero=0){return dist(c,s,inside_zero);}\n  bool intersect(circle\
    \ c,point p){return sign(dist(c,p))==0;}\n  bool intersect(circle c,line l){return\
    \ sign(dist(c,l))==0;}\n  bool intersect(circle c,segment s){return sign(dist(c,s))==0;}\n\
    \  bool intersect(circle c,circle d){return sign(dist(c,d))==0;}\n  bool intersect(point\
    \ p,circle c){return intersect(c,p);}\n  bool intersect(line l,circle c){return\
    \ intersect(c,l);}\n  bool intersect(segment s,circle c){return intersect(c,s);}\n\
    \  vector<point>crosspoint(circle c,circle d){\n    vector<point>ret;\n    if(sign(dist(c,d))!=0)return\
    \ ret;\n    point cd=d.c-c.c;\n    double di=cd.abs();\n    double x=(cd.norm()-d.r*d.r+c.r*c.r)/((double)2.0*di);\n\
    \    point inter=c.c+cd*(x/di);\n    point rev=cd*point(0,sqrt(c.r*c.r-x*x)/di);\n\
    \    ret.push_back(inter+rev);\n    if(sign(rev.norm())==0)ret.push_back(inter-rev);\n\
    \    return ret;\n  }\n  vector<point>tangentpoint(circle c,point p){\n    vector<point>ret;\n\
    \    double sin=c.r/(p-c.c).abs();\n    if(sign(sin-1.0)==0)return ret;\n    double\
    \ theta=pi/2.0-asin(min(sin,double(1.0)));\n    ret.push_back(c.c+(p-c.c)*point::polar(sin,theta));\n\
    \    if(sign(sin-double(1.0))!=0)ret.push_back(c.c+(p-c.c)*point::polar(sin,-theta));\n\
    \    return ret;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/geometry.hpp
  requiredBy: []
  timestamp: '2022-03-02 21:28:09+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/geometry.hpp
layout: document
redirect_from:
- /library/Geometry/geometry.hpp
- /library/Geometry/geometry.hpp.html
title: Geometry/geometry.hpp
---
