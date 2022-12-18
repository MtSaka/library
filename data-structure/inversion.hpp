#pragma once
#include"../template/template.hpp"
#include"binary-indexed-tree.hpp"

template<typename T>
long long inversion(vector<T>a){
  int n=a.size();
  compressor<T>c(a);
  c.build();
  a=c.pressed(a);
  long long ans=0;
  BinaryIndexedTree<int>bit(c.size());
  for(int i=0;i<n;i++){
    ans+=i-bit.sum(a[i]+1);
    bit.add(a[i],1);
  }
  return ans;
}
/**
 * @brief Inversion Number(転倒数)
*/