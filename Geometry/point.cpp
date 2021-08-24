#include<bits/stdc++.h>
using namespace std;
double eps=0.0000000001;
int sign(double x){
  if(x>eps)return 1;
  if(x<-eps)return -1;
  return 0;
}
bool equals(double x,double y){
  return abs(x-y)<eps;
}
struct point{
  double x;
  double y;
  point(){
    x=0,y=0;
  }
  point(double X,double Y){
    x=X,y=Y;
  }
  point operator-(){
    return point(-x,-y);
  }
  point operator+(point p){
    return point(x+p.x,y+p.y);
  }
  point operator-(point p){
    return point(x-p.x,y-p.y);
  }
  point operator*(double k){
    return point(x*k,y*k);
  }
  point operator/(double k){
    return point(x/k,y/k);
  }
  point &operator+=(point p){
    x+=p.x;
    y+=p.y;
    return *this;
  }
  point &operator-=(point p){
    x-=p.x;
    y-=p.y;
    return *this;
  }
  point &operator*=(double k){
    x*=k;
    y*=k;
    return *this;
  }
  point &operator/=(double k){
    x/=k;
    y/=k;
    return *this;
  }
  bool operator==(point p){
    return equals(x,p.x)&&equals(y,p.y);
  }
  bool operator!=(point p){
    return !(*this==p);
  }
  point &rotate(double t){
    double X=x*cos(t)-y*sin(t);
    double Y=x*sin(t)+y*cos(t);
    x=X,y=Y;
    return *this;
  }
  point &rotate(point p,double t){
    *this-=p;
    (*this).rotate(t);
    *this+=p;
    return *this;
  }
  point &rotate90(){
    swap(x,y);
    x=-x;
    return *this;
  }
};
istream &operator>>(istream &is,point&p){
  double x,y;
  is>>x>>y;
  p=point(x,y);
  return is;
}
ostream &operator<<(ostream &os,point p){
  os<<p.x<<' '<<p.y;
  return os;
}
double abs(point p){
  return sqrt(p.x*p.x+p.y*p.y);
}
point rotate(point p,double t){
 return point(p.x*cos(t)-p.y*sin(t),p.x*sin(t)+p.y*cos(t));
}
point rotate(point p,point q,double t){
  return rotate(p-q,t)+q;
}
double dist(point p,point q){
  return abs(p-q);
}
double arg(point p){
  return atan2(p.y,p.x);
}
double dot(point p,point q){
  return p.x*q.y+p.y*q.x;
}
double cross(point p,point q){
  return p.x*q.y-p.y*q.x;
}
double angle(point a,point b,point c){
  a-=b;
  c-=b;
  return acos(dot(a,c)/(abs(a)*abs(c)));
}