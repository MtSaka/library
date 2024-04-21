#pragma once
#include"../template/template.hpp"

template<class T>
struct SegmentTreeBeats{
  private:
  static constexpr T INF=numeric_limits<T>::max();
  struct S{
    T sum=0,b1=0,s1=0,b2=-INF,s2=INF,b_cnt=1,s_cnt=1,add=0;
    S(){}
    S(const T&a):sum(a),b1(a),s1(a){}
  };
  vector<S>seq;
  int size=1,idx=0;
  void update(int k){
    S&s=seq[k];
    S&l=seq[2*k];
    S&r=seq[2*k+1];
    s.sum=l.sum+r.sum;
    if(l.b1==r.b1){
      s.b1=l.b1;
      s.b2=max(l.b2,r.b2);
      s.b_cnt=l.b_cnt+r.b_cnt;
    }
    else{
      s.b1=max(l.b1,r.b1);
      s.b2=max(l.b1>r.b1?l.b2:l.b1,l.b1>r.b1?r.b1:r.b2);
      s.b_cnt=l.b1>r.b1?l.b_cnt:r.b_cnt;
    }
    if(l.s1==r.s1){
      s.s1=l.s1;
      s.s2=min(l.s2,r.s2);
      s.s_cnt=l.s_cnt+r.s_cnt;
    }
    else{
      s.s1=min(l.s1,r.s1);
      s.s2=min(l.s1>r.s1?l.s1:l.s2,l.s1>r.s1?r.s2:r.s1);
      s.s_cnt=l.s1>r.s1?r.s_cnt:l.s_cnt;
    }
  }
  void eval_add(int k,T x){
    S&s=seq[k];
    s.sum+=x<<(idx+__builtin_clz(k)-31);
    s.b1+=x,s.s1+=x;
    if(s.b2!=-INF)s.b2+=x;
    if(s.s2!=INF)s.s2+=x;
    s.add+=x;
  }
  void eval_min(int k,T x){
    S&s=seq[k];
    s.sum+=(x-s.b1)*s.b_cnt;
    if(s.s1==s.b1)s.s1=x;
    if(s.s2==s.b1)s.s2=x;
    s.b1=x;
  }
  void eval_max(int k,T x){
    S&s=seq[k];
    s.sum+=(x-s.s1)*s.s_cnt;
    if(s.b1==s.s1)s.b1=x;
    if(s.b2==s.s1)s.b2=x;
    s.s1=x;
  }
  void eval(int k){
    S&s=seq[k];
    if(s.add!=0){
      eval_add(k*2,s.add);
      eval_add(k*2+1,s.add);
      s.add=0;
    }
    if(s.b1<seq[2*k].b1)eval_min(2*k,s.b1);
    if(s.s1>seq[2*k].s1)eval_max(2*k,s.s1);
    if(s.b1<seq[2*k+1].b1)eval_min(2*k+1,s.b1);
    if(s.s1>seq[2*k+1].s1)eval_max(2*k+1,s.s1);
  }
  void apply_min(int k,T x){
    if(seq[k].b1<=x)return;
    if(seq[k].b2<x){
      eval_min(k,x);
      return;
    }
    eval(k);
    apply_min(2*k,x);
    apply_min(2*k+1,x);
    update(k);
  }
  void apply_max(int k,T x){
    if(seq[k].s1>=x)return;
    if(seq[k].s2>x){
      eval_max(k,x);
      return;
    }
    eval(k);
    apply_max(2*k,x);
    apply_max(2*k+1,x);
    update(k);
  }
  void inner_chmin(int l,int r,T x){
    if(l==r)return;
    l+=size,r+=size;
    for(int i=idx;i>=1;i--){
      if(((l>>i)<<i)!=l)eval(l>>i);
      if(((r>>i)<<i)!=r)eval(r>>i);
    }
    int l2=l,r2=r;
    while(l<r){
      if(l&1)apply_min(l++,x);
      if(r&1)apply_min(--r,x);
      l>>=1;
      r>>=1;
    }
    l=l2,r=r2;
    for(int i=1;i<=idx;i++){
      if(((l>>i)<<i)!=l)update(l>>i);
      if(((r>>i)<<i)!=r)update(r>>i);
    }
  }
  void inner_chmax(int l,int r,T x){
    if(l==r)return;
    l+=size,r+=size;
    for(int i=idx;i>=1;i--){
      if(((l>>i)<<i)!=l)eval(l>>i);
      if(((r>>i)<<i)!=r)eval(r>>i);
    }
    int l2=l,r2=r;
    while(l<r){
      if(l&1)apply_max(l++,x);
      if(r&1)apply_max(--r,x);
      l>>=1;
      r>>=1;
    }
    l=l2,r=r2;
    for(int i=1;i<=idx;i++){
      if(((l>>i)<<i)!=l)update(l>>i);
      if(((r>>i)<<i)!=r)update(r>>i);
    }
  }
  void inner_add(int l,int r,T x){
    if(l==r)return;
    l+=size,r+=size;
    for(int i=idx;i>=1;i--){
      if(((l>>i)<<i)!=l)eval(l>>i);
      if(((r>>i)<<i)!=r)eval(r>>i);
    }
    int l2=l,r2=r;
    while(l<r){
      if(l&1)eval_add(l++,x);
      if(r&1)eval_add(--r,x);
      l>>=1;
      r>>=1;
    }
    l=l2,r=r2;
    for(int i=1;i<=idx;i++){
      if(((l>>i)<<i)!=l)update(l>>i);
      if(((r>>i)<<i)!=r)update(r>>i);
    }
  }
  void inner_update(int l,int r,T x){
    if(l==r)return;
    l+=size,r+=size;
    for(int i=idx;i>=1;i--){
      if(((l>>i)<<i)!=l)eval(l>>i);
      if(((r>>i)<<i)!=r)eval(r>>i);
    }
    int l2=l,r2=r;
    while(l<r){
      if(l&1)apply_min(l++,x),apply_max(l,x);
      if(r&1)apply_min(--r,x),apply_max(r,x);
      l>>=1;
      r>>=1;
    }
    l=l2,r=r2;
    for(int i=1;i<=idx;i++){
      if(((l>>i)<<i)!=l)update(l>>i);
      if(((r>>i)<<i)!=r)update(r>>i);
    }
  }
  T inner_min(int l,int r){
    if(l==r)return INF;
    T sml=INF,smr=INF;
    l+=size,r+=size;
    for(int i=idx;i>=1;i--){
      if(((l>>i)<<i)!=l)eval(l>>i);
      if(((r>>i)<<i)!=r)eval(r>>i);
    }
    while(l<r){
      if(l&1)sml=min(sml,seq[l++].s1);
      if(r&1)smr=min(seq[--r].s1,smr);
      l>>=1,r>>=1;
    }
    return min(sml,smr);
  }
  T inner_max(int l,int r){
    if(l==r)return -INF;
    T sml=-INF,smr=-INF;
    l+=size,r+=size;
    for(int i=idx;i>=1;i--){
      if(((l>>i)<<i)!=l)eval(l>>i);
      if(((r>>i)<<i)!=r)eval(r>>i);
    }
    while(l<r){
      if(l&1)sml=max(sml,seq[l++].b1);
      if(r&1)smr=max(seq[--r].b1,smr);
      l>>=1,r>>=1;
    }
    return max(sml,smr);
  }
  T inner_sum(int l,int r){
    if(l==r)return 0;
    T sml=0,smr=0;
    l+=size,r+=size;
    for(int i=idx;i>=1;i--){
      if(((l>>i)<<i)!=l)eval(l>>i);
      if(((r>>i)<<i)!=r)eval(r>>i);
    }
    while(l<r){
      if(l&1)sml+=seq[l++].sum;
      if(r&1)smr+=seq[--r].sum;
      l>>=1,r>>=1;
    }
    return sml+smr;
  }
  public:
  SegmentTreeBeats(){}
  SegmentTreeBeats(int n):SegmentTreeBeats(vector<T>(n)){}
  SegmentTreeBeats(const vector<T>&v){
    const int n=v.size();
    while(size<n)size<<=1,idx++;
    seq.resize(2*size);
    for(int i=0;i<n;i++)seq[i+size]=v[i];
    for(int i=size-1;i;i--)update(i);
  }
  void range_chmin(int l,int r,T x){inner_chmin(l,r,x);}
  void range_chmax(int l,int r,T x){inner_chmax(l,r,x);}
  void range_add(int l,int r,T x){inner_add(l,r,x);}
  void range_update(int l,int r,T x){inner_update(l,r,x);}
  T range_min(int l,int r){return inner_min(l,r);}
  T range_max(int l,int r){return inner_max(l,r);}
  T range_sum(int l,int r){return inner_sum(l,r);}
};
/**
 * @brief Segment Tree Beats!(Rnage Chmin Chmax Add Update Range Sum Min Max)
*/