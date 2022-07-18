#pragma once
template<typename T>
vector<T>gcd_convolution(vector<T>a,vector<T>b){
  const int n=a.size();
  vector<bool>sieve(n,true);
  for(int p=2;p<n;p++)if(sieve[p]){
    for(int i=(n-1)/p;i>0;i--)a[i]+=a[i*p],sieve[i*p]=false;
    sieve[p]=1;
  }
  for(int p=2;p<n;p++)if(sieve[p])for(int i=(n-1)/p;i>0;i--)b[i]+=b[i*p];
  for(int i=0;i<n;i++)a[i]*=b[i];
  for(int p=2;p<n;p++)if(sieve[p]){
    for(int i=1;i*p<n;i++)a[i]-=a[i*p];
  }
  return a;
}