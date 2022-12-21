#pragma once
#include"../../template/template.hpp"

template<typename T,T mod>
struct StaticModint{
  static_assert(is_integral<T>::value,"T must be integral");
  static_assert(is_unsigned<T>::value,"T must be unsgined");
  static_assert(mod>0,"mod must be positive");
  static_assert(mod<=INF<T>,"mod*2 must be less than or equal to T::max()");
  private:
  using large_t=typename double_size_uint<T>::type;
  using signed_t=typename make_signed<T>::type;
  T val;
  public:
  constexpr StaticModint():val(0){}
  
};
template<int m>
struct ModInt{
  private:
  unsigned int x;
  static constexpr unsigned int umod(){return m;}
  public:
  static ModInt raw(int v){
    ModInt ret;
    ret.x=v;
    return ret;
  }
  constexpr ModInt():x(0){}
  constexpr ModInt(int y){
    int v=y%m;
    if(v<0)v+=m;
    x=(unsigned int)v;
  }
  constexpr ModInt(long long y){
    long long v=y%(long long)m;
    if(v<0)v+=m;
    x=(unsigned int)v;
  }
  constexpr ModInt(unsigned int y){
    x=(unsigned int)(y%umod());
  }
  ModInt& operator++(){x++;if(x==umod())x=0;return *this;}
  ModInt& operator--(){if(x==0)x=umod();x--;return *this;}
  ModInt operator++(int){
    ModInt ret=*this;
    ++*this;
    return ret;
  }
  ModInt operator--(int){
    ModInt ret=*this;
    --*this;
    return ret;
  }
  ModInt& operator+=(const ModInt&p){if((x+=p.x)>=umod())x-=umod();return *this;}
  ModInt& operator-=(const ModInt&p){if((x-=p.x)>=umod())x+=umod();return *this;}
  ModInt& operator*=(const ModInt&p){
    unsigned long long y=x;
    y*=p.x;
    x=(unsigned int)(y%umod());
    return *this;
  }
  ModInt& operator/=(const ModInt&p){return *this*=p.inv();}
  ModInt operator+()const{return *this;}
  ModInt operator-()const{return ModInt()-*this;}
  ModInt pow(long long n)const{
    ModInt ret(1),mul=*this;
    while(n){
      if(n&1)ret*=mul;
      mul*=mul;
      n>>=1;
    }
    return ret;
  }
  ModInt inv()const{
    long long a=x,b=m,u=1,v=0;
    while(b){
      long long t=a/b;
      swap(a-=t*b,b);
      swap(u-=t*v,v);
    }
    return ModInt(u);
  }
  friend ModInt operator+(const ModInt&l,const ModInt&r){return ModInt(l)+=r;}
  friend ModInt operator-(const ModInt&l,const ModInt&r){return ModInt(l)-=r;}
  friend ModInt operator*(const ModInt&l,const ModInt&r){return ModInt(l)*=r;}
  friend ModInt operator/(const ModInt&l,const ModInt&r){return ModInt(l)/=r;}
  friend bool operator==(const ModInt&l,const ModInt&r){return l.x==r.x;}
  friend bool operator!=(const ModInt&l,const ModInt&r){return l.x!=r.x;}
  friend ostream &operator<<(ostream &os,const ModInt&p) {
    return os<<p.val();
  }
  friend istream &operator>>(istream &is, ModInt &a) {
    long long t;
    is>>t;
    a=ModInt(t);
    return (is);
  }
  static constexpr int get_mod(){return m;}
  int val()const{return (int)x;}
};
/**
 * @brief ModInt
*/