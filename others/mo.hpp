#pragma once
#include"../../template/template.hpp"

struct Mo{
  int n;
  vector<int>left,right;
  Mo(int n):n(n){}
  void add(int l,int r){
    left.push_back(l);
    right.push_back(r);
  }
  template<typename AL,typename AR,typename DL,typename DR,typename REM>
  void run(const AL&add_left,const AR&add_right,const DL&delete_left,const DR&delete_right,const REM&rem){
    const int q=left.size(),width=max<int>(1,int(sqrt(3)*n/sqrt(max(1,2*q))));
    vector<int>order(q);
    iota(order.begin(),order.end(),0);
    sort(order.begin(),order.end(),[&](int a,int b){
      const int ablock=left[a]/width,bblock=left[b]/width;
      if(ablock!=bblock)return ablock<bblock;
      return (ablock&1)?(right[a]>right[b]):(right[a]<right[b]);
    });
    int l=0,r=0;
    for(auto idx:order){
      while(l>left[idx])add_left(--l);
      while(r<right[idx])add_right(r++);
      while(l<left[idx])delete_left(l++);
      while(r>right[idx])delete_right(--r); 
      rem(idx);
    }
  }
  template<typename A,typename D,typename REM>
  void run(const A&add,const D&del,const REM&rem){
    run(add,add,del,del,rem);
  }
};
/**
 * @brief Mo's Algorithm
*/