#include<bits/stdc++.h>
#include"../../code/library/Math/ntt.cpp>"
#include"../../code/library/Math/modulo.cpp"
using namespace std;
vector<long long>mod_ntt(const vector<long long>&a,const vector<long long&>b,const long long&m){
  NTT<167772161>ntt1;
  NTT<469762049>ntt2;
  NTT<1224736769>ntt3;
  auto x=ntt1.multiply(a,b);
  auto y=ntt2.multiply(a,b);
  auto z=ntt3.multiply(a,b);
  long long m1=167772161,m2=469762049,m3=1224736769,m1_inv_m2=modinv(m1,m2),m12_inv_m3=modinv(m1*m2,m3),m12_mod=m1*m2%m;
  vector<long long>res(x.size());
  for(int i=0;i<x.size();i++){
    long long v1=(y[i]-x[i])*m1_inv_m2%m2;
    if(v1<0)v1+=m2;
    long long v2=(z[i]-(x[i]+m1*v1)%m3)*m12_inv_m3%m3;
    if(v2<0)v2+=m3;
    long long c=(x[i]+m1*v1+m12_mod*v2)%m;
    if(c<0)c+=m;
    res[i]=c;
  }
  return res;
}