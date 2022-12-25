#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"
#include"../../../template/template.hpp"
#include"../../../math/number/kth-root-integer.hpp"
int main(){
  INT(t);
  while(t--){
    uint64_t a;cin>>a;
    INT(k);
    print(kth_root_integer(a,k));
  }
}