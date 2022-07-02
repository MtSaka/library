#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E"
#include"../../template/template.hpp"
#include"../../Data_Structure/dual_segtree.hpp"
int e(){return 0;}
int mapping(int a,int b){return a+b;}
int composition(int a,int b){return a+b;}
int id(){return 0;}
int main(){
  int n,q;cin>>n>>q;
  dual_segtree<int,e,int,mapping,composition,id>seg(n);
  while(q--){
    int t;cin>>t;
    if(t==0){
      int l,r,x;cin>>l>>r>>x;
      seg.apply(l-1,r,x);
    }
    else{
      int k;cin>>k;
      print(seg[k-1]);
    }
  }
}