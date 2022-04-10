#pragma once
template<class S,S (*op)(S,S),S (*e)()>
struct segtree{
  private:
  int _n,size=1,idx=0;
  vector<S>seq;
  void update(int k){seq[k]=op(seq[2*k],seq[2*k+1]);}
  public:
  segtree():segtree(0){};
  segtree(int n):segtree(vector<S>(n,e())){}
  segtree(const vector<S>&v):_n(int(v.size())){
    while(size<_n)size<<=1,idx++;
    seq=vector<S>(2*size,e());
    for(int i=0;i<_n;i++)seq[size+i]=v[i];
    for(int i=size-1;i>=1;i--)update(i);
  }
  void set(int p,S x){
    p+=size;
    seq[p]=x;
    for(int i=1;i<=idx;i++)update(p>>i);
  }
  S operator[](int p){return seq[p+size];}
  S query(int l,int r){
    S sml=e(),smr=e();
    l+=size,r+=size;
    while(l<r){
      if(l&1)sml=op(sml,seq[l++]);
      if(r&1)smr=op(seq[--r],smr);
      l>>=1,r>>=1;
    }
    return op(sml,smr);
  }
  S all_query()const{return seq[1];}
  template<typename F>
  int find_right(int l,const F&f)const{
    if(l==_n)return _n;
    l+=size;
    S sum=e();
    do{
      while(!(l&1))l>>=1;
      if(!f(op(sum,seq[l]))){
        while(l<size){
          l<<=1;
          if(f(op(sum,seq[l])))sum=op(sum,seq[l++]);
        }
        return l-size;
      }
      sum=op(sum,seq[l++]);
    }while((l&-l)!=l);
    return _n;
  }
  template<typename F>
  int find_left(int r,const F&f)const{
    if(!r)return 0;
    r+=size;
    S sum=e();
    do{
      r--;
      while(r>1&&(r&1))r>>=1;
      if(!f(op(seq[r],sum))){
        while(r<size){
          (r<<=1)++;
          if(f(op(seq[r],sum)))sum=op(seq[r--],sum);
        }
        return r+1-size;
      }
      sum=op(seq[r],sum);
    }while((r&-r)!=r);
    return 0;
  }
};
/**
 * @brief Segment Tree(セグメント木)
*/