#include<bits/stdc++.h>
#include<../../code/library/Math/modint.cpp>
using namespace std;
template<long long m>
struct NTT{
  using mint=modint<m>;
  mint g=2;
  int limit=0;
  vector<mint>root,inv_root;
  NTT(){
    while(g.pow((m-1)>>1)==1)g+=1;
    long long now=m-1;
    while(!(now&1)){
      now>>=1,limit++;
    }
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
    vector<mint>ret(sz);
    if(sz==1)return ;
    vector<mint>x(sz/2),y(sz/2);
    for(int i=0;i<sz/2;i++){
      x[i]=a[i*2];
      y[i]=a[i*2+1];
    }
    dft(x,inv);
    dft(y,inv);
    int e=__builtin_ffsll(sz)-1;
    mint n=1,z=(t==1?root[e],inv_root[e]);
    for(int i=0;i<sz;i++){
      a[i]=x[i%(sz/2)]+n*y[i%(sz/2)];
      n*=z;
    }
  }
  vector<mint>multiply(vector<mint>a,vector<mint>b){
    int cnt=0,sz=1,mxsiz=a.size()+b.size()-1;
    while(sz<mxsiz)sz<<=1,cnt++;
    a.resize(sz),b.resize(sz);
    dft(a,1,cnt,limit),dft(b,1,cnt,limit);
    for(int i=0;i<sz;i++)a[i]*=b[i];
    dft(a,-1,cnt,limit);
    for(int i=0;i<sz;i++)a[i]/=sz;
    a.resize(mxsiz);
    return a;
  }
};