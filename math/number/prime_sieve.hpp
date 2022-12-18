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
      if(res.size()&&res.back().first==mpf[now])res.back().second++;
      else res.emplace_back(mpf[now],1);
      now/=mpf[now];
    }
    return res;
  }
};
template<typename T>
struct IsPrime{
  T MAX;
  vector<bool>isprime;
  IsPrime(T MAX):MAX(MAX),isprime(MAX+1,true){
    isprime[0]=isprime[1]=false;
    for(T i=2;i<MAX+1;i++){
      if(!isprime[i])continue;
      for(T j=i*i;j<MAX+1;j+=i)isprime[j]=false;
    }
  }
  bool is_prime(T x){return isprime[x];}
  vector<T>primes(T m=-1){
    if(m==-1)m=MAX;
    vector<T>res;
    for(T i=2;i<m+1;i++)if(isprime[i])res.push_back(i);
    return res;
  }
};
/**
 * @brief Prime Sieve(エラトステネスの篩)
*/