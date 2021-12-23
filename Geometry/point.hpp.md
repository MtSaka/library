---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Geometry/line.hpp
    title: Geometry/line.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Point(\u70B9)"
    links: []
  bundledCode: "#line 1 \"Geometry/point.hpp\"\n/**\n * @brief Point(\u70B9)\n*/\n\
    double eps=0.0000000001;\nint sign(double x){\n  if(x>eps)return 1;\n  if(x<-eps)return\
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
    }\n"
  code: "/**\n * @brief Point(\u70B9)\n*/\ndouble eps=0.0000000001;\nint sign(double\
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
    \  a-=b;\n  c-=b;\n  return acos(dot(a,c)/(abs(a)*abs(c)));\n}"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/point.hpp
  requiredBy:
  - Geometry/line.hpp
  timestamp: '2021-12-23 11:45:08+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/point.hpp
layout: document
redirect_from:
- /library/Geometry/point.hpp
- /library/Geometry/point.hpp.html
title: "Point(\u70B9)"
---
