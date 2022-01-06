/**
 * @brief Formal Power Series(形式的冪級数)
*/
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
  FPS &operator<<=(const int&d){
    (*this).insert((*this).begin(),d,mint(0));
    return *this;
  }
  FPS &operator>>=(const int&d){
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
    NTT<Mod>ntt;
    vector<mint>inv;
    inv.reserve(d+1);
    inv.push_back(mint(0));
    inv.push_back(mint(1));
    auto integral_inplace=[&](FPS&F)->void{
      const int n=F.size();
      while(inv.size()<=n){
        int i=inv.size();
        inv.push_back((-inv[Mod%i]*mint(Mod/i)));
      }
      F.insert(F.begin(),mint(0));
      for(int i=1;i<=n;i++)F[i]*=inv[i];
    };
    auto diff_inplace=[&](FPS&F)->void{
      if(F.empty())return;
      F.erase(F.begin());
      T c=1,one=1;
      for(int i=1;i<F.size();i++)F[i]*=c,c+=one;
    };
    FPS b{1,1<n?(*this)[1]:0},c{1},z1,z2{1,1};
    for(int m=2;m<d;m<<=1){
      auto y=b;
      y.resize(2*m);
      ntt.dft(y,1);
      z1=z2;
      FPS z(m);
      for(int i=0;i<m;i++)z[i]=y[i]*z1[i];
      ntt.dft(z,-1);
      fill(z.begin(),z.end()+m/2,mint(0));
      ntt.dft(z,1);
      for(int i=0;i<m;i++)z[i]*=-z1[i];
      ntt.dft(z,-1);
      c.insert(c.end(),z.begin()+m/2,z.end());
      z2=c;
      z2.resize(2*m);
      ntt.dft(z2,1);
      FPS x((*this).begin(),(*this).begin()+min(n,m));
      x.resize(m);
      diff_inplace(x);
      x.push_back(mint(0));
      ntt.dft(x,1);
      for(int i=0;i<m;i++)x[i]*=y[i];
      ntt.dft(x,-1);
      x-=c.diff();
      x.resize(2*m);
      for(int i=0;i<m-1;i++)x[m+i]=x[i],x[i]=mint(0);
      ntt.dft(x,1);
      for(int i=0;i<m;i++)x[i]*=z2[i];
      ntt.dft(x,-1);
      x.pop_back();
      integral_inplace(x);
      for(int i=m;i<min(n,2*m);i++)x[i]+=(*this)[i];
      fill(x.begin(),x.begin()+m,mint(0));
      ntt.dft(x,1);
      for(int i=0;i<2*m;i++)x[i]*=y[i];
      ntt.dft(x,-1);
      b.insert(b.end(),x.begin()+m,x.end());
    }
    b.resize(d);
    return b;
  }
};