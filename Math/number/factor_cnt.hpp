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
/**
 * @brief Factor Count(約数個数)
*/