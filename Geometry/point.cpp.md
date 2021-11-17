---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Geometry/line.cpp
    title: Geometry/line.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Geometry/point.cpp\"\ndouble eps=0.0000000001;\nint sign(double\
    \ x){\n  if(x>eps)return 1;\n  if(x<-eps)return -1;\n  return 0;\n}\nbool equals(double\
    \ x,double y){\n  return abs(x-y)<eps;\n}\nstruct point{\n  double x;\n  double\
    \ y;\n  point(){\n    x=0,y=0;\n  }\n  point(double X,double Y){\n    x=X,y=Y;\n\
    \  }\n  point operator-(){\n    return point(-x,-y);\n  }\n  point operator+(point\
    \ p){\n    return point(x+p.x,y+p.y);\n  }\n  point operator-(point p){\n    return\
    \ point(x-p.x,y-p.y);\n  }\n  point operator*(double k){\n    return point(x*k,y*k);\n\
    \  }\n  point operator/(double k){\n    return point(x/k,y/k);\n  }\n  point &operator+=(point\
    \ p){\n    x+=p.x;\n    y+=p.y;\n    return *this;\n  }\n  point &operator-=(point\
    \ p){\n    x-=p.x;\n    y-=p.y;\n    return *this;\n  }\n  point &operator*=(double\
    \ k){\n    x*=k;\n    y*=k;\n    return *this;\n  }\n  point &operator/=(double\
    \ k){\n    x/=k;\n    y/=k;\n    return *this;\n  }\n  bool operator==(point p){\n\
    \    return equals(x,p.x)&&equals(y,p.y);\n  }\n  bool operator!=(point p){\n\
    \    return !(*this==p);\n  }\n  point &rotate(double t){\n    double X=x*cos(t)-y*sin(t);\n\
    \    double Y=x*sin(t)+y*cos(t);\n    x=X,y=Y;\n    return *this;\n  }\n  point\
    \ &rotate(point p,double t){\n    *this-=p;\n    (*this).rotate(t);\n    *this+=p;\n\
    \    return *this;\n  }\n  point &rotate90(){\n    swap(x,y);\n    x=-x;\n   \
    \ return *this;\n  }\n};\nistream &operator>>(istream &is,point&p){\n  double\
    \ x,y;\n  is>>x>>y;\n  p=point(x,y);\n  return is;\n}\nostream &operator<<(ostream\
    \ &os,point p){\n  os<<p.x<<' '<<p.y;\n  return os;\n}\ndouble abs(point p){\n\
    \  return sqrt(p.x*p.x+p.y*p.y);\n}\npoint rotate(point p,double t){\n return\
    \ point(p.x*cos(t)-p.y*sin(t),p.x*sin(t)+p.y*cos(t));\n}\npoint rotate(point p,point\
    \ q,double t){\n  return rotate(p-q,t)+q;\n}\ndouble dist(point p,point q){\n\
    \  return abs(p-q);\n}\ndouble arg(point p){\n  return atan2(p.y,p.x);\n}\ndouble\
    \ dot(point p,point q){\n  return p.x*q.y+p.y*q.x;\n}\ndouble cross(point p,point\
    \ q){\n  return p.x*q.y-p.y*q.x;\n}\ndouble angle(point a,point b,point c){\n\
    \  a-=b;\n  c-=b;\n  return acos(dot(a,c)/(abs(a)*abs(c)));\n}\n"
  code: "double eps=0.0000000001;\nint sign(double x){\n  if(x>eps)return 1;\n  if(x<-eps)return\
    \ -1;\n  return 0;\n}\nbool equals(double x,double y){\n  return abs(x-y)<eps;\n\
    }\nstruct point{\n  double x;\n  double y;\n  point(){\n    x=0,y=0;\n  }\n  point(double\
    \ X,double Y){\n    x=X,y=Y;\n  }\n  point operator-(){\n    return point(-x,-y);\n\
    \  }\n  point operator+(point p){\n    return point(x+p.x,y+p.y);\n  }\n  point\
    \ operator-(point p){\n    return point(x-p.x,y-p.y);\n  }\n  point operator*(double\
    \ k){\n    return point(x*k,y*k);\n  }\n  point operator/(double k){\n    return\
    \ point(x/k,y/k);\n  }\n  point &operator+=(point p){\n    x+=p.x;\n    y+=p.y;\n\
    \    return *this;\n  }\n  point &operator-=(point p){\n    x-=p.x;\n    y-=p.y;\n\
    \    return *this;\n  }\n  point &operator*=(double k){\n    x*=k;\n    y*=k;\n\
    \    return *this;\n  }\n  point &operator/=(double k){\n    x/=k;\n    y/=k;\n\
    \    return *this;\n  }\n  bool operator==(point p){\n    return equals(x,p.x)&&equals(y,p.y);\n\
    \  }\n  bool operator!=(point p){\n    return !(*this==p);\n  }\n  point &rotate(double\
    \ t){\n    double X=x*cos(t)-y*sin(t);\n    double Y=x*sin(t)+y*cos(t);\n    x=X,y=Y;\n\
    \    return *this;\n  }\n  point &rotate(point p,double t){\n    *this-=p;\n \
    \   (*this).rotate(t);\n    *this+=p;\n    return *this;\n  }\n  point &rotate90(){\n\
    \    swap(x,y);\n    x=-x;\n    return *this;\n  }\n};\nistream &operator>>(istream\
    \ &is,point&p){\n  double x,y;\n  is>>x>>y;\n  p=point(x,y);\n  return is;\n}\n\
    ostream &operator<<(ostream &os,point p){\n  os<<p.x<<' '<<p.y;\n  return os;\n\
    }\ndouble abs(point p){\n  return sqrt(p.x*p.x+p.y*p.y);\n}\npoint rotate(point\
    \ p,double t){\n return point(p.x*cos(t)-p.y*sin(t),p.x*sin(t)+p.y*cos(t));\n\
    }\npoint rotate(point p,point q,double t){\n  return rotate(p-q,t)+q;\n}\ndouble\
    \ dist(point p,point q){\n  return abs(p-q);\n}\ndouble arg(point p){\n  return\
    \ atan2(p.y,p.x);\n}\ndouble dot(point p,point q){\n  return p.x*q.y+p.y*q.x;\n\
    }\ndouble cross(point p,point q){\n  return p.x*q.y-p.y*q.x;\n}\ndouble angle(point\
    \ a,point b,point c){\n  a-=b;\n  c-=b;\n  return acos(dot(a,c)/(abs(a)*abs(c)));\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/point.cpp
  requiredBy:
  - Geometry/line.cpp
  timestamp: '2021-11-17 20:52:48+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/point.cpp
layout: document
redirect_from:
- /library/Geometry/point.cpp
- /library/Geometry/point.cpp.html
title: Geometry/point.cpp
---
