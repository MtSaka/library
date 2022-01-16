#pragma once
#include"ntt.hpp"
template<long long Mod>
struct FPS:vector<modint<Mod>>{
  using mint=modint<Mod>;
  using vector<mint>::vector;
  using vector<mint>::operator=;
  void shrink(){while(!(*this).empty()&&(*this).back()==mint(0))(*this).pop_back();}
  FPS inv(int d=-1)const{
    NTT<Mod>ntt;
    const int n=(*this).size();
    if(d==-1)d=n;
    FPS res{(*this)[0].inv()};
    for(int m=1;m<d;m<<=1){
      FPS f((*this).begin(),(*this).begin()+min(n,2*m));
      FPS g(res);
      f.resize(2*m),g.resize(2*m);
      ntt.dft(f,1),ntt.dft(g,1);
      for(int i=0;i<2*m;i++)f[i]*=g[i];
      ntt.dft(f,-1);
      f.erase(f.begin(),f.begin()+m);
      f.resize(2*m);ntt.dft(f,1);
      for(int i=0;i<2*m;i++)f[i]*=g[i];
      ntt.dft(f,-1);
      mint iz=mint(2*m).inv();iz*=-iz;
      for(int i=0;i<m;i++)f[i]*=iz;
      res.insert(res.end(),f.begin(),f.begin()+m);
    }
    res.resize(d);
    return res;
  }
  FPS operator+(const mint&r)const{return FPS(*this)+=r;}
  FPS operator-(const mint&r)const{return FPS(*this)-=r;}
  FPS operator*(const mint&r)const{return FPS(*this)*=r;}
  FPS operator/(const mint&r)const{return FPS(*this)/=r;}
  FPS operator+(const FPS&r)const{return FPS(*this)+=r;}
  FPS operator-(const FPS&r)const{return FPS(*this)-=r;}
  FPS operator<<(const int&d)const{return FPS(*this)<<=d;}
  FPS operator>>(const int&d)const{return FPS(*this)>>=d;}
  FPS operator*(const FPS&r)const{return FPS(*this)*=r;}
  FPS operator/(const FPS&r)const{return FPS(*this)/=r;}
  FPS operator%(const FPS&r)const{return FPS(*this)%=r;}
  FPS operator-()const{
    FPS ret(*this);
    for(auto &i:ret)i=-i;
    return ret;
  }
  FPS &operator+=(const mint&r){
    if((*this).empty())(*this).resize(1);
    (*this)[0]+=r;
    return *this;
  }
  FPS &operator-=(const mint&r){
    if((*this).empty())(*this).resize(1);
    (*this)[0]-=r;
    return *this;
  }
  FPS &operator*=(const mint&r){
    for(auto &i:*this)i*=r;
    return *this;
  }
  FPS &operator/=(const mint&r){
    (*this)*=r.inv();
    return *this;
  }
  FPS &operator+=(const FPS&r){
    const int n=(*this).size(),m=r.size();
    (*this).resize(max(n,m));
    for(int i=0;i<m;i++)(*this)[i]+=r[i];
    return *this;
  }
  FPS &operator-=(const FPS&r){
    const int n=(*this).size(),m=r.size();
    (*this).resize(max(n,m));
    for(int i=0;i<m;i++)(*this)[i]-=r[i];
    return *this;
  }
  FPS &operator<<=(const long long&d){
    (*this).insert((*this).begin(),d,mint(0));
    return *this;
  }
  FPS &operator>>=(const long long&d){
    (*this).erase((*this).begin(),(*this).begin()+d);
    return *this;
  }
  FPS &operator*=(const FPS&r){
    (*this)=NTT<Mod>::multiply((*this),r);
    return *this;
  }
  FPS &operator/=(FPS r){
    const int n=(*this).size(),m=r.size();
    if(n<m){
      (*this).clear();
      return *this;
    }
    const int sz=n-m+1;
    reverse((*this).begin(),(*this).end());
    reverse(r.begin(),r.end());
    (*this).resize(sz);
    (*this)*=r.inv(sz);
    (*this).resize(sz);
    reverse((*this).begin(),(*this).end());
    return (*this);
  }
  FPS &operator%=(const FPS&r){
    const int n=(*this).size(),m=r.size();
    if(n<m)return (*this);
    (*this)-=(*this)/r*r;
    (*this).resize(m-1);
    shrink();
    return (*this);
  }
  pair<FPS,FPS>div_mod(const FPS&r){
    FPS p=*this/r,q=*this-p*r;
    q.shrink();
    return {p,q};
  }
  mint operator()(const mint&x)const{
    mint ret(0),w(1);
    for(auto &e:*this){
      ret+=e*w;
      w*=x;
    }
    return ret;
  }
  FPS diff()const{
    const int n=(*this).size();
    FPS ret(max(0,n-1));
    for(int i=1;i<n;i++)ret[i-1]=(*this)[i]*mint(i);
    return ret;
  }
  FPS integral()const{
    const int n=(*this).size();
    vector<mint>inv(n+1);
    inv[1]=mint(1);
    for(int i=2;i<=n;i++)inv[i]=-inv[Mod%i]*mint(Mod/i);
    FPS ret(n+1);
    for(int i=0;i<n;i++)ret[i+1]=(*this)[i]*inv[i+1];
    return ret;
  }
  FPS log(int d=-1)const{
    const int n=(*this).size();
    if(d==-1)d=n;
    FPS res=diff()*inv(d);
    res.resize(d-1);
    return res.integral();
  }
  FPS exp(int d=-1)const{
    const int n=(*this).size();
    if(d==-1)d=n;
    FPS f={mint(1)+(*this)[0],(*this)[1]},res{1,1<n?(*this)[1]:0};
    for(int m=2;m<d;m<<=1){
      f.insert(f.end(),(*this).begin()+min(m,n),(*this).begin()+min(n,2*m));
      if((int)f.size()<2*m)f.resize(2*m);
      res=res*(f-res.log(2*m));
      res.resize(2*m);
    }
    res.resize(d);
    return res;
  }
  FPS pow(long long k,int d=-1)const{
    const int n=(*this).size();
    if(d==-1)d=n;
    for(int i=0;i<n;i++){
      if((*this)[i]!=mint()){
        mint rev=(*this)[i].inv();
        if(i*k>d)return FPS(d,mint(0));
        FPS ret=(((*this*rev)>>i).log(d)*k).exp(d)*((*this)[i].pow(k));
        ret=(ret<<(i*k));
        ret.resize(d);
        return ret;
      }
    }
    return FPS(d,mint(0));
  }
  FPS sqrt(int d=-1,const function<mint(mint)>&get_sqrt=[](mint){return mint(1);})const{
    const int n=(*this).size();
    if(d==-1)d=n;
    if((*this)[0]==mint(0)){
      for(int i=1;i<n;i++){
        if((*this)[i]!=mint(0)){
          if(i&1)return {};
          if(d-i/2<=0)break;
          auto ret=(*this>>i).sqrt(d-i/2,get_sqrt);
          if(ret.empty())return {};
          ret=ret<<(i/2);
          if((int)ret.size()<d)ret.resize(d);
          return ret;
        }
      }
      return FPS(d);
    }
    auto sqr=get_sqrt((*this)[0]);
    if(sqr*sqr!=(*this)[0])return {};
    FPS ret{sqr};
    mint inv2=mint(2).inv();
    FPS f={(*this)[0]};
    for(int i=1;i<d;i<<=1){
      if(i<n)f.insert(f.end(),(*this).begin()+i,(*this).begin()+min(n,i<<1));
      if((int)f.size()<(i<<1))f.resize(i<<1);
      ret=(ret+f*ret.inv(i<<1))*inv2;
    }
    ret.resize(d);
    return ret;
  }
};
/**
 * @brief Formal Power Series(形式的冪級数)
*/