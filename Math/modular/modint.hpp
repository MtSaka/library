#pragma once
template<long long m>
struct modint{
  long long x;
  constexpr modint():x(0){}
  constexpr modint(long long y):x(y>=0?y%m:(m-(-y)%m)%m){}
  modint inv()const{
    long long a=x,b=m,u=1,v=0,t;
    while(b){
      t=a/b;
      swap(a-=t*b,b);
      swap(u-=t*v,v);
    }
    return modint(u);
  }
  modint &operator+=(const modint&p){if((x+=p.x)>=m)x-=m;return *this;}
  modint &operator-=(const modint&p){if((x+=m-p.x)>=m)x-=m;return *this;}
  modint &operator*=(const modint&p){x=x*p.x;if(x>=m)x%=m;return *this;}
  modint &operator/=(const modint&p){*this*=p.inv();return *this;}
  friend modint operator+(const modint&l,const modint&r){return modint(l)+=r;}
  friend modint operator-(const modint&l,const modint&r){return modint(l)-=r;}
  friend modint operator*(const modint&l,const modint&r){return modint(l)*=r;}
  friend modint operator/(const modint&l,const modint&r){return modint(l)/=r;}
  modint operator-()const{return modint(-x);}
  modint operator+()const{return *this;}
  modint &operator++(){x++;if(x==m)x=0;return *this;}
  modint &operator--(){if(x==0)x=m;x--;return *this;}
  modint operator++(int){modint ret(*this);++*this;return ret;}
  modint operator--(int){modint ret(*this);--*this;return ret;}
  friend bool operator==(const modint&l,const modint&r){return l.x==r.x;}
  friend bool operator!=(const modint&l,const modint&r){return l.x!=r.x;}
  modint pow(long long n)const{
    modint ret(1),mul(x);
    while(n){
      if(n&1)ret*=mul;
      mul*=mul;
      n>>=1;
    }
    return ret;
  }
  friend ostream &operator<<(ostream &os,const modint&p) {
    return os<<p.x;
  }
  friend istream &operator>>(istream &is, modint &a) {
    long long t;
    is>>t;
    a=modint<m>(t);
    return (is);
  }
  static long long get_mod(){return m;}
};
/**
 * @brief modint
*/