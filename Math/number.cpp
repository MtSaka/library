#include<bits/stdc++.h>
using namespace std;
long long digsum(long long n){
  long long ans=0;
  while(n){
    ans+=n%10;
    n/=10;
  }
  return ans;
}
long long gcd(long long a,long long b){return (b?gcd(b,a%b):a);}
long long lcm(long long a,long long b){return a/gcd(a,b)*b;}