#pragma once
#include"../../template/template.hpp"
#include"../convolution/ntt.hpp"

template<int m>
struct FormalPowerSeries:vector<ModInt<m>>{
  using mint=ModInt<m>;
  using vector<mint>::vector;
  using vector<mint>::operator=;
  void shrink(){while(!(*this).empty()&&(*this).back()==mint())(*this).pop_back();}
  FormalPowerSeries inv(int d=-1)const{
    NTT<m>ntt;
    const int n=(*this).size();
    if(d==-1)d=n;
    FormalPowerSeries res{(*this)[0].inv()};
    for(int sz=1;sz<d;sz<<=1){
      FormalPowerSeries f((*this).begin(),(*this).begin()+min(n,2*sz));
      FormalPowerSeries g(res);
      f.resize(2*sz),g.resize(2*sz);
      ntt.dft(f,1),ntt.dft(g,1);
      for(int i=0;i<2*sz;i++)f[i]*=g[i];
      ntt.dft(f,-1);
      f.erase(f.begin(),f.begin()+sz);
      f.resize(2*sz);ntt.dft(f,1);
      for(int i=0;i<2*sz;i++)f[i]*=g[i];
      ntt.dft(f,-1);
      mint iz=mint(2*sz).inv();iz*=-iz;
      for(int i=0;i<sz;i++)f[i]*=iz;
      res.insert(res.end(),f.begin(),f.begin()+sz);
    }
    res.resize(d);
    return res;
  }
  FormalPowerSeries operator+(const mint&r)const{return FormalPowerSeries(*this)+=r;}
  FormalPowerSeries operator-(const mint&r)const{return FormalPowerSeries(*this)-=r;}
  FormalPowerSeries operator*(const mint&r)const{return FormalPowerSeries(*this)*=r;}
  FormalPowerSeries operator/(const mint&r)const{return FormalPowerSeries(*this)/=r;}
  FormalPowerSeries operator+(const FormalPowerSeries&r)const{return FormalPowerSeries(*this)+=r;}
  FormalPowerSeries operator-(const FormalPowerSeries&r)const{return FormalPowerSeries(*this)-=r;}
  FormalPowerSeries operator<<(const int&d)const{return FormalPowerSeries(*this)<<=d;}
  FormalPowerSeries operator>>(const int&d)const{return FormalPowerSeries(*this)>>=d;}
  FormalPowerSeries operator*(const FormalPowerSeries&r)const{return FormalPowerSeries(*this)*=r;}
  FormalPowerSeries operator/(const FormalPowerSeries&r)const{return FormalPowerSeries(*this)/=r;}
  FormalPowerSeries operator%(const FormalPowerSeries&r)const{return FormalPowerSeries(*this)%=r;}
  FormalPowerSeries operator-()const{
    FormalPowerSeries ret(*this);
    for(auto &i:ret)i=-i;
    return ret;
  }
  FormalPowerSeries &operator+=(const mint&r){
    if((*this).empty())(*this).resize(1);
    (*this)[0]+=r;
    return *this;
  }
  FormalPowerSeries &operator-=(const mint&r){
    if((*this).empty())(*this).resize(1);
    (*this)[0]-=r;
    return *this;
  }
  FormalPowerSeries &operator*=(const mint&r){
    for(auto &i:*this)i*=r;
    return *this;
  }
  FormalPowerSeries &operator/=(const mint&r){
    (*this)*=r.inv();
    return *this;
  }
  FormalPowerSeries &operator+=(const FormalPowerSeries&r){
    const int n=(*this).size(),sz=r.size();
    (*this).resize(max(n,sz));
    for(int i=0;i<sz;i++)(*this)[i]+=r[i];
    return *this;
  }
  FormalPowerSeries &operator-=(const FormalPowerSeries&r){
    const int n=(*this).size(),sz=r.size();
    (*this).resize(max(n,sz));
    for(int i=0;i<sz;i++)(*this)[i]-=r[i];
    return *this;
  }
  FormalPowerSeries &operator<<=(const long long&d){
    (*this).insert((*this).begin(),d,mint(0));
    return *this;
  }
  FormalPowerSeries &operator>>=(const long long&d){
    (*this).erase((*this).begin(),(*this).begin()+d);
    return *this;
  }
  FormalPowerSeries &operator*=(const FormalPowerSeries&r){
    (*this)=NTT<m>::multiply((*this),r);
    return *this;
  }
  FormalPowerSeries &operator/=(FormalPowerSeries r){
    const int n=(*this).size(),n1=r.size();
    if(n<n1){
      (*this).clear();
      return *this;
    }
    const int sz=n-n1+1;
    reverse((*this).begin(),(*this).end());
    reverse(r.begin(),r.end());
    (*this).resize(sz);
    (*this)*=r.inv(sz);
    (*this).resize(sz);
    reverse((*this).begin(),(*this).end());
    return (*this);
  }
  FormalPowerSeries &operator%=(const FormalPowerSeries&r){
    const int n=(*this).size(),sz=r.size();
    if(n<sz)return (*this);
    (*this)-=(*this)/r*r;
    (*this).resize(sz-1);
    shrink();
    return (*this);
  }
  pair<FormalPowerSeries,FormalPowerSeries>div_mod(const FormalPowerSeries&r){
    FormalPowerSeries p=*this/r,q=*this-p*r;
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
  FormalPowerSeries diff()const{
    const int n=(*this).size();
    FormalPowerSeries ret(max(0,n-1));
    for(int i=1;i<n;i++)ret[i-1]=(*this)[i]*mint(i);
    return ret;
  }
  FormalPowerSeries integral()const{
    const int n=(*this).size();
    vector<mint>inv(n+1);
    inv[1]=mint(1);
    for(int i=2;i<=n;i++)inv[i]=-inv[m%i]*mint(m/i);
    FormalPowerSeries ret(n+1);
    for(int i=0;i<n;i++)ret[i+1]=(*this)[i]*inv[i+1];
    return ret;
  }
  FormalPowerSeries log(int d=-1)const{
    const int n=(*this).size();
    if(d==-1)d=n;
    FormalPowerSeries res=diff()*inv(d);
    res.resize(d-1);
    return res.integral();
  }
  FormalPowerSeries exp(int d=-1)const{
    const int n=(*this).size();
    if(d==-1)d=n;
    FormalPowerSeries f={mint(1)+(*this)[0],(*this)[1]},res{1,1<n?(*this)[1]:0};
    for(int sz=2;sz<d;sz<<=1){
      f.insert(f.end(),(*this).begin()+min(sz,n),(*this).begin()+min(n,2*sz));
      if((int)f.size()<2*sz)f.resize(2*sz);
      res=res*(f-res.log(2*sz));
      res.resize(2*sz);
    }
    res.resize(d);
    return res;
  }
  FormalPowerSeries pow(long long k,int d=-1)const{
    const int n=(*this).size();
    if(d==-1)d=n;
    if(k==0){
      FormalPowerSeries ans(d,mint(0));
      ans[0]=1;
      return ans;
    }
    for(int i=0;i<n;i++){
      if((*this)[i]!=mint()){
        if(i>d/k)return FormalPowerSeries(d,mint(0));
        mint rev=(*this)[i].inv();
        FormalPowerSeries ret=(((*this*rev)>>i).log(d)*k).exp(d)*((*this)[i].pow(k));
        ret=(ret<<(i*k));
        ret.resize(d);
        return ret;
      }
    }
    return FormalPowerSeries(d,mint(0));
  }
  FormalPowerSeries sqrt(int d=-1,const function<mint(mint)>&get_sqrt=[](mint){return mint(1);})const{
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
      return FormalPowerSeries(d);
    }
    auto sqr=get_sqrt((*this)[0]);
    if(sqr*sqr!=(*this)[0])return {};
    FormalPowerSeries ret{sqr};
    mint inv2=mint(2).inv();
    FormalPowerSeries f={(*this)[0]};
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