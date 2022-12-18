void dft(vector<complex<double>>&a,double inv){
  const int sz=a.size();
  if(sz==1)return;
  const int mask=sz-1;
  vector<complex<double>>b(sz);
  for(int i=sz>>1;i>=1;i>>=1){
    complex<double>z=polar(1.0,2*M_PI*i*inv/sz),w=1;
    for(int j=0;j<sz;j+=i){
      for(int k=0;k<i;k++)b[j+k]=a[((j<<1)&mask)+k]+w*a[(((j<<1)+i)&mask)+k];
      w*=z;
    }
    swap(a,b);
  }
}
template<typename T>
vector<double>multiply(const vector<T>&a,const vector<T>&b){
  int sz=1;
  while(sz<(int)a.size()+b.size()-1)sz<<=1;
  vector<complex<double>>ma(sz),mb(sz);
  for(int i=0;i<(int)a.size();i++)ma[i]=a[i];
  for(int i=0;i<(int)b.size();i++)mb[i]=b[i];
  dft(ma,1);dft(mb,1);
  for(int i=0;i<sz;i++)ma[i]*=mb[i];
  dft(ma,-1);
  vector<double>res(a.size()+b.size()-1);
  for(int i=0;i<(int)res.size();i++)res[i]=(ma[i].real())/(double)sz;
  return res;
}
/**
 * @brief Fast Fourier Transform(高速フーリエ変換)
*/