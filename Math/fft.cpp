struct FFT{
  void dft(vector<complex<double>>&a,double inv){
    int sz=a.size();
    if(sz==1)return;
    int mask=sz-1;
    vector<complex<double>>b(sz);
    for(int i=sz>>1;i>=1;i>>=1){
      complex<double>z=polar(1.0,2*pi*i*inv/sz),w=1;
      for(int j=0;j<sz;j+=i){
        for(int k=0;k<i;k++)b[j+k]=a[((j<<1)&mask)+k]+w*a[(((j<<1)+i)&mask)+k];
        w*=z;
      }
      swap(a,b);
    }
  }
  template<typename T>
  vector<double>multiply(vector<T>a,vector<T>b){
    int sz=1;
    while(sz<a.size()+b.size()-1)sz<<=1;
    vector<complex<double>>ma(sz),mb(sz);
    for(int i=0;i<a.size();i++)ma[i]=a[i];
    for(int i=0;i<b.size();i++)mb[i]=b[i];
    dft(ma,1);
    dft(mb,1);
    for(int i=0;i<sz;i++)ma[i]*=mb[i];
    dft(ma,-1);
    vector<double>res(a.size()+b.size()-1);
    for(int i=0;i<res.size();i++)res[i]=(ma[i].real())/(double)sz;
    return res;
  }
};