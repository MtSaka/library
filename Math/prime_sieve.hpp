/**
 * @brief Prime Sieve(エラトステネスの篩)
*/
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
  vector<pair<T,int>>factorize(T n){
    vector<pair<T,int>>res;
    T now=n;
    while(now!=1){
      if(res.back().first==mpf[now])res.back().second++;
      else res.emplace_back(mpf[now],1);
      now/=mpf[now];
    }
    return res;
  }
};