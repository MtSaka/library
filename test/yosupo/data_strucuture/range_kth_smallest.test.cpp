// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/range_kth_smallest
#include"../../../template/template.hpp"
#include"../../../ds/wavelet/wavelet-matrix.hpp"
int main(){
  int n,q;
  cin>>n>>q;
  vi a(n);cin>>a;
  CompressedWaveletMatrix<int,18>w(a);
  while(q--){
    int l,r,k;
    cin>>l>>r>>k;
    print(w.kth_smallest(l,r,k));
  }
}