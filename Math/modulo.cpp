#include<bits/stdc++.h>
using namespace std;
long long modpow(long long a,long long n,long long m){
  long long ans=1;
  while(n>0){
    if(n&1)ans=ans*a%m;
    a=a*a%m;
    n>>=1;
  }
  return ans;
}
long long modinv(long long a,long long m){
  long long b=m,c=1,d=0;
  while(b){
    long long t=a/b;
    a-=t*b;swap(a,b);
    c-=t*d;swap(c,d);
  }
  c%=m;
  if(c<0)c+=m;
  return c;
}