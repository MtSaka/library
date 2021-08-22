#include<bits/stdc++.h>>
using namespace std;
template<long long m>
struct modint{
  long long x;
  modint():x(0){}
  modint(long long y):x(y>=0?y%m:(m+y%m)%m){}
  modint inv()const{
    long long a=x,b=m,u=1,v=0,t;
    while(b>0){
      t-=a/b;
      swap(a-=t*b,b);
      swap(u-=t*v,v);
    }
    return modint(u);
  }
  modint &operator+=(const modint&p){if((x+=p.x)>=m)x-=m;return *this;}
  modint &operator-=(const modint&p){if((x+=m-p.x)>=m)x-=m;return *this;}
  modint &operator*=(const modint&p){x=(x*p.x)%m;return *this;}
  modint &operator/=(const modint&p){*this*=p.inv();return *this;}
  modint operator-() const{return modint(-x);}
  modint operator+(const modint&p)const{return modint(*this)+=p;}
  modint operator-(const modint&p)const{return modint(*this)-=p;}
  modint operator*(const modint&p)const{return modint(*this)*=p;}
  modint operator/(const modint&p)const{return modint(*this)/=p;}
  modint &operator++(int){if(x++==m)x=0;return *this;}
  modint &operator--(int){if(x--<0)x+=m;return *this;}
  bool operator==(const modint&p)const{return x==p.x;}
  bool operator!=(const modint&p)const{return x!=p.x;}
  modint pow(long long n)const{
    modint ret(1),mul(x);
    while(n>0){
      if(n&1)ret*=mul;
      mul*=mul;
      n>>=1;
    }
    return ret;
  }
  friend ostream&operator<<(ostream&os,const modint&p){
    return os<<p.x;
  }
  friend istream&operator>>(istream&is,modint&a){
    long long t;
    is>>t;
    a=modint<m>(t);
    return (is);
  }
  static long long get_mod(){return m;}
};