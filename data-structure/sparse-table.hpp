#pragma once
#include"../template/template.hpp"
#include"../others/monoid.hpp"

template<typename M>
struct SparseTable{
  private:
  using T=typename M::value_type;
  int lg,n;
  vector<vector<T>>table;
  vector<int>log_table;
  T internal_prod(int l,int r)const{
    int d=log_table[r-l];
    return M::op(table[d][l],table[d][r-(1<<d)]);
  }
  public:
  SparseTable()=default;
  SparseTable(const vector<T>&v){init(v);}
  void init(const vector<T>&v){
    n=v.size();
    lg=ceil_log2(n)+1;
    table.assign(lg,vector<T>(n));
    table[0]=v;
    rep(i,1,lg)rep(j,n-(1<<i)+1)table[i][j]=M::op(table[i-1][j],table[i-1][j+(1<<(i-1))]);
    log_table.assign(n+1,0);
    log_table[1]=0;
    rep(i,2,n+1)log_table[i]=log_table[i>>1]+1;
  }
  template<bool dummy=true,typename enable_if<Monoid::has_id<M>::value&&dummy>::type* = nullptr>
  T prod(int l,int r)const{
    if(l==r)return M::id();
    return internal_prod(l,r);
  }
  template<bool dummy=true,typename enable_if<!Monoid::has_id<M>::value&&dummy>::type* = nullptr>
  T prod(int l,int r)const{
    if(l==r)return T{};
    return internal_prod(l,r);
  }
};
/**
 * @brief Sparse Table
*/