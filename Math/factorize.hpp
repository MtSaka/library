/**
 * @brief Prime Factorization(素因数分解)
*/
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