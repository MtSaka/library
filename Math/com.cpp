#include"modint.cpp"
template<long long m>
struct combination{
  using mint=modint<m>;
  vector<mint>dat,idat;
  long long mx;
  combination(long long mx_=300000):dat(mx_+1,1),idat(mx_+1,1),mx(mx_){
    for(long long i=1;i<=mx;i++)dat[i]=dat[i-1]*mint(i);
    idat[mx]/=dat[mx];
    for(long long i=mx;i>0;i--)idat[i-1]=idat[i]*mint(i);
  }
  mint com(long long n,long long k){
    if(n<0||k<0||n<k)return mint(0);
    return dat[n]*idat[k]*idat[n-k];
  }
  mint fac(long long n){
    if(n<0)return mint(0);
    return dat[n];
  }
};