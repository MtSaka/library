#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"
#include"../../../template/template.hpp"
#include"../../../math/number/kth-root-integer.hpp"
int main(){
  int t;
  cin>>t;
  while(t--){
    uint64_t a;
    int k;
    cin>>a>>k;
    cout<<kth_root_integer(a,k)<<endl;
  }
}