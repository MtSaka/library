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
template<typename T>
struct prime_sieve{
  vector<T>mpf;
  vector<T>primes;
  prime_sieve(T n=1e5){
    mpf.resize(n+1,0);
    iota(mpf.begin(),mpf.end(),0);
    mpf[0]=mpf[1]=-1;
    for(T i=2;i*i<=n;i++){
      if(mpf[i]==i){
        for(T j=i*i;j<=n;j+=i){
          if(mpf[j]==j)mpf[j]=i;
        }
      }
    }
    for(T i=2;i<=n;i++)if(mpf[i]==i)primes.push_back(i);
  }
  vector<T>factorize(T n){
    vector<T>res;
    T now=n;
    while(now!=1){
      res.push_back(mpf[now]);
      now/=mpf[now];
    }
    return res;
  }
};
template<typename T>
struct range_prime_sieve{
  T l,r,m;
  vector<T>small;
  vector<vector<T>>large;
  vector<T>mul;
  range_prime_sieve(T l,T r):l(l),r(r),m(sqrt(r)+1){
    large.resize(r-l);
    small.resize(m);
    mul.resize(r-l);
    iota(mul.begin(),mul.end(),l);
    iota(small.begin(),small.end(),0);
    for(T i=2;i*i<r;i++){
      if(small[i]==i){
        for(T j=i*i;j<m;j+=i)if(small[j]==j)small[j]=i;
        for(T j=(l+i-1)/i*i;j<r;j+=i){
          while(mul[j-l]%i==0){
            mul[j-l]/=i;
            large[j-l].push_back(i);
          }
        }
      }
    }
  }
  vector<T>factor(T n){
    vector<T>res=large[n-l];
    if(mul[n-l]!=1)res.push_back(mul[n-l]);
    return res;
  }
};