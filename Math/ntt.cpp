#include"modint.cpp"
template<long long m>
struct NTT{
  using mint=modint<m>;
  mint g=2;
  int limit=0;
  vector<mint>root,inv_root;
  mint primitive_root(long long mo){
    if(mo==167772161)return mint(3);
    if(mo==469762049)return mint(3);
    if(mo==754974721)return mint(11);
    if(mo==998244353)return mint(3);
    if(mo==1224736769)return mint(3);
    return mint(0);
  }
  NTT(){
    g=primitive_root(m);
    long long now=m-1;
    while(!(now&1))now>>=1,limit++;
    root.resize(limit+1,1),inv_root.resize(limit+1,1);
    root[limit]=g.pow(now);
    inv_root[limit]/=root[limit];
    for(int i=limit-1;i>=0;i--){
      root[i]=root[i+1]*root[i+1];
      inv_root[i]=inv_root[i+1]*inv_root[i+1];
    }
  }
  void dft(vector<mint>&a,int inv){
    int sz=a.size();
    if(sz==1)return;
    int mask=sz-1;
    vector<mint>b(sz);
    for(int i=sz>>1;i>=1;i>>=1){
      int e=__builtin_ffsll(sz/i)-1;
      mint w=1,z=(inv==1?root[e]:inv_root[e]);
      for(int j=0;j<sz;j+=i){
        for(int k=0;k<i;k++)b[j+k]=a[((j<<1)&mask)+k]+w*a[(((j<<1)+i)&mask)+k];
        w*=z;
      }
      swap(a,b);
    }
  }
  vector<mint>multiply(vector<mint>a,vector<mint>b){
    int sz=1,mxsiz=a.size()+b.size()-1;
    while(sz<mxsiz)sz<<=1;
    a.resize(sz),b.resize(sz);
    dft(a,1),dft(b,1);
    for(int i=0;i<sz;i++)a[i]*=b[i];
    dft(a,-1);
    mint iz=mint(sz).inv();
    for(int i=0;i<mxsiz;i++)a[i]*=iz;
    a.resize(mxsiz);
    return a;
  }
  template<typename T,std::enable_if_t<is_integral<T>::value>* = nullptr>
  vector<T>multiply(const vector<T>&a,const vector<T>&b){
    using mint=modint<m>;
    vector<mint>a2(a.size()),b2(b.size());
    for(int i=0;i<a.size();i++)a2[i]=a[i];
    for(int i=0;i<b.size();i++)b2[i]=b[i];
    auto c2=multiply(move(a2),move(b2));
    vector<T>c(c2.size());
    for(int i=0;i<c.size();i++)c[i]=c2[i].x;
    return c;
  }
};