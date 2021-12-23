---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Geometry/point.hpp
    title: Geometry/point.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Geometry/point.hpp\"\ndouble eps=0.0000000001;\nint sign(double\
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
    \  a-=b;\n  c-=b;\n  return acos(dot(a,c)/(abs(a)*abs(c)));\n}\n#line 2 \"Geometry/line.hpp\"\
    \nstruct line{\n  point a;\n  point b;\n  line(){}\n  line(point p){b=p;}\n  line(point\
    \ p,point q){a=p,b=q;}\n  line(double A,double B){a=point(0,B),b=point(1,A+B);}\n\
    \  line(double A,double B,double C){\n    if(sign(B)==0){\n      a=point(-C/A,0);\n\
    \      b=point(-C/A,1);\n    }\n    else{\n      a=point(0,-C/B);\n      b=point(1,-(A+C)/B);\n\
    \    }\n  }\n  line operator+(point p){\n    return line(a+p,b+p);\n  }\n  line\
    \ operator-(point p){\n    return line(a-p,b-p);\n  }\n  line &operator+=(point\
    \ p){\n    a+=p;\n    b+=p;\n    return *this;\n  }\n  line &operator-=(point\
    \ p){\n    a-=p;\n    b-=p;\n    return *this;\n  }\n  bool operator==(line l){\n\
    \    return sign(cross(b-a,l.a-a))==0&&sign(cross(b-a,l.b-a));\n  }\n};\nistream&operator>>(istream\
    \ &is,line &l){\n  point a,b;\n  is>>a>>b;\n  l=line(a,b);\n  return is;\n}\n\
    ostream&operator<<(ostream&os,line l){\n  os<<l.a<<' '<<l.b;\n  return os;\n}\n\
    point vec(line l){\n  return l.b-l.a;\n}\npoint unit(line l){\n  return vec(l)/abs(vec(l));\n\
    }\npoint part(line l,double a,double b){\n  return (l.a*b+l.b*a)/(a+b);\n}\nbool\
    \ is_parallel(line a,line b){\n  return sign(cross(vec(a),vec(b)))==0;\n}\n"
  code: "#include\"point.hpp\"\nstruct line{\n  point a;\n  point b;\n  line(){}\n\
    \  line(point p){b=p;}\n  line(point p,point q){a=p,b=q;}\n  line(double A,double\
    \ B){a=point(0,B),b=point(1,A+B);}\n  line(double A,double B,double C){\n    if(sign(B)==0){\n\
    \      a=point(-C/A,0);\n      b=point(-C/A,1);\n    }\n    else{\n      a=point(0,-C/B);\n\
    \      b=point(1,-(A+C)/B);\n    }\n  }\n  line operator+(point p){\n    return\
    \ line(a+p,b+p);\n  }\n  line operator-(point p){\n    return line(a-p,b-p);\n\
    \  }\n  line &operator+=(point p){\n    a+=p;\n    b+=p;\n    return *this;\n\
    \  }\n  line &operator-=(point p){\n    a-=p;\n    b-=p;\n    return *this;\n\
    \  }\n  bool operator==(line l){\n    return sign(cross(b-a,l.a-a))==0&&sign(cross(b-a,l.b-a));\n\
    \  }\n};\nistream&operator>>(istream &is,line &l){\n  point a,b;\n  is>>a>>b;\n\
    \  l=line(a,b);\n  return is;\n}\nostream&operator<<(ostream&os,line l){\n  os<<l.a<<'\
    \ '<<l.b;\n  return os;\n}\npoint vec(line l){\n  return l.b-l.a;\n}\npoint unit(line\
    \ l){\n  return vec(l)/abs(vec(l));\n}\npoint part(line l,double a,double b){\n\
    \  return (l.a*b+l.b*a)/(a+b);\n}\nbool is_parallel(line a,line b){\n  return\
    \ sign(cross(vec(a),vec(b)))==0;\n}\n"
  dependsOn:
  - Geometry/point.hpp
  isVerificationFile: false
  path: Geometry/line.hpp
  requiredBy: []
  timestamp: '2021-12-23 11:07:04+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/line.hpp
layout: document
redirect_from:
- /library/Geometry/line.hpp
- /library/Geometry/line.hpp.html
title: Geometry/line.hpp
---
