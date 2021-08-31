#include<bits/stdc++.h>
using namespace std;
bool is_prime(long long N){
  if(N<2)return 0;
  if(N==2)return 1;
  if(N%2==0)return 0;
  for(long long i=3;i*i<=N;i+=2){
    if(N%i==0)return 0;
  }
  return 1;
}
vector<pair<long long,long long>>factorize(long long N){
  vector<pair<long long,long long>>ans;
  for(long long i=2;i*i<=N;i++){
    if(N%i!=0)continue;
    long long idx=0;
    while(N%i==0){
      idx++;
      N/=i;
    }
    ans.push_back({i,idx});
  }
  if(N!=1)ans.push_back({N,1});
  return ans;
}
vector<long long>factor(long long N){
  vector<long long>ans;
  for(long long i=1;i*i<=N;i++){
    if(N%i==0){
      ans.push_back(i);
      if(i*i!=N){
        ans.push_back(N/i);
      }
    }
  }
  sort(ans.rbegin(),ans.rend());
  return ans;
}
long long factor_cnt(long long N){
  long long ans=1;
  for(long long i=2;i*i<=N;i++){
    if(N%i==0){
      int e=0;
      while(N%i==0){
        N/=i;
        e++;
      }
      ans*=e+1;
    }
  }
  if(N!=1)ans*=2;
  return ans;
}