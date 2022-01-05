/**
 * @brief Segment Tree(セグメント木)
*/
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
    S ret=e();
    l+=size,r+=size;
    while(l<r){
      if(l&1)ret=op(ret,seq[l++]);
      if(r&1)ret=op(seq[--r],ret);
      l>>=1,r>>=1;
    }
    return ret;
  }
  S all_query()const{return seq[1];}
};