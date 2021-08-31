#include<bits/stdc++.h>
using namespace std;
namespace fastprime{
  using i128=__uint128_t;
  long long inner_modmul(long long x,long long y,long long p){
    return i128(x)*y%p;
  }
  long long inner_modpow(long long n,long long m,long long p){
    long long res=1;
    while(m){
      if(m&1)res=inner_modmul(res,n,p);
      n=inner_modmul(n,n,p);
      m>>=1;
    }
    return res;
  }
  bool miller_rabin(long long n,vector<long long>p){
    long long s=__builtin_ctzll(n-1),d=n>>s;
    for(long long a:p){
      if(n<=a)break;
      long long t=d,y=inner_modpow(a,t,n);
      while(t!=n-1&&y!=1&&y!=n-1){
        y=inner_modmul(y,y,n);
        t=inner_modmul(t,2,n);
      }
      if(y!=n-1&&!(t&1))return false;
    }
    return true;
  }
  bool is_prime(long long n){
    if(n<=2)return n==2;
    if(!(n&1))return false;
    if(n<=4759123141)return miller_rabin(n,{2,7,61});
    return miller_rabin(n,{2,325,9375,28178,450775,9780504,1795265022});
  }
  long long factor(long long n){
    if(!(n&1))return 2;
    else if(is_prime(n))return n;
    int c=2;
    while(true){
      auto f=[&](long long x){
        x=inner_modmul(x,x,n)+c;
        if(x>=n)x-=n;
        return x;
      };
      long long x=c,g=1,q=1,xs,y;
      int m=128;
      int l=1;
      while(g==1){
        y=x;
        for(int i=1;i<l;i++)x=f(x);
        int k=0;
        while(k<l&&g==1){
          xs=x;
          for(int i=0;i<m&&i<l-k;i++){
            x=f(x);
            q=inner_modmul(q,llabs(y-x),n);
          }
          g=__gcd(q,n);
          k+=m;
        }
        l*=2;
      }
      if(g==n){
        do{
          xs=f(xs);
          g=__gcd(llabs(xs-y),n);
        }while(g==1);
      }
      if(g!=n)return g;
      c++;
    }
  }
  vector<long long>factorize_sub(long long n){
    if(n==1)return {};
    long long p=factor(n);
    if(p==n)return {p};
    vector<long long>l=factorize_sub(n/p);
    vector<long long>r=factorize_sub(p);
    l.insert(l.end(),r.begin(),r.end());
    return l;
  }
  vector<long long>factorize(long long n,bool sorted=true){
    vector<long long>res=factorize_sub(n);
    if(sorted)sort(res.begin(),res.end());
    return res;
  }
};