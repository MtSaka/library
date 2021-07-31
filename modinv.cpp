ll modinv(ll a,ll m){
  if(a==1){return 1;}
  return m-modinv(m%a,m)*(m/a)%m;
}
