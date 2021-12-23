#include"point.hpp"
struct line{
  point a;
  point b;
  line(){}
  line(point p){b=p;}
  line(point p,point q){a=p,b=q;}
  line(double A,double B){a=point(0,B),b=point(1,A+B);}
  line(double A,double B,double C){
    if(sign(B)==0){
      a=point(-C/A,0);
      b=point(-C/A,1);
    }
    else{
      a=point(0,-C/B);
      b=point(1,-(A+C)/B);
    }
  }
  line operator+(point p){
    return line(a+p,b+p);
  }
  line operator-(point p){
    return line(a-p,b-p);
  }
  line &operator+=(point p){
    a+=p;
    b+=p;
    return *this;
  }
  line &operator-=(point p){
    a-=p;
    b-=p;
    return *this;
  }
  bool operator==(line l){
    return sign(cross(b-a,l.a-a))==0&&sign(cross(b-a,l.b-a));
  }
};
istream&operator>>(istream &is,line &l){
  point a,b;
  is>>a>>b;
  l=line(a,b);
  return is;
}
ostream&operator<<(ostream&os,line l){
  os<<l.a<<' '<<l.b;
  return os;
}
point vec(line l){
  return l.b-l.a;
}
point unit(line l){
  return vec(l)/abs(vec(l));
}
point part(line l,double a,double b){
  return (l.a*b+l.b*a)/(a+b);
}
bool is_parallel(line a,line b){
  return sign(cross(vec(a),vec(b)))==0;
}
