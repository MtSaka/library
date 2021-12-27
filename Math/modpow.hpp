/**
 * @brief Mod Pow(べき乗)
*/
template<typename T,typename S>
T modpow(T a,S b,T m){
  T ret=1;
  while(b){
    if(b&1)ret=ret*a%m;
    a=a*a%m;
    b>>=1;
  }
  return ret;
}