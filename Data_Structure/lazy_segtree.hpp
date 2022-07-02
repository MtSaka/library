#pragma once
template<class S,S (*op)(S,S),S (*e)(),class F,S (*mapping)(F,S),F (*composition)(F,F),F (*id)()>
struct lazy_segtree{
  private:
  int _n,size=1,idx=0;
  vector<S>seq;
  vector<F>lazy;
  void update(int k){seq[k]=op(seq[2*k],seq[2*k+1]);}
  void all_apply(int k,F f){
    seq[k]=mapping(f,seq[k]);
    if(k<size)lazy[k]=composition(f,lazy[k]);
  }
  void eval(int k){
    all_apply(2*k,lazy[k]);
    all_apply(2*k+1,lazy[k]);
    lazy[k]=id();
  }
  public:
  lazy_segtree():lazy_segtree(0){}
  lazy_segtree(int n):lazy_segtree(vector<S>(n,e())){}
  lazy_segtree(const vector<S>&v):_n(int(v.size())){
    while(size<_n)size<<=1,idx++;
    seq=vector<S>(2*size,e());
    lazy=vector<F>(2*size,id());
    for(int i=0;i<_n;i++)seq[size+i]=v[i];
    for(int i=size-1;i>=1;i--)update(i);
  }
  void set(int p,S x){
    p+=size;
    for(int i=idx;i>=1;i--)eval(p>>i);
    seq[p]=x;
    for(int i=1;i<=idx;i++)update(p>>i);
  }
  S operator[](int p){
    p+=size;
    for(int i=idx;i>=1;i--)eval(p>>i);
    return seq[p];
  }
  S query(int l,int r){
    if(l==r)return e();
    S sml=e(),smr=e();
    l+=size,r+=size;
    for(int i=idx;i>=1;i--){
      if(((l>>i)<<i)!=l)eval(l>>i);
      if(((r>>i)<<i)!=r)eval(r>>i);
    }
    while(l<r){
      if(l&1)sml=op(sml,seq[l++]);
      if(r&1)smr=op(seq[--r],smr);
      l>>=1,r>>=1;
    }
    return op(sml,smr);
  }
  S all_query()const{return seq[1];}
  void apply(int p,F f){
    p+=size;
    for(int i=idx;i>=1;i--)eval(p>>i);
    seq[p]=mapping(f,seq[p]);
    for(int i=1;i<=idx;i++)update(p>>i);
  }
  void apply(int l,int r,F f){
    if(l==r)return ;
    l+=size;
    r+=size;
    for(int i=idx;i>=1;i--){
      if(((l>>i)<<i)!=l)eval(l>>i);
      if(((r>>i)<<i)!=r)eval(r>>i);
    }
    int l2=l,r2=r;
    while(l<r){
      if(l&1)all_apply(l++,f);
      if(r&1)all_apply(--r,f);
      l>>=1;
      r>>=1;
    }
    l=l2,r=r2;
    for(int i=1;i<=idx;i++){
      if(((l>>i)<<i)!=l)update(l>>i);
      if(((r>>i)<<i)!=r)update(r>>i);
    }
  }
};
/**
 * @brief Lazy Segment Tree(遅延セグメント木)
*/