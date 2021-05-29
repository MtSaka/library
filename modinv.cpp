#include<bits/stdc++.h>
#define ll long long
ll modinv(ll a,ll m){
  ll b=m,x=1,y=0;
  while(b>0){
    x-=y*(a/b);
    swap(x,y);
    a=a%b;
    swap(a,b);
  }
  x=x%m; 
  if(x>=0){
    return x;
  }
  else{
    return x+m;
  }
}
