#include<bits/stdc++.h>
using namespace std;
struct fft{
  void dft(vector<complex<double>>&a,double inv){
    int sz=a.size();
    if(sz==1)return;
    vector<complex<double>>x,y;
    for(int i=0;i<sz/2;i++){
      x.push_back(a[2*i]);
      y.push_back(a[2*i+1]);
    }
    dft(x,inv);
    dft(y,inv);
    complex<double> n=1,z=polar(1.0,inv*2.0*acos(-1)/(double)sz);
    for(int i=0;i<sz;i++){
      a[i]=x[i%(sz/2)]+n*y[i%(sz/2)];
      n*=z;
    }
  }
  template<typename T>
  vector<double>multiply(vector<T>a,vector<T>b){
    int sz=1;
    while(sz<a.size()+b.size())sz*=2;
    vector<complex<double>>ma(sz),mb(sz);
    for(int i=0;i<a.size();i++)ma[i]=a[i];
    for(int i=0;i<b.size();i++)mb[i]=b[i];
    dft(ma,1);
    dft(mb,1);
    for(int i=0;i<sz;i++)ma[i]*=mb[i];
    dft(ma,-1);
    vector<double>res(a.size()+b.size()-1);
    for(int i=0;i<a.size()+b.size()-1;i++)res[i]=((ma[i].real())/(double)sz);
    return res;
  }
};