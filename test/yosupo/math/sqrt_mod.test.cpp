// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/sqrt_mod
#include"../../../template/template.hpp"
#include"../../../math/modular/mod-sqrt.hpp"
int main(){
  int t;
  cin>>t;
  while(t--){
    LL(y,p);
    print(mod_sqrt(y,p));
  }
}