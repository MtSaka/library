#include<bits/stdc++.h>
#include<../../code/library/Math/ntt.cpp>
#include<../../code/library/Math/modulo.cpp>
using namespace std;
vector<long long>mod_convolution(vector<long long>a,vector<long long>b,long long m){
  NTT<167772161>ntt1;
  NTT<469762049>ntt2;
  NTT<1224736769>ntt3;
  vector<modint<167772161>>a1(a.size()),b1(b.size());
  vector<modint<469762049>>a2(a.size()),b2(b.size());
  vector<modint<1224736769>>a3(a.size()),b3(b.size());
  for(int i=0;i<a.size();i++)a1[i]=a[i],a2[i]=a[i],a3[i]=a[i];
  for(int i=0;i<b.size();i++)b1[i]=b[i],b2[i]=b[i],b3[i]=b[i];
  auto x=ntt1.multiply(a1,b1);
  auto y=ntt2.multiply(a2,b2);
  auto z=ntt3.multiply(a3,b3);
  long long m1=167772161,m2=469762049,m3=1224736769,m1_inv_m2=modinv(m1,m2),m12_inv_m3=modinv(m1*m2,m3),m12_mod=m1*m2%m;
  vector<long long>res(x.size());
  for(int i=0;i<x.size();i++){
    long long v1=(y[i].x-x[i].x)*m1_inv_m2%m2;
    if(v1<0)v1+=m2;
    long long v2=(z[i].x-(x[i].x+m1*v1)%m3)*m12_inv_m3%m3;
    if(v2<0)v2+=m3;
    long long c=(x[i].x+m1*v1+m12_mod*v2)%m;
    if(c<0)c+=m;
    res[i]=c;
  }
  return res;
}