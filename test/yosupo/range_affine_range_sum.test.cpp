#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include"../../template/template.hpp"
#include"../../Math/modint.hpp"
#include"../../Data_Structure/lazy_segtree.hpp"
using mint=modint<mod>;
using Pi=pair<mint,int >;
using qi=pair<mint,mint>;
Pi op(Pi a,Pi b){return {a.first+b.first,a.second+b.second};}
Pi mapping(qi a,Pi b){return {a.first*b.first+a.second*mint(b.second),b.second};}
qi composition(qi b,qi a){return {a.first*b.first,a.second*b.first+b.second};}
Pi e(){return Pi(0,0);}
qi id(){return qi(1,0);}
int main(){
  INT(n,q);
  lazy_segtree<Pi,op,e,qi,mapping,composition,id>s(n);
  rep(i,n){
    mint a;
    scan(a);
    s.set(i,Pi(a,1));
  }
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