#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include"../../../template/template.hpp"
#include"../../../data-structure/convex-hull-trick.hpp"
int main(){
  ConvexHullTrick cht;
  INT(n,q);
  rep(i,n){
    INT(a,b);
    cht.add_line(a,b);
  }
  rep(i,q){
    INT(t);
    if(t==0){
      INT(a,b);
      cht.add_line(a,b);
    }
    else{
      INT(x);
      print(cht.get_min(x));
    }
  }
}