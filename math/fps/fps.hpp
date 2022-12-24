#pragma once
#include"../../template/template.hpp"
#include"../convolution/convolution.hpp"

template<typename mint=ModInt<998244353>>
struct FormalPowerSeries:vector<mint>{
  using vector<mint>::vector;
  using FPS=FormalPowerSeries<mint>;
  private:
  static constexpr unsigned int p=mint::get_mod();
  public:
  inline void shrink(){while(!(*this).empty()&&(*this).back()==mint())(*this).pop_back();}
  FPS& dot(const FPS&r){
    rep(i,min((*this).size(),r.size()))(*this)[i]*=r[i];
    return *this;
  }
  FPS inv(int d=-1)const{
    const int n=(*this).size();
    if(d==-1)d=n;
    FPS res(d);
    res[0]=(*this)[0].inv();
    for(int sz=1;sz<d;sz<<=1){
      FPS f((*this).begin(),(*this).begin()+min(n,2*sz));
      FPS g(res.begin(),res.begin()+sz);
      f.resize(2*sz),g.resize(2*sz);
      ntt(f),ntt(g);
      f.dot(g);
      intt(f);
      rep(i,sz)f[i]=0;
      ntt(f);
      f.dot(g);
      intt(f);
      rep(j,sz,min(2*sz,d))res[j]=-f[j];
    }
    return res;
  }
  FPS operator+()const{return *this;}
  FPS operator-()const{
    FPS res(*this);
    for(auto &x:res)x=-x;
    return res;
  }
  FPS& operator+=(const mint&r){
    shrink();
    if((*this).empty())(*this).resize(1);
    (*this)[0]+=r;
    return *this;
  }
  FPS& operator-=(const mint&r){
    shrink();
    if((*this).empty())(*this).resize(1);
    (*this)[0]-=r;
    return *this;
  }
  FPS& operator*=(const mint&r){
    shrink();
    for(auto &x:*this)x*=r;
    return *this;
  }
  FPS& operator/=(const mint&r){
    shrink()
    (*this)*=r.inv();
    return *this;
  }
  FPS& operator+=(const FPS&r){
    shrink();
    if((*this).size()<r.size())(*this).resize(r.size());
    rep(i,r.size())(*this)[i]+=r[i];
    return *this;
  }
  FPS& operator-=(const FPS&r){
    shrink();
    if((*this).size()<r.size())(*this).resize(r.size());
    rep(i,r.size())(*this)[i]-=r[i];
    return *this;
  }
  FPS& operator*=(const FPS&r){
    shrink();
    auto ret=convolution(*this,r);
    (*this)={ret.begin(),ret.end()};
    return *this;
  }
  FPS& operator/=(const FPS&r){
    shrink();
    const int n=(*this).size(),m=r.size();
    if(n<m){
      (*this).clear();
      return *this;
    }
    const int d=n-m+1;
    reverse((*this).begin(),(*this).end());
    reverse(r.begin(),r.end());
    (*this).resize(d);
    (*this)*=r.inv(d);
    (*this).resize(d);
    reverse((*this).begin(),(*this).end());
    return *this;
  }
  FPS& operator%=(const FPS&r){
    shrink();
    const int n=(*this).size(),m=r.size();
    if(n<m)return *this;
    (*this)-=(*this)/r*r;
    shrink();
    return *this;
  }
  friend FPS operator+(const FPS&l,const mint&r){return FPS(l)+=r;}
  friend FPS operator-(const FPS&l,const mint&r){return FPS(l)-=r;}
  friend FPS operator*(const FPS&l,const mint&r){return FPS(l)*=r;}
  friend FPS operator/(const FPS&l,const mint&r){return FPS(l)/=r;}
  friend FPS operator+(const mint&l,const FPS&r){return FPS(r)+=l;}
  friend FPS operator-(const mint&l,const FPS&r){return FPS(-r)+=l;}
  friend FPS operator*(const mint&l,const FPS&r){return FPS(r)*=l;}
  friend FPS operator+(const FPS&l,const FPS&r){return FPS(l)+=r;}
  friend FPS operator-(const FPS&l,const FPS&r){return FPS(l)-=r;}
  friend FPS operator*(const FPS&l,const FPS&r){return FPS(l)*=r;}
  friend FPS operator/(const FPS&l,const FPS&r){return FPS(l)/=r;}
  friend FPS operator%(const FPS&l,const FPS&r){return FPS(l)%=r;}
  pair<FPS,FPS>div_mod(const FPS&r)const{
    FPS q=(*this)/r;
    FPS m;
    if((*this).size()>=r.size())m=(*this)-q*r;
    else m=*this;
    q.shrink(),m.shrink();
    return {q,m};
  }
  mint operator()(const mint&x)const{
    mint res=0,w=1;
    for(auto &v:*this)res+=v*w,w*=x;
    return res;
  }
  FPS diff()const{
    const int n=(*this).size();
    FPS res(n-1);
    rep(i,1,n)res[i-1]=(*this)[i]*i;
    return res;
  }
  FPS& inplace_diff(){
    shrink();
    (*this).erase((*this).begin());
    mint coeff=1;
    for(int i=0;i<(int)(*this).size();i++){
      (*this)[i]*=coeff;
      coeff++;
    }
    return *this;
  }
  FPS integral()const{
    const int n=(*this).size();
    vector<mint>iv(n+1,1);
    rep(i,2,n+1)iv[i]=-iv[p%i]*(p/i);
    FPS res(n+1);
    rep(i,n)res[i+1]=(*this)[i]*iv[i+1];
    return res;
  }
  FPS& inplace_integral(){
    shrink();
    const int n=(*this).size();
    vector<mint>iv(n+1,1);
    rep(i,2,n+1)iv[i]=-iv[p%i]*(p/i);
    (*this).insert((*this).begin(),mint(0));
    rep(i,1,n+1)(*this)[i]*=iv[i];
    return *this;
  }
  FPS log(int d=-1)const{
    const int n=(*this).size();
    if(d==-1)d=n;
    FPS res=diff()*inv(d);
    res.resize(d-1);
    return res.integral();
  }
  FPS& inplace_log(int d=-1){
    shrink();
    const int n=(*this).size();
    if(d==-1)d=n;
    FPS tmp=inv(d);
    (*this).inplace_diff()*=tmp;
    (*this).resize(d-1);
    return (*this).inplace_integral();
  }
  FPS exp(int d=-1)const{
    const int n=(*this).size();
    if(d==-1)d=n;
    if(n==1){
      FPS res(d,mint());
      res[0]=1;
      return res;
    }
    FPS f={mint(1)+(*this)[0],(*this)[1]},res{1,(*this)[1]};
    for(int sz=2;sz<d;sz<<=1){
      f.insert(f.end(),(*this).begin()+min(sz,n),(*this).begin()+min(n,sz<<1));
      f.resize(sz<<1);
      res=res*(f-res.log(sz<<1));
      res.resize(sz<<1);
    }
    res.resize(d);
    return res;
  }
  FPS pow(ll k,int d=-1)const{
    const int n=(*this).size();
    if(d==-1)d=n;
    if(k==0){
      FPS ans(d,mint());
      ans[0]=1;
      return ans;
    }
    for(int i=0;i<n;i++){
      if((*this)[i]!=mint()){
        if(i>d/k)return FPS(d,mint());
        mint rev=(*this)[i].inv();
        FPS res=(((*this*rev)>>i).log(d)*k).exp(d)*((*this)[i].pow(k));
        res=(res<<(i*k));
        res.resize(d);
        return res;
      }
    }
    return FPS(d,mint());
  }
  FPS sqrt(const function<mint(mint)>&get_sqrt=[](mint){return mint(1);},int d=-1)const{
    const int n=(*this).size();
    if(d==-1)d=n;
    if((*this)[0]==mint(0)){
      rep(i,1,n){
        if((*this)[i]!=mint(0)){
          if(i&1)return {};
          if(d-i/2<=0)break;
          auto res=(*this>>i).sqrt(get_sqrt,d-i/2);
          if(res.empty())return {};
          res=res<<(i/2);
          res.resize(d);
          return res;
        }
      }
      return FPS(d);
    }
    auto sqr=get_sqrt((*this)[0]);
    if(sqr*sqr!=(*this)[0])return {};
    FPS res{sqr};
    const mint inv2=mint(2).inv();
    FPS f={(*this)[0]};
    for(int i=1;i<d;i<<=1){
      if(i<n)f.insert(f.end(),(*this).begin()+i,(*this).begin()+min(n,i<<1));
      if((int)f.size()<(i<<1))f.resize(i<<1);
      res=(res+f*res.inv(i<<1))*inv2;
    }
    res.resize(d);
    return res;
  }
};
/*
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
};*/
/**
 * @brief Formal Power Series(形式的冪級数)
*/