/**
 * @brief Range Prime Sieve(エラトステネスの区間篩)
*/
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