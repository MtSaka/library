#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include"../../template/template.hpp"
#include"../../Data_Structure/wavelet_matrix.hpp"
int main(){
  int n,q;
  cin>>n>>q;
  vi a;cin>>a;
  compressed_wavelet_matrix<int,18>w(a);
  while(q--){
    int l,r,k;
    cin>>l>>r>>k;
    print(w.kth_smallest(l,r,k));
  }
}