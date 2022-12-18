#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"
#include"../../../template/template.hpp"
#include"../../../data-structure/binary-indexed-tree.hpp"
int main(){
  INT(n,q);
  BinaryIndexedTree<int>bit(n);
  while(q--){
    INT(t,x,y);
    if(t)print(bit.query(x-1,y));
    else bit.add(x-1,y);
  }
}