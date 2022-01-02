/**
 * @brief Range Prime Sieve(エラトステネスの区間篩)
*/
template<typename T>
struct range_prime_sieve{
  T l,r,m;
  vector<T>small;
  vector<vector<pair<T,int>>>large;
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
            if(large[j-l].back().first==i)large[j-l].back().second++;
            else large[j-l].emplace_back(i,1);
          }
        }
      }
    }
  }
  vector<pair<T,int>>factor(T n){
    vector<pair<T,int>>res=large[n-l];
    if(mul[n-l]!=1)res.emplace_back(mul[n-l],1);
    return res;
  }
};