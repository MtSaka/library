vector<pair<long long,int>>factorize(long long N){
  vector<pair<long long,int>>ans;
  for(long long i=2;i*i<=N;i++){
    if(N%i!=0)continue;
    int idx=0;
    while(N%i==0){
      idx++;
      N/=i;
    }
    ans.push_back({i,idx});
  }
  if(N!=1)ans.push_back({N,1});
  return ans;
}
/**
 * @brief Prime Factorization(素因数分解)
*/