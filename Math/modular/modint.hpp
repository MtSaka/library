#pragma once
template<int m>
struct modint{
  private:
  unsigned int x;
  static constexpr unsigned int umod(){return m;}
  public:
  static modint raw(int v){
    modint ret;
    ret.x=v;
    return ret;
  }
  constexpr modint():x(0){}
  constexpr modint(int y){
    int v=y%m;
    if(v<0)v+=m;
    x=(unsigned int)v;
  }
  constexpr modint(long long y){
    long long v=y%(long long)m;
    if(v<0)v+=m;
    x=(unsigned int)v;
  }
  constexpr modint(unsigned int y){
    x=(unsigned int)(y%umod());
  }
  modint& operator++(){x++;if(x==umod())x=0;return *this;}
  modint& operator--(){if(x==0)x=umod();x--;return *this;}
  modint operator++(int){
    modint ret=*this;
    ++*this;
    return ret;
  }
  modint operator--(int){
    modint ret=*this;
    --*this;
    return ret;
  }
  modint& operator+=(const modint&p){if((x+=p.x)>=umod())x-=umod();return *this;}
  modint& operator-=(const modint&p){if((x-=p.x)>=umod())x+=umod();return *this;}
  modint& operator*=(const modint&p){
    unsigned long long y=x;
    y*=p.x;
    x=(unsigned int)(y%umod());
    return *this;
  }
  modint& operator/=(const modint&p){return *this*=p.inv();}
  modint operator+()const{return *this;}
  modint operator-()const{return modint()-*this;}
  modint pow(long long n)const{
    modint ret(1),mul=*this;
    while(n){
      if(n&1)ret*=mul;
      mul*=mul;
      n>>=1;
    }
    return ret;
  }
  modint inv()const{
    long long a=x,b=m,u=1,v=0;
    while(b){
      long long t=a/b;
      swap(a-=t*b,b);
      swap(u-=t*v,v);
    }
    return modint(u);
  }
  friend modint operator+(const modint&l,const modint&r){return modint(l)+=r;}
  friend modint operator-(const modint&l,const modint&r){return modint(l)-=r;}
  friend modint operator*(const modint&l,const modint&r){return modint(l)*=r;}
  friend modint operator/(const modint&l,const modint&r){return modint(l)/=r;}
  friend bool operator==(const modint&l,const modint&r){return l.x==r.x;}
  friend bool operator!=(const modint&l,const modint&r){return l.x!=r.x;}
  friend ostream &operator<<(ostream &os,const modint&p) {
    return os<<p.val();
  }
  friend istream &operator>>(istream &is, modint &a) {
    long long t;
    is>>t;
    a=modint(t);
    return (is);
  }
  static constexpr int get_mod(){return m;}
  int val()const{return (int)x;}
};
/**
 * @brief modint
*/