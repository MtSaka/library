#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include"../../template/template.hpp"
#include"../../data-structure/segment-tree.hpp"
#include"../../math/modular/modint.hpp"
using mint=modint<mod>;
using S=pair<mint,mint>;
S op(S a,S b){return S{a.first*b.first,a.second*b.first+b.second};}
S e(){return S{mint(1),mint(0)};}
int main(){
  int n,q;
  cin>>n>>q;
  vector<S>a(n);
  cin>>a;
  SegmentTree<S,op,e>s(a);
  while(q--){
    int t;
    cin>>t;
    if(t){
      int l,r,x;
      cin>>l>>r>>x;
      auto [n,m]=s.query(l,r);
      cout<<n*mint(x)+m<<endl;
    }
    else{
      int p;
      cin>>p;
      mint c,d;
      cin>>c>>d;
      s.set(p,S{c,d});
    }
  }
}