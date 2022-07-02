#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D"
#include"../../template/template.hpp"
#include"../../Data_Structure/dual_segtree.hpp"
int e(){return (int)((1LL<<31)-1);}
int mapping(int a,int b){return a==-1?b:a;}
int composition(int a,int b){return a==-1?b:a;}
int id(){return -1;}
int main(){
  int n,q;cin>>n>>q;
  dual_segtree<int,e,int,mapping,composition,id>seg(n);
  while(q--){
    int t;cin>>t;
    if(t==0){
      int l,r,x;cin>>l>>r>>x;
      seg.apply(l,r+1,x);
    }
    else{
      int k;cin>>k;
      print(seg[k]);
    }
  }
}