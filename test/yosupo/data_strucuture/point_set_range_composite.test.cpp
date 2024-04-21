#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include"../../../template/template.hpp"
#include"../../../others/monoid2.hpp"
#include"../../../math/modular/modint.hpp"
#include"../../../ds/segment/segment-tree.hpp"
using mint=ModInt<998244353>;
using T=pair<mint,mint>;
int main(){
  INT(n,q);
  vector<T>a(n);cin>>a;
  SegmentTree<Monoid::Composite<mint>>seg(a);
  while(q--){
    INT(t,a,b,c);
    if(t==0)seg.set(a,T{b,c});
    else{
      auto [x,y]=seg.prod(a,b);
      print(x*c+y);
    }
  }
}