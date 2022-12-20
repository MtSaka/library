#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include"../../template/template.hpp"
#include"../../math/modular/ModInt.hpp"
#include"../../data-structure/lazy-segment-tree.hpp"
using mint=ModInt<998244353>;
using Pi=pair<mint,int >;
using qi=pair<mint,mint>;
Pi op(Pi a,Pi b){return {a.first+b.first,a.second+b.second};}
Pi mapping(qi a,Pi b){return {a.first*b.first+a.second*mint(b.second),b.second};}
qi composition(qi b,qi a){return {a.first*b.first,a.second*b.first+b.second};}
Pi e(){return Pi(0,0);}
qi id(){return qi(1,0);}
int main(){
  INT(n,q);
  vector<Pi>a(n,{0,1});
  rep(i,n)cin>>a[i].first;
  LazySegmentTree<Pi,op,e,qi,mapping,composition,id>s(a);
  while(q--){
    LL(t);
    if(t){
      INT(l,r);
      print(s.query(l,r).first);
    }
    else{
      INT(l,r);
      mint b,c;
      scan(b,c);
      s.apply(l,r,qi(b,c));
    }
  }
}