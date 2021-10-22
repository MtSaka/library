#include<bits/stdc++.h>
#include"../../code/library/Math/ntt.cpp"
using namespace std;
template<long long m>
struct FPS{
  using mint=modint<m>;
  vector<mint>val;
  NTT<m>ntt;
  FPS(){}
  FPS(int sz):val(sz){}
  FPS(const vector<mint>&a):val(a){}
  FPS(vector<mint>&&a):val(move(a)){}
  FPS(const FPS &other):val(other.val){}
  FPS(FPS &&other):val(move(other.val)){}
  mint &operator[](int i){return val[i];}
  size_t size()const{return val.size();}
  void resize(const int sz){val.resize(sz);}
  void shrink(){while(!val.empty()&&val.back()==mint(0))val.pop_back();}
  FPS &operator=(const FPS &other){
    val=other.val;
    return *this;
  }
  FPS &operator=(FPS &&other){
    val=move(other.val);
    return *this;
  }
  FPS inv(int mx=-1)const{
    if(mx==-1)mx=size();
    FPS g(1);
    g[0]=val[0].inv();
    int now=1;
    while(now<mx){
      now<<=1;
      FPS t=(*this);
      t.resize(now);
      t*=-g;
      t[0]+=2,g*=t;
      g.resize(now);
    }
    g.resize(mx);
    return g;
  }
  FPS operator+(const FPS&r)const{return FPS(*this)+=r;}
  FPS operator-(const FPS&r)const{return FPS(*this)-=r;}
  FPS operator*(const FPS&r)const{return FPS(*this)*=r;}
  FPS operator/(const FPS&r)const{return FPS(*this)/=r;}
  FPS operator%(const FPS&r)const{return FPS(*this)%=r;}
  FPS operator-()const{
    FPS ret(val);
    for(int i=0;i<val.size();i++)ret[i]=-ret[i];
    return ret;
  }
  FPS operator+=(FPS r){
    if(r.size()>val.size())val.resize(r.size());
    for(int i=0;i<r.size();i++)val[i]+=r[i];
    return *this;
  }
  FPS operator-=(FPS r){
    if(r.size()>val.size())val.resize(r.size());
    for(int i=0;i<r.size();i++)val[i]-=r[i];
    return *this;
  }
  FPS operator*=(FPS r){
    val=ntt.multiply(val,r.val);
    return *this;
  }
  FPS operator/=(FPS r){
    if(val.size()<r.size()){
      val.clear();
      return *this;
    }
    int sz=val.size()-r.size()+1;
    reverse(val.begin(),val.end());
    reverse(r.val.begin(),r.val.end());
    val.resize(sz);
    (*this)*=r.inv(sz);
    val.resize(sz);
    reverse(val.begin(),val.end());
    return (*this);
  }
  FPS operator%=(FPS r){
    if(val.size()<r.size())return (*this);
    (*this)-=(*this)/r*r;
    val.resize(r.size()-1);
    shrink();
    return (*this);
  }
  FPS diff()const{
    int n=size();
    FPS ret(max(0,n-1));
    for(int i=1;i<n;i++)ret[i-1]=val[i]*mint(i);
    return ret;
  }
  FPS integral()const{
    int n=size();
    FPS ret(n+1);
    for(int i=0;i<n;i++)ret[i+1]=val[i]/mint(i+1);
    return ret;
  }
  FPS log(int mx=-1)const{
    if(mx==-1)mx=size();
    FPS res=diff()*inv(mx);
    res.resize(mx-1);
    return res.integral();
  }
};