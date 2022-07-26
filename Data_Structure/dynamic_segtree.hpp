#pragma once
template<typename S,S (*op)(S,S),S (*e)()>
struct dynamic_segtree{
  public:
  dynamic_segtree():dynamic_segtree(numeric_limits<long long>::max()>>1){}
  dynamic_segtree(long long n):n(n),root(nullptr){}
  void set(int p,const S&x){inner_set(root,0,n,p,x);}
  S get(long long p)const{return inner_get(root,0,n,p);}
  S operator[](long long p)const{return inner_get(root,0,n,p);}
  S query(long long l,long long r)const{return inner_query(root,0,n,l,r);}
  S all_query()const{return root?root->val:e();}
  void reset(long long l,long long r){inner_reset(root,0,n,l,r);}
  private:
  struct node;
  using ptr=unique_ptr<node>;
  struct node{
    S val;
    ptr l,r;
    node(const S&val):val(val),l(nullptr),r(nullptr){}
  };
  ptr root;
  const long long n;
  void inner_set(ptr&nd,long long l,long long r,long long p,const S&x){
    if(!nd)nd=make_unique<node>(e());
    if(r-l==1){nd->val=x;return;}
    long long m=(l+r)>>1;
    if(p<m)inner_set(nd->l,l,m,p,x);
    else inner_set(nd->r,m,r,p,x);
    nd->val=op(nd->l?nd->l->val:e(),nd->r?nd->r->val:e());
  }
  S inner_get(const ptr&nd,long long l,long long r,long long p)const{
    if(!nd)return e();
    if(r-l==1)return nd->val;
    long long m=(l+r)>>1;
    if(p<m)return inner_get(nd->l,l,m,p);
    return inner_get(nd->r,m,r,p);
  }
  S inner_query(const ptr&nd,long long nl,long long nr,long long l,long long r)const{
    if(!nd||nr<=l||r<=nl)return e();
    if(l<=nl&&nr<=r)return nd->val;
    long long m=(nl+nr)>>1;
    return op(inner_query(nd->l,nl,m,l,r),inner_query(nd->r,m,nr,l,r));
  }
  void inner_reset(ptr&nd,long long nl,long long nr,long long l,long long r){
    if(!nd||nr<=l||r<=nl)return;
    if(l<=nl&&nr<=r){
      nd.reset();return;
    }
    long long m=(l+r)>>1;
    inner_reset(nd->l,nl,m,l,r);
    inner_reset(nd->r,m,nr,l,r);
    nd->val=op(nd->l?nd->l->val:e(),nd->r?nd->r->val:e());
  }
};
/**
 * @brief Dynamic Segment Tree(動的セグ木)
 */