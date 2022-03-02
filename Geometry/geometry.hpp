#pragma once
#include<bits/stdc++.h>
using namespace std;
namespace geometry{
  const double eps=1e-8;
  const double pi=acos(-1.0);
  bool equals(double a,double b){return fabs(a-b)<eps;}
  double torad(double deg){return deg*pi/180.0;}
  double todeg(double rad){return rad*180.0/pi;}
  int sign(double a){return (a>eps?1:(a<-eps?-1:0));}
  struct point{
    double x,y;
    point(double x=0.0,double y=0.0):x(x),y(y){}
    point operator-()const{return point(-x,-y);}
    point operator+(const point&p)const{return point(x+p.x,y+p.y);}
    point operator-(const point&p)const{return point(x-p.x,y-p.y);}
    point operator*(const double&k)const{return point(x*k,y*k);}
    point operator/(const double&k)const{return point(x/k,y/k);}
    point operator*(const point&p)const{return point(x*p.x-y*p.y,x*p.y+y*p.x);}
    point operator/(const point&p)const{return point((x*p.x+y*p.y)/p.norm(),(x*p.y-y*p.x)/p.norm());}
    point& operator*=(const double&k){x*=k;y*=k;return *this;}
    point& operator/=(const double&k){x/=k;y/=k;return *this;}
    point& operator+=(const point&p){x+=p.x;y+=p.y;return *this;}
    point& operator-=(const point&p){x-=p.x;y-=p.y;return *this;}
    bool operator==(const point&p){return equals(x,p.x)&&equals(y,p.y);}
    double abs()const{return sqrt(norm());}
    double norm()const{return x*x+y*y;}
    static point polar(double r,double theta){return point(r*cos(theta),r*sin(theta));}
  };
  struct segment{point s,t;segment(point s=0,point t=0):s(s),t(t){}};
  struct line{point s,t;line(point s=0,point t=0):s(s),t(t){}};
  struct circle{point c;double r;circle(point c=0,double r=0):c(c),r(r){}};
  struct polygon{
    int n;
    vector<point>ps;
    polygon(int n=0):n(n),ps(n){}
    polygon(vector<point>ps):n(ps.size()),ps(ps){}
    point &operator[](int i){return ps[i];}
  };
  ostream &operator<<(ostream&os,const point&p){return os<<p.x<<" "<<p.y;}
  istream &operator>>(istream&is,point&p){return is>>p.x>>p.y;}
  double cross(point a,point b){return a.x*b.y-a.y*b.x;}
  double dot(point a,point b){return a.x*b.x+a.y*b.y;}
  point rotate(point o=point(0,0),point p,double theta){
    point pp=p-o;
    point res(pp.x*cos(theta)-pp.y*sin(theta),pp.x*sin(theta)+pp.y*cos(theta));
    return res+o;
  }
  int ccw(point a,point b,point c){
    b-=a,c-=a;
    if(cross(b,c)>eps)return 1;
    if(cross(b,c)<-eps)return -1;
    if(dot(b,c)<0)return 2;
    if(b.norm()<c.norm())return -2;
    return 0;
  }
  bool intersect(point a,line l){return abs(ccw(l.s,a,l.t))!=1;}
  int line_place(line l,line m){
    if(intersect(m.s,l)&&intersect(m.t,l))return 1;
    else if(intersect(0,line(l.t-l.s,m.t-m.s)))return 2;
    else if(sign(dot(l.t-l.s,m.t-m.s))==0)return 3;
    return 0;
  }
  bool intersect(line l,line m){return line_place(l,m)!=1&&line_place(l,m)!=2;}
  bool intersect(line l,segment s){s.s-=l.s,s.t-=l.s;l.t-=l.s,l.s-=l.s;return sign(cross(l.t,s.s)*cross(l.t,s.t))!=1;}
  bool intersect(segment s,segment t){return (ccw(s.s,s.t,t.s)*ccw(s.s,s.t,t.t)<=0&&ccw(t.s,t.t,s.s)*ccw(t.s,t.t,s.t)<=0);}
  bool intersect(point a,segment s){return ccw(s.s,s.t,a)==0;}
  bool intersect(line l,point a){return intersect(a,l);}
  bool intersect(segment s,point a){return intersect(a,s);}
  bool intersect(segment s,line l){return intersect(l,s);}
  point project(line l,point p){point a=l.t-l.s,b=p-l.s;return l.s+a*(dot(a,b)/a.norm());}
  point project(point p,line l){return project(l,p);}
  point reflect(line l,point p){return project(l,p)*2-p;}
  point reflect(point p,line l){return reflect(l,p);}
  double dist(point p,point q){return (p-q).abs();}
  double dist(line l,point p){return dist(p,project(l,p));}
  double dist(point p,line l){return dist(p,project(l,p));}
  double dist(line l,line m){
    if(line_place(l,m)!=2)return 0;
    return dist(l,m.s);
  }
  double dist(line l,segment s){
    if(intersect(l,s))return 0;
    return min(dist(l,s.s),dist(l,s.t));
  }
  double dist(segment s,line l){return dist(l,s);}
  double dist(segment s,point p){
    point q=project(line(s.s,s.t),p);
    if(intersect(s,q))return (p-q).abs();
    else return min((s.s-p).abs(),(s.t-p).abs());
  }
  double dist(point p,segment s){return dist(p,s);}
  double dist(segment s,segment t){
    if(intersect(s,t))return 0;
    return min(min(dist(s,t.s),dist(s,t.t)),min(dist(t,s.s),dist(t,s.t)));
  }
  point crosspoint(line l,line m){
    double a=cross(m.t-m.s,m.s-l.s);
    double b=cross(m.t-m.s,l.t-l.s);
    if(sign(a)==0&&sign(b)==0)return l.s;
    else if(sign(b)==0)throw "no crosspoint";
    return l.s+(l.t-l.s)*(a/b);
  }
  double dist(circle c,point p,bool inside_zero=0){
    if(inside_zero)return max(dist(c.c,p)-c.r,0.0);
    return max(abs(dist(c.c,p)-c.r),0.0); 
  }
  double dist(circle c,line l){return max(dist(l,c.c)-c.r,0.0);}
  double dist(circle c,segment s,bool inside_zero=0){
    double sqr1=(s.s-c.c).norm(),sqr2=(s.t-c.c).norm();
    if(inside_zero==0){
      if((sqr1<c.r*c.r)^(sqr2<c.r*c.r))return 0;
      else if(sqr1<c.r&&sqr2<c.r)return c.r-sqrt(max(sqr1,sqr2));
      return max(dist(s,c.c)-c.r,0.0);
    }
    else{
      if(sqr1<c.r*c.r||sqr2<c.r*c.r)return 0;
      return max(dist(s,c.c)-c.r,0.0);
    }
  }
  double dist(circle c,circle d){
    double dir=(c.c-d.c).abs();
    return sign(dir-abs(c.r-d.r))==1?max(dir-c.r-d.r,0.0):abs(c.r-d.r)-dir;
  }
  double dist(point p,circle c,bool inside_zero=0){return dist(c,p,inside_zero);}
  double dist(line l,circle c){return dist(c,l);}
  double dist(segment s,circle c,bool inside_zero=0){return dist(c,s,inside_zero);}
  bool intersect(circle c,point p){return sign(dist(c,p))==0;}
  bool intersect(circle c,line l){return sign(dist(c,l))==0;}
  bool intersect(circle c,segment s){return sign(dist(c,s))==0;}
  bool intersect(circle c,circle d){return sign(dist(c,d))==0;}
  bool intersect(point p,circle c){return intersect(c,p);}
  bool intersect(line l,circle c){return intersect(c,l);}
  bool intersect(segment s,circle c){return intersect(c,s);}
  vector<point>crosspoint(circle c,circle d){
    vector<point>ret;
    if(sign(dist(c,d))!=0)return ret;
    point cd=d.c-c.c;
    double di=cd.abs();
    double x=(cd.norm()-d.r*d.r+c.r*c.r)/((double)2.0*di);
    point inter=c.c+cd*(x/di);
    point rev=cd*point(0,sqrt(c.r*c.r-x*x)/di);
    ret.push_back(inter+rev);
    if(sign(rev.norm())==0)ret.push_back(inter-rev);
    return ret;
  }
  vector<point>tangentpoint(circle c,point p){
    vector<point>ret;
    double sin=c.r/(p-c.c).abs();
    if(sign(sin-1.0)==0)return ret;
    double theta=pi/2.0-asin(min(sin,double(1.0)));
    ret.push_back(c.c+(p-c.c)*point::polar(sin,theta));
    if(sign(sin-double(1.0))!=0)ret.push_back(c.c+(p-c.c)*point::polar(sin,-theta));
    return ret;
  }
};