#pragma once
#include"../template/template.hpp"

template<class S,S (*op)(S,S),S (*e)()>
struct DisjointSparseTable{
  private:
  vector<vector<S>>table;
  vector<int>log_table;
  public:
  DisjointSparseTable(const vector<S>&v){
    int bit=0,sz=1;
    while(sz<=(int)v.size())sz<<=1,bit++;
    table.resize(bit,vector<S>(v.size(),e()));
    for(size_t i=0;i<v.size();i++)table[0][i]=v[i];
    int shift=1;
    for(int i=1;i<bit;i++){
      shift<<=1;
      for(int j=0;j<(int)v.size();j+=shift<<1){
        int l=min<int>(j+shift,v.size());
        table[i][l-1]=v[l-1];
        for(int k=l-2;k>=j;k--)table[i][k]=op(v[k],table[i][k+1]);
        if((int)v.size()==l)break;
        table[i][l]=v[l];
        int r=min<int>(l+shift,v.size());
        for(int k=l+1;k<r;k++)table[i][k]=op(table[i][k-1],v[k]);
      }
    }
    log_table.resize(sz);
    for(int i=2;i<sz;i++)log_table[i]=1+log_table[i>>1];
  }
  S query(int l,int r){
    if(l==r)return e();
    if(l>=--r)return table[0][l];
    int pos=log_table[l^r];
    return op(table[pos][l],table[pos][r]);
  }
};
/**
 * @brief Disjoint Sparse Table
 */