#pragma once
namespace geometry{
  const long double eps=1e-9;
  const long double pi=acos(-1.0);
  bool equals(long double a,long double b){return fabs(a-b)<eps;}
  long double torad(long double deg){return deg*pi/180.0;}
  long double todeg(long double rad){return rad*180.0/pi;}
  int sign(long double a){return (a>eps?1:(a<-eps?-1:0));}
  struct point{
    long double x,y;
    point(long double x=0.0,long double y=0.0):x(x),y(y){}
    point operator-()const{return point(-x,-y);}
    point operator+(const point&p)const{return point(x+p.x,y+p.y);}
    point operator-(const point&p)const{return point(x-p.x,y-p.y);}
    point operator*(const long double&k)const{return point(x*k,y*k);}
    point operator/(const long double&k)const{return point(x/k,y/k);}
    point operator*(const point&p)const{return point(x*p.x-y*p.y,x*p.y+y*p.x);}
    point operator/(const point&p)const{return point((x*p.x+y*p.y)/p.norm(),(x*p.y-y*p.x)/p.norm());}
    point& operator*=(const long double&k){x*=k;y*=k;return *this;}
    point& operator/=(const long double&k){x/=k;y/=k;return *this;}
    point& operator+=(const point&p){x+=p.x;y+=p.y;return *this;}
    point& operator-=(const point&p){x-=p.x;y-=p.y;return *this;}
    bool operator==(const point&p){return equals(x,p.x)&&equals(y,p.y);}
    long double abs()const{return sqrt(norm());}
    long double norm()const{return x*x+y*y;}
    static point polar(long double r,long double theta){return point(r*cos(theta),r*sin(theta));}
  };
  struct segment{point s,t;segment(point s=0,point t=0):s(s),t(t){}};
  struct line{point s,t;line(point s=0,point t=0):s(s),t(t){}};
  struct circle{point c;long double r;circle(point c=0,long double r=0):c(c),r(r){}};
  struct polygon{
    int n;
    vector<point>ps;
    polygon(int n=0):n(n),ps(n){}
    polygon(vector<point>ps):n(ps.size()),ps(ps){}
    point &operator[](int i){return ps[i];}
  };
  ostream &operator<<(ostream&os,const point&p){return os<<p.x<<" "<<p.y;}
  istream &operator>>(istream&is,point&p){return is>>p.x>>p.y;}
  long double cross(point a,point b){return a.x*b.y-a.y*b.x;}
  long double dot(point a,point b){return a.x*b.x+a.y*b.y;}
  point rotate(point p,long double theta,point o=point(0,0)){
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
  long double dist(point p,point q){return (p-q).abs();}
  long double dist(line l,point p){return dist(p,project(l,p));}
  long double dist(point p,line l){return dist(p,project(l,p));}
  long double dist(line l,line m){
    if(line_place(l,m)!=2)return 0;
    return dist(l,m.s);
  }
  long double dist(line l,segment s){
    if(intersect(l,s))return 0;
    return min(dist(l,s.s),dist(l,s.t));
  }
  long double dist(segment s,line l){return dist(l,s);}
  long double dist(segment s,point p){
    point q=project(line(s.s,s.t),p);
    if(intersect(s,q))return (p-q).abs();
    else return min((s.s-p).abs(),(s.t-p).abs());
  }
  long double dist(point p,segment s){return dist(p,s);}
  long double dist(segment s,segment t){
    if(intersect(s,t))return 0;
    return min(min(dist(s,t.s),dist(s,t.t)),min(dist(t,s.s),dist(t,s.t)));
  }
  point crosspoint(line l,line m){
    long double a=cross(m.t-m.s,m.s-l.s);
    long double b=cross(m.t-m.s,l.t-l.s);
    if(sign(a)==0&&sign(b)==0)return l.s;
    else if(sign(b)==0)throw "no crosspoint";
    return l.s+(l.t-l.s)*(a/b);
  }
  long double dist(circle c,point p,bool inside_zero=0){
    if(inside_zero)return max(dist(c.c,p)-c.r,(long double)0.0);
    return max(abs(dist(c.c,p)-c.r),(long double)0.0); 
  }
  long double dist(circle c,line l){return max(dist(l,c.c)-c.r,(long double)0.0);}
  long double dist(circle c,segment s,bool inside_zero=0){
    long double sqr1=(s.s-c.c).norm(),sqr2=(s.t-c.c).norm();
    if(inside_zero==0){
      if((sqr1<c.r*c.r)^(sqr2<c.r*c.r))return 0;
      else if(sqr1<c.r&&sqr2<c.r)return c.r-sqrt(max(sqr1,sqr2));
      return max(dist(s,c.c)-c.r,(long double)0.0);
    }
    else{
      if(sqr1<c.r*c.r||sqr2<c.r*c.r)return 0;
      return max(dist(s,c.c)-c.r,(long double)0.0);
    }
  }
  long double dist(circle c,circle d){
    long double dir=(c.c-d.c).abs();
    return sign(dir-abs(c.r-d.r))==1?max(dir-c.r-d.r,(long double)0.0):abs(c.r-d.r)-dir;
  }
  long double dist(point p,circle c,bool inside_zero=0){return dist(c,p,inside_zero);}
  long double dist(line l,circle c){return dist(c,l);}
  long double dist(segment s,circle c,bool inside_zero=0){return dist(c,s,inside_zero);}
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
    long double di=cd.abs();
    long double x=(cd.norm()-d.r*d.r+c.r*c.r)/((long double)2.0*di);
    point inter=c.c+cd*(x/di);
    point rev=cd*point(0,sqrt(c.r*c.r-x*x)/di);
    ret.push_back(inter+rev);
    if(sign(rev.norm())==0)ret.push_back(inter-rev);
    return ret;
  }
  vector<point>tangentpoint(circle c,point p){
    vector<point>ret;
    long double sin=c.r/(p-c.c).abs();
    if(sign(sin-1.0)==0)return ret;
    long double theta=pi/2.0-asin(min(sin,(long double)1.0));
    ret.push_back(c.c+(p-c.c)*point::polar(sin,theta));
    if(sign(sin-(long double)1.0)!=0)ret.push_back(c.c+(p-c.c)*point::polar(sin,-theta));
    return ret;
  }
  point circumcenter(polygon pol){
    assert(pol.n==3);
    pol[0]=(pol[0]-pol[2])/2.0;
    pol[1]=(pol[1]-pol[2])/2.0;
    return pol[2]+crosspoint(line(pol[0],pol[0]*point(1,1)),line(pol[1],pol[1]*point(1,1)));
  }
  point circumcenter(point a,point b,point c){
    return circumcenter(polygon(vector<point>{a,b,c}));
  }
  point center_of_gravity(polygon pol){
    assert(pol.n==3);
    return (pol[0]+pol[1]+pol[2])/3.0;
  }
  point center_of_gravity(point p1,point p2,point p3){
    return center_of_gravity(polygon(vector<point>{p1,p2,p3}));
  }
  point innercenter(polygon pol){
    assert(pol.n==3);
    long double a=dist(pol[0],pol[1]),b=dist(pol[1],pol[2]),c=dist(pol[2],pol[0]);
    return (pol[0]*a+pol[1]*b+pol[2]*c)/(a+b+c);
  }
  point innercenter(point p1,point p2,point p3){
    return innercenter(polygon(vector<point>{p1,p2,p3}));
  }
  point orthocenter(polygon pol){
    assert(pol.n==3);
    return pol[0]+pol[2]+pol[3]-center_of_gravity(pol)*2.0;
  }
  point orthocenter(point p1,point p2,point p3){
    return orthocenter(polygon(vector<point>{p1,p2,p3}));
  }
  long double area(polygon&pol){
    long double ret=0;
    for(int i=0;i<pol.n;i++)ret+=cross(pol[i],pol[(i+1)%pol.n]);
    return ret/2.0;
  }
  long double isconvex(polygon&pol){
    int neg=0,pos=0;
    for(int i=0;i<pol.n;i++){
      int dir=ccw(pol[i],pol[(i+1)%pol.n],pol[(i+2)%pol.n]);
      if(dir==1)pos++;
      else if(dir==-1)neg++;
    }
    if(pos&&neg)return 0;
    return 1;
  }
  int in_polygon(point p,polygon&pol){
    int n=pol.n;
    bool in=false;
    for(int i=0;i<n;i++){
      point a=pol[i],b=pol[(i+1)%n];
      if(intersect(p,segment(a,b)))return 2;
      if(intersect(segment(p,point(p.x+1.0,INT_MAX)),segment(a,b)))in=!in; 
    }
    return in;
  }
};