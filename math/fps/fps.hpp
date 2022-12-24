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
  FPS& operator/=(FPS r){
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
  FPS& operator<<=(ll k){
    shrink();
    (*this).insert((*this).begin(),k,mint(0));
    return *this;
  }
  FPS& operator>>=(ll k){
    shrink();
    if(k>(ll)(*this).size())(*this).clear();
    else (*this).erase((*this).begin(),(*this).begin()+k);
    return *this;
  }
  FPS operator<<(ll k)const{return FPS(*this)<<=k;}
  FPS operator>>(ll k)const{return FPS(*this)>>=k;}
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
/**
 * @brief Formal Power Series(形式的冪級数)
*/